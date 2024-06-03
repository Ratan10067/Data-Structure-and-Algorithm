#include <iostream>
using namespace std;
void maximumelement(int a[], int size)
{
    int b = a[0];
    for (int i = 0; i < size; i++)
    {
        if (b <= a[i])
        {
            b = a[i];
        }
    }
        cout <<"the maximum of all the elements in array is  : "<< b << endl;
}
int main()
{
    int m;
    cout<<"Enter the size of array : ";
    cin >> m;
    int arr[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    maximumelement(arr, m);
    return 0;
}