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
#define allpt_r(v) (v).rbegin(), (v).rend()

#define DEBUG

const int mod = 1e9 + 7;
const string wsp = " ";
const string tb = "\t";
const string rt = "\n";

template <typename T>
void show1dvec(vector<T> v)
{
    int n = v.size() - 1;
    rep(i, n) cout << v[i] << wsp;
    cout << v[n] << rt;
    return;
}

template <typename T>
void show2dvec(vector<vector<T>> v)
{
    int n = v.size();
    rep(i, n) show1dvec(v[i]);
}

template <typename T>
void cum_2d(int m, vector<vector<T>> &v)
{
    ll s;
    rep(i, m)
    {
        s = 0;
        rep(j, m)
        {
            s += v[i + 1][j + 1];
            v[i + 1][j + 1] = s;
        }
    }
    rep(j, m)
    {
        s = 0;
        rep(i, m)
        {
            s += v[i + 1][j + 1];
            v[i + 1][j + 1] = s;
        }
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
