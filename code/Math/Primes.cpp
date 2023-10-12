// IsPrime(2) = true, IsPrime(4) = false
// Factorize(72) = { {2, 3}, {3, 2} }
bool IsPrime(ll n){
    if(n < 2) return false;
    for(ll i=2; i*i<=n; i++) if(n % i == 0) return false;
    return true;
}
vector<pair<ll,ll>> Factorize(ll n){
    if(n == 1) return {};
    vector<pair<ll,ll>> res;
    for(ll i=2; i*i<=n; i++){
        if(n % i != 0) continue;
        int cnt = 0;
        while(n % i == 0) n /= i, cnt++;
        res.emplace_back(i, cnt);
    }
    if(n != 1) res.emplace_back(n, 1);
    return res;
}