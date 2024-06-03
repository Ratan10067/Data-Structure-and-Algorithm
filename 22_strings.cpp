#include <iostream>
using namespace std;
void palindrone(char str[], int n)
{
    char brr[20];
    int ans = 0;
    int s = 0, e = n - 1;
    while (s < e)
    {
        swap(str[s], str[e]);
        s++;
        e--;
    }
    for (int i = 0; i < n; i++)
    {
        brr[i] = str[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << str[i];
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << brr[i];
    }
    cout << endl;
    int s1 = 0, e1 = n - 1;
    while (s1<n)
    {
        if (str[s1] == brr[n-1-s1])
        {
            ans++;
        }
        s1++;
    }

    cout << ans << endl;
    if (ans == n)
    {
        cout << "The Name that you are Enter is Palindrone " << endl;
    }
    else
    {
        cout << "The Name that you are Enter is not a Palindrone" << endl;
    }
}
int lengthcount(char arr[])
{
    int count = 0;
    int i = 0;
    while (arr[i] != '\0')
    {
        count++;
        i++;
    }
    return count;
}
int main()
{
    // char name[15];
    // cout << "Enter your name : ";
    // cin >> name;
    // name[2] = '\0';
    // cout<<name<<endl;
    char str[20];
    cout << "Enter the number that you want to check for palindrone : ";
    cin >> str;
    int length = lengthcount(str);
    palindrone(str, length);

    return 0;
}