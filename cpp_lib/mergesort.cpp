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
using namespace std;
typedef long long ll;

// #define DEBUG

int counter;
void my_margesort(int a[], int left, int right);

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

void merge(int a[], int left, int right, int middle)
{
    int const inf = 1e9 + 7;
    int n1 = middle - left;
    int n2 = right - middle;

    int leftarray[n1 + 1], rightarray[n2 + 1];
    for (int i = 0; i < n1; i++)
    {
        leftarray[i] = a[left + i];
    }
    leftarray[n1] = inf;

    for (int i = 0; i < n2; i++)
    {
        rightarray[i] = a[middle + i];
    }
    rightarray[n2] = inf;

    int i = 0, j = 0;
    for (int k = left; k < right; k++)
    {
        counter++;
        if (leftarray[i] <= rightarray[j])
        {
            a[k] = leftarray[i];
            i++;
        }
        else
        {
            a[k] = rightarray[j];
            j++;
        }
    }
}

void my_margesort(int a[], int left, int right)
{
    int middle;
    if (left + 1 < right)
    {
        middle = (left + right) / 2;
        my_margesort(a, left, middle);
        my_margesort(a, middle, right);
        merge(a, left, right, middle);
    }
}

int main()
{

#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf());    //for debug
#endif

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    my_margesort(a, 0, n);
    printarray(n, a);
    cout << counter << endl;

    return 0;
}

// getline(cin,s);
// a = strtok(s, ",");  ","で分解
// for (int i = 0; i < n; i++)