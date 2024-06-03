#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int brr[n - 1];
        int crr[n - 2];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n - 1; i++)
        {
            cin >> brr[i];
        }

        for (int i = 0; i < n - 2; i++)
        {
            cin >> crr[i];
        }
        bool found1 = false;
        for (int i = 0; i < n; i++)
        {
            found1 = false;
            for (int j = 0; j < n - 1; j++)
            {
                if (arr[i] == brr[j])
                {
                    found1 = true;
                    break;
                }
            }
            if (!found1)
            {
                cout << arr[i] << " ";
            }
        }
        bool found2 = false;
        for (int i = 0; i < n; i++)
        {
            found2 = false;
            for (int j = 0; j < n - 2; j++)
            {
                if (arr[i] == crr[j])
                {
                    found2 = true;
                    break;
                }
            }
            if (!found2)
            {
                cout << arr[i] << endl;
            }
        }
    }
    return 0;
}