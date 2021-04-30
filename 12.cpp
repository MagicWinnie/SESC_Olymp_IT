#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool check(string s)
{
    int counter = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            counter++;
        else
            counter--;
        if (counter < 0)
            return false;
    }
    return counter == 0;
}

string get_unique(string s)
{
    string out;
    map<char, int> m;

    for (int i = 0; i < s.length(); i++)
    {
        m[s[i]]++;
    }

    for(map<char, int>::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        out += iter->first;
    }
    return out;
}

int main()
{
    string s;
    cin >> s;
    cout << "IMPOSSIBLE" << endl;
    // string unique = get_unique(s);
    // string s1 = s;
    // replace(s1.begin(), s1.end(), unique[0], '(');
    // replace(s1.begin(), s1.end(), unique[1], ')');

    // string s2 = s;
    // replace(s2.begin(), s2.end(), unique[1], '(');
    // replace(s2.begin(), s2.end(), unique[0], ')');

    // bool res1 = check(s1);
    // bool res2 = check(s2);

    // if (res1)
    // {
    //     cout << s1 << endl;
    // }
    // else if (res2)
    // {
    //     cout << s2 << endl;
    // }
    // else
    // {
    //     cout << "IMPOSSIBLE" << endl;
    // }
}