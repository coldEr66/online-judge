struct KM{ // 0-base
    int w[MAXn][MAXn],hl[MAXn],hr[MAXn],slk[MAXn]; // ll
    int fl[MAXn],fr[MAXn],pre[MAXn],q[MAXn],ql,qr,n;
    bool vl[MAXn],vr[MAXn];
    void init(int _n){
        n = _n;
        for (int i=0;i<n;++i) for (int j=0;j<n;++j) w[i][j] = -INF;
    }
    void add_edge(int a,int b,int wei) { // ll
        w[a][b] = wei;
    }
    bool chk(int x){
        if (vl[x] = 1, ~fl[x]) return vr[q[qr++] = fl[x]] = 1;
        while (~x) swap(x, fr[fl[x] = pre[x]]);
        return 0;
    }
    void bfs(int s){
        fill(slk,slk+n,INF);
        fill(vl,vl+n,0), fill(vr,vr+n,0);
        ql=qr=0, q[qr++] = s, vr[s] = 1;
        while (true) {
            int d; // ll
            while (ql < qr) {
                for (int x=0,y=q[ql++];x<n;++x) {
                    if (!vl[x] && slk[x] >= (d = hl[x] + hr[y] - w[x][y])) {
                        if (pre[x] = y, d) slk[x] = d;
                        else if (!chk(x)) return;
                    }
                }
            }
            d = INF;
            for (int x=0;x<n;++x) {
                if (!vl[x] && d > slk[x]) d = slk[x];
            }
            for (int x=0;x<n;++x) {
                if (vl[x]) hl[x] += d;
                else slk[x] -= d;
                if (vr[x]) hr[x] -= d;
            }
            for (int x=0;x<n;++x) {
                if (!vl[x] && !slk[x] && !chk(x)) return;
            }
        }
    }
    int solve(){ // ll
        fill(fl,fl+n,-1), fill(fr,fr+n,-1), fill(hr,hr+n,0);
        for (int x=0;x<n;++x) hl[x] = *max_element(w[x],w[x] + n);
        for (int x=0;x<n;++x) bfs(x);
        int ret = 0; // ll
        for (int x=0;x<n;++x) ret += w[x][fl[x]];
        return ret;
    }
}; 

