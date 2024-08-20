#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x1, y1, z1, x2, y2, z2;
    cout << "Enter two vector one by one: ";
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    double px = (y1 * z2 - y2 * z1);
    double py = (x2 * z1 - x1 * z2);
    double pz = (x1 * y2 - x2 * y1);
    cout << "Cross product is: " << px << " " << py << " " << pz;
    
    return 0;
}