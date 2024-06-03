#include <iostream>
using namespace std;
int binarySearch(int a[], int size, int key)
{
    int start = 0, end = size - 1;
    int mid = (start + end) / 2;
    while (start <= end)
    {
        if (a[mid] == key)
        {
            return mid;
        }
        if (a[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2; // aise TLE nhi ayega agar end aur start dono hi bahut bade hai jo ki int ke range se bahur ja rahe  hai
    }
    return 1;
}
int main()
{
    int even[6] = {2, 4, 6, 8, 10, 12};
    int odd[5] = {3, 8, 11, 14, 17};
    int key;
    cout << "Enter the value that you want for seach : ";
    cin >> key;
    int index = binarySearch(even, 6, key);
    cout << "The value of index is : " << index << endl;
    // int index1 = binarySearch(odd,5,key);
    return 0;
}