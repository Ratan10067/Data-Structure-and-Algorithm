#include <iostream>
using namespace std;
int firstoccu(int arr[], int n, int key)
{
    int s = 0, e = n - 1, ans = 0;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int key;
    cout << "Enter the value that you want for seach : ";
    cin >> key;
    int even[5] = {1, 2, 3, 3, 5};
    cout<<"the index of the number that you enter is "<<firstoccu(even,5,key)<<endl;
    return 0;
}