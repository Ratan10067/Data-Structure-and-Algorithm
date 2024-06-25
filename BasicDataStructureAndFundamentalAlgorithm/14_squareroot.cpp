#include <iostream>
using namespace std;
int squareroot(int num)
{
    int s = 0, e = num, mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        int square = mid * mid;
        if (square == num)
        {
            return mid;
        }
        if (square < num)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter the number : ";
    cin >> n;
    int answer = squareroot(n);
    cout << answer << endl;
    return 0;
}