ll D[505050], P[505050];
vector<pair<ll,ll>> G[505050]; // {정점, 가중치}
// 주의: 가중치 >= 0, 음수 있으면 bellman ford 사용

// s -> t 최단 경로 출력
void Dijkstra(int s, int t){
    memset(D, 0x3f, sizeof D);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>> Q;
    Q.emplace(D[s]=0, s);
    while(!Q.empty()){
        auto [c,v] = Q.top(); Q.pop();
        if(c == D[v]) for(auto [i,w] : G[v]) if(D[i] > c + w) Q.emplace(D[i]=c+w, i), P[i] = v;
    }
    vector<int> path;
    for(int i=t; i!=s; i=P[i]) path.push_back(i);
    path.push_back(s);
    reverse(path.begin(), path.end());
    for(auto i : path) cout << i << " ";
}