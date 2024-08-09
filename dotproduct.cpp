#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x1, y1, z1, x2, y2, z2;
    cout << "Enter two vector one by one: ";
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    double product = (x1 * x2) + (y1 * y2) + (z1 * z2);
    cout << "Dot product is: " << product;
    if (product == 0)
    {
        cout << "\nVectors are perpendicular.";
    }
    return 0;
}