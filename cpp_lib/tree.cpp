#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;

class tree;

class tree
{
    int id;
    int parentid = -1;
    int depth = 0;
    string status = "root";
    vector<int> children;

public:
    tree()
    {
        int n, v;
        cin >> id >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> v;
            children.push_back(v);
        }
    }

    void printtree()
    {
        printf("node %d: parent = %d, depth = %d, ", id, parentid, depth);
        cout << status << ", [";
        for (auto itr = children.begin(); itr != children.end(); itr++)
        {
            if (itr == children.begin())
                cout << *itr;
            else
                cout << ", " << *itr;
        }
        cout << "]\n";
    }

    int getid()
    {
        return id;
    }

    int setdepth(tree a[])
    {
        if (parentid == -1)
        {
            depth = 0;
            return depth;
        }
        else
        {

            depth = a[parentid].setdepth(a) + 1;
            return depth;
        }
    }

    void setparent(int p)
    {
        parentid = p;
    }

    void getchildren(tree a[])
    {
        int next, vs;
        vs = children.size();
        for (auto itr = children.begin(); itr != children.end(); itr++)
        {
            next = *itr;
            a[next].setparent(id);
        }
    }

    void treesearch()
    {

        if (parentid != -1)
        {
            if (children.size() == 0)
                status = "leaf";
            else
                status = "internal node";
        }
    }
};

void babblesort(int n, tree a[])
{
    int flag = 1;
    while (flag)
    {
        flag = 0;
        for (int j = n - 1; j > 0; j--)
        {
            if (a[j].getid() < a[j - 1].getid())
            {
                swap(a[j], a[j - 1]);
                flag = 1;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    tree nodes[n];
    babblesort(n, nodes);
    for (int i = 0; i < n; i++)
    {
        nodes[i].getchildren(nodes);
    }

    for (int i = 0; i < n; i++)
    {
        nodes[i].treesearch();
    }

    for (int i = 0; i < n; i++)
    {
        nodes[i].setdepth(nodes);
        nodes[i].printtree();
    }
    return 0;
}
