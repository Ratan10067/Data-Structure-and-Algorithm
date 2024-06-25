#include <iostream>
using namespace std;
void reversearray(int a[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        int temp = a[i];
        a[i] = a[size - i - 1];
        a[size - i - 1] = temp;
    }
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}
int main()
{
    int arr[] = {12, 23, 1, 4, 3, 2, 6,34,56,12};
    reversearray(arr, 10);
    return 0;
}