#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int sieveEratos(int l, int n)
{
    vector<bool> a(n + 1, true);
    for (int i = 2; i * i <= n; i++)
    {
        if (a[i])
        {
            for (int j = i * i; j <= n; j += i)
                a[j] = false;
        }
    }
    int count = 0;
    for (int i = max(l, 2); i <= n; i++)
    {
        // cout << a[i] << " ";
        if (a[i] == true)
            count++;
    }
    // cout << endl;
    return count;
}

int main()
{
    int n, l, r;
    cin >> n;

    map<int, bool> prime;

    for (int i = 0; i < n; i++)
    {
        cin >> l >> r;
        cout << sieveEratos(l, r) << endl;
    }
}