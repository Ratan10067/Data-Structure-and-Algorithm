#include <iostream>
#include <vector>
using namespace std;
void rotate(vector<int> & nums, int k)
{
    int t = nums.size()-1 - k;
    int j = 0;
    int x = k;
    while (k--)
    {
        x = t + 1;
        while (1)
        {
            if ((x - 1) == j)
            {
                swap(nums[j], nums[j + 1]);
                break;
            }
            else
            {
                swap(nums[x - 1], nums[x]);
                x--;
            }
        }
        t++;
        j++;
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    rotate(arr, 3);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }cout<<endl;

    return 0;
}