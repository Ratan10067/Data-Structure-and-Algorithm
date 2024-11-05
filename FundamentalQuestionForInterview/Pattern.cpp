#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    // char a = '*';
    // for (int i = 0; i <= n; i++){
    //     for (int j = 1; j <= i; j++)
    //     {
    //         cout<<a<<" ";
    //     }
    //     cout<<endl;
    // }
    // int a = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         a++;
    //         cout << a << " ";
    //     }
    //     cout << endl;
    // }
    
    // char a = 64;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         char ch = a + j+i-1;
    //          cout <<ch << " ";
    //         // a = a + 1;
    //     }
    //     cout << endl;
        
    // }
    // char a =65;
    // for (int i = 1; i <= n; i++)
    //     {
    //         for (int j = 1; j <= i; j++)
    //         {
    //             char ch = a ;
    //              cout <<ch << " ";
    //         }
    //             a = a + 1;
    //         cout << endl;

    //     }
    // for(int i=1;i<=n;i++){
    //     for (int j = 1; j <= n; j++)
    //     {
    //         if(j>=i){
    //         cout<<"*"<<" ";
    //     }
    //     }
    //     cout<<endl;
    // }
    // for (int i = 1; i <= n; i++)
    // {
    //     for(int j = 1;j<=n-i;j++){
    //         cout<<" ";
    //     }
    //     for (int k = 1; k = i; i++)
    //     {
    //         cout<<"*";
    //     }
        
    //     cout<<endl;
    // }

    // challenging part !!!!.......!!!!!!!!
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << j << " ";
        }

        for (int k = 1; k <= i - 1; k++)
        {
            cout << "*"
                 << " ";
        }
        for (int p = 1; p <= i - 1; p++)
        {
            cout << "*"
                 << " ";
        }

        for (int t = 1; t <= n - i + 1; t++)
        {
            cout <<n-i-t+2<< " ";
        }
        cout << endl;
    }

        return 0;
}