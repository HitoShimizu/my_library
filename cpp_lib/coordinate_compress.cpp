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

// 座標圧縮
// x：圧縮する座標列（ソートしてなくて良い）
// zip：座標関係を保持する連想配列
// xs：圧縮後の座標列の長さ、つまりユニークな座標の数
//圧縮時には両端の番兵（l，r）と合わせて使う


const int l = -2e9-10;
const int r = 2e9+10;
template <typename T>
void coordinate_compress(vector<T> &x, map<T, int> &zip, int &xs)
{
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    xs = x.size();
    for (int i = 0; i < xs; i++)
    {
        zip[x[i]] = i;
    }
}

int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    return 0;
}