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
const int mod = mod1;
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
ostream &operator<<(ostream &os, const vector<T> &v) {
    if (v.size() == 0) return os;
    int n = v.size() - 1;
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
    int n = v.size();
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
    int n = v.size();
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
ll pow_mod(T p, S q, R mod = 1ll) {
    ll ret = 1, r = p;
    while (q) {
        if (q % 2) ret *= r, ret %= mod;
        r = (r * r) % mod, q /= 2;
    }
    return ret % mod;
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
    void getconnect0_1() {
        ll a, b;
        cin >> a >> b;
        nodes[a].connect.emplace_back(b, 1);
        nodes[b].connect.emplace_back(a, 1);
    }
    void getconnect0_2() {
        ll a, b, c;
        cin >> a >> b >> c;
        nodes[a].connect.emplace_back(b, c);
        nodes[b].connect.emplace_back(a, c);
    }
    void getconnect1_1() {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        nodes[a].connect.emplace_back(b, 1);
        nodes[b].connect.emplace_back(a, 1);
    }
    void getconnect1_2() {
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

struct point {
    int x;
    int y;
    point() {
        x = 0;
        y = 0;
    }
    point(int _x, int _y) {
        x = _x;
        y = _y;
    }
    void pointinput() {
        int _x, _y;
        cin >> _x >> _y;
        x = _x;
        y = _y;
    }
    void pointinv() { swap(x, y); }
};

istream &operator>>(istream &is, point &p) {
    is >> p.x >> p.y;
    return is;
}

ostream &operator<<(ostream &os, point &p) {
    os << p.x << wsp << p.y << rt;
    return os;
}

double pointseuc(point a, point b) {
    ll ax = a.x, bx = b.x, ay = a.y, by = b.y;
    return sqrt(pow(ax - bx, 2) + pow(ay - by, 2));
}

ll pointseucsquare(point a, point b) {
    ll ax = a.x, bx = b.x, ay = a.y, by = b.y;
    return (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
}

int pointsmanhattan(point a, point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

double dist_segment_point(TL3 segment, point p) {
    double a = get<0>(segment);
    double b = get<1>(segment);
    double c = get<2>(segment);
    return abs(a * p.x + b * p.y - c) / (a * a + b * b + c * c);
}

TL3 segment_parameter(point p, point q) {
    ll a, b, c;
    a = q.y - p.y;
    b = p.x - q.x;
    c = a * p.x + b * p.y;
    TL3 ret = (TL3){a, b, c};
    // cout << a << b << c << rt;
    return ret;
}

int cross_check(TL3 segment, point p) {
    ll a = get<0>(segment);
    ll b = get<1>(segment);
    ll c = get<2>(segment);

    auto f = a * p.x + b * p.y - c;
    int ret;
    if (f > 0) ret = 1;
    if (f == 0) ret = 0;
    if (f < 0) ret = -1;
    return ret;
}

VI shave(int n) {
    VI v;
    if (n <= 1) return v;
    vector<bool> w(n + 1, true);
    int x;
    w[0] = w[1] = false;
    rep2(i, 2, n + 1) {
        if (w[i]) {
            x = i * 2;
            while (x <= n) {
                w[x] = false;
                x += i;
            }
        }
    }
    rep(i, n + 1) if (w[i]) v.emplace_back(i);
    return v;
}

void shave(vector<int> &v, int n) {
    if (n <= 1) return;
    vector<bool> w(n + 1, true);
    int x;
    w[0] = w[1] = false;
    rep2(i, 2, n + 1) {
        if (w[i]) {
            x = i * 2;
            while (x <= n) {
                w[x] = false;
                x += i;
            }
        }
    }
    rep(i, n + 1) if (w[i]) v.emplace_back(i);
}

template <typename T>
void coordinate_compress(vector<T> &x, map<T, int> &zip, int &xs) {
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    xs = x.size();
    for (int i = 0; i < xs; i++) {
        zip[x[i]] = i;
    }
}

// ll getpalindrome(int l, int r, const string &s, VL &memo) {
//     if (r - l <= 1) return 1;
//     if (memo[l] != -1) return memo[l];
//     ll ret{1};
//     int n = (r - l) / 2;
//     string sl, sr;
//     rep(i, n) {
//         sl += s[l + i];
//         sr += s[r - 1 - i];
//         string rsr(i + 1, '0');
//         reverse_copy(allpt_c(sr), rsr.begin());
//         // cout << sl << wsp << sr << wsp << rsr << rt;
//         if (sl == rsr) {
//             ret += getpalindrome(l + i + 1, r - i - 1, s, memo);
//             ret %= mod;
//         }
//     }
//     memo[l] = ret;
//     return ret;
// }

void getpalindrome(int l, int r, int n, const string &s, VVB &memo) {
    if (r - l <= 1 || s[l] == s[r - 1]) {
        memo[l][r] = true;
        if (l > 0 && r < n) {
            getpalindrome(l - 1, r + 1, n, s, memo);
        }
    }
    return;
}

// void djcstra(graph graphs, int s, int t) {
//     const int n = graphs._n;
//     VL shortest(n, inf);
//     shortest[s] = 0;
//     priority_queue<pair<ll, int>> pq;
//     pq.push(make_pair(0, s));
//     while (!pq.empty()) {
//         auto [t, v] = pq.top();
//         pq.pop();
//         t = -t;
//         if (shortest[v] != t) continue;
//         for (auto [u, c] : graphs.nodes[v].connect) {
//             if (t + c < shortest[u]) {
//                 shortest[u] = t + c;
//                 pq.push(make_pair(-(t + c), u));
//             }
//         }
//     }
// }

class Unionfind {
    vector<int> p;

   public:
    Unionfind(int n) {
        for (int i = 0; i < n; i++) {
            p.push_back(i);
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
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            p[x] = y;
        }
    }

    bool isunion(int x, int y) { return find(x) == find(y); }
    void showtree() { cout << p; }
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
              int r = -1)  //閉区間 l <= x < r とする
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
              int r = -1)  //閉区間 l <= x < r とする
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
              int r = -1)  //閉区間 l <= x < r とする
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

template <typename T>
class Bit_Index_Tree  // 1-index

{
    int n = 0;
    vector<T> v;

   public:
    Bit_Index_Tree(int _n, T x = 0) {
        n = _n;
        v.resize(n + 1);
        fill(allpt(v), x);
    }
    Bit_Index_Tree(vector<T> _v) {
        n = _v.size();
        v = _v;
    }
    void add(int i, T x) {
        while (i <= n) {
            v[i] += x;
            i += i & -i;
        }
    }
    T get_sum(int i) {
        T ret = 0;
        while (i > 0) {
            ret += v[i];
            i -= i & -i;
        }
        return ret;
    }
    T get_range_sum(int l, int r) {  // 半開区間　l <= x < r
        return get_sum(r) - get_sum(l);
    }
};

// #define DEBUG

VI smallest_prime_factors(int n) {
    VI ret(n + 1);
    iota(allpt(ret), 0);
    for (int i = 2; i * i <= n; i++) {
        if (ret[i] == i) {
            for (int j = i * i; j <= n; j += i) {
                if (ret[j] == j) ret[j] = i;
            }
        }
    }
    return ret;
}

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
        eval_add(k, l, r);  //求める範囲とは違っても評価が行われることがある！
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
                    r);  //求める範囲とは違っても評価が行われることがある！
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
              int r = -1)  //閉区間 l <= x < r とする
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
              int r = -1)  //閉区間 l <= x < r とする
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

