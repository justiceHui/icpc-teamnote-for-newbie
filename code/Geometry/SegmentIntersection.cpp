// 선분 교차 - 선분 ab와 선분 cd가 만나면 true
bool SegmentIntersection(Point a, Point b, Point c, Point d){
    int ab = CCW(a, b, c) * CCW(a, b, d);
    int cd = CCW(c, d, a) * CCW(c, d, b);
    if(ab == 0 && cd == 0){
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);
        return !(b < c || d < a);
    }
    return ab <= 0 && cd <= 0;
}