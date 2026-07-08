#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
 
    while (t--) {
        ll n;
        cin >> n;
        unordered_map<ll, ll> last;
        ll l = 0;
        ll ans = 0;
 
        for (ll r = 0; r < n; ++r) {
            ll x;
            cin >> x;
 
            if (last.count(x) && last[x] >= l) {
                l = last[x] + 1;
            }
 
            last[x] = r;
            ans = max(ans, r - l + 1);
        }
        cout << ans << '\n';
    }
}