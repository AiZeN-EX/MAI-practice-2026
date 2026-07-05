#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    size_t n;
    cin >> n;
    vector<ll> dt, min, max;
    ll mi, ma;
    if (n == 1) {
        ll x;
        cin >> x;
        cout << "1 1\n1 1\n1 1\n"; 
    } else {
        for (ll i = 0; i < n; ++i) {
            ll x;
            cin >> x;
            dt.push_back(x);
        }
        for (ll i = 0; i < n - 1; ++i) {
            if (i == 0) {
                if (dt[i] < dt[i + 1]) {
                    min.push_back(i + 1);
                } else {
                    max.push_back(i + 1);
                } 
                } else {
                if (dt[i] < dt[i + 1] && dt[i] < dt[i - 1]) {
                    min.push_back(i + 1);
                } else if ((dt[i] > dt[i + 1] && dt[i] > dt[i - 1])) {
                    max.push_back(i + 1);
                }
                }
            }
            if (dt[dt.size() - 1] < dt[dt.size() - 2]) {
                min.push_back(dt.size());
            } else {
                max.push_back(dt.size());
            }

        cout << min.size() << ' ';
        mi = min[0];
        for (ll i = 0; i < min.size(); ++i) {
            if (dt[min[i] - 1] < dt[mi - 1]) {
                mi = min[i];
            }
            cout << min[i] << ' ';
        }
        cout << '\n';
        cout << max.size() << ' ';
        ma = max[0];
        for (ll i = 0; i < max.size(); ++i) {
            if (dt[max[i] - 1] > dt[ma - 1]) {
                ma = max[i];
            }
            cout << max[i] << ' ';
        }
        cout << '\n';
        cout << mi << " " << ma << '\n';
    }
} 