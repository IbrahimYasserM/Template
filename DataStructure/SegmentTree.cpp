template <typename T>
struct SegmentTree{
  #define L x*2+1
  #define R x*2+2
  T *a, *b;
  int n=1;
  explicit SegmentTree(int m){
    while(n<m) n*=2;
    a = new T[n*2]{};
    b = new T[n*2]{};
  }
  T merge(T a, T b){
    T c;
    c = a + b;
    return c;
  }
  // update index
  void set(int i, int v, int x=-1, int lx=-1, int rx=-1){
    if(!~x) set(i,v,0,0,n);
    else if(rx-lx==1) a[x] = v;
    else {
      b[L] += b[x];
      b[R] += b[x];
      b[x] = 0;
      int m = (lx+rx)/2;
      if(i<m) set(i,v,L,lx,m);
      else set(i,v,R,m,rx);
      a[x] = merge(a[L]+b[L]*(rx-lx)/2,a[R]+b[R]*(rx-lx)/2);
    }
  }
  // update range
  void add(int l, int r, int v, int x=-1, int lx=-1, int rx=-1){
    if(!~x) add(l,r,v,0,0,n);
    else if(l>=rx||r<=lx);
    else if(r>=rx&&l<=lx) b[x] += v;
    else {
      b[L] += b[x];
      b[R] += b[x];
      b[x] = 0;
      int m = (lx+rx)/2;
      add(l,r,v,L,lx,m);
      add(l,r,v,R,m,rx);
      a[x] = merge(a[L]+b[L]*(rx-lx)/2,a[R]+b[R]*(rx-lx)/2);
    }
  }
  // get index
  T is(int i, int x=-1, int lx=-1, int rx=-1){
    if(!~x) return is(i,0,0,n);
    if(rx-lx==1) return a[x] + b[x];
    b[L] += b[x];
    b[R] += b[x];
    b[x] = 0;
    int m = (lx+rx)/2;
    if(i<m) return is(i,L,lx,m);
    return is(i,R,m,rx);
  }
  // get range
  T get(int l, int r, int x=-1, int lx=-1, int rx=-1){
    if(!~x) return get(l,r,0,0,n);
    if(l>=rx||r<=lx) return 0;
    if(r>=rx&&l<=lx) return a[x] + b[x]*(rx-lx);
    b[L] += b[x];
    b[R] += b[x];
    b[x] = 0;
    int m = (lx+rx)/2;
    return merge(get(l,r,L,lx,m),get(l,r,R,m,rx));
  }
};
