ll PowMod(ll a, ll b, ll c){
    if(c == 1) return 0;
    ll res = 1;
    for(a%=c; b; b >>= 1, a = a * a % c) if(b & 1) res = res * a % c;
    return res;
}