#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;

int linersearch(int a[], int n, int x);
void insetrtionsort(int a[], int n);
void printarray(int n, int a[]);
void babblesort(int n, int a[]);
void selectionsort(int n, int a[]);
void countingsort(int n, int a[]);
void minimumcostsort(int n, int a[]);

int linersearch(int a[], int n, int x)
{
    int ret = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == x)
        {
            ret = 1;
            break;
        }
    }
    return ret;
}

void insetrtionsort(int a[], int n)
{
    int j, v;
    for (int i = 1; i < n; i++)
    {
        v = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}

void babblesort(int n, int a[])
{
    int flag = 1;
    int counter = 0;
    int tmp;
    while (flag)
    {
        flag = 0;
        for (int j = n - 1; j > 0; j--)
        {
            if (a[j] < a[j - 1])
            {
                swap(a[j], a[j - 1]);
                counter++;
                flag = 1;
            }
        }
    }
    printarray(n, a);
    cout << counter << endl;
}

void selectionsort(int n, int a[])
{
    int minj;
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        minj = i;
        for (int j = i; j < n; j++)
        {
            if (a[j] < a[minj])
                minj = j;
        }
        if (i != minj)
        {
            swap(a[minj], a[i]);
            counter++;
        }
    }
    printarray(n, a);
    cout << counter << endl;
}

void countingsort(int n, int a[])
{
    int b[n] = {};
    int k = 0;
    for (int i = 0; i < n; i++)
        k = max(a[i], k);
    int c[k + 1] = {};
    for (int i = 0; i < n; i++)
        c[a[i]]++;
    for (int i = 1; i < k + 1; i++)
        c[i] += c[i - 1];
    for (int i = n - 1; i > -1; i--)
    {

        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }
    printarray(n, b);
}

void minimumcostsort(int n, int a[])
{
    int maxa, maxindex, cost;
    cost = 0;
    for (int i = n - 1; i > 0; i--)
    {
        maxa = a[0];
        maxindex = 0;
        for (int j = 1; j <= i; j++)
        {
            if (a[j] > maxa)
            {
                maxa = a[j];
                maxindex = j;
            }
        }
        if (maxindex != i)
        {
            cost += maxa + a[i];
            swap(a[maxindex], a[i]);
        }
    }
    cout << cost << endl;
    printarray(n, a);
}

void printarray(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
        if (i != n - 1)
            cout << " ";
    }
    cout << endl;
}

int gcd(int a, int b)
{
    if (a < b)
    {
        int t = a;
        a = b;
        b = t;
    }
    cout << a << " " << b << endl;
    if (b == 0)
        return a;
    else
        return gcd(b, b % a);
}

ll fib(int x)
{
    ll a[x + 1] = {};
    a[0] = 1, a[1] = 1;
    if (x >= 2)
    {
        for (int i = 2; i < x + 1; i++)
        {
            a[i] = a[i - 1] + a[i - 2];
        }
    }
    return a[x];
}

int lcs(string s, string t)
{
    int la = s.size();
    int lb = t.size();
    int lcs[la + 1][lb + 1] = {};
    for (int i = 0; i < la; i++)
    {
        for (int j = 0; j < lb; j++)
        {
            if (s[i] == t[j])
            {
                lcs[i + 1][j + 1] = lcs[i][j] + 1;
            }
            else
            {
                lcs[i + 1][j + 1] = max(lcs[i][j + 1], lcs[i + 1][j]);
            }
        }
    }

    return lcs[la][lb];
}

int main()
{
    int q, m, ans;
    string s, t;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> s >> t;
        cout << lcs(s, t) <<endl;
    }
    return 0;
}
