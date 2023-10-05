#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define DEBUG

const int maxint = 1e9;
struct timestamp;
vector<int> shortest, indeg;
vector<vector<int>> connective;

void dag(int n)
{
    vector<int> search;
    vector<int> new_search;

    for (int i = 0; i < n; i++)
    {

        if (indeg[i] == 0)
        {
            search.push_back(i);
            cout << i << endl;
        }
    }
    while (!search.empty())
    {
        for (auto itr = search.begin(); itr != search.end(); itr++)
        {
            for (auto itr2 = connective[*itr].begin(); itr2 != connective[*itr].end(); itr2++)
            {
                indeg[*itr2] -= 1;
                if (indeg[*itr2] == 0)
                {
                    new_search.push_back(*itr2);
                    indeg[*itr2] = -1;
                    cout << *itr2 << endl;
                }
            }
        }
        search.clear();
        search = new_search;
        new_search.clear();
    }
}

/* 頂点の入次数が0のものを順次探索*/
/* 探索で見つかった頂点の入次数を1減らして0になったら新たに探索*/

int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    int n, s, t, m, maxindex;
    cin >> n >> m;
    connective.resize(n);
    indeg.resize(n);
    for (int i = 0; i < n; i++)
    {
        shortest.push_back(maxint);
        indeg.push_back(0);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> s >> t;
        connective[s].push_back(t);
        indeg[t]++;
    }

    dag(n);

    return 0;
}

// getline(cin,s);
// a = strtok(s, ",");  ","で分解
// for (int i = 0; i < n; i++)
// for (int j = 0; j < m; j++)