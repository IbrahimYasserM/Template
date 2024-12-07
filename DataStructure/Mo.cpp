struct Query{
  int l, r, i;
  static int SQ;
  bool operator<(Query& o){
    if(l/SQ != o.l/SQ) return l<o.l;
    return (l/SQ%2?r>o.r:r<o.r);
  }
};
void Mo(){
  auto add = [&](int i){

  };
  auto del = [&](int i){

  };
  auto query = [&](){
  
  };
}
