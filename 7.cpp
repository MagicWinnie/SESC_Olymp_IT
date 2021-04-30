#include <iostream>

using namespace std;

int gcd_ext(int a, int b, int &x, int &y)
{
    if (a == 0) {
		x = 0; y = 1;
		return b;
	}
    int x0, y0;
	int d = gcd_ext(b % a, a, x0, y0);
	x = y0 - (b / a) * x0;
	y = x0;
	return d;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int u, v, x, y, g;
    g = gcd_ext(a, b, u, v);
    if (c % g == 0)
    {
        x = u * (c / g);
        y = v * (c / g);
        cout << x << " " << y << endl;  
    } else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}