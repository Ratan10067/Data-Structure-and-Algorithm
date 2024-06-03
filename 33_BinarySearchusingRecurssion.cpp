#include <iostream>
using namespace std;
bool BinarySearch(int num[], int target, int size, int s, int e)
{
    if (s > e)
    {
        return false;
    }
    int mid = s + (e - s) / 2;
    if (num[mid] == target)
    {
        return true;
    }
    if (num[mid] < target)
    {
        return BinarySearch(num, target, size, mid + 1, e);
    }
    else
    {
        return BinarySearch(num, target, size, s, mid - 1);
    }
}
int main()
{
    int arr[] = {11, 21, 31, 41, 51, 61, 71, 81, 91};
    int key;
    cout << "Enter the number that you want to Search : ";
    cin >> key;
    int s = 0;
    int e = 8;
    bool found = BinarySearch(arr, key, 9, s, e);
    if (found)
    {
        cout << "The Number that you are enter is Present" << endl;
    }
    else
    {
        cout << "The Number that you are enter is not Present" << endl;
    }

    return 0;
}