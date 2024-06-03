#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number : ";
    cin >> n;
    // int i = 0, ans = 0, j;
    // while (n != 0)
    // {
    //     j = n % 10;
    //     ans = (ans * 10) + j;
    //     n = n / 10;
        
    // }
    // cout << ans << endl;
    int i= 0;
    while (i<=n)
    {
        if(n==pow(2,i)){
            return true;
        }
        i++;
    }
    
    return 0;
}