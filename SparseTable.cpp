struct SparseTable{
  long long *a[30];
  int n, *lg;
  long long merge(long long a, long long b){
    return a + b;
  }
  explicit SparseTable(int m, long long b[]){
    n = m;
    lg = new int[n+1]{};
    for(int i=2;i<=n;++i)
      lg[i] = lg[i/2] + 1;
    for(int j=0;j<30;++j)
      a[j] = new long long[n];
    for(int i=0;i<n;++i)
      a[0][i] = b[i];
    for(int j=0;j<30;++j)
      for(int i=0;i<=n-(1<<j);++i)
        a[j][i] = merge(a[j-1][i], a[j-1][i+(1<<(j-1))]);
  }
  long long get(int l, int r){
    return merge(a[lg[r-l+1]][l], a[lg[r-l+1]][r-(1<<lg[r-l+1])+1]);
  }
};
