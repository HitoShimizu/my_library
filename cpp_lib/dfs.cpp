#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define DEBUG

int set_time = 1;
const int maxint = 1000;
struct timestamp;
vector<int> color;
vector<timestamp> ts;
vector< vector<int> > connective;

struct timestamp
{
    int node;
    int discoverry_time;
    int terminate_time;
};

void init_ts(int n, timestamp *a)
{
    a->node = n;
    a->discoverry_time = -1;
    a->terminate_time = -1;
}

void disp_ts(timestamp a)
{
    cout << a.node + 1 << " " << a.discoverry_time << " " << a.terminate_time << endl;
}

void dfs(int x, timestamp *a, vector<int> v)
{
    color[x] = 1;
    a->discoverry_time = set_time;
    set_time++;
    for (auto itr = v.begin(); itr != v.end(); itr++)
    {   
        if (color[*itr] == -1)
            dfs(*itr, &ts[*itr], connective[*itr]);
    }

    a->terminate_time = set_time;
    set_time++;
    
}

int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    int n, v, k, x;
    cin >> n;
    timestamp tsi;
    connective.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v >> k;
        color.push_back(-1);
        init_ts(i, &tsi);
        ts.push_back(tsi);
        for (int j = 0; j < k; j++)
        {
            cin >> x;
            connective[i].push_back(x-1);
        }
        
    }
    for (int i = 0; i < n; i++){
        if (color[i] == -1)
            dfs(i, &ts[i], connective[i]);
    }

    for_each(ts.begin(), ts.end(), disp_ts);

    return 0;
}


// getline(cin,s);
// a = strtok(s, ",");  ","で分解
// for (int i = 0; i < n; i++)