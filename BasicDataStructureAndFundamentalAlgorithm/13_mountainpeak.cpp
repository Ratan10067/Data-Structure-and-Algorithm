#include <iostream>
using namespace std;
int mountainpeak(int arr[], int n)
{
    int s = 0, e = n - 1, mid = s + (e - s) / 2, ans;
    while (s < e)
    {

        if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
        {
            // ans = mid;
            return mid;
        }
            if (arr[mid] < arr[mid + 1])
            {
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
             mid = s + (e - s) / 2;
        // else if (arr[mid] < arr[mid + 1])
        // {
        //     s = mid + 1;
        // }
        // else
        // {
        //     e = mid - 1;
        // }
        // mid = s + (e - s) / 2;
    }
    return s;
}
int main()
{
    int str[5] = { 5,4,1, 2, 3};
    cout << "The index of peak elemnet is : " << mountainpeak(str, 5) << endl;
    return 0;
}