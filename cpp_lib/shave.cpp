#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define DEBUG

void shave(vector<int> &v, int n) {
    if (n <= 1) return;
    vector<bool> w(n + 1, true);
    int x;
    w[0] = w[1] = false;
    rep2(i, 2, n + 1) {
        if (w[i]) {
            x = i * 2;
            while (x <= n) {
                w[x] = false;
                x += i;
            }
        }
    }
    rep(i, n + 1) if (w[i]) v.emplace_back(i);
}

int main() {
#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt");  // for debug
    cin.rdbuf(in.rdbuf());     // for debug
#endif
    const int Maxshave = 1e4;
    int n, s, ans;
    cin >> n;
    ans = 0;
    bool isprime;
    vector<int> v;
    shave(v, Maxshave);
    for (int i = 0; i < n; i++) {
        cin >> s;
        isprime = true;
        for (auto itr = v.begin(); itr != v.end(); itr++) {
            if (*itr == s)
                break;
            else if (s % *itr == 0) {
                isprime = false;
                break;
            }
        }
        if (isprime == true) ans += 1;
    }
    cout << ans << endl;
}

// getline(cin,s);
// a = strtok(s, ",");  ","で分解
// for (int i = 0; i < n; i++)