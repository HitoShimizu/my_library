#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define DEBUG

const int INTMAX = 2 * 1e9 + 10;
const int NMAX = 2 * 1e3;

bool check[NMAX];

template <typename T>
int dfs(int s, int t, T f, vector<pair<T, T>> edge[], vector<T> &used) {
    int d = 0;
    check[s] = true;
    if (s == t) {
        used.push_back(t);
        return f;
    }

    for (auto next : edge[s]) {
        if (!check[next.first] && next.second > 0)
            d = dfs(next.first, t, min(next.second, f), edge, used);
        if (d > 0) {
            used.push_back(s);
            return d;
        }
        // DFSが終点まで行くと正の値dが帰ってくるので、辺の容量の調整をして終了
    }
    return 0;  //そうでなければ何もしない
}

int main() {
#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt");  // for debug
    cin.rdbuf(in.rdbuf());     // for debug
#endif

    int n, m, s, t, c, a, b, f, ans;
    cin >> n >> m;

    vector<pair<int, int>> edge[n];
    vector<int> used;

    f = 1, ans = 0;
    for (int i = 0; i < m; i++) {
        cin >> s >> t >> c;
        edge[s].push_back(make_pair(t, c));
        edge[t].push_back(make_pair(s, 0));
    }
    while (f > 0) {
        for (int i = 0; i < n; i++) check[i] = false;

        f = dfs(0, n - 1, INTMAX, edge, used);
        a = -1, b = -1;
        for (auto i : used) {
            a = b;
            b = i;

            if (a >= 0 && b >= 0) {
                for (auto &j : edge[a])  //値の変更を伴うので参照
                    if (j.first == b) {
                        j.second += f;
                        break;
                    }
                for (auto &j : edge[b])
                    if (j.first == a) {
                        j.second -= f;
                        break;
                    }
            }
        }
        ans += f;
        used.clear();
    }
    cout << ans << endl;

    return 0;
}

// getline(cin,s);
// a = strtok(s, ",");  ","で分解
// for (int i = 0; i < n; i++)