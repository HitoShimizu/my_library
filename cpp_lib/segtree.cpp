#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <functional>

using namespace std;
typedef long long ll;

#define DEBUG

template <typename T>
class Segtree // 0-index 抽象化セグ木
{

    vector<T> sgt;
    int n;
    int k;
    T e;
    function<T(T, T)> update_one;
    // update function
    function<T(T, T)> operation;

   public:
    Segtree(int n1, function<T(T, T)> _operation, function<T(T, T)> _update, T _e)
    {
        int na = 1;
        int ka = 0;
        e = _e;
        operation = _operation;
        update_one = _update;
        while (na < n1)
        {
            na *= 2;
            ka++;
        }
        for (int i = 0; i < 2 * na; i++)
            sgt.push_back(e);
        n = na;
        k = ka;
    }

    void update(int i, T x)
    {
        i += n;
        sgt[i] = update_one(sgt[i], x);
        while (i > 1)
        {
            i /= 2;
            sgt[i] = operation(sgt[2 * i], sgt[2 * i + 1]);
        }
    }

    T query(int a, int b, int k = 1, int l = 0, int r = -1) //閉区間 l <= x < r とする
    {
        if (r == -1)
            r = n;
        if (r <= a || b <= l)
            return e;
        if (a == l && b == r)
            return sgt[k];
        else
            return operation(query(a, min(b, (l + r) / 2), 2 * k, l, (l + r) / 2), query(max(a, (l + r) / 2), b, 2 * k + 1, (l + r) / 2, r));
    }


    T operator[](int i){
        return sgt[i + n];
    }

    // void printsegtree()
    // {
    //     for (int i = 0; i < 2 * n; i++)
    //     {
    //         cout << sgt[i] << " ";
    //     }
    //     cout << endl;
    // }
};

int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    int n, q, k, c, x, y;
    cin >> n >> q;
    RangeMinorMaxorSumQuery segtree(n, 0);

    for (int i = 0; i < q; i++)
    {
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