#include <iostream>
using namespace std;
bool LinearSearch(int num[], int target, int size)
{
    if (size == 0)
    {
        return 0;
    }

    // int answer = LinearSearch(num + 1, target, size - 1);
    if (num[0] == target)
    {
        return true;
    }
    else
    {
        bool remainingpart = LinearSearch(num + 1, target, size - 1);
        return remainingpart;
    }
}
int main()
{
    int arr[] = {11, 21, 31, 41, 51, 61, 71, 81, 91};
    int key;
    cout << "Enter the number that you want to Search : ";
    cin >> key;
    bool found = LinearSearch(arr, key, 9);
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