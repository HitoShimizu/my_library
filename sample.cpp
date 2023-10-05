// #include <bits/stdc++.h>
#include <algorithm>
#include <atcoder/all>
#include <bitset>
#include <chrono>
#include <cmath>
#include <complex>
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
using namespace atcoder;
using mint1 = modint1000000007;
using mint2 = modint998244353;
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

constexpr int mod1 = 1e9 + 7, mod2 = 998244353, mod3 = 1e9 + 9;
constexpr int mod = mod2;
constexpr ll inf = 1e18;
constexpr int infint = 1e9;
constexpr double pi = 3.14159265359;

bool test;
const string wsp = " ";
const string tb = "\t";
const string rt = "\n";
const string alphabets = "abcdefghijklmnopqrstuvwxyz";
std::random_device seed_gen;
std::mt19937 engine(seed_gen());
// 乱数生成用メルセンヌ・ツイスタエンジン

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

int get1dcoodinate(int w, int i, int j) { return i * w + j; }

template <typename T, typename S>
istream &operator>>(istream &is, pair<T, S> &v) {
    is >> v.first >> v.second;
    return is;
}

template <typename T, typename S>
ostream &operator<<(ostream &os, pair<T, S> &v) {
    os << v.first << wsp << v.second << rt;
    return os;
}

