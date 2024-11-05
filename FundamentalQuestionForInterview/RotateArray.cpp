#include <iostream>
using namespace std;
void Rotatearray(int arr[], int n, int k)
{
    int temp[n],brr[k];
    for (int i = 0; i <= k; i++)
    {
        brr[i]=arr[i];
        for (int j = i; j <= k; j++)
        {
            temp[i]=arr[i+k];
            break;
        }
    }
    for (int i = 0; i < k; i++)
    {
        temp[k+i]=brr[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << temp[i] << " ";
    }
    cout<<"\n";
}
int main()
{
    int k;
    cin >> k;
    int arr[] = {12, 13, 21, 23, 11};
    Rotatearray(arr, 5, k);
    return 0;
}