// n: 왼쪽 정점 개수, m: 오른쪽 정점 개수, 0-based
struct HopcroftKarp{
  int n, m;
  vector<vector<int>> g;
  vector<int> dst, le, ri;
  vector<char> visit, track;
  HopcroftKarp(int n, int m) : n(n), m(m) { clear(); }
  void clear(){
    g = vector<vector<int>>(n); dst = vector<int>(n, 0);
    le = vector<int>(n, -1); ri = vector<int>(m, -1);
    visit = vector<char>(n, 0); track = vector<char>(n+m, 0);
  }
  void add_edge(int s, int e){ g[s].push_back(e); }
  bool bfs(){
    bool res = false;
    queue<int> que;
    fill(dst.begin(), dst.end(), 0);
    for(int i=0; i<n; i++) if(le[i] == -1) que.push(i), dst[i] = 1;
    while(!que.empty()){
      int v = que.front(); que.pop();
      for(auto i : g[v]){
        if(ri[i] == -1) res = true;
        else if(!dst[ri[i]]) dst[ri[i]] = dst[v] + 1, que.push(ri[i]);
      }
    }
    return res;
  }
  bool dfs(int v){
    if(visit[v]) return false;
    visit[v] = 1;
    for(auto i : g[v]){
      if(ri[i] == -1 || !visit[ri[i]] && dst[ri[i]] == dst[v] + 1 && dfs(ri[i])){
        le[v] = i; ri[i] = v; return true;
      }
    }
    return false;
  }
  int maximum_matching(){
    int res = 0;
    fill(le.begin(), le.end(), -1);
    fill(ri.begin(), ri.end(), -1);
    while(bfs()){
      fill(visit.begin(), visit.end(), 0);
      for(int i=0; i<n; i++) if(le[i] == -1) res += dfs(i);
    }
    return res;
  }
  vector<pair<int,int>> maximum_matching_edges(){
    int matching = maximum_matching();
    vector<pair<int,int>> edges; edges.reserve(matching);
    for(int i=0; i<n; i++) if(le[i] != -1) edges.emplace_back(i, le[i]);
    return edges;
  }
  void dfs_track(int v){
    if(track[v]) return; track[v] = 1;
    for(auto i : g[v]) track[n+i] = 1, dfs_track(ri[i]);
  }
  tuple<vector<int>, vector<int>, int> minimum_vertex_cover(){
    int matching = maximum_matching();
    fill(track.begin(), track.end(), 0);
    for(int i=0; i<n; i++) if(le[i] == -1) dfs_track(i);
    vector<int> lv, rv;
    for(int i=0; i<n; i++) if(!track[i]) lv.push_back(i);
    for(int i=0; i<m; i++) if(track[n+i]) rv.push_back(i);
    assert(lv.size() + rv.size() == matching);
    return {lv, rv, lv.size() + rv.size()};
  }
};