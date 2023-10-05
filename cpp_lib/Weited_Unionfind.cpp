
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
const int mod = mod1;
const ll inf = 1e18;

const string wsp = " ";
const string tb = "\t";
const string rt = "\n";

class Weited_Unionfind
{
    vector<int> p;
    vector<int> diff;
    VVI children;

public:
    int find(int x);
    void unite(int x, int y, int d, bool &ok);
    bool isunion(int x, int y);
    Weited_Unionfind(int n);
    void showdiff(int x, int y);
};

Weited_Unionfind::Weited_Unionfind(int n)
{
    children.resize(n);
    for (int i = 0; i < n; i++)
    {
        p.emplace_back(i);
        diff.emplace_back(0);
        children[i].emplace_back(i);
    }
}
int Weited_Unionfind::find(int x)
{
    while (p[x] != x)
    {
        p[x] = p[p[x]];
        x = p[x];
    }
    return x;
}

void Weited_Unionfind::unite(int x, int y, int d, bool &ok)
{
    int px, py, bigtree, smalltree, dx, dy;
    px = Weited_Unionfind::find(x);
    py = Weited_Unionfind::find(y);
    if (px == py)
    {
        if (diff[y] - diff[x] != d)
            ok = false;
        return;
    }
    dx = diff[x] - diff[px];
    dy = diff[y] - diff[py];
    bigtree = (children[px].size() >= children[py].size() ? px : py);
    smalltree = (bigtree == px ? py : px);
    p[smalltree] = bigtree;
    for (int z : children[smalltree])
    {
        children[bigtree].emplace_back(z);
        if (px == bigtree)
            diff[z] += d - dy + dx;
        else
            diff[z] -= d - dy + dx;
    }
    children[smalltree].clear();
}

bool Weited_Unionfind::isunion(int x, int y)
{
    return Weited_Unionfind::find(x) == Weited_Unionfind::find(y);
}

void Weited_Unionfind::showdiff(int x, int y)
{
    int px, py;
    px = Weited_Unionfind::find(x);
    py = Weited_Unionfind::find(y);
    if (px != py)
        cout << "?" << rt;
    else
        cout << diff[y] - diff[x] << rt;
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

    int n, q, a, b, d;
    bool ok{true};
    cin >> n >> q;
    Weited_Unionfind un(n + 1);

    rep(qi, q)
    {
        cin >> a >> b >> d;
        un.unite(a, b, d, ok);
        if (!ok)
            break;
    }

    cout << (ok ? "Yes" : "No") << rt;

    return 0;
}
