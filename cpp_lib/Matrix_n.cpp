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




class Matrix_n
{
    int matsize;
    VVL mat;

public:
    Matrix_n();
    Matrix_n(int n);
    Matrix_n(int n, const VVL &inmat);

    void showmat();
    void identify();
    ll getone(const int &i, const int &j);
    int getsize();
    const Matrix_n operator+(const Matrix_n &b);
    const Matrix_n operator-(const Matrix_n &b);
    const Matrix_n operator*(const Matrix_n &b);
    Matrix_n &operator+=(const Matrix_n &b);
    Matrix_n &operator-=(const Matrix_n &b);
    const Matrix_n operator+();
    const Matrix_n operator-();
    const Matrix_n operator%(const int &b);
    Matrix_n &operator%=(const int &b);
    
};

Matrix_n::Matrix_n()
{
    matsize = 0;
    VVL mat;
}

Matrix_n::Matrix_n(int n)
{
    matsize = n;
    mat.resize(n);
    rep(i, n) rep(j, n)
        mat[i]
            .emplace_back(0);
}

Matrix_n::Matrix_n(int n, const VVL &inmat)
{
    matsize = n;
    mat.resize(n);
    rep(i, n)
    {
        mat[i].resize(n);
        rep(j, n)
        {
            mat[i][j] = inmat[i][j];
        }
    }
}

void Matrix_n::identify()
{
    rep(i, matsize) rep(j, matsize)
    {
        mat[i][j] = i == j ? 1 : 0;
    }
}

ll Matrix_n::getone(const int &i, const int &j)
{
    return mat[i][j];
}

int Matrix_n::getsize()
{
    return matsize;
}

const Matrix_n Matrix_n::operator+(const Matrix_n &b)
{
    Matrix_n ret(matsize);
    rep(i, matsize) rep(j, matsize)
    {
        ret.mat[i][j] = mat[i][j] + b.mat[i][j];
    }
    return ret;
}

const Matrix_n Matrix_n::operator-(const Matrix_n &b)
{
    Matrix_n ret(matsize);
    rep(i, matsize) rep(j, matsize)
    {
        ret.mat[i][j] = mat[i][j] - b.mat[i][j];
    }
    return ret;
}

const Matrix_n Matrix_n::operator*(const Matrix_n &b)
{
    Matrix_n ret(matsize);
    rep(i, matsize) rep(j, matsize) rep(k, matsize)
    {
        ret.mat[i][j] += mat[i][k] * b.mat[k][j];
    }
    return ret;
}

const Matrix_n Matrix_n::operator%(const int &b)
{
    Matrix_n ret(matsize);
    rep(i, matsize) rep(j, matsize)
    {
        ret.mat[i][j] = mat[i][j] % b;
    }
    return ret;
}

const Matrix_n Matrix_n::operator+()
{
    return *this;
}

const Matrix_n Matrix_n::operator-()
{
    Matrix_n ret(matsize);
    rep(i, matsize) rep(j, matsize)
    {
        ret.mat[i][j] = -mat[i][j];
    }
    return ret;
}

Matrix_n &Matrix_n::operator+=(const Matrix_n &b)
{
    rep(i, matsize) rep(j, matsize)
    {
        mat[i][j] += b.mat[i][j];
    }
    return *this;
}

Matrix_n &Matrix_n::operator-=(const Matrix_n &b)
{
    rep(i, matsize) rep(j, matsize)
    {
        mat[i][j] -= b.mat[i][j];
    }
    return *this;
}

Matrix_n &Matrix_n::operator%=(const int &b)
{
    rep(i, matsize) rep(j, matsize)
    {
        mat[i][j] %= b;
    }
    return *this;
}

Matrix_n mat_pow_mod(Matrix_n a, ll p, ll m)
{
    const int n = a.getsize();
    Matrix_n b(n);
    b.identify();

    while(p > 0)
    {
        if (p % 2)
        {
            b = b * a;
            b %= m;
        }
        p /= 2;
        a = a * a;
        a %= m;
    }
    return b;
}

void Matrix_n::showmat()
{
    cout << mat;
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

    const VVL a = {{100, 1}, {0, 1}};
    ll n, x;
    cin >> n;
    x = n - 1;
    Matrix_n p(2), q(2, a);
    p.identify();

    rep(i, 100)
    {
        if (x % 2 == 1)
        {
            p = p * q;
            p %= mod;
        }
        x /= 2;
        if (x == 0)
        {
            break;
        }
        q = q * q;
        q %= mod;
    }

    cout << (p.getone(0, 0) + p.getone(0, 1)) % mod << rt;
    ;

    n %= 11;
    if (n == 0)
    {
        cout << 0 << rt;
        return 0;
    }
    string r = "1";
    rep(i, n - 1)
    {
        r += "01";
    }
    cout << r << rt;

    return 0;
}
