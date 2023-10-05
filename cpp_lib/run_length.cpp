#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using PII = std::pair<int, int>;
using PLL = std::pair<ll, ll>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define DEBUG

vector<int> run_length(int n)
{
    int prev, next, counter;
    vector<int> ret;

    cin >> next;
    prev = next;
    counter = 1;
    rep(i, n - 1)
    {
        cin >> next;
        if (next == prev)
            counter++;
        else
        {
            ret.push_back(counter);
            counter = 1;
        }

        if (i == n - 2)
            ret.push_back(counter);
        prev = next;
    }
    return ret;
}

pair<vector<int>, vector<int>> run_length(int n) {
    int prev, next, counter{1};
    vector<int> value;
    vector<int> length;

    if (n == 1) {
        cin >> prev;
        length.push_back(counter);
        value.push_back(prev);
        return make_pair(value, length);
    }
    cin >> next;
    prev = next;
    rep(i, n - 1) {
        cin >> next;
        if (next == prev)
            counter++;
        else {
            length.push_back(counter);
            value.push_back(prev);
            counter = 1;
        }
        if (i == n - 2) {
            length.push_back(counter);
            value.push_back(next);
        }
        prev = next;
    }
    return make_pair(value, length);
}

vector<pair<char, int>> run_length(string s) {
    vector<pair<char, int>> ret;
    int counter = 1;
    char c = s[0];
    int n = s.length();
    if (n == 1) {
        ret.emplace_back(make_pair(c, counter));
        return ret;
    }
    rep2(i, 1, n) {
        if (c != s[i]) {
            ret.emplace_back(make_pair(c, counter));
            c = s[i];
            counter = 1;
        } else {
            counter++;
        }
        if (i == n - 1) {
            ret.emplace_back(make_pair(c, counter));
        }
    }
    return ret;
}

int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif


    return 0;
}