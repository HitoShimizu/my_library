#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <math.h>
using namespace std;
typedef long long ll;

struct card;
int linersearch(int a[], int n, int x);
void insetrtionsort(int a[], int n);
void printcard(int n, card a[]);
void babblesort(int n, card a[]);
void selectionsort(int n, card a[]);
void countingsort(int n, int a[]);
void minimumcostsort(int n, int a[]);
string comparecardsarray(card a[], card b[]);

struct card
{
    char surt;
    int value;
};

void printcard(int n, card a[])
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i].surt << a[i].value;
        if (i != n - 1)
            cout << " ";
    }
    cout << endl;
}

void babblesort(int n, card a[])
{
    int flag = 1;
    while (flag)
    {
        flag = 0;
        for (int j = n - 1; j > 0; j--)
        {
            if (a[j].value < a[j - 1].value)
            {
                swap(a[j], a[j - 1]);
                flag = 1;
            }
        }
    }
    printcard(n, a);
}

void selectionsort(int n, card a[])
{
    int minj;
    for (int i = 0; i < n; i++)
    {
        minj = i;
        for (int j = i; j < n; j++)
        {
            if (a[j].value < a[minj].value)
                minj = j;
        }
        if (i != minj)
        {
            swap(a[minj], a[i]);
        }
    }
    printcard(n, a);
}

string comparecardsarray(card a[], card b[], int n)
{
    string ret;
    int check = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].surt == b[i].surt && a[i].value == b[i].value)
            check++;
    }
    if (check == n)
        ret = "Stable";
    else
        ret = "Not stable";
    return ret;
}

int main()
{
    int n;
    string s;
    cin >> n;
    card a[n], b[n], c[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        a[i].surt = s[0];
        a[i].value = s[1] - '0';
        b[i] = a[i];
        c[i] = a[i];
    }
    babblesort(n, b);
    cout << "Stable" << endl;
    selectionsort(n, c);
    cout << comparecardsarray(b, c, n) << endl;
    return 0;
}
