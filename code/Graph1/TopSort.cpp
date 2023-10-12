int N, M, In[1010];
vector<int> G[1010];
void AddEdge(int s, int e){ G[s].push_back(e); In[e]++; }
void TopSort(){
    queue<int> Q;
    for(int i=1; i<=N; i++) if(!In[i]) Q.push(i);
    while(!Q.empty()){
        int v = Q.front(); Q.pop();
        cout << v << " ";
        for(auto i : G[v]) if(!--In[i]) Q.push(i);
    }
}