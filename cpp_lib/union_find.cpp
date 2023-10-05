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

using namespace std;
typedef long long ll;

#define DEBUG

class Unionfind
{
    vector<int> p;

public:
    int find(int x);
    void unite(int x, int y);
    bool isunion(int x, int y);
    Unionfind(int n);
    void showtree();
};

Unionfind::Unionfind(int n)
{
    for (int i = 0; i < n; i++)
    {
        p.push_back(i);
    }
}
int Unionfind::find(int x)
{
    while (p[x] != x)
    {
        p[x] = p[p[x]];
        x = p[x];
    }
    return x;
}

void Unionfind::unite(int x, int y)
{
    x = Unionfind::find(x);
    y = Unionfind::find(y);
    if (x != y)
    {
        p[x] = y;
    }
}

bool Unionfind::isunion(int x, int y)
{
    return Unionfind::find(x) == Unionfind::find(y);
}

void Unionfind::showtree()
{
    for (int i = 0; i < p.size() - 1; i++)
    {
        cout << p[i] << " ";
    }
    cout << p[p.size() - 1] << "\n";
}

int main()
{
#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    int n, q, op, x, y, d;
    cin >> n >> q;
    int a[2 * n + 1];
    for (int i = 0; i <= 2 * n; i++)
    {
        a[i] = i;
    }

    for (int i = 0; i < q; i++)
    {
        cin >> op >> x >> y >> d;
        d %= 2;
        if (op == 1)
        {
            if (d == 1)
            {
                unite(a, x, n + y);
                unite(a, n + x, y);
            }
            else
            {
                unite(a, x, y);
                unite(a, n + x, n + y);
            }
        }
        else
        {
            cout << ((find(a, x) == find(a, y)) ? "YES" : "NO") << endl;
        }
    }

    return 0;
}

// getline(cin,s);
// a = strtok(s, ",");  ","で分解
// for (int i = 0; i < n; i++)