#include <iostream>
#define ll long long;
using namespace std;
void solve(int *arr, int cnt)
{
    int sum = 0;
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = i; j <4; j++)
    //     {
    //         int curr=0;
    //         for (int l = i; l <=j; l++)
    //         {
    //             curr+=arr[l];
    //         }
    //         sum+=curr;
    //     }

    // }
    for (int i = 0; i < 4; i++)
    {
        sum += ((i + 1) * (4 - i)) * arr[i];
    }
    cout << sum << endl;
}
int main()
{
    int arr[4] = {1, 2, 3, 4};
    solve(arr, 4);
    cout << INT_MAX << endl;
    cout << (1 << 31) - 1 << endl;
    return 0;
}