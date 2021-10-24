#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point
{
	double x, y;
	Point()
	{
		x = 0.0;
		y = 0.0;
	};
	Point(double x_, double y_)
	{
		x = x_;
		y = y_;
	}
	Point operator-(Point a)
	{
		return Point(x - a.x, y - a.y);
	}
	Point operator-=(Point a)
	{
		x -= a.x;
		y -= a.y;
		return *this;
	}
	Point operator+(Point a)
	{
		return Point(x + a.x, y + a.y);
	}
	Point operator+=(Point a)
	{
		x += a.x;
		y += a.y;
		return *this;
	}
	Point operator*(Point a)
	{
		return Point(x * a.x, y * a.y);
	}
	Point operator*=(Point a)
	{
		x *= a.x;
		y *= a.y;
		return *this;
	}
	double operator^(Point a)
	{
		return x * a.y - y * a.x;
	}
	friend ostream &operator<<(ostream &os, const Point &pt)
	{
		os << pt.x << ' ' << pt.y;
		return os;
	}
};

double euclidean(Point a, Point b)
{
	return pow(pow(a.x - b.x, 2.0) + pow(a.y - b.y, 2.0), 0.5);
}
bool smrt_cmp(Point a, Point b)
{
	return a.y < b.y || a.y == b.y && a.x < b.x;
}
bool polar_cmp(Point a, Point b)
{
	return (a ^ b) > 0 || ((a ^ b) == 0 && (euclidean(a, Point()) < euclidean(b, Point())));
}

int main()
{
	cout << fixed << setprecision(4);
	int n;
	cin >> n;
	vector<Point> arr(n);

	for (int i = 0; i < n; i++)
	{
		Point temp_p;
		cin >> temp_p.x >> temp_p.y;
		arr[i] = temp_p;
	}
	if (n < 3)
	{
		cout << 0.0 << endl;
		return 0;
	}
	sort(arr.begin(), arr.end(), &smrt_cmp);

	Point base_pt = arr.front();
	for (int i = 0; i < arr.size(); i++)
		arr[i] -= base_pt;

	sort(arr.begin() + 1, arr.end(), &polar_cmp);

	vector<Point> convex_hull;
	for (size_t i = 0; i < arr.size(); i++)
	{
        while (
				convex_hull.size() >= 2 &&
				((arr[i] - convex_hull.back()) ^ (convex_hull[convex_hull.size() - 2] - convex_hull.back())) <= 0
			)
            convex_hull.pop_back();
        convex_hull.push_back(arr[i]);
    }

	double area = 0.0;
	for (size_t i = 0; i < convex_hull.size(); i++)
		area += ((convex_hull[i] + base_pt) ^ (convex_hull[(i + 1) % convex_hull.size()] + base_pt));
	cout << 0.5 * area << endl;
}