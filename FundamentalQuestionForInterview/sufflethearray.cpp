#include <iostream>
using namespace std;

int main()
{
    int nums[] = {1, 2, 3, 4, 4, 3, 2, 1};
    int n = 4;
    for (int i = 0; i < 8 - n; i++)
    {
        for (int j = n + i; j > 2 * i + 1; j--)
        {
            swap(nums[j], nums[j - 1]);
        }
    }
    for (int i = 0; i < 8; i++)
    {
        cout << nums[i] << " ";
    }
    cout << "\n";
    return 0;
}