#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using VI = vector<int>;
using VL = vector<ll>;
using VS = vector<string>;
using VB = vector<bool>;
using VVB = vector<vector<bool>>;
using VVI = vector<VI>;
using VVL = vector<VL>;
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
#define rep3(i, s, n, d) for (int i = (s); i < (int)(n); i += (d))
#define allpt(v) (v).begin(), (v).end()
#define allpt_c(v) (v).cbegin(), (v).cend()
#define allpt_r(v) (v).rbegin(), (v).rend()
#define allpt_cr(v) (v).crbegin(), (v).crend()

const int mod1 = 1e9 + 7, mod2 = 998244353, mod3 = 1e9 + 9;
const int mod = mod1;
const ll inf = 1e18;

const string wsp = " ";
const string tb = "\t";
const string rt = "\n";


// 区間更新一点求値用

class RangeAddQuery // 0-index
{
    int const intmax = 2147483647;
    int const intmin = 0;
    vector<int> sgt;
    int n;
    int k;

public:
    RangeAddQuery(int n1, int f = -1)
    {
        if (f == -1)
            f = intmax;
        else if (f == 0)
            f = intmin;
        int na = 1;
        int ka = 0;
        while (na < n1)
        {
            na *= 2;
            ka++;
        }
        for (int i = 0; i < 2 * na; i++)
            sgt.push_back(f);
        n = na;
        k = ka;
    }

    int get_sum(int i)
    {
        int ret = 0;
        i += n;
        while (i > 1)
        {
            ret += sgt[i];
            i /= 2;
        }
        return ret;
    }

    void add_sum(int i, int x)
    {
        i += n;
        sgt[i] += x;
        while (i > 1)
        {
            i /= 2;
            sgt[i] = sgt[2 * i] + sgt[2 * i + 1];
        }
    }

    void update_sum(int a, int b, int x = 1, int k = 1, int l = 0, int r = -1) //閉区間 l <= x < r とする
    {
        if (r == -1)
            r = n;
        if (r <= a || b <= l)
            return;
        if (a == l && b == r)
            sgt[k] += x;
        else
        {
            update_sum(a, min(b, (l + r) / 2), x, 2 * k, l, (l + r) / 2);
            update_sum(max(a, (l + r) / 2), b, x, 2 * k + 1, (l + r) / 2, r);
        }
    }

    void printsegtree()
    {
        for (int i = 0; i < 2 * n; i++)
        {
            cout << sgt[i] << " ";
        }
        cout << endl;
    }
};



#define DEBUG

int main()
{

    // cin.tie(0);
    // ios::sync_with_stdio(false);

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    return 0;
}
