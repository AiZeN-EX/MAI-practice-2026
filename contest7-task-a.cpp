#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll INF = (ll)4e18;

struct Edge {
    ll u, v, w;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, s;
    cin >> n >> m >> s;
    vector<Edge> edges(m);

    for (ll i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    vector<ll> dist(n + 1, INF);
    dist[s] = 0;

    for (ll i = 1; i < n; i++) {
        for (Edge edge : edges) {
            if (dist[edge.u] == INF) {
                continue;
            }

            dist[edge.v] = min(dist[edge.v], dist[edge.u] + edge.w);
        }
    }
    for (Edge edge : edges) {
        if (dist[edge.u] == INF) {
            continue;
        }
        if (dist[edge.v] > dist[edge.u] + edge.w) {
            cout << "Negative cycle";
            return 0;
        }
    }
    for (ll i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            cout << "inf ";
        } else {
            cout << dist[i] << ' ';
        }
    }
}
