#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <stack>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;

class bits
{
    int length = 64;
    bool bitarray[64] = {};

public:
    bits()
    {
        bool bitarray[64] = {};
    }

    void bittest(int i)
    {
        cout << bitarray[i] << endl;
    }

    void set_or_clear_or_flip_bits(vector<int> mask, int n = 0)
    {
        int ln = mask.size();
        for (int i = 0; i < ln; i++)
        {
            if (n == 0)
                bitarray[mask[i]] = 1;
            else if (n == 1)
                bitarray[mask[i]] = 0;
            else if (n == 2)
                bitarray[mask[i]] = bitarray[mask[i]] ^ 1;
        }
        cout << length << endl;
        for (int i = 0; i < length; i++)
            cout << bitarray[i];
        cout << endl;
    }

    void all_any_none_count_bits(vector<int> mask, int n = 0)
    {
        int ln = mask.size();
        int counter = 0;
        for (int i = 0; i < ln; i++)
        {
            if (bitarray[mask[i]] == 1)
                counter++;
        }
        if (n == 0)
            cout << ((counter == ln) ? 1 : 0) << endl;
        else if (n == 1)
            cout << ((counter != 0) ? 1 : 0) << endl;
        else if (n == 2)
            cout << ((counter == 0) ? 1 : 0) << endl;
        else if (n == 3)
            cout << counter << endl;
    }

    void make_integer(vector<int> mask)
    {
        int b = 1;
        bool bitarray2[64] = {};
        int ln = mask.size();
        for (int i = 0; i < ln; i++)
        {
            bitarray2[mask[i]] = bitarray[mask[i]]; 
        }
        ll ans = 0;
        for (int i = 0; i < length; i++)
        {
            ans += bitarray2[i] * b;
            b *= 2;
        }
        cout << ans << endl;
    }
};
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

void printbit(unsigned int x)
{
    unsigned int b, y;

    b = 32;
    int a[b];
    y = pow(2, 31);
    cin >> x;

    for (int i = 0; i < b; i++)
    {
        if (x >= y)
        {
            a[i] = 1;
            x -= y;
        }
        else
            a[i] = 0;

        y = y >> 1;
    }
    printarray(b, a);
}

int main()
{
    int n, m, x, q, op, mask;
    cin >> n;
    bits bitsarray;
    vector<int> mask_list[n];
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            mask_list[i].push_back(x);
        }
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> op >> mask;
        switch (op)
        {
        case 0:
            bitsarray.bittest(mask);
            break;
        case 1:
            bitsarray.set_or_clear_or_flip_bits(mask_list[mask], 0);
            break;
        case 2:
            bitsarray.set_or_clear_or_flip_bits(mask_list[mask], 1);
            break;
        case 3:
            bitsarray.set_or_clear_or_flip_bits(mask_list[mask], 2);
            break;
        case 4:
            bitsarray.all_any_none_count_bits(mask_list[mask], 0);
            break;
        case 5:
            bitsarray.all_any_none_count_bits(mask_list[mask], 1);
            break;
        case 6:
            bitsarray.all_any_none_count_bits(mask_list[mask], 2);
            break;
        case 7:
            bitsarray.all_any_none_count_bits(mask_list[mask], 3);
            break;
        case 8:
            bitsarray.make_integer(mask_list[mask]);
            break;
        }
    }
    return 0;
}

// getline(cin,s);
// a = strtok(s, ",");  ","で分解
// for (int i = 0; i < n; i++)