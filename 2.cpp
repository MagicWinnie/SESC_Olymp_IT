#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <map>

using namespace std;

struct Point
{
    Point() : x(0.0), y(0.0) {}
    Point(double a, double b) : x(a), y(b) {}
    double x;
    double y;
};

// CHECKING FOR INSIDE SOLUTIONS
bool is_point_in_polygon(vector<Point> vert, Point test)
{
    int i, j, nvert = vert.size();
    bool c = false;
    for (i = 0, j = nvert - 1; i < nvert; j = i++)
    {
        if (((vert[i].y > test.y) != (vert[j].y > test.y)) &&
            (test.x < (vert[j].x - vert[i].x) * (test.y - vert[i].y) / (vert[j].y - vert[i].y) + vert[i].x))
            c = !c;
    }
    return c;
}

bool is_first_inside(vector<Point> one, vector<Point> two)
{
    for (int i = 0; i < one.size(); i++)
    {
        bool t = is_point_in_polygon(two, one[i]);
        if (!t)
            return false;
    }
    return true;
}

bool is_second_inside(vector<Point> one, vector<Point> two)
{
    for (int i = 0; i < two.size(); i++)
    {
        bool t = is_point_in_polygon(one, two[i]);
        if (!t)
            return false;
    }
    return true;
}
// CHECKING FOR CROSSING SOLUTIONS
Point cross_runner(Point p0, Point p1, Point p2, Point p3)
{
    Point s1(p1.x - p0.x, p1.y - p0.y), s2(p3.x - p2.x, p3.y - p2.y);

    double s, t;
    s = (-s1.y * (p0.x - p2.x) + s1.x * (p0.y - p2.y)) / (-s2.x * s1.y + s1.x * s2.y);
    t = (s2.x * (p0.y - p2.y) - s2.y * (p0.x - p2.x)) / (-s2.x * s1.y + s1.x * s2.y);

    if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
    {
        return Point(p0.x + (t * s1.x), p0.y + (t * s1.y));
    }
    return Point(20000, 20000);
}

Point cross(vector<Point> one, vector<Point> two)
{
    one.push_back(one[0]);
    two.push_back(two[0]);
    for (int i = 0; i < one.size() - 1; i++)
    {
        for (int j = 0; j < two.size() - 1; j++)
        {
            if (i == j)
                continue;
            Point temp = cross_runner(one[i], one[i + 1], two[j], two[j + 1]);
            if (temp.x != 20000 && temp.y != 20000)
                return temp;
        }
    }
    return Point(20000, 20000);
}

typedef std::numeric_limits< double > dbl;

int main()
{
    cout.precision(dbl::max_digits10);
    int a, b;
    vector<Point> one, two;

    cin >> a;

    for (int i = 0; i < a; i++)
    {
        double temp_x, temp_y;
        cin >> temp_x >> temp_y;
        one.push_back(Point(temp_x, temp_y));
    }

    cin >> b;

    for (int i = 0; i < b; i++)
    {
        double temp_x, temp_y;
        cin >> temp_x >> temp_y;
        two.push_back(Point(temp_x, temp_y));
    }

    bool f = is_first_inside(one, two);
    bool s = is_second_inside(one, two);

    if (f)
    {
        cout << "first is inside" << endl;
    }
    else if (s)
    {
        cout << "second is inside" << endl;
    }
    else
    {
        Point temp = cross(one, two);
        if (temp.x == 20000 && temp.y == 20000)
            cout << "separate" << endl;
        else
        {
            cout << "cross" << endl;
            cout << temp.x << " " << temp.y << endl;
        }
    }
}