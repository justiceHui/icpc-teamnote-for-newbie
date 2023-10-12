// 주의: 구간 범위에 음수가 들어가면 / 2 말고 >> 1로 해야 함

// 1 1 1 ... 1 1 0 0 ... 0 꼴일 때 마지막 1의 위치
int l = 1, r = n;
while(l < r){
    int m = (l + r + 1) / 2;
    if(Check(m)) l = m;
    else r = m - 1;
}

// 0 0 0 ... 0 0 1 1 ... 1 꼴일 때 첫 번째 1의 위치
int l = 1, r = n;
while(l < r){
    int m = (l + r) / 2;
    if(Check(m)) r = m;
    else l = m + 1;
}