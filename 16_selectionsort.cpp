#include <iostream>
using namespace std;
void selectionsort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int minindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minindex])
            {
                minindex=j;
            }
                // int temp = arr[minindex];
                // arr[minindex] = arr[j];
                // arr[j] = temp;
        }
        swap(arr[minindex],arr[i]);
    }
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[6] = {12, 11, 10, 9, 8, 7};
    selectionsort(arr, 6);
    return 0;
}