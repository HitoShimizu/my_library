#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;

#define DEBUG

class RangeSumQueryWithDelay  // 0-index
{
    ll const intmax = 2147483647;
    ll const intmin = 0;
    ll const delaydefault = 2147483647;

    vector<ll> sgt;
    vector<ll> sgt_deray;
    int n;
    int k;

   public:
    RangeSumQueryWithDelay(int n1, int f = -1) {
        if (f == -1)
            f = intmax;
        else if (f == 0)
            f = intmin;
        int na = 1;
        int ka = 0;
        while (na < n1) {
            na *= 2;
            ka++;
        }
        for (int i = 0; i < 2 * na; i++) {
            sgt.push_back(f);
            sgt_deray.emplace_back(delaydefault);
        }
        n = na;
        k = ka;
    }

    void eval_update(int k, int l, int r) {
        if (sgt_deray[k] != delaydefault) {
            sgt[k] = sgt_deray[k];
            if (r - l > 1) {
                sgt_deray[2 * k] = sgt_deray[k] / 2;
                sgt_deray[2 * k + 1] = sgt_deray[k] / 2;
            }
            sgt_deray[k] = delaydefault;
        }
    }

    void range_update(int a, int b, ll x, int k = 1, int l = 0, int r = -1) {
        if (r == -1) r = n;
        eval_update(k, l, r);  //求める範囲とは違っても評価が行われることがある！
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            sgt_deray[k] = (r - l) * x;
            eval_update(k, l, r);
        } else {
            range_update(a, b, x, 2 * k, l, (l + r) / 2);
            range_update(a, b, x, 2 * k + 1, (l + r) / 2, r);
            sgt[k] = sgt[2 * k] + sgt[2 * k + 1];
        }
    }

    ll get_sum(int a, int b, int k = 1, int l = 0,
              int r = -1)  //閉区間 l <= x < r とする
    {
        if (r == -1) r = n;
        if (r <= a || b <= l) return intmin;
        eval_update(k, l, r);
        if (a <= l && r <= b) {
            return sgt[k];
        } else {
            ll v1 = get_sum(a, b, 2 * k, l, (l + r) / 2);
            ll v2 = get_sum(a, b, 2 * k + 1, (l + r) / 2, r);
            return v1 + v2;
        }
    }

    void printsegtree() {
        for (int i = 0; i < 2 * n; i++) {
            cout << sgt[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < 2 * n; i++) {
            cout << sgt_deray[i] << " ";
        }
        cout << endl;
    }
};

int main() {
#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt");  // for debug
    cin.rdbuf(in.rdbuf());     // for debug
#endif

    int n, q, k, c, x, y;
    cin >> n >> q;
    RangeSumQueryWithDelay segtree(n, 0);

    for (int i = 0; i < q; i++) {
        cin >> c >> x >> y;
        if (c == 0)
            segtree.add_sum(x - 1, y);
        else
            cout << segtree.get_sum(x - 1, y) << endl;
    }
    return 0;
}

// getline(cin,s);
// a = strtok(s, ",");  ","で分解
// for (int i = 0; i < n; i++)