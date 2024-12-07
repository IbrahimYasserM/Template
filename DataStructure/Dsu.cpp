struct Dsu{
  int *p;
  explicit Dsu(int n){
    p = new int[n];
    while(n--) p[n] = n;
  }
  int get(int a){
    if(a != p[a]) p[a] = get(p[a]);
    return p[a];
  }
  void connect(int a, int b){
    a = get(a);
    b = get(b);
    p[b] = a;
  }
};
