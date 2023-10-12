struct Point{
    int x, y;
    // 방법 1: 연산자 오버로딩
    // x좌표 오름차순, x좌표 같으면 y좌표 오름차순
    // sort(시작 주소, 끝 주소)
    bool operator < (const Point &p) const {
        if(x != p.x) return x < p.x;
        else return y < p.y;
    }
};

// 방법 2: 비교 함수 구현
// sort(시작 주소, 끝 주소, Compare)
bool Compare(const Point &a, const Point &b){
    if(a.x != b.x) return a.x < b.x;
    else return a.y < b.y;
}

vector<Point> V;
V.push_back({1, 2});
V.push_back({1, 1});
V.push_back({2, 3});
sort(V.begin(), V.end()); // 방법 1
sort(V.begin(), V.end(), Compare); // 방법 2