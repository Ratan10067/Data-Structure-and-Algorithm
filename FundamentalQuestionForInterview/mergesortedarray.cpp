#include <iostream>
using namespace std;
void mergesort(int a[], int b[], int c[])
{
    int ans=0;
    for (int i = 0; i < 6; i++)
    {
        a[i] = b[i];
    }
    for (int i = 0; i < 3; i++)
    {
        a[6 + i] = c[i];
    }
    for (int i = 0; i < 9; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 9; i++)
    {
        int minindex = i;
        for (int j = i + 1; j < 9; j++)
        {
            if (a[j] < a[minindex])
            {
                minindex = j;
            }
        }
        swap(a[i], a[minindex]);
    }
    for (int i = 0; i < 9; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < 9; i++)
    {
        if (a[i]==0)
        {
            ans++;
        }  
    }
    cout<<ans<<endl;
    for (int i = ans; i < 9; i++)
    {
        cout<<a[i]<<" ";
    }
    
    cout << endl;
}
int main()
{
    int arr[6] = {1, 2, 3, 0, 0, 0};
    int brr[3] = {2, 5, 6};
    int crr[9];
    mergesort(crr, arr, brr);
    return 0;
}