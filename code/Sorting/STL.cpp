vector<int> v = {3, 5, 7, 7, 7, 10};

// lower_bound: x 이상인 가장 빠른 위치
// 배열은 정렬되어 있어야 함, O(log N)
for(int i=3; i<=8; i++){
    cout << lower_bound(v.begin(), v.end(), i) - v.begin() << " ";
} // 0 1 1 2 2 5
cout << "\n";

// upper_bound: x 초과인 가장 빠른 위치
// 배열은 정렬되어 있어야 함, O(log N)
for(int i=3; i<=8; i++){
    cout << upper_bound(v.begin(), v.end(), i) - v.begin() << " ";
} // 1 1 2 2 5 5
cout << "\n";

// binary_search: x가 있으면 true, 없으면 false
// 배열은 정렬되어 있어야 함, O(log N)
for(int i=3; i<=8; i++){
    cout << binary_search(v.begin(), v.end(), i) << " ";
} // 1 0 1 0 1 0
cout << "\n";

vector<int> a = {1, 3, 5, 2, 4, 6};

// nth_element(a.begin(), a.begin()+k, a.end())
// 정렬했을 때 a[k]에 와야 하는 수가 a[k]에 옴
// a[k] 미만의 수는 모두 a[0..k-1]으로 이동
// a[k] 초과의 수는 모두 a[k+1..]으로 이동
// 평균 시간 복잡도 O(N), 최악 시간 복잡도 O(N log N)
nth_element(a.begin(), a.begin()+3, a.end());
for(auto i : a) cout << i << " "; // a b c 4 d e
// a b c <= 4, d e >= 4