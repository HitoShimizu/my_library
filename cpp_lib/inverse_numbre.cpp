#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using VI = vector<int>;
using VL = vector<ll>;
using PII = std::pair<int, int>;
using PLL = std::pair<ll, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define allpt(v) (v).begin(), (v).end()
#define allpt_c(v) (v).cbegin(), (v).cend()
#define allpt_r(v) (v).rbegin(), (v).rend()

#define DEBUG

const int mod = 1e9 + 7;
const string wsp = " ";
const string tb = "\t";
const string rt = "\n";



ll getinv(VI v) {
    int n = v.size();
    ll ret{0};
    RangeMinorMaxorSumQuery<ll> sgt(n + 1, 0);
    for (auto x : v) {
        ret += sgt.get_sum(x + 1, n);
        sgt.add_sum(x, 1);
    }
    return ret;
}
