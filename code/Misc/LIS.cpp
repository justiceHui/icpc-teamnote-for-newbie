// LIS({10, 20, 10, 30, 20, 50}) = {10, 20, 30, 50}
vector<int> LIS(const vector<int> &v){
  int n = v.size();
  vector<int> pos(n), lis, res;
  for(int i=0; i<n; i++){
    if(lis.empty() || lis.back() < v[i]){
      lis.push_back(v[i]); pos[i] = lis.size();
    }
    else{
      int idx = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
      lis[idx] = v[i]; pos[i] = idx + 1;
    }
  }
  int len = lis.size();
  for(int i=n-1; i>=0; i--) if(pos[i] == len) res.push_back(v[i]), len--;
  reverse(res.begin(), res.end());
  return res;
}