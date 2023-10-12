// 원소의 대소관계를 유지하면서 [0, N) 범위의 수로 압축함
// ex. {50, 31, 24, 10, 46, 10} -> {4, 2, 1, 0, 3, 0}
int N = 6, A[6] = {50, 31, 24, 10, 46, 10};
vector<int> C;
for(int i=0; i<N; i++) C.push_back(A[i]);
sort(C.begin(), C.end());
C.erase(unique(C.begin(), C.end()), C.end());
for(int i=0; i<N; i++){
    A[i] = lower_bound(C.begin(), C.end(), A[i]) - C.begin();
}
for(int i=0; i<N; i++) cout << A[i] << " "; // 4 2 1 0 3 0