void dfs_1(graph &tree, int u) {
    cout << u << rt;
    for (auto [v, _] : tree.nodes[u].connect)
        if (v != tree.root && tree.nodes[v].parent == -1) {
            tree.nodes[v].parent = u;
            dfs_1(tree, v);
            tree.nodes[u].subtree += tree.nodes[v].subtree;
            tree.nodes[u].children.emplace_back(PII(tree.nodes[v].subtree, v));
        }
}

void dfs_2(graph &tree, int u, int d) {
    cout << u << wsp << d << rt;

    sort(allpt_r(tree.nodes[u].children));
    rep(j, tree.nodes[u].children.size()) {
        auto [_, v] = tree.nodes[u].children[j];
        cout << (VI){u, v, j};
        dfs_2(tree, v, j == 0 ? d : d + 1);
    }
}

int main() {
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    // リアクティブ問題のときはコメントアウト

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    // ifstream in("input.txt");                             // for debug
    // cin.rdbuf(in.rdbuf());                                // for debug
    chrono::system_clock::time_point timestart, timeend;  // for debug
    timestart = std::chrono::system_clock::now();         // for debug

#endif

    int n, q, t, a, b;
    cin >> n >> q;
    graph tree(n);
    Unionfind uf(n);
    VI ans_list(q, -2);
    vector<TI3> queries;
    rep(i, q) {
        cin >> t >> a >> b;
        --a, --b;
        if (t == 1) {
            if (!uf.isunion(a, b)) {
                uf.unite(a, b);
                tree.nodes[a].connect.emplace_back((PII){b, 0});
                tree.nodes[b].connect.emplace_back((PII){a, 0});
            } else {
                // update with_HL
            }
        } else {
            if (!uf.isunion(a, b)) {
                ans_list[i] = -1;
            } else {
                // sum with_HL
                ans_list[i] = 0;
            }
        }
        queries.emplace_back((TI3){t, a, b});
    }

    rep2(i, 1, n) if (!uf.isunion(0, i)) {
        uf.unite(0, i);
        tree.nodes[i].connect.emplace_back((PII){0, 0});
        tree.nodes[0].connect.emplace_back((PII){i, 0});
    }
    dfs_1(tree, tree.root);

    rep(i, n) cout << tree.nodes[i].subtree << rt;
    dfs_2(tree, tree.root, 0);

    cout << ans_list;

#ifdef DEBUG
    timeend = chrono::system_clock::now();
    auto elapsed =
        chrono::duration_cast<chrono::milliseconds>(timeend - timestart)
            .count();
    cout << "Time is " << elapsed << "ms" << std::endl;
#endif

    return 0;
}
