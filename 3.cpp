#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

typedef std::numeric_limits<double> dbl;

int main()
{
    cout.precision(dbl::max_digits10);
    double x0, y0, r0, x1, y1, r1;
    cin >> x0 >> y0 >> r0;
    cin >> x1 >> y1 >> r1;
    double d = pow(pow((double)(x1 - x0), 2.0) + pow((double)(y1 - y0), 2.0), 0.5);

    if (d > r0 + r1 || d < abs(r0 - r1))
        cout << 0 << endl;
    else if (d == 0 && r0 == r1)
        cout << -1 << endl;
    else
    {
        double a = (pow(r0, 2.0) - pow(r1, 2.0) + pow(d, 2.0)) / (2.0 * d);
        double h = pow(pow(r0, 2.0) - pow(a, 2.0), 0.5);
        double tempX = x0 + a * (x1 - x0) / d;
        double tempY = y0 + a * (y1 - y0) / d;
        double oneX = tempX + h * (y1 - y0) / d;
        double oneY = tempY - h * (x1 - x0) / d;

        double twoX = tempX - h * (y1 - y0) / d;
        double twoY = tempY + h * (x1 - x0) / d;

        if (oneX == twoX && oneY == twoY)
            cout << 1 << "\n"
                 << oneX << " " << oneY << endl;
        else
            cout << 2 << "\n"
                 << oneX << " " << oneY << "\n"
                 << twoX << " " << twoY << endl;
    }
    return 0;
}