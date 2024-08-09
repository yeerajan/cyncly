#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x1, y1, x2, y2;
    cout << "Enter two points one by one: ";
    cin >> x1 >> y1 >> x2 >> y2;
    double Y = y2 - y1, X = x2 - x1;
    double C = (Y * x1) - (X * y1);
    char ch = '+';
    if (std::signbit(X))
        ch = '+';
    else
        ch = '-';
    cout << "Equation of line is: " << Y << "X" << ch << abs(X) << "Y = " << C << endl;
    double a, b;
    cout << "enter a point to find perpendicular distance: ";
    cin >> a >> b;
    double dist = (Y * a - X * b - C) / hypot(X, Y);
    cout << "Distance is: " << dist;
    return 0;
}