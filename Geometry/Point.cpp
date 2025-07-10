typedef int T;
const long double PI = acosl(-1);
const T eps = 0;
#define Point std::complex<T>
#define X real()
#define Y imag()
T dot(Point a, Point b){
    return (a * std::conj(b)).X;
}
T cross(Point a, Point b){
    return (a * std::conj(b)).Y;
}
long double abs(Point a){
    return std::sqrtl(dot(a, a));
}
long double arg(Point a){
    return atan2l(a.Y, a.X);
}
T side(Point a, Point b, Point c){
    return cross(b-a, c-a);
}
void get2Points(T a, T b, T c, Point &p1, Point &p2){
    if(b){
        p1 = Point(0, (long double)c/b);
        p2 = Point(1, (long double)(c-a)/b);
    }
    else {
        p1 = Point((long double)c/a, 0);
        p2 = Point((long double)c/a, 1);
    }
}
void getLine(Point p1, Point p2, T &a, T &b, T &c){
    T dx = p2.X - p1.X;
    T dy = p2.Y - p1.Y;
    a = -dy;
    b = dx;
    c = dx * p1.Y - dy * p1.X;
}
bool onRay(Point a, Point b, Point c){
    return side(a, b, c) == 0 && dot(b-a, c-a) >= 0;
}
bool onSegment(Point a, Point b, Point c){
    return onRay(a, b, c) && onRay(b, a, c);
}
long double distance(Point a, Point b, Point c){
    if(dot(b-a, c-a) <= eps) return abs(c-a);
    if(dot(a-b, c-b) <= eps) return abs(c-b);
    return std::abs(cross(c-a, c-b) / abs(a-b));
}
bool parallel(Point a, Point b, Point c, Point d){
    return std::abs(cross(b-a, d-c)) <= eps;
}
bool intersect(Point a, Point b, Point c, Point d){
    if(onSegment(a, b, c) || onSegment(a, b, d) || onSegment(c, d, a) || onSegment(c, d, b))
        return true;
    return side(a, b, c) / std::abs(side(a, b, c)) * side(a, b, d) < 0 && side(c, d, a) / std::abs(side(c, d, a)) * side(c, d, b) < 0;
}
std::pair<long double, long double> intersection(T a1, T b1, T c1, T a2, T b2, T c2){
    Point a(a1, a2), b(b1, b2), c(c1, c2);
    if(std::abs(cross(a, b)) <= eps || std::abs(cross(a, b)) <= eps)
        return {};
    return {(long double) cross(c, b) / cross(a, b), (long double) cross(a, c) / cross(a, b)};
}
std::pair<long double, long double> intersection(Point a, Point b, Point c, Point d){
    T a1, b1, c1, a2, b2, c2;
    getLine(a, b, a1, b1, c1);
    getLine(c, d, a2, b2, c2);
    return intersection(a1, b1, c1, a2, b2, c2);
}
