#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> cnt(8);

    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        cnt[x]++;
    }

    if (cnt[5] > 0 || cnt[7] > 0) {
        cout << -1;
        return 0;
    }

    ll a = cnt[4]; 
    cnt[1] -= a;
    cnt[2] -= a;

    ll b = cnt[3]; 
    cnt[1] -= b;
    cnt[6] -= b;

    if (cnt[1] < 0 || cnt[2] < 0 || cnt[6] < 0) {
        cout << -1;
        return 0;
    }

    ll c = cnt[1]; 

    if (cnt[2] != c || cnt[6] != c) {
        cout << -1;
        return 0;
    }

    for (ll i = 0; i < a; ++i) {
        cout << "1 2 4\n";
    }
    for (ll i = 0; i < b; ++i) {
        cout << "1 3 6\n";
    }
    for (ll i = 0; i < c; ++i) {
        cout << "1 2 6\n";
    }
}