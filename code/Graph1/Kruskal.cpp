int N, M, P[10101];
int Find(int v){ return v == P[v] ? v : P[v] = Find(P[v]); }
bool Merge(int u, int v){
    u = Find(u); v = Find(v);
    if(u == v) return false;
    P[u] = v; return true;
}
int main(){
    cin >> N >> M;
    vector<tuple<int,int,int>> E; // {weight, from, to}
    for(int i=1,u,v,w; i<=M; i++){
        cin >> u >> v >> w;
        E.emplace_back(w, u, v);
    }
    sort(E.begin(), E.end());
    for(int i=1; i<=N; i++) P[i] = i;
    long long res = 0;
    for(auto [w,u,v] : E) if(Merge(u, v)) res += w;
    cout << res;
}