#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct node
{
    node() : ind(-1), weight(-1), count(-1) {}
    node(int a, long long b, long long c) : ind(a), weight(b), count(c) {}
    int ind;
    long long weight, count;
};

int main()
{
    long long n, m, w, temp_1, temp_2, min_bullet = LLONG_MAX, min_health = LLONG_MAX;
    vector<node> bullets, health;

    cin >> n >> m >> w;

    for (int i = 0; i < n; i++)
    {
        cin >> temp_1 >> temp_2;
        min_bullet = min(temp_1, min_bullet);
        bullets.push_back(node(i, temp_1, temp_2));
    }

    for (int i = 0; i < m; i++)
    {
        cin >> temp_1 >> temp_2;
        min_health = min(temp_1, min_health);
        health.push_back(node(i, temp_1, temp_2));
    }
    if (min_bullet + min_health > w)
    {
        cout << "DIE" << endl;
        return 0;
    }

    sort(bullets.begin(), bullets.end(), [&](node a, node b) { return a.count < b.count || (a.count == b.count && a.weight > b.weight); });
    sort(health.begin(), health.end(), [&](node a, node b) { return a.count < b.count || (a.count == b.count && a.weight > b.weight); });

    // cout << "BULLETS:" << endl;
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     cout << bullets[i].ind << " " << bullets[i].weight << " " << bullets[i].count << endl;
    // }
    // cout << "HEALTH:" << endl;
    // for (int i = m - 1; i >= 0; i--)
    // {
    //     cout << health[i].ind << " " << health[i].weight << " " << health[i].count << endl;
    // }

    struct node b, h;
    int i = n - 1, j = m - 1;
    while (i >= 0 || j >= 0)
    {
        // cout << i << " " << j << endl;
        if (bullets[i].weight + health[j].weight <= w)
        {
            b = bullets[i];
            h = health[j];
            break;
        }
        else
        {
            if (bullets[i - 1].weight < health[j - 1].weight)
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    cout << "SURVIVE" << endl;
    cout << b.weight + h.weight << " " << b.count + h.count << endl;
    cout << b.ind + 1 << " " << h.ind + 1 << endl;
}

/*
2 3 80
10 100
20 150
50 50
60 50
55 60
*/
/*
2 3 65
10 100
20 150
50 50
60 50
55 60
*/
//WAAWWAWWAWWWAWAAWWAW 40
//AAAWWAWPAAWAAWAAWAAW 60
//   11 1   1  1  1  1 intersection
