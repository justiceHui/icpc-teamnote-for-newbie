int SP[5050505]; // SP[i] = i의 가장 작은 소인수
vector<int> Primes;

// n 이하의 모든 소수를 구함
void Sieve(int n){
  for(int i=2; i<=n; i++){
    if(SP[i]) continue;
    for(int j=i; j<=n; j+=i) if(!SP[j]) SP[j] = i;
  }
}

// Sieve 먼저 호출해야 함
vector<pair<int,int>> Factorize(int n){
  vector<pair<int,int>> res;
  while(n != 1){
    if(res.empty() || res.back().first != SP[n]) res.emplace_back(SP[n], 1);
    else res.back().second++;
    n /= SP[n];
  }
  return res;
}