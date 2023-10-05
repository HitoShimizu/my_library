#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using VI = vector<int>;
using VL = vector<ll>;
using VVI = vector<vector<int>>;
using VVL = vector<vector<ll>>;
using PII = std::pair<int, int>;
using PLL = std::pair<ll, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep3(i, s, n, d) for (int i = (s); i < (int)(n); i += (d))
#define allpt(v) (v).begin(), (v).end()
#define allpt_c(v) (v).cbegin(), (v).cend()
#define allpt_r(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7;

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
    cout << v[n];
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

VI cumsum(VI &v)
{
    int s = 0;
    VI ret = {0};

    rep(i, v.size())
    {
        s += v[i];
        ret.push_back(s);
    }
    return ret;
}

void shuffle(VI &v, int t)
{
    int temp = v[t - 1];
    rep(i, t - 1) v[t - 1 - i] = v[t - 2 - i];
    v[0] = temp;
}

struct node
{
    VI children;
    ll ans = 1;
    ll ans_from_subtree = 1;
    ll ans_from_surtree = 1;
    int parent = -1;
    int subtree_size = 1;
    int surtree_size = 1;
};

void printsubtree(node n)
{
    cout << "parent = " << n.parent << rt;
    cout << "children = ";
    show1dvec(n.children);
    cout << rt;
    cout << "subtree_size = " << n.subtree_size << rt;
    cout << "surtree_size = " << n.surtree_size << rt;
    cout << "ans_from_subtree = " << n.ans_from_subtree << rt;
    cout << "ans_from_surtree = " << n.ans_from_surtree << rt;
    cout << "ans = " << n.ans << rt;
    cout << rt;
}

ll pow_mod(int p, int q, int mod)
{
    ll ret = 1, r = p;
    while (q)
    {
        if (q % 2)
            ret *= r, ret %= mod;
        r = (r * r) % mod, q /= 2;
    }
    return ret % mod;
}

ll const nmax = 101;
VL frac_table(nmax, 1);
VL frac_inv_table(nmax, 1);

void dfs(const int &x, const VVI &connect, vector<node> &nodes)
{
    for (auto z : connect[x])
    {
        if (z != nodes[x].parent)
        {
            nodes[z].parent = x;
            nodes[x].children.push_back(z);
            dfs(z, connect, nodes);
        }
    }
}

void dfs2(const int &x, const int &n, const VVI &connect, vector<node> &nodes)
{
    for (auto &z : nodes[x].children)
    {
        dfs2(z, n, connect, nodes);
        nodes[x].subtree_size += nodes[z].subtree_size;
        
        nodes[x].ans_from_subtree *= frac_inv_table[nodes[z].subtree_size];
        nodes[x].ans_from_subtree %= mod;
        nodes[x].ans_from_subtree *= nodes[z].ans_from_subtree;
        nodes[x].ans_from_subtree %= mod;
    }
    nodes[x].surtree_size = n - nodes[x].subtree_size;
    nodes[x].ans_from_subtree *= frac_table[nodes[x].subtree_size - 1];
    nodes[x].ans_from_subtree %= mod;
}

void dfs3(const int &x, const int &n, VVI &connect, vector<node> &nodes)
{
    nodes[x].ans = nodes[x].ans_from_subtree;
    if (nodes[x].parent != -1)
    {
        nodes[x].ans *= frac_table[n - 1];
        nodes[x].ans %= mod;
        nodes[x].ans *= frac_inv_table[nodes[x].surtree_size];
        nodes[x].ans %= mod;
        nodes[x].ans *= frac_inv_table[nodes[x].subtree_size - 1];
        nodes[x].ans %= mod;
        nodes[x].ans *= nodes[x].ans_from_surtree;
        nodes[x].ans %= mod;
    }
    for (auto z : nodes[x].children)
    {
        nodes[z].ans_from_surtree *= nodes[x].ans;
        nodes[z].ans_from_surtree *= frac_inv_table[n - 1];
        nodes[z].ans_from_surtree %= mod;
        nodes[z].ans_from_surtree *= frac_table[nodes[z].subtree_size];
        nodes[z].ans_from_surtree %= mod;
        nodes[z].ans_from_surtree *= frac_table[n - 1 - nodes[z].subtree_size];
        nodes[z].ans_from_surtree %= mod;
        nodes[z].ans_from_surtree *= pow_mod(nodes[z].ans_from_subtree, mod - 2, mod);
        nodes[z].ans_from_surtree %= mod;

        dfs3(z, n, connect, nodes);
    }
}

#define DEBUG

int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    int s = 1, t = 1;
    rep2(i, 1, nmax)
    {
        frac_table[i] = (frac_table[i - 1] * i) % mod;
        frac_inv_table[i] = (frac_inv_table[i - 1] * pow_mod(i, mod - 2, mod)) % mod;
    }

    int n, a, b;
    cin >> n;
    VVI connect(n);
    vector<node> nodes(n);
    rep(i, n - 1)
    {
        cin >> a >> b;
        a--, b--;
        connect[a].push_back(b);
        connect[b].push_back(a);
    }

    dfs(0, connect, nodes);
    dfs2(0, n, connect, nodes);
    dfs3(0, n, connect, nodes);
    
#ifdef DEBUG
    for_each(allpt(nodes), printsubtree);
#endif

    for_each(allpt(nodes), [](const node &z){cout << z.ans << rt;});


    return 0;
}
