#include <bits/stdc++.h>
// #include <set>
// #include <map>
// #include <cmath>
// #include <deque>
// #include <vector>
// #include <iostream>
// #include <algorithm>

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

template <typename T>
void show1dvec(const vector<T> &v) {
    if (v.size() == 0) return;
    int n = v.size() - 1;
    rep(i, n) cout << v[i] << wsp;
    cout << v[n] << rt;
    return;
}

int get1dcoodinate(int w, int i, int j) { return i * w + j; }

template <typename T>
void operator++(vector<T> &v) {
    for (auto &x : v) ++x;
}

template <typename T>
void operator--(vector<T> &v) {
    for (auto &x : v) --x;
}

template <typename T, typename S>
void operator++(pair<T, S> &v) {
    ++v.first, ++v.second;
}

template <typename T, typename S>
void operator--(pair<T, S> &v) {
    --v.first, --v.second;
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

template <typename T>
void range_sort(vector<T> &arr, int l, int r) {
    sort(arr.begin() + l, arr.begin() + r);
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

template <typename T>
T mex(vector<T> v) {
    sort(allpt(v));
    v.erase(unique(v.begin(), v.end()), v.end());
    int ret = 0;
    for (auto x : v) {
        if (ret < x) return ret;
        ret++;
    }
    return ret;
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
    ll ret = 1, r = p % _mod;
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

struct node {
    int parent = -1;
    ll weight = 0;
    int depth = 0;
    int degree = -1;
    int subtree = 1;
    int check = 0;
    int scc = -1;
    VPLL children;
    VI parent_list;
    VPLL connect;

    node() {
        parent = -1;
        weight = 0;
        depth = 0;
        degree = -1;
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


template <typename T>
void coordinate_compress(vector<T> &x, map<T, int> &zip, int &xs) {
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    xs = x.size();
    for (int i = 0; i < xs; i++) {
        zip[x[i]] = i;
    }
}

template <typename T>
pair<map<T, int>, int> coordinate_compress(vector<T> &x) {
    map<T, int> zip;
    int xs;
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    xs = x.size();
    for (int i = 0; i < xs; i++) {
        zip[x[i]] = i;
    }
    return make_pair(zip, xs);
}



class Unionfind {
    vector<int> p;
    vector<int> w;

   public:
    Unionfind(int n) {
        for (int i = 0; i < n; i++) {
            p.emplace_back(i);
            w.emplace_back(0);
        }
    }
    int find(int x) {
        while (p[x] != x) {
            p[x] = p[p[x]];
            x = p[x];
        }
        return x;
    }
    int getval(int x) { return p[x]; }
    int getweight(int x) { return w[find(x)]; }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            p[x] = min(x, y);
            p[y] = min(x, y);
            // w[min(x, y)] += w[max(x, y)];
            // w[max(x, y)] = 0;
        }
    }

    bool isunion(int x, int y) { return find(x) == find(y); }
    void showtree() { cout << p << w; }
};

template <typename T>
class RangeMinorMaxorSumQuery  // 0-index
{
    int const intmax = 2147483647;
    int const intmin = 0;
    vector<T> sgt;
    int n;
    int k;

   public:
    RangeMinorMaxorSumQuery(int n1, T f = -1) {
        if (f == -1)
            f = intmax;
        else if (f == 0)
            f = intmin;
        int na = 1;
        int ka = 0;
        while (na < n1) {
            na *= 2;
            ka++;
        }
        for (int i = 0; i < 2 * na; i++) sgt.push_back(f);
        n = na;
        k = ka;
    }

    void update_min(int i, int x) {
        i += n;
        sgt[i] = x;
        while (i > 1) {
            i /= 2;
            sgt[i] = min(sgt[2 * i], sgt[2 * i + 1]);
        }
    }
    void update_max(int i, T x) {
        i += n;
        sgt[i] = x;
        while (i > 1) {
            i /= 2;
            sgt[i] = max(sgt[2 * i], sgt[2 * i + 1]);
        }
    }
    void update_sum(int i, T x) {
        i += n;
        sgt[i] = x;
        while (i > 1) {
            i /= 2;
            sgt[i] = sgt[2 * i] + sgt[2 * i + 1];
        }
    }

    void add_sum(int i, T x) {
        i += n;
        sgt[i] += x;
        while (i > 1) {
            i /= 2;
            sgt[i] = sgt[2 * i] + sgt[2 * i + 1];
        }
    }

    void add_min(int i, T x) {
        i += n;
        sgt[i] += x;
        while (i > 1) {
            i /= 2;
            sgt[i] = min(sgt[2 * i], sgt[2 * i + 1]);
        }
    }

    void add_max(int i, T x) {
        i += n;
        sgt[i] += x;
        while (i > 1) {
            i /= 2;
            sgt[i] = max(sgt[2 * i], sgt[2 * i + 1]);
        }
    }

    T get_min(int a, int b, int k = 1, int l = 0,
              int r = -1)  // 閉区間 l <= x < r とする
    {
        if (r == -1) r = n;
        if (r <= a || b <= l) return intmax;
        if (a == l && b == r)
            return sgt[k];
        else
            return min(
                get_min(a, min(b, (l + r) / 2), 2 * k, l, (l + r) / 2),
                get_min(max(a, (l + r) / 2), b, 2 * k + 1, (l + r) / 2, r));
    }
    T get_max(int a, int b, int k = 1, int l = 0,
              int r = -1)  // 閉区間 l <= x < r とする
    {
        if (r == -1) r = n;
        if (r <= a || b <= l) return intmin;
        if (a == l && b == r)
            return sgt[k];
        else
            return max(
                get_max(a, min(b, (l + r) / 2), 2 * k, l, (l + r) / 2),
                get_max(max(a, (l + r) / 2), b, 2 * k + 1, (l + r) / 2, r));
    }
    T get_sum(int a, int b, int k = 1, int l = 0,
              int r = -1)  // 閉区間 l <= x < r とする
    {
        if (r == -1) r = n;
        if (r <= a || b <= l) return intmin;
        if (a == l && b == r)
            return sgt[k];
        else
            return get_sum(a, min(b, (l + r) / 2), 2 * k, l, (l + r) / 2) +
                   get_sum(max(a, (l + r) / 2), b, 2 * k + 1, (l + r) / 2, r);
    }

    T operator[](int i) { return sgt[i + n]; }

    void printsegtree() {
        for (int i = 0; i < 2 * n; i++) {
            cout << sgt[i] << " ";
        }
        cout << endl;
    }
};


class RangeSumQueryWithDelay  // 0-index
{
    ll const intmax = 2147483647;
    ll const intmin = 0;
    vector<ll> sgt;
    vector<ll> sgt_deray;
    int n;
    int k;

   public:
    RangeSumQueryWithDelay(int n1, int f = -1) {
        if (f == -1)
            f = intmax;
        else if (f == 0)
            f = intmin;
        int na = 1;
        int ka = 0;
        while (na < n1) {
            na *= 2;
            ka++;
        }
        for (int i = 0; i < 2 * na; i++) {
            sgt.push_back(f);
            sgt_deray.emplace_back(0);
        }
        n = na;
        k = ka;
    }

    void eval_add(int k, int l, int r) {
        if (sgt_deray[k] != 0) {
            sgt[k] += sgt_deray[k];
            if (r - l > 1) {
                sgt_deray[2 * k] += sgt_deray[k] / 2;
                sgt_deray[2 * k + 1] += sgt_deray[k] / 2;
            }
            sgt_deray[k] = 0;
        }
    }

    void eval_update(int k, int l, int r) {
        if (sgt_deray[k] != 0) {
            sgt[k] = sgt_deray[k];
            if (r - l > 1) {
                sgt_deray[2 * k] = sgt_deray[k];
                sgt_deray[2 * k + 1] = sgt_deray[k];
            }
            sgt_deray[k] = 0;
        }
    }

    void range_add(int a, int b, ll x, int k = 1, int l = 0, int r = -1) {
        if (r == -1) r = n;
        eval_add(k, l, r);  // 求める範囲とは違っても評価が行われることがある！
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            sgt_deray[k] += (r - l) * x;
            eval_add(k, l, r);
        } else {
            range_add(a, b, x, 2 * k, l, (l + r) / 2);
            range_add(a, b, x, 2 * k + 1, (l + r) / 2, r);
            sgt[k] = sgt[2 * k] + sgt[2 * k + 1];
        }
    }

    void range_add_max(int a, int b, ll x, int k = 1, int l = 0, int r = -1) {
        if (r == -1) r = n;
        eval_update(k, l,
                    r);  // 求める範囲とは違っても評価が行われることがある！
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            sgt_deray[k] += x;
            eval_update(k, l, r);
        } else {
            range_add_max(a, b, x, 2 * k, l, (l + r) / 2);
            range_add_max(a, b, x, 2 * k + 1, (l + r) / 2, r);
            sgt[k] = max(sgt[2 * k], sgt[2 * k + 1]);
        }
    }

    ll getsum(int a, int b, int k = 1, int l = 0,
              int r = -1)  // 閉区間 l <= x < r とする
    {
        if (r == -1) r = n;
        if (r <= a || b <= l) return intmin;
        eval_add(k, l, r);
        if (a <= l && r <= b) {
            return sgt[k];
        } else {
            auto v1 = getsum(a, b, 2 * k, l, (l + r) / 2);
            auto v2 = getsum(a, b, 2 * k + 1, (l + r) / 2, r);
            return v1 + v2;
        }
    }

    ll getmax(int a, int b, int k = 1, int l = 0,
              int r = -1)  // 閉区間 l <= x < r とする
    {
        if (r == -1) r = n;
        if (r <= a || b <= l) return -inf;
        eval_update(k, l, r);
        if (a <= l && r <= b) {
            return sgt[k];
        } else {
            auto v1 = getmax(a, b, 2 * k, l, (l + r) / 2);
            auto v2 = getmax(a, b, 2 * k + 1, (l + r) / 2, r);
            return max(v1, v2);
        }
    }

    void printsegtree() {
        for (int i = 0; i < 2 * n; i++) {
            cout << sgt[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < 2 * n; i++) {
            cout << sgt_deray[i] << " ";
        }
        cout << endl;
    }
};


struct heavy_light_decomposition : public graph {
    using graph::graph;
    VI hl_tree_list = VI(_n), hl_tree_index = VI(_n),
       hl_tree_parent = VI(_n, -1);
    vector<tuple<int, int, ll>> edges;
    VVI order = VVI(_n);
    RangeMinorMaxorSumQuery<ll> sgt = RangeMinorMaxorSumQuery<ll>(_n, 0);

    void get_weight_dfs(int u) {
        for (auto p : nodes[u].connect) {
            auto v = p.first;
            if (v == nodes[u].parent) continue;
            nodes[v].depth = nodes[u].depth + 1;
            nodes[v].parent = u;
            get_weight_dfs(v);
            nodes[u].subtree += nodes[v].subtree;
        }
    }

    void make_order_dfs(int u, int x, int &s, int &a, int b) {
        order[x].emplace_back(u);
        hl_tree_list[u] = a;
        hl_tree_parent[u] = b;
        hl_tree_index[u] = order[x].size() - 1;
        VPII subtree_index_list;
        for (auto p : nodes[u].connect) {
            auto v = p.first;
            if (v == nodes[u].parent) continue;
            subtree_index_list.emplace_back(make_pair(nodes[v].subtree, v));
        }
        sort(allpt_r(subtree_index_list));
        for (auto [_, v] : subtree_index_list) {
            if (v == nodes[u].parent) continue;
            if (v == subtree_index_list[0].second) {
                make_order_dfs(v, x, s, a, b);
            } else {
                a += order[s - 1].size();
                s++;
                make_order_dfs(v, s - 1, s, a, u);
            }
        }
    }

    int getcoodinate(int x) { return hl_tree_list[x] + hl_tree_index[x]; }

    void make_order() {
        get_weight_dfs(root);
        int s = 1, a = 0;
        make_order_dfs(root, 0, s, a, root);
        for (auto [u, v, c] : edges) {
            auto a = getcoodinate(u);
            auto b = getcoodinate(v);
            if (a > b)
                sgt.update_sum(a, c);
            else
                sgt.update_sum(b, c);
        }
    }

    void edge_update() {
        int x;
        ll c;
        cin >> x >> c;
        --x;
        auto [u, v, _] = edges[x];
        auto y = max(getcoodinate(u), getcoodinate(v));
        sgt.update_sum(y, c);
    }

    void edge_sum() {
        int a, b;
        ll ans{0};
        cin >> a >> b;
        --a, --b;
        ans = 0;
        while (hl_tree_list[a] != hl_tree_list[b]) {
            if (hl_tree_list[a] > hl_tree_list[b]) {
                auto l = hl_tree_list[a];
                auto r = getcoodinate(a) + 1;
                ans += sgt.get_sum(l, r);
                a = hl_tree_parent[a];
            } else {
                auto l = hl_tree_list[b];
                auto r = getcoodinate(b) + 1;
                ans += sgt.get_sum(l, r);
                b = hl_tree_parent[b];
            }
        }
        auto a1 = getcoodinate(a);
        auto b1 = getcoodinate(b);
        auto l = min(a1, b1) + 1;
        auto r = max(a1, b1) + 1;
        ans += sgt.get_sum(l, r);
        cout << ans << rt;
    }
};

int main() {
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    // リアクティブ問題のときはコメントアウト

    int n, q, op, a, b, x;
    ll c, ans;
    cin >> n;
    heavy_light_decomposition hl_tree(n);
    rep(_, n - 1) {
        cin >> a >> b >> c;
        a--, b--;
        hl_tree.nodes[a].connect.emplace_back(b, c);
        hl_tree.nodes[b].connect.emplace_back(a, c);
        hl_tree.edges.emplace_back(make_tuple(a, b, c));
    }
    hl_tree.make_order();
    // cout << hl_tree.order << hl_tree.hl_tree_list << hl_tree.hl_tree_index
    //      << hl_tree.hl_tree_parent;

    cin >> q;
    rep(_, q) {
        cin >> op;
        if (op == 1) {
            hl_tree.edge_update();
        } else {
            hl_tree.edge_sum();
        }
    }

    return 0;
}
