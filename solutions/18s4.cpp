#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[10000001] {0, 1, 1, 2};
unordered_map<int, ll> dp2;

ll trees(int n) {
    if (n < 10000001 && dp[n]) return dp[n];
    if (dp2[n]) return dp2[n];
    ll ret = 0;

    for (int i = 2; i <= n; ) {
        int step = n / (n / i) - i + 1;
//        while(n / i == n / (i + step)) step++;

        ret += trees(n / i) * step;
        i += step;
    }

    if (n < 10000001) dp[n] = ret;
    else dp2[n] = ret;

    return ret;

}

int main() {
    int n;
    cin >> n;

    cout << trees(n) << endl;
}