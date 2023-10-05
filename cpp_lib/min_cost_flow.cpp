// #include <bits/stdc++.h>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>

using namespace std;
using ll = long long;
using VI = vector<int>;
using VL = vector<ll>;
using VD = vector<double>;
using VS = vector<string>;
using VB = vector<bool>;
using VVB = vector<vector<bool>>;
using VVI = vector<VI>;
using VVL = vector<VL>;
using VVD = vector<VD>;
using VVVI = vector<VVI>;
using VVVL = vector<VVL>;
using VVVD = vector<VVD>;
using PII = std::pair<int, int>;
using VPII = std::vector<std::pair<int, int>>;
using PLL = std::pair<ll, ll>;
using VPLL = std::vector<std::pair<ll, ll>>;
using TI3 = std::tuple<int, int, int>;
using TI4 = std::tuple<int, int, int, int>;
using TL3 = std::tuple<ll, ll, ll>;
using TL4 = std::tuple<ll, ll, ll, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define repr2(i, g, n) for (int i = (int)(n)-1; i >= (g); i--)
#define rep3(i, s, n, d) for (int i = (s); i < (int)(n); i += (d))
#define repr3(i, g, n, d) for (int i = (int)(n)-1; i >= (g); i -= (d))
#define allpt(v) (v).begin(), (v).end()
#define allpt_c(v) (v).cbegin(), (v).cend()
#define allpt_r(v) (v).rbegin(), (v).rend()
#define allpt_cr(v) (v).crbegin(), (v).crend()

const int mod1 = 1e9 + 7, mod2 = 998244353, mod3 = 1e9 + 9;
const int mod = mod2;
const ll inf = 1e18;
const int infint = 1e9;

const string wsp = " ";
const string tb = "\t";
const string rt = "\n";
const string alphabets = "abcdefghijklmnopqrstuvwxyz";
// std::random_device seed_gen;
// std::mt19937 engine(seed_gen());
// 乱数生成用メルセンヌ・ツイスタエンジン

template <typename T>
void show1dvec(const vector<T> &v) {
    if (v.size() == 0) return;
    int n = v.size() - 1;
    rep(i, n) cout << v[i] << wsp;
    cout << v[n] << rt;
    return;
}

int get1dcoodinate(int w, int i, int j) { return i * w + j; }

template <typename T, typename S>
istream &operator>>(istream &is, pair<T, S> &v) {
    is >> v.first >> v.second;
    return is;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    if (v.size() == 0) return os;
    int n = (int)v.size() - 1;
    rep(i, n) os << v[i] << wsp;
    os << v[n] << rt;
    return os;
}

template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
    if (v.size() == 0) return is;
    int n = v.size();
    rep(i, n) is >> v[i];
    return is;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v) {
    if (v.size() == 0) return os;
    int n = (int)v.size();
    rep(i, n) os << v[i];
    return os;
}

template <typename T>
istream &operator>>(istream &is, vector<vector<T>> &v) {
    if (v.size() == 0) return is;
    int n = v.size();
    rep(i, n) is >> v[i];
    return is;
}

template <typename T, typename S>
istream &operator>>(istream &is, vector<pair<T, S>> &v) {
    if (v.size() == 0) return is;
    int n = v.size();
    rep(i, n) is >> v[i].first >> v[i].second;
    return is;
}

template <typename T, typename S>
ostream &operator<<(ostream &os, const vector<pair<T, S>> &v) {
    if (v.size() == 0) return os;
    int n = v.size();
    rep(i, n) os << v[i].first << wsp << v[i].second << rt;
    return os;
}

void show2dvec(const vector<string> &v) {
    int n = (int)v.size();
    rep(i, n) cout << v[i] << rt;
}

template <typename T>
void show2dvec(const vector<vector<T>> &v) {
    int n = v.size();
    rep(i, n) show1dvec(v[i]);
}

template <typename T>
void range_sort(vector<T> &arr, int l, int r) {
    sort(arr.begin() + l, arr.begin() + r);
}

template <typename T, typename S>
void show1dpair(const vector<pair<T, S>> &v) {
    int n = v.size();
    rep(i, n) cout << v[i].first << v[i].second << rt;
    return;
}

template <typename T, typename S>
void pairzip(const vector<pair<T, S>> &v, vector<T> &t, vector<T> &s) {
    int n = v.size();
    rep(i, n) {
        t.push_back(v[i].first);
        s.push_back(v[i].second);
    }
    return;
}

template <typename T>
void maxvec(vector<T> &v) {
    T s = v[0];
    int n = v.size();
    rep(i, n - 1) {
        if (s > v[i + 1]) {
            v[i + 1] = s;
        }
        s = v[i + 1];
    }
}

