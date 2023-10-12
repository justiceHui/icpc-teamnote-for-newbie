int N, M, C[1010];
vector<int> G[1010];
void AddEdge(int s, int e){ G[s].push_back(e); }
void DFS(int v){
    cout << v << " ";
    C[v] = 1;
    for(auto i : G[v]) if(!C[i]) DFS(i);
}
void BFS(int s){
    queue<int> Q;
    Q.push(s); C[s] = 1;
    while(!Q.empty()){
        int v = Q.front(); Q.pop();
        cout << v << " ";
        for(auto i : G[v]) if(!C[i]) Q.push(i), C[i] = 1;
    }
}