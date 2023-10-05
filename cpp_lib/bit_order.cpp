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

vector<int> make_bit_order(int n) {
    const int m = (1 << n);
    vector<pair<int, int>> order_pair(m);
    rep(i, m) order_pair[i].first = __builtin_popcount(i),
              order_pair[i].second = i;
    sort(allpt(order_pair));
    vector<int> ret(m);
    rep(i, m) ret[i] = order_pair[i].second;
    return ret;
}

int main() {
#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt");  // for debug
    cin.rdbuf(in.rdbuf());     // for debug
#endif

    ll const nmax = 101;
    VL frac_table(nmax, 1);
    VL frac_inv_table(nmax, 1);

    int s = 1, t = 1;
    rep2(i, 1, nmax) {
        frac_table[i] = (frac_table[i - 1] * i) % mod;
        frac_inv_table[i] =
            (frac_inv_table[i - 1] * pow_mod(i, mod - 2, mod)) % mod;
    }

    return 0;
}