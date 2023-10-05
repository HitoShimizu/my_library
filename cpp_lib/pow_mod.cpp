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


template <typename T, typename S, typename R>
ll pow_mod(T p, S q, R mod = 1ll)
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

void make_frac_tables(int n, VL &frac_list, VL &frac_inv_list)
{
    rep(i, n)
    {
        frac_list[i + 1] *= frac_list[i] * (i + 1);
        frac_list[i + 1] %= mod;
        frac_inv_list[i + 1] *= frac_inv_list[i] * pow_mod(i + 1, mod - 2, mod);
        frac_inv_list[i + 1] %= mod;
    }
}

ll comb(int a, int b, const VL &frac_list, const VL &frac_inv_list)
{
    if (a < b)
        return 0;
    ll ret = frac_list[a];
    ret *= frac_inv_list[b];
    ret %= mod;
    ret *= frac_inv_list[a - b];
    ret %= mod;
    return ret;
}

ll perm(int a, int b, const VL &frac_list, const VL &frac_inv_list)
{
    if (a < b)
        return 0;
    ll ret = frac_list[a];
    ret *= frac_inv_list[a - b];
    ret %= mod;
    return ret;
}

ll multset(int a, int b, const VL &frac_list, const VL &frac_inv_list)
{
    if (a == 0 && b == 0)
        return 1;
    return comb(a + b - 1, b, frac_list, frac_inv_list);
}

int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    ll const nmax = 101;
    VL frac_table(nmax, 1);
    VL frac_inv_table(nmax, 1);

    int s = 1, t = 1;
    rep2(i, 1, nmax)
    {
        frac_table[i] = (frac_table[i - 1] * i) % mod;
        frac_inv_table[i] = (frac_inv_table[i - 1] * pow_mod(i, mod - 2, mod)) % mod;
    }

    return 0;
}