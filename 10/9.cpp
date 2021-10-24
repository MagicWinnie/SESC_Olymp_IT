#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// int calculate(int i, int j, int n)
// {
// }

// void smart(int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << calculate(i, j, n) << " ";
//         }
//         cout << endl;
//     }
// }

void perebor(int n)
{
    vector<vector<int>> arr(n, vector<int>(n));
    arr[0][0] = 1;
    int num = 2;
    int i = 0, j = 1;
    bool down = true;
    while (num <= n * n)
    {
        if (down)
        {
            while (j >= 0 && i < n )
            {
                // cout << "DOWN: " << i << " " << j << "; NUM: " << num <<  endl;
                arr[i][j] = num;
                j--;
                i++;
                num++;
            }
            // cout << "END DOWN: " << i << " " << j << "; NUM: " << num <<  endl;
            j++;
            if ( i >= n )
            {
                i = n - 1;
                j++;
            }
            down = false;
        } else {
            while (j < n && i >= 0)
            {
                // cout << "UP: " << i << " " << j << "; NUM: " << num <<  endl;
                arr[i][j] = num;
                j++;
                i--;
                num++;
            }
            // cout << "END UP: " << i << " " << j << "; NUM: " << num <<  endl;
            i++;
            if ( j >= n )
            {
                j = n - 1;
                i++;
            }
            down = true;
        }
        // if ( j < 0 || i < 0 || j >= n || i >= n) break;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    // smart(n);
    perebor(n);
}
// f(y, x, n) = a
// --------------
// f(1, 1, n) = 1
// f(1, 2, n) = 2
// f(1, 3, n) = 6
// f(1, 4, n) = 7
// f(1, 5, n) = 15
// f(n, n, n) = n^2