#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using VI = vector<int>;
using VL = vector<ll>;
using VS = vector<string>;
using VB = vector<bool>;
using VVI = vector<VI>;
using VVL = vector<VL>;
using PII = std::pair<int, int>;
using PLL = std::pair<ll, ll>;
using TI3 = std::tuple<int, int, int>;
using TI4 = std::tuple<int, int, int, int>;
using TL3 = std::tuple<ll, ll, ll>;
using TL4 = std::tuple<ll, ll, ll, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep3(i, s, n, d) for (int i = (s); i < (int)(n); i += (d))
#define allpt(v) (v).begin(), (v).end()
#define allpt_c(v) (v).cbegin(), (v).cend()
#define allpt_r(v) (v).rbegin(), (v).rend()

const int mod1 = 1e9 + 7, mod2 = 998244353, mod3 = 1e9 + 9;
const int mod = mod2;
const ll inf = 1e18;

const string wsp = " ";
const string tb = "\t";
const string rt = "\n";

template <typename T>
void show1dvec(const vector<T> &v)
{
    if (v.size() == 0)
        return;
    int n = v.size() - 1;
    rep(i, n) cout << v[i] << wsp;
    cout << v[n] << rt;

    return;
}

template <typename T>
void show2dvec(const vector<vector<T>> &v)
{
    int n = v.size();
    rep(i, n) show1dvec(v[i]);
}

template <typename T, typename S>
void show1dpair(const vector<pair<T, S>> &v)
{
    int n = v.size();
    rep(i, n) cout << v[i].first << wsp << v[i].second << rt;
    return;
}

template <typename T, typename S>
void pairzip(const vector<pair<T, S>> &v, vector<T> &t, vector<T> &s)
{
    int n = v.size();
    rep(i, n)
    {
        t.push_back(v[i].first);
        s.push_back(v[i].second);
    }
    return;
}

template <typename T>
void maxvec(vector<T> &v)
{
    T s = v[0];
    int n = v.size();
    rep(i, n - 1)
    {
        if (s > v[i + 1])
        {
            v[i + 1] = s;
        }
        s = v[i + 1];
    }
}

template <typename T, typename S>
bool myfind(T t, S s)
{
    return find(t.cbegin(), t.cend(), s) != t.cend();
}

bool check(int y, int x, int h, int w)
{
    return 0 <= y && y < h && 0 <= x && x < w;
}

template <typename T>
vector<T> cumsum(const vector<T> &v)
{
    T s = 0;
    vector<T> ret;

    rep(i, v.size())
    {
        s += v[i];
        s %= mod;
        ret.emplace_back(s);
    }
    return ret;
}


void dfs(int v, int d, vector<vector<PII>> &connect, VI &depth, VL &accum_d, VVI &dp)
{
    depth[v] = d;
    {
        for (auto &[u, c] : connect[v])
        {
            if (depth[u] == -1)
            {
                accum_d[u] += accum_d[v] + c;
                dp[u][0] = v;
                dfs(u, d + 1, connect, depth, accum_d, dp);
            }
        }
    }
    return;
}

int lca(int a, int b, const VI &depth, const VVI &dp)
{
    int c, d;
    if (depth[a] < depth[b])
        swap(a, b);
    d = depth[a] - depth[b];

    rep(i, 25)
    {
        if (d & (1 << i))
            a = dp[a][i];
    }
    if (a == b)
        return a;
    // 深さが不一致なら浅い方に揃え、一致したら終了

    while (dp[a][0] != dp[b][0])
    {
        rep(i, 25) if (dp[a][i + 1] == dp[b][i + 1])
        {
            a = dp[a][i];
            b = dp[b][i];
            break;
        }
        // すぐ上の頂点が一致するまでダブリングで同じ深さまで登る
    }
    return dp[a][0];
}

#define DEBUG

int main()
{

    cin.tie(0);
    ios::sync_with_stdio(false);

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    const int m = 25;
    int n, q, a, b, c, d;
    cin >> n;
    vector<vector<PII>> connect(n);
    ll ans;
    VI depth(n, -1);
    VL accum_d(n, 0);
    VVI dp(n, VI(m, -1));
    rep(i, n - 1)
    {
        cin >> a >> b >> c;
        a--, b--;
        connect[a].emplace_back(make_pair(b, c));
        connect[b].emplace_back(make_pair(a, c));
    }

    dfs(0, 0, connect, depth, accum_d, dp);
    rep(j, m - 1) rep(i, n) if (dp[i][j] != -1)
    {
        dp[i][j + 1] = dp[dp[i][j]][j];
    }
    // show2dvec(dp);
    // show1dvec(depth);
    cin >> q;
    rep(i, q)
    {
        ans = 0;
        cin >> a >> b;
        a--, b--;
        d = lca(a, b, depth, dp);

        ans = accum_d[a] + accum_d[b] - 2 * accum_d[d];
        cout << ans << rt;
    }
    return 0;
}
