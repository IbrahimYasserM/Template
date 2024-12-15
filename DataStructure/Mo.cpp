struct Query{
  int l, r, i;
  static int SQ;
  bool operator<(Query& o){
    if(l/SQ != o.l/SQ) return l<o.l;
    return (l/SQ%2?r>o.r:r<o.r);
  }
};
void Mo(){
  Query qs[q];
  for(int i=0;i<q;i++) {
    std::cin >> qs[i].l >> qs[i].r;
    qs[i].i = i;
  }
  std::sort(qs,qs+q);
  auto add = [&](int i){

  };
  auto del = [&](int i){

  };
  auto query = [&](){

  };
  int l=0,r=-1;
  for(auto &[lx, rx, i] : qs) {
    while (rx>r) add(++r);
    while (lx<l) add(--l);
    while (rx<r) del(r--);
    while (lx>l) del(l++);
  }
}
