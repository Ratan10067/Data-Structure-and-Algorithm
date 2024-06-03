#include <iostream>
using namespace std;
int calculatingPower(int x, int y)
{
    if (y == 0)
    {
        return 1;
    }
    if (y==1)
    {
        return x;
    }
    
    if (y % 2 == 0)
    {
        return calculatingPower(x, y / 2) * calculatingPower(x, y / 2);
    }
    else
    {
        return x * calculatingPower(x, y / 2) * calculatingPower(x, y / 2);
    }
}
int main()
{
    int a, b;
    cin >> a >> b;
    int ans = calculatingPower(a, b);
    cout << ans << endl;
    return 0;
}