template <typename T, typename S>
bool myfind(T t, S s) {
    return find(t.cbegin(), t.cend(), s) != t.cend();
}

bool check(int y, int x, int h, int w) {
    return 0 <= y && y < h && 0 <= x && x < w;
}

bool check(int y, int x, int h1, int h2, int w1, int w2) {
    return h1 <= y && y < h2 && w1 <= x && x < w2;
}

bool iskadomatsu(int a, int b, int c) {
    return (a != b && b != c && c != a) &&
           ((a > b && b < c) || (a < b && b > c));
}

template <typename T>
bool iskadomatsu(vector<T> v) {
    T a = v[0], b = v[1], c = v[2];
    return (a != b && b != c && c != a) &&
           ((a > b && b < c) || (a < b && b > c));
}

double euc_dist(PII a, PII b) {
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

// VS split(string s, char c) {
//     VS ret;
//     string part;
//     s += c;
//     rep(i, s.length()) {
//         if (s[i] == c) {
//             if (part != "") ret.emplace_back(part);
//             part = "";
//         } else if (s[i] != c) {
//             part += s[i];
//         }
//     }
//     return ret;
// }

VS split(string s, char c, char d = ' ') {
    VS ret;
    // reverse(allpt(s));
    string part;
    s += c;
    rep(i, s.length()) {
        if (s[i] == c) {
            if (part != "") {
                // string t;
                // t += c;
                // ret.emplace_back(t);
                ret.emplace_back(part);
            }
            part = "";
        } else {
            part += s[i];
        }
    }
    return ret;
}

template <typename T, typename S, typename R>
ll pow_mod(T p, S q, R _mod = 1ll) {
    ll ret = 1, r = p;
    while (q) {
        if (q % 2) ret *= r, ret %= _mod;
        r = (r * r) % _mod, q /= 2;
    }
    return ret % _mod;
}

template <typename T, typename S>
ll pow_no_mod(T p, S q) {
    ll ret = 1, r = p;
    while (q) {
        if (q % 2) ret *= r;
        r = (r * r), q /= 2;
    }
    return ret;
}

void make_frac_tables(VL &frac_list, VL &frac_inv_list) {
    rep(i, frac_list.size() - 1) {
        frac_list[i + 1] *= frac_list[i] * (i + 1);
        frac_list[i + 1] %= mod;
        frac_inv_list[i + 1] *= frac_inv_list[i] * pow_mod(i + 1, mod - 2, mod);
        frac_inv_list[i + 1] %= mod;
    }
}

pair<VL, VL> make_frac_tables(int n) {
    VL frac_list(n + 1, 1), frac_inv_list(n + 1, 1);
    rep(i, n) {
        frac_list[i + 1] *= frac_list[i] * (i + 1);
        frac_list[i + 1] %= mod;
        frac_inv_list[i + 1] *= frac_inv_list[i] * pow_mod(i + 1, mod - 2, mod);
        frac_inv_list[i + 1] %= mod;
    }
    return make_pair(frac_list, frac_inv_list);
}

ll perm(int a, int b, const VL &frac_list, const VL &frac_inv_list) {
    if (a < b) return 0;
    if (b < 0) return 0;
    ll ret = frac_list[a];
    ret *= frac_inv_list[a - b];
    ret %= mod;
    return ret;
}

ll comb(int a, int b, const VL &frac_list, const VL &frac_inv_list) {
    if (a < b) return 0;
    if (b < 0) return 0;
    ll ret = frac_list[a];
    ret *= frac_inv_list[b];
    ret %= mod;
    ret *= frac_inv_list[a - b];
    ret %= mod;
    return ret;
}

struct vec2d {
    ll x;
    ll y;
    vec2d(ll _x, ll _y) {
        x = _x;
        y = _y;
    }
    ll dot(vec2d p) { return x * p.x + y * p.y; }
    vec2d diff(vec2d p) { return vec2d(x - p.x, y - p.y); }
};

struct node {
    int parent = -1;
    ll weight = 0;
    int depth = 0;
    int degree = 0;
    int subtree = 1;
    int check = 0;
    int scc = -1;
    int use_leaf;
    priority_queue<int> coins;
    VPLL children;
    VI parent_list;
    VPLL connect;

    node() {
        parent = -1;
        weight = 0;
        depth = 0;
        degree = 0;
        subtree = 1;
        check = 0;
        children;
        parent_list;
        connect;
    }
};

struct graph {
    int _n;
    int root = 0;
    vector<node> nodes;
    graph(int n) {
        _n = n;
        rep(i, _n) nodes.emplace_back(node());
    }
    void getconnect_nocost() {
        ll a, b;
        cin >> a >> b;
        nodes[a].connect.emplace_back(b, 1);
        nodes[b].connect.emplace_back(a, 1);
    }
    void getconnect_cost() {
        ll a, b, c;
        cin >> a >> b >> c;
        nodes[a].connect.emplace_back(b, c);
        nodes[b].connect.emplace_back(a, c);
    }
    void getconnect_increment_nocost() {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        nodes[a].connect.emplace_back(b, 1);
        nodes[b].connect.emplace_back(a, 1);
    }
    void getconnect_increment_cost() {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        nodes[a].connect.emplace_back(b, c);
        nodes[b].connect.emplace_back(a, c);
    }
    void showparent() {
        rep(i, _n - 1) cout << nodes[i].parent << wsp;
        cout << nodes[_n - 1].parent << rt;
    }
    void showweight() {
        rep(i, _n - 1) cout << nodes[i].weight << wsp;
        cout << nodes[_n - 1].weight << rt;
    }
    void showsubtree() {
        rep(i, _n - 1) cout << nodes[i].subtree << wsp;
        cout << nodes[_n - 1].subtree << rt;
    }
    void showdepth() {
        rep(i, _n - 1) cout << nodes[i].depth << wsp;
        cout << nodes[_n - 1].depth << rt;
    }
};

class min_cost_flow {
    struct edge {
        size_t to, rev;
        ll cost, cap;
    };
    int n;
    vector<ll> potencial, shortest;
    vector<size_t> preview_node, preview_edge;
    vector<vector<edge>> connect;

    void djcstra(size_t s, size_t t) {
        fill(allpt(shortest), inf);
        shortest[s] = 0;
        priority_queue<pair<ll, size_t>, vector<pair<ll, size_t>>,
                       greater<pair<ll, size_t>>>
            pq;
        pq.push(make_pair(0, s));
        while (!pq.empty()) {
            auto [t, u] = pq.top();
            pq.pop();
            if (shortest[u] != t) continue;
            rep(i, connect[u].size()) {
                edge &e = connect[u][i];
                if (e.cap > 0 && shortest[e.to] > t + e.cost + potencial[u] -
                                                      potencial[e.to]) {
                    shortest[e.to] =
                        t + e.cost + potencial[u] - potencial[e.to];
                    preview_node[e.to] = u;
                    preview_edge[e.to] = i;
                    pq.push(make_pair(shortest[e.to], e.to));
                }
            }
        }
    }

   public:
    min_cost_flow(int n) {
        this->n = n;
        potencial.resize(n);
        shortest.resize(n);
        preview_node.resize(n);
        preview_edge.resize(n);
        connect.resize(n);
    }
    void add_edge(size_t from, size_t to, ll cost, ll cap) {
        connect[from].emplace_back((edge){to, connect[to].size(), cost, cap});
        connect[to].emplace_back(
            (edge){from, connect[from].size() - 1, -cost, 0});
    }
    int get_min_cost_flow(size_t s, size_t t, ll f) {
        ll ret{0}, d;
        fill(allpt(potencial), 0);
        while (f > 0) {
            while (f > 0) {
                djcstra(s, t);
                if (shortest[t] == inf) return -1;
                rep(i, n) potencial[i] += shortest[i];
                d = f;
                for (auto v = t; v != s; v = preview_node[v]) {
                    d = min(d, connect[preview_node[v]][preview_edge[v]].cap);
                }
                f -= d;
                ret += d * potencial[t];
                for (auto v = t; v != s; v = preview_node[v]) {
                    auto &e = connect[preview_node[v]][preview_edge[v]];
                    e.cap -= d;
                    connect[v][e.rev].cap += d;
                }
            }
        }
        return ret;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // リアクティブ問題のときはコメントアウト

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    // ifstream in("input.txt");                             // for debug
    // cin.rdbuf(in.rdbuf());                                // for debug
    chrono::system_clock::time_point timestart, timeend;  // for debug
    timestart = std::chrono::system_clock::now();         // for debug

#endif

    int n, m, f, a, b, c, d;
    cin >> n >> m >> f;
    min_cost_flow minflow(n);
    rep(_, m) {
        cin >> a >> b >> d >> c;
        minflow.add_edge(a, b, c, d);
    }
    cout << minflow.get_min_cost_flow(0, n - 1, f) << rt;

#ifdef DEBUG
    timeend = chrono::system_clock::now();
    auto elapsed =
        chrono::duration_cast<chrono::milliseconds>(timeend - timestart)
            .count();
    cout << "Time is " << elapsed << "ms" << std::endl;
#endif

    return 0;
}
