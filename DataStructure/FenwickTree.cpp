struct FenwickTree {
  int *a, n;
  explicit FenwickTree(int m){
    n = m+1;
    a = new int[n]{};
  }
  void update(int i, int v) {
      for (++i; i < n; i += (i & -i))
          a[i] += v;
  }
  int query(int i) const {
      int ret = 0;
      for (++i; i; i -= (i & -i))
          ret += a[i];
      return ret;
  }
};
