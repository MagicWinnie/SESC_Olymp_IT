#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

double round_up(double value, int decimal_places)
{
    const double multiplier = std::pow(10.0, decimal_places);
    return std::ceil(value * multiplier) / multiplier;
}

bool cmp(vector<double> a, vector<double> b)
{
    return a[1] < b[1] || (abs(a[1] - b[1]) < 10e-2 && (a[3] < b[3])) || 
    (abs(a[1] - b[1]) < 10e-2 && abs(a[3] - b[3]) < 10e-2 && a[2] < b[2]); // || 
    //(abs(a[1] - b[1]) < 10e-3 && abs(a[3] - b[3]) < 10e-3 && abs(a[2] < b[2]) < 10e-3 && a[0] < b[0]);
}

void bubbleSort(vector<vector<double>> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if ((arr[j][0] - arr[j + 1][0]) > 10e-6)
                swap(arr[j], arr[j + 1]);
}

int main()
{
    int n, num = 78;
    float a, b, c, d;
    cin >> n;

    vector<vector<double>> mymap;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c >> d;
        mymap.push_back({a, b, c, d});
        // vector<float> temp{a, b, c, d};
        // mymap[a * pow((float)n, b) * pow(c, (float)n) * pow(log((float)n), d)] = temp;
    }

    stable_sort(mymap.begin(), mymap.end(), cmp);
    // bubbleSort(mymap);

    // for (int i = 0; i < mymap.size(); i++)
    // {
    //     cout << mymap[i][0] << " ";
    // }
    // cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << mymap[i][0] << " " << mymap[i][1] << " " << mymap[i][2] << " " << mymap[i][3] << endl;
    }
}