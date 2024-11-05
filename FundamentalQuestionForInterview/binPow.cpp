#include <iostream>
using namespace std;
using lli = long long int;
lli power(lli a, lli b)
{
    lli ans = 1;
    while (b)
    {
        if (b % 2 == 1)
        {
            ans = a * ans;
        }
        a = a * a;
        b /= 2;
    }
    return ans;
}
lli binpow(lli a, lli b, lli p)
{
    lli ans = 1;
    while (b)
    {
        if (b % 2 == 1)
        {
            ans = a * ans % p;
        }
        a = a * a % p;
        b /= 2;
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        lli a, b, c, p;
        cin>>a>>b>>c>>p;
        a %= p;
        lli x = power(b, c);
        lli y = binpow(a, x, p);
        cout << y << endl;
    }
    return 0;
}