ostream &operator<<(ostream &os, modint &v) {
    os << v.val();
    return os;
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

template <class T>
bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
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
    int subtree = 0;
    int check = 0;
    int scc = -1;
    VPLL children;
    VI parent_list;
    VPLL connect;
    ll black_from_children;
    ll black_from_parent;

    node() {
        parent = -1;
        weight = 0;
        depth = 0;
        degree = 0;
        subtree = 0;
        check = 0;
        black_from_children = 1;
        black_from_parent = 1;
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
    // pair<VL, VI> djcstra(int s = 0) {
    //     VL shortest(_n, inf);
    //     VI prev(_n, -1);
    //     shortest[s] = 0;
    //     priority_queue<pair<ll, int>> pq;
    //     pq.push(make_pair(0, s));
    //     while (!pq.empty()) {
    //         auto [t, u] = pq.top();
    //         pq.pop();
    //         t = -t;
    //         if (shortest[u] != t) continue;
    //         for (auto [v, c] : nodes[u].connect) {
    //             if (t + c < shortest[v]) {
    //                 shortest[v] = t + c;
    //                 prev[v] = u;
    //                 pq.push(make_pair(-(t + c), v));
    //             }
    //         }
    //     }
    //     return make_pair(shortest, prev);
    // }

    pair<VL, VI> djcstra(VI s) {
        VL shortest(_n, inf);
        VI prev(_n, -1);
        priority_queue<pair<ll, int>> pq;
        for (auto x : s) {
            shortest[x] = 0;
            pq.push(make_pair(0, x));
        }
        while (!pq.empty()) {
            auto [t, u] = pq.top();
            pq.pop();
            t = -t;
            if (shortest[u] != t) continue;
            for (auto [v, c] : nodes[u].connect) {
                if (t + c < shortest[v]) {
                    shortest[v] = t + c;
                    prev[v] = u;
                    pq.push(make_pair(-(t + c), v));
                }
            }
        }
        return make_pair(shortest, prev);
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
    return abs(a * p.x + b * p.y - c) / sqrt(a * a + b * b);
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

bool iscross(point p1, point p2, point p3, point p4) {
    auto segment_1 = segment_parameter(p1, p2);
    auto segment_2 = segment_parameter(p3, p4);
    const double eps = 1e-6;
    bool ans{false};
    if (cross_check(segment_1, p3) * cross_check(segment_1, p4) == 0 &&
        cross_check(segment_2, p1) * cross_check(segment_2, p2) == 0) {
        auto xmin_1 = min(p1.x, p2.x) - eps;
        auto xmin_2 = min(p3.x, p4.x) - eps;
        auto xmax_1 = max(p1.x, p2.x) + eps;
        auto xmax_2 = max(p3.x, p4.x) + eps;
        auto ymin_1 = min(p1.y, p2.y) - eps;
        auto ymin_2 = min(p3.y, p4.y) - eps;
        auto ymax_1 = max(p1.y, p2.y) + eps;
        auto ymax_2 = max(p3.y, p4.y) + eps;

        if (xmin_1 <= p3.x && p3.x <= xmax_1 && ymin_1 <= p3.y &&
            p3.y <= ymax_1)
            ans = true;
        if (xmin_1 <= p4.x && p4.x <= xmax_1 && ymin_1 <= p4.y &&
            p4.y <= ymax_1)
            ans = true;
        if (xmin_2 <= p1.x && p1.x <= xmax_2 && ymin_2 <= p1.y &&
            p1.y <= ymax_2)
            ans = true;
        if (xmin_2 <= p2.x && p2.x <= xmax_2 && ymin_2 <= p2.y &&
            p2.y <= ymax_2)
            ans = true;
    } else if (cross_check(segment_1, p3) * cross_check(segment_1, p4) <= 0 &&
               cross_check(segment_2, p1) * cross_check(segment_2, p2) <= 0) {
        ans = true;
    }
    return ans;
}

// int on_the_segment(point p, point q1, point q2) {
//     auto [a, b, c] = segment_parameter(q1, q2);

//     if (p.x < min(q1.x, q2.x) || max(q1.x, q2.x) < p.x) return 0;
//     if (p.y < min(q1.y, q2.y) || max(q1.y, q2.y) < p.y) return 0;

//     auto f = a * p.x + b * p.y - c;
//     return f == 0;
// }

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
void sort_and_unique(vector<T> &x) {
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
}

template <typename T>
void coordinate_compress(vector<T> &x, map<T, int> &zip, int &xs) {
    sort_and_unique(x);
    xs = x.size();
    for (int i = 0; i < xs; i++) zip[x[i]] = i;
}

template <typename T>
pair<map<T, int>, int> coordinate_compress(vector<T> &x) {
    map<T, int> zip;
    sort_and_unique(x);
    int xs = x.size();
    for (int i = 0; i < xs; i++) zip[x[i]] = i;
    return make_pair(zip, xs);
}

template <typename T>
pair<map<T, int>, int> copy_coordinate_compress(vector<T> &x) {
    VI x_copy = x;
    auto [x_zip, xl] = coordinate_compress(x_copy);
    for (auto &v : x) v = x_zip[v];
    return make_pair(x_zip, xl);
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

// void getpalindrome(int l, int r, int n, const string &s, VVB &memo) {
//     if (r - l <= 1 || s[l] == s[r - 1]) {
//         memo[l][r] = true;
//         if (l > 0 && r < n) {
//             getpalindrome(l - 1, r + 1, n, s, memo);
//         }
//     }
//     return;
// }

class Unionfind {
    vector<int> p;
    vector<int> w;

   public:
    Unionfind(int n, int _w = 1) {
        for (int i = 0; i < n; i++) {
            p.emplace_back(i);
            w.emplace_back(_w);
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
    void setweight(int x, int _w) { w[find(x)] |= _w; }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            p[x] = min(x, y);
            p[y] = min(x, y);
            w[min(x, y)] |= w[max(x, y)];
            w[max(x, y)] = 0;
        }
    }

    bool isunion(int x, int y) { return find(x) == find(y); }
    void showtree() { cout << p << w; }
};

template <typename T>
class RangeMinorMaxorSumQuery  // 0-index
{
    T const intmax = inf;
    T const intmin = 0;
    vector<T> sgt;
    int n;
    int k;

   public:
    RangeMinorMaxorSumQuery(int n1, T f) {
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

    void update_min(int i, T x) {
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
    void update_gcd(int i, T x) {
        i += n;
        sgt[i] = x;
        while (i > 1) {
            i /= 2;
            sgt[i] = gcd(sgt[2 * i], sgt[2 * i + 1]);
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
        if (r <= a || b <= l) return inf;
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
        if (r <= a || b <= l) return 0;
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
    T get_gcd(int a, int b, int k = 1, int l = 0,
              int r = -1)  // 閉区間 l <= x < r とする
    {
        if (r == -1) r = n;
        if (r <= a || b <= l) return 0;
        if (a == l && b == r)
            return sgt[k];
        else
            return gcd(
                get_gcd(a, min(b, (l + r) / 2), 2 * k, l, (l + r) / 2),
                get_gcd(max(a, (l + r) / 2), b, 2 * k + 1, (l + r) / 2, r));
    }

    void update_xor(int i, T x) {
        i += n;
        sgt[i] = x;
        while (i > 1) {
            i /= 2;
            sgt[i] = sgt[2 * i] ^ sgt[2 * i + 1];
        }
    }

    T get_xor(int a, int b, int k = 1, int l = 0,
              int r = -1)  // 閉区間 l <= x < r とする
    {
        if (r == -1) r = n;
        if (r <= a || b <= l) return 0;
        if (a == l && b == r)
            return sgt[k];
        else
            return get_xor(a, min(b, (l + r) / 2), 2 * k, l, (l + r) / 2) ^
                   get_xor(max(a, (l + r) / 2), b, 2 * k + 1, (l + r) / 2, r);
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
    void add(int i, T x) {
        while (i <= n) {
            v[i] += x;
            i += i & -i;
        }
    }
    Bit_Index_Tree(int _n, T x = 0) {
        n = _n;
        v.resize(n + 1);
        fill(allpt(v), x);
    }
    Bit_Index_Tree(vector<T> _v) {
        n = _v.size();
        v.resize(n + 1);
        fill(allpt(v), 0);
        rep(i, n) add(i, v[i]);
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

// void dfs_1(graph &tree, int u)
// {
//     cout << u << rt;
//     for (auto [v, _] : tree.nodes[u].connect)
//         if (v != tree.root && tree.nodes[v].parent == -1)
//         {
//             tree.nodes[v].parent = u;
//             dfs_1(tree, v);
//             tree.nodes[u].subtree += tree.nodes[v].subtree;
//             tree.nodes[u].children.emplace_back(PII(tree.nodes[v].subtree,
//             v));
//         }
// }

// void dfs_2(graph &tree, int u, int d)
// {
//     cout << u << wsp << d << rt;

//     sort(allpt_r(tree.nodes[u].children));
//     rep(j, tree.nodes[u].children.size())
//     {
//         auto [_, v] = tree.nodes[u].children[j];
//         cout << (VI){u, (int)v, j};
//         dfs_2(tree, v, j == 0 ? d : d + 1);
//     }
// }

template <typename T>
class Matrix_n {
    int matsize;
    vector<vector<T>> mat;

   public:
    Matrix_n() {
        matsize = 0;
        vector<vector<T>> mat;
    }
    Matrix_n(int n) {
        matsize = n;
        mat.resize(n);
        rep(i, n) rep(j, n) mat[i].emplace_back(0);
    }
    Matrix_n(const vector<vector<T>> &inmat) {
        int n = inmat.size();
        matsize = n;
        mat.resize(n);
        rep(i, n) {
            mat[i].resize(n);
            rep(j, n) { mat[i][j] = inmat[i][j]; }
        }
    }
    void identify() {
        rep(i, matsize) rep(j, matsize) { mat[i][j] = i == j ? 1 : 0; }
    }
    T getone(const int &i, const int &j) { return mat[i][j]; }

    int getsize() { return matsize; }

    const Matrix_n operator+(const Matrix_n &b) {
        Matrix_n ret(matsize);
        rep(i, matsize) rep(j, matsize) {
            ret.mat[i][j] = mat[i][j] + b.mat[i][j];
        }
        return ret;
    }

    const Matrix_n operator-(const Matrix_n &b) {
        Matrix_n ret(matsize);
        rep(i, matsize) rep(j, matsize) {
            ret.mat[i][j] = mat[i][j] - b.mat[i][j];
        }
        return ret;
    }

    const Matrix_n operator*(const Matrix_n &b) {
        Matrix_n ret(matsize);
        rep(i, matsize) rep(j, matsize) rep(k, matsize) {
            ret.mat[i][j] += mat[i][k] * b.mat[k][j];
            ret.mat[i][j] %= mod;
        }
        return ret;
    }

    const Matrix_n operator%(const int &b) {
        Matrix_n ret(matsize);
        rep(i, matsize) rep(j, matsize) { ret.mat[i][j] = mat[i][j] % b; }
        return ret;
    }

    const Matrix_n operator+() { return *this; }

    const Matrix_n operator-() {
        Matrix_n ret(matsize);
        rep(i, matsize) rep(j, matsize) { ret.mat[i][j] = -mat[i][j]; }
        return ret;
    }

    Matrix_n &operator+=(const Matrix_n &b) {
        rep(i, matsize) rep(j, matsize) { mat[i][j] += b.mat[i][j]; }
        return *this;
    }

    Matrix_n &operator-=(const Matrix_n &b) {
        rep(i, matsize) rep(j, matsize) { mat[i][j] -= b.mat[i][j]; }
        return *this;
    }

    Matrix_n &operator%=(const int &b) {
        rep(i, matsize) rep(j, matsize) { mat[i][j] %= b; }
        return *this;
    }

    void showmat() { cout << mat; }
};

template <typename T>
Matrix_n<T> mat_pow_mod(Matrix_n<T> a, ll p, ll m = mod) {
    const int n = a.getsize();
    Matrix_n<T> b(n);
    b.identify();

    while (p > 0) {
        if (p % 2) {
            b = b * a;
            b %= m;
        }
        p /= 2;
        a = a * a;
        a %= m;
    }
    return b;
}

template <typename T>
Matrix_n<T> mat_pow_no_mod(Matrix_n<T> a, ll p) {
    const int n = a.getsize();
    Matrix_n<T> b(n);
    b.identify();

    while (p > 0) {
        if (p % 2) {
            b = b * a;
        }
        p /= 2;
        a = a * a;
    }
    return b;
}

VL make_frac_k(int k, int l) {
    VL ret(l + 1, 1);
    rep(i, l) {
        ret[i + 1] = ret[i] * k;
        ret[i + 1] %= mod;
    }
    return ret;
}

template <typename T, typename S>
void ans_print(T ans, T nodata, S printdata) {
    if (ans == nodata) {
        cout << printdata;
    } else {
        cout << ans;
    }
    cout << endl;
}

int mex(VI v) {
    sort_and_unique(v);
    int n = v.size();
    rep(i, n) {
        if (v[i] != i) return i;
    }
    return n;
}

map<PLL, bool> makemap(ll n, VI x_list) {
    int m = x_list.size();
    VPLL search, new_search;
    map<PLL, bool> ret;
    search.emplace_back((PLL){0, 1});
    for (auto x : x_list) {
        for (auto [s, p] : search) {
            new_search.emplace_back((PLL){s, p});
            auto new_s = s + x, new_p = p * x / gcd(p, x);
            if (new_s <= n && new_p <= n) {
                new_search.emplace_back((PLL){new_s, new_p});
            }
        }
        search = new_search;
    }
    for (auto sp : search) ret[sp] = true;
    return ret;
}

int main(int argc, char *argv[]) {
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    // リアクティブ問題のときはコメントアウト

    cout << 200000 << wsp << 200000 << wsp << 200000000 << rt;
    VI v(200000, 100000000);
    cout << v << v;


    return 0;
}
