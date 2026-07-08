#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    vector<vector<ll>> dp(n, vector<ll>(m));
    dp[0][0] = a[0][0];
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if (i > 0 && j > 0) {
            dp[i][j] = a[i][j] + max({dp[i - 1][j], dp[i][j - 1], dp[i- 1][j - 1]});
            } else if (i == 0 && j == 0) {
                continue;
            } else if (i == 0) {
                dp[i][j] = a[i][j] + dp[i][j - 1];
            } else if (j == 0) {
                dp[i][j] = a[i][j] + dp[i - 1][j];
            }
        }
    }   
    cout << dp[n - 1][m - 1];
}
