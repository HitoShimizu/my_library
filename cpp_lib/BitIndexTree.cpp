#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

// #define DEBUG

template <typename T>
class Bit_Index_Tree {
    int n = 0;
    vector<T> v;

   public:
    Bit_Index_Tree(int _n, T x = 0) {
        n = _n;
        v.resize(n + 1);
        fill(allpt(v), x);
    }
    Bit_Index_Tree(vector<T> _v) {
        n = _v.size();
        v = _v;
    }
    void add(int i, T x) {
        while (i <= n) {
            v[i] += x;
            i += i & -i;
        }
    }
    T get_sum(int i) {
        T ret = 0;
        while (i > 0) {
            ret += v[i];
            i -= i & -i;
        }
        return ret;
    }

    T get_range_sum(int l, int r) {  // l <= x < r
        return get_sum(r) - get_sum(l - 1);
    }
};
