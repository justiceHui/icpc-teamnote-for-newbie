// Directed Graph이면 add_edge(s, e, c)
// Undirected Graph이면 add_edge(s, e, c, c)
template<typename flow_t, flow_t MAX_U=(1<<30)>
struct Dinic{ // 0-based
  struct edge_t{ int v, r; flow_t c, f; };
  int n;
  vector<vector<edge_t>> g;
  vector<int> lv, idx;
  Dinic(int n) : n(n) { clear(); }
  void clear(){
    g = vector<vector<edge_t>>(n);
    lv = vector<int>(n, 0);
    idx = vector<int>(n, 0);
  }
  void add_edge(int s, int e, flow_t c1, flow_t c2=flow_t(0)){
    g[s].push_back({e, (int)g[e].size(), c1, 0});
    g[e].push_back({s, (int)g[s].size()-1, c2, 0});
  }
  bool bfs(int s, int t, flow_t limit=1){
    fill(lv.begin(), lv.end(), 0);
    queue<int> que; que.push(s); lv[s] = 1;
    while(!que.empty()){
      int v = que.front(); que.pop();
      for(const auto &e : g[v]) if(!lv[e.v] && e.c - e.f >= limit) que.push(e.v), lv[e.v] = lv[v] + 1;
    }
    return lv[t] != 0;
  }
  flow_t dfs(int v, int t, flow_t fl=MAX_U){
    if(v == t || fl == flow_t(0)) return fl;
    for(int &i=idx[v]; i<g[v].size(); i++){
      auto &e = g[v][i];
      if(lv[e.v] != lv[v] + 1 || e.c - e.f == flow_t(0)) continue;
      flow_t now = dfs(e.v, t, min(fl, e.c - e.f));
      if(now == flow_t(0)) continue;
      e.f += now; g[e.v][e.r].f -= now;
      return now;
    }
    return 0;
  }
  flow_t maximum_flow(int s, int t){
    flow_t flow = 0, augment = 0;
    while(bfs(s, t)){
      fill(idx.begin(), idx.end(), 0);
      while((augment=dfs(s, t)) != flow_t(0)) flow += augment;
    }
    return flow;
  }
  // {최소 컷 비용, s와 같은 집합, t와 같은 집합, 절단 간선}
  tuple<flow_t, vector<int>, vector<int>, vector<pair<int,int>>> minimum_cut(int s, int t){
    flow_t flow = maximum_flow(s, t);
    vector<int> a, b;
    vector<pair<int,int>> edges;
    bfs(s, t, 1);
    for(int i=0; i<n; i++) (lv[i] ? a : b).push_back(i);
    for(auto i : a) for(auto e : g[i]) if(e.c != flow_t(0) && !lv[e.v]) edges.emplace_back(i, e.v);
    return {flow, a, b, edges};
  }
};