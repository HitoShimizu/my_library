#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxint = 1e9;
vector<int> shortest;
vector<vector<pair<int, int>>> connective;

void djkstra(int x) {
    vector<int> search = {x};
    vector<int> new_search;
    shortest[x] = 0;
    int v, d;
    while (!search.empty()) {
        for (auto i : search) {
            for (auto j : connective[i]) {
                v = j.first, d = j.second;
                if (shortest[v] > d + shortest[i]) {
                    shortest[v] = d + shortest[i];
                    new_search.emplace_back(v);
                }
            }
        }
        search.clear();
        search = new_search;
        new_search.clear();
    }
}

// 高速ダイクストラ
vector<ll> shortest;
vector<bool> used;
vector<vector<pair<int, int>>> connective;

void djkstra(int x) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
        search;
    shortest[x] = 0;
    search.push((pair<ll, int>){0, x});

    while (!search.empty()) {
        auto [dmin, i] = search.top();
        search.pop();
        if (used[i]) continue;
        used[i] = true;
        for (auto [v, d] : connective[i]) {
            if (!used[v] && shortest[v] > d + shortest[i]) {
                shortest[v] = d + shortest[i];
                search.push((pair<ll, int>){shortest[v], v});
            }
        }
    }
}

#define DEBUG

int main() {
#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt");  // for debug
    cin.rdbuf(in.rdbuf());     // for debug
#endif

    int n, v, k, x, c;
    cin >> n;
    connective.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v >> k;
        shortest.push_back(maxint);
        for (int j = 0; j < k; j++) {
            cin >> x >> c;
            connective[i].push_back(make_pair(x, c));
        }
    }
    djkstra(0);
    for (int i = 0; i < n; i++) {
        cout << i << " ";
        if (shortest[i] == maxint) {
            cout << "INF" << endl;
        } else {
            cout << shortest[i] << endl;
        }
    }

    return 0;
}

// getline(cin,s);
// a = strtok(s, ",");  ","で分解
// for (int i = 0; i < n; i++)
// for (int j = 0; j < m; j++)