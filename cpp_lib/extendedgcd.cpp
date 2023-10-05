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
    rep(i, n) os << v[i].first << v[i].second << rt;
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
    rep(i, n) cout << v[i].first << wsp << v[i].second << rt;
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

bool iskadomatsu(int a, int b, int c) {
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
                string t;
                t += c;
                ret.emplace_back(t);
                ret.emplace_back(part);
            }
            part = "";
        } else if (s[i] == d) {
            if (part != "") {
                string t;
                t += d;
                ret.emplace_back(t);
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
    int degree = 1;
    int subtree = 1;
    VPII children;
    VPII connect;
    node(int n) {
        parent = -1;
        weight = 0;
        depth = 0;
        degree = 0;
        subtree = 1;
        children;
        connect;
    }
};

struct graph {
    int _n;
    int root = 0;
    vector<node> nodes;
    graph(int n) {
        _n = n;
        rep(i, _n) nodes.emplace_back(node(_n));
    }
    void getconnect0_1() {
        int a, b;
        cin >> a >> b;
        nodes[a].connect.emplace_back(b, 0);
        nodes[b].connect.emplace_back(a, 0);
    }
    void getconnect0_2() {
        int a, b, c;
        cin >> a >> b >> c;
        nodes[a].connect.emplace_back(b, c);
        nodes[b].connect.emplace_back(a, c);
    }
    void getconnect1_1() {
        int a, b;
        cin >> a >> b;
        a--, b--;
        nodes[a].connect.emplace_back(b, 0);
        nodes[b].connect.emplace_back(a, 0);
    }
    void getconnect1_2() {
        int a, b, c;
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

ll extendedgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extendedgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

// #define DEBUG

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

    ll x, y;
    extendedgcd(111, 30, x, y);
    cout << x << ", " << y << endl;

#ifdef DEBUG
    timeend = chrono::system_clock::now();
    auto elapsed =
        chrono::duration_cast<chrono::milliseconds>(timeend - timestart)
            .count();
    cout << "Time is " << elapsed << "ms" << std::endl;
#endif

    return 0;
}
