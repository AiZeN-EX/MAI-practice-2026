#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    priority_queue<ll> l;
    priority_queue<ll, vector<ll>, greater<ll>> r;

    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;

        if (l.empty() || x <= l.top()) {
            l.push(x);
        } else {
            r.push(x);
        }
        if (l.size() < r.size()) {
            l.push(r.top());
            r.pop();
        }
        if (l.size() > r.size() + 1) {
            r.push(l.top());
            l.pop();
        }

        cout << l.top() << '\n';
    }
}