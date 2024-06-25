#include <iostream>
using namespace std;
void BubbleSort(int *arr, int size)
{
    if (size == 1)
    {
        return;
    }
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    BubbleSort(arr, size - 1);
}
int main()
{
    int arr[] = {91, 81, 71, 61, 51, 41, 31, 21, 11};
    BubbleSort(arr, 9);
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}