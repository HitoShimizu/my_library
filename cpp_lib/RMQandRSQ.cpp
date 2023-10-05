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

template <typename T>
class RangeMinorMaxorSumQuery  // 0-index
{
    int const intmax = 2147483647;
    int const intmin = 0;
    vector<T> sgt;
    int n;
    int k;

   public:
    RangeMinorMaxorSumQuery(int n1, int f = -1) {
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
        for (int i = 0; i < 2 * na; i++) sgt.push_back(f);
        n = na;
        k = ka;
    }

    void update_min(int i, int x) {
        i += n;
        sgt[i] = x;
        while (i > 1) {
            i /= 2;
            sgt[i] = min(sgt[2 * i], sgt[2 * i + 1]);
        }
    }
    void update_max(int i, T x) {
        i += n;
        sgt[i] = x;
        while (i > 1) {
            i /= 2;
            sgt[i] = max(sgt[2 * i], sgt[2 * i + 1]);
        }
    }
    void update_sum(int i, T x) {
        i += n;
        sgt[i] = x;
        while (i > 1) {
            i /= 2;
            sgt[i] = sgt[2 * i] + sgt[2 * i + 1];
        }
    }

    void add_sum(int i, T x) {
        i += n;
        sgt[i] += x;
        while (i > 1) {
            i /= 2;
            sgt[i] = sgt[2 * i] + sgt[2 * i + 1];
        }
    }

    void add_min(int i, T x) {
        i += n;
        sgt[i] += x;
        while (i > 1) {
            i /= 2;
            sgt[i] = min(sgt[2 * i], sgt[2 * i + 1]);
        }
    }

    void add_max(int i, T x) {
        i += n;
        sgt[i] += x;
        while (i > 1) {
            i /= 2;
            sgt[i] = max(sgt[2 * i], sgt[2 * i + 1]);
        }
    }

    T get_min(int a, int b, int k = 1, int l = 0,
              int r = -1)  //閉区間 l <= x < r とする
    {
        if (r == -1) r = n;
        if (r <= a || b <= l) return intmax;
        if (a == l && b == r)
            return sgt[k];
        else
            return min(
                get_min(a, min(b, (l + r) / 2), 2 * k, l, (l + r) / 2),
                get_min(max(a, (l + r) / 2), b, 2 * k + 1, (l + r) / 2, r));
    }
    T get_max(int a, int b, int k = 1, int l = 0,
              int r = -1)  //閉区間 l <= x < r とする
    {
        if (r == -1) r = n;
        if (r <= a || b <= l) return intmin;
        if (a == l && b == r)
            return sgt[k];
        else
            return max(
                get_max(a, min(b, (l + r) / 2), 2 * k, l, (l + r) / 2),
                get_max(max(a, (l + r) / 2), b, 2 * k + 1, (l + r) / 2, r));
    }
    T get_sum(int a, int b, int k = 1, int l = 0,
              int r = -1)  //閉区間 l <= x < r とする
    {
        if (r == -1) r = n;
        if (r <= a || b <= l) return intmin;
        if (a == l && b == r)
            return sgt[k];
        else
            return get_sum(a, min(b, (l + r) / 2), 2 * k, l, (l + r) / 2) +
                   get_sum(max(a, (l + r) / 2), b, 2 * k + 1, (l + r) / 2, r);
    }

    T operator[](int i) { return sgt[i + n]; }

    void printsegtree() {
        for (int i = 0; i < 2 * n; i++) {
            cout << sgt[i] << " ";
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
    RangeMinorMaxorSumQuery segtree(n, 0);

    for (int i = 0; i < q; i++) {
        cin >> c >> x >> y;
        if (c == 0)
            segtree.add_sum(x - 1, y);
        else
            cout << segtree.getsum(x - 1, y) << endl;
    }
    return 0;
}

// getline(cin,s);
// a = strtok(s, ",");  ","で分解
// for (int i = 0; i < n; i++)