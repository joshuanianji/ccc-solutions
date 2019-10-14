#include <bits/stdc++.h>

typedef unsigned long long ull;
using namespace std;

ull arr[3001][3001] = {0};
ull fen[3001][3001] = {0};

inline int lsb(int i) {
    return i&-i;
}

int n, k;
void setv(int x, int y, ull v) {
    for (;x <= n; x += lsb(x)) {
        for (int yy = y; yy <= n; yy += lsb(yy)) {
            fen[x][yy] = max(fen[x][yy], v);
        }
    }
}


int getv(int x, int y) {
    int xx = x;

    ull ret = 0;
    for (; x >= 1; x -= lsb(x)) {
        for (int yy = y; yy >= 1; yy -= lsb(yy)) {
            ret = max(ret, fen[x][yy]);
        }
    }
    //printf("%d %d [%d] -> %d\n", xx, y, arr[xx][y], ret);

    return ret;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = n - i + 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    ull res = 0;
    for (int diag = n; diag >= 1; diag--) {
        for(int step = 0; step <= n - diag; step++) {
            setv(diag + step, n - step, arr[diag + step][n - step]);

            //cout << diag << endl;

            if (step >= k - 1) {
                res += getv(diag + step, n - step + k - 1);
            }
        }
    }

    cout << res << endl;
}
