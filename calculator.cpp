#include <iostream>
using namespace std;

int main()
{
    cout << "Enter the operator(+,-,*,/): " << endl;
    char ch;
    cin >> ch;
    double a, b;
    cout << "Enter the two number: ";
    cin >> a >> b;

    switch (ch)
    {
    case '+':
        cout << a << '+' << b << '=' << a + b;
        break;

    case '-':
        cout << a << '-' << b << '=' << a - b;
        break;

    case '*':
        cout << a << '*' << b << '=' << a * b;
        break;

    case '/':
        if (b == 0.0)
        {
            cout << "Divide by zero situation";
            break;
        }
        else
        {
            cout << a << '/' << b << '=' << a / b;
            break;
        }

    default:
        cout << "Wrong operator chosen";
    }

    return 0;
}