struct Sqrt{
  long long *a, *b;
  static int SQ;
  explicit Sqrt(int n){
    SQ = sqrt(n) + 1;
    a = new long long[n]{};
    b = new long long[SQ]{};
  }
  void set(int i, int v){
    b[i/SQ] -= a[i];
    a[i] = v;
    b[i/SQ] += a[i];
  }
  long long get(int r){
    long long sum=0;
    for(int i=0;i<r/SQ;++i)
      sum += b[i];
    for(int i=r/SQ*SQ;i<=r;++i)
      sum += a[i];
    return sum;
  }
  long long get(int l, int r){
    return get(r) - get(l-1);
  }
};