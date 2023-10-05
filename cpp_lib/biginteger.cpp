
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using VI = vector<int>;
using VL = vector<ll>;
using VS = vector<string>;
using VVI = vector<VI>;
using VVL = vector<VL>;
using PII = std::pair<int, int>;
using PLL = std::pair<ll, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define rep3(i, s, n, d) for (int i = (s); i < (int)(n); i += (d))
#define allpt(v) (v).begin(), (v).end()
#define allpt_c(v) (v).cbegin(), (v).cend()
#define allpt_r(v) (v).rbegin(), (v).rend()

const int mod = 1e9 + 7, mod2 = 998244353, mod3 = 1e9 + 9;
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

VL cumsum(const VL &v)
{
    int s = 0;
    VL ret = {0};

    rep(i, v.size())
    {
        s += v[i];
        ret.push_back(s);
    }
    return ret;
}

bool iskadomatsu(int a, int b, int c)
{
    return (a != b && b != c && c != a) && ((a > b && b < c) || (a < b && b > c));
}

const int maxlonginteger = 500000;
class LongInteger
{
    VI digit;
    int sign;

public:
    LongInteger()
    {
        digit.resize(maxlonginteger);
        fill(allpt(digit), 0);
        sign = 0;
    }
    LongInteger(const string &s)
    {
        digit.resize(maxlonginteger);
        fill(allpt(digit), 0);
        sign = 0;
        if (s[0] == '-')
        {
            sign = -1;
            rep(i, s.length() - 1)
                digit[maxlonginteger - s.length() + i + 1] = s[i + 1] - '0';
        }
        else
        {
            rep(i, s.length())
                digit[maxlonginteger - s.length() + i] = s[i] - '0';
        }
    }

    LongInteger(const int insign, const VI &indigit)
    {
        digit.resize(maxlonginteger);
        rep(i, maxlonginteger)
            digit[i] = indigit[i];
        sign = insign;
    }

    bool absequal(LongInteger a)
    {
        bool ret{true};
        rep(i, maxlonginteger)
        {
            ret &= (digit[i] == a.digit[i]);
        }
        return ret;
    }
    bool absgreat(LongInteger a)
    {
        bool ret{false};
        rep(i, maxlonginteger)
        {
            if (digit[i] < a.digit[i])
                break;
            else if (digit[i] > a.digit[i])
            {
                ret = true;
                break;
            }
        }
        return ret;
    }

    bool absgt(LongInteger a)
    {
        return absgreat(a) || absequal(a);
    }

    bool absless(LongInteger a)
    {
        bool ret{false};
        rep(i, maxlonginteger)
        {
            if (digit[i] > a.digit[i])
                break;
            else if (digit[i] < a.digit[i])
            {
                ret = true;
                break;
            }
        }
        return ret;
    }

    bool abslt(LongInteger a)
    {
        return absless(a) || absequal(a);
    }

    void printlonginteger()
    {
        bool zero{true};
        if (sign == -1)
            cout << '-';
        rep(i, maxlonginteger)
        {
            if (zero && digit[i] != 0)
                zero = false;
            if (!zero)
                cout << digit[i];
        }
        if (zero)
            cout << 0;
        cout << rt;
    }

    LongInteger operator+(LongInteger a)
    {
        int outsign;
        VI outdigit(maxlonginteger, 0);
        LongInteger ret;

        if (sign == a.sign)
        {
            outsign = sign;
            repr(i, maxlonginteger)
            {
                outdigit[i] = outdigit[i] + digit[i] + a.digit[i];
                if (i != 0)
                    outdigit[i - 1] += outdigit[i] / 10;
                outdigit[i] %= 10;
            }
        }
        else if (sign == 0 && a.sign == -1)
        {
            if (absgt(a))
            {
                outsign = 0;
                repr(i, maxlonginteger)
                {
                    if (i != 0 && digit[i] < a.digit[i])
                    {
                        digit[i] += 10;
                        digit[i - 1] -= 1;
                    }
                    outdigit[i] = digit[i] - a.digit[i];
                }
            }
            else
            {
                outsign = -1;
                repr(i, maxlonginteger)
                {
                    if (i != 0 && a.digit[i] < digit[i])
                    {
                        a.digit[i] += 10;
                        a.digit[i - 1] -= 1;
                    }
                    outdigit[i] = a.digit[i] - digit[i];
                }
            }
        }
        else if (sign == -1 && a.sign == 0)
        {
            if (abslt(a))
            {
                outsign = 0;
                repr(i, maxlonginteger)
                {
                    if (i != 0 && a.digit[i] < digit[i])
                    {
                        a.digit[i] += 10;
                        a.digit[i - 1] -= 1;
                    }
                    outdigit[i] = a.digit[i] - digit[i];
                }
            }
            else
            {

                outsign = -1;
                repr(i, maxlonginteger)
                {
                    if (i != 0 && digit[i] < a.digit[i])
                    {
                        digit[i] += 10;
                        digit[i - 1] -= 1;
                    }
                    outdigit[i] = digit[i] - a.digit[i];
                }
            }
        }

        ret = LongInteger(outsign, outdigit);
        return ret;
    }

    LongInteger operator-(LongInteger a)
    {
        int outsign;
        VI outdigit(maxlonginteger, 0);
        LongInteger ret;

        if (a.sign == -1)
            a.sign = 0;
        else if (a.sign == 0 && count(allpt_c(a.digit), 0) != maxlonginteger)
            a.sign = -1;
        ret = *this + a; 
    
        return ret;
    }
};

#define DEBUG

int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    string a, b;
    cin >> a >> b;
    LongInteger lia(a), lib(b), lic;
    lic = lia - lib;
    lic.printlonginteger();

    return 0;
}
