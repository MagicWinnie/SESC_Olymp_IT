// Mix the company with numbers
#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <vector>
#include <locale>

using namespace std;

map<int, string> d2c{{2, "ABC"}, {3, "DEF"}, {4, "GHI"}, {5, "JKL"}, {6, "MN"}, {7, "PRS"}, {8, "TUV"}, {9, "WXY"}, {0, "OQZ"}};

int main()
{
    string name;
    cin >> name;

    string num;
    cin >> num;

    int n1 = name.length() + 1;
    int n2 = num.size() + 1;

    vector<vector<int>> arr(n1, vector<int>(n2));

    for (int i = 0; i < n1; i++)
        arr[i][0] = i;

    for (int i = 0; i < n2; i++)
        arr[0][i] = i;

    for (int i = 1; i < n1; i++)
        for (int j = 1; j < n2; j++)
        {
            if (d2c[num[i - 1] - '0'].find(name[j - 1]) != string::npos)
                arr[i][j] = min(min(arr[i - 1][j] + 1, arr[i][j - 1] + 1), arr[i - 1][j - 1]);
            else
                arr[i][j] = min(arr[i - 1][j] + 1, arr[i][j - 1] + 1);
        }

    int i = n1 - 1, j = n2 - 1;

    while (i >= 0 && j >= 0)
    {
        if (arr[i][j] - arr[max(0, i - 1)][j] == 1)
        {
            name.insert(j, 1, num[i - 1]);
            i--;
        }
        else if (arr[i][j] - arr[i][max(j - 1, 0)] == 1)
        {
            name.erase(j - 1, 1);
            j--;
        }
        else
        {
            i--;
            j--;
        }
    }

    int count = 0;
    for (char &c : name)
    {
        count += isalpha(c);
    }
    cout << count << endl;
    // cout << arr[n1 - 1][n2 - 1] << endl;
    return 0;
}