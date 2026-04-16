// Sardina
// Time Complexity: O(N * log(N))
bool cw(point a, point b, point c, bool include_collinear) {
    int o = orient(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
void convex_hull(vector<point>& a, bool include_collinear = false) {
    point p0 = *min_element(a.begin(), a.end(), [](point a, point b) {
    return make_pair(a.Y, a.X) < make_pair(b.Y, b.X);
    });
    sort(a.begin(), a.end(), [&p0](const point& a, const point& b) {
    int o = orient(p0, a, b);
    if (o == 0)
        return (p0.X-a.X)*(p0.X-a.X) + (p0.Y-a.Y)*(p0.Y-a.Y)
        < (p0.X-b.X)*(p0.X-b.X) + (p0.Y-b.Y)*(p0.Y-b.Y);
        return o < 0;
        });
    if (include_collinear) {
        int i = (int)a.size()-1;
        while (i >= 0 && orient(p0, a[i], a.back()) == 0) i--;
        reverse(a.begin()+i+1, a.end());
    }
    vector<point> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_colline
        ar))
            st.pop_back();
        st.push_back(a[i]);
    }
    if (include_collinear == false && st.size() == 2 && st[0] == st[1])
        st.pop_back();
    a = st;
}