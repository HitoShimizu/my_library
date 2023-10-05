#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define DEBUG

const int inf = 1e9;
vector<tuple<int, int, int>> node_list;
vector<int> dist_list;


void bellman_ford(int r, int v)
{
    int x, y, z;
    bool negative_cycle_flag = false;
    vector<int> new_dist_list;
    vector<int> dist1, dist2;

    dist_list[r] = 0;

    for (int i = 0; i < v; i++)
    {
        new_dist_list = dist_list;
        for (auto w : node_list)
        {
            x = get<0>(w), y = get<1>(w), z = get<2>(w);
            if (new_dist_list[x] != inf)
                new_dist_list[y] = min(new_dist_list[y], dist_list[x] + z);
        }
        dist_list = new_dist_list;

        if (v > 1 && i == v - 2)
            dist1 = dist_list;
        if (v > 1 && i == v - 1)
            dist2 = dist_list;
    }
    if (v > 1)
        for (int i = 0; i < v; i++)
            if (dist1[i] != dist2[i])
                negative_cycle_flag = true;

    if (negative_cycle_flag)
        cout << "NEGATIVE CYCLE" << endl;
    else
        for (auto i : dist_list){
            if (i != inf)
                cout << i << endl;
            else
                cout << "INF" << endl;    
        }
    return;
};

int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    int v, e, r, s, t, d;
    cin >> v >> e >> r;
    dist_list.resize(v);
    fill(dist_list.begin(), dist_list.end(), inf);
    for (int i = 0; i < e; i++)
    {
        cin >> s >> t >> d;
        node_list.push_back(make_tuple(s, t, d));
    }
    bellman_ford(r, v);

    return 0;
}
