#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<string> a(n);
    queue<pair<ll, ll>> q;

    for (ll i = 0; i < n; ++i) {
        cin >> a[i];

        for (ll j = 0; j < m; ++j) {
            if (a[i][j] != '.' && a[i][j] != '#') {
                q.push({i, j});
            }
        }
    }
    vector<ll> dx = {-1, 1, 0, 0};
    vector<ll> dy = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (ll i = 0; i < 4; ++i) {
            ll nx = x + dx[i];
            ll ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }
            if (a[nx][ny] != '.') {
                continue;
            }
            a[nx][ny] = a[x][y];
            q.push({nx, ny});
        }
    }

    for (ll i = 0; i < n; ++i) {
        cout << a[i] << '\n';
    }
}