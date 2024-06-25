#include <iostream>
using namespace std;
void bubblesort(int arr[], int n)
{
    bool swapped = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i ; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped=true;
            }
        }
    if(swapped==false){
        break;
    }
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int arr[6] = {10, 6, 8, 3, 4, 2};
    bubblesort(arr, 6);
    return 0;
}