#include <iostream>
using namespace std;
bool ispresent(int a[][4],int n){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if(a[i][j]==n){
                return 1;
            }
        }
        
    }
    return 0;
}
    void colsum(int a[3][4]){
        int sum1=0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                sum1 = sum1 + a[j][i];
            }
            
        cout<<sum1<<endl;
        }
    }
int main()
{
    int arr[3][4] = {{1, 11, 111, 1111}, {2, 22, 222, 2222}, {3, 33, 333, 3333}};
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 4; j++)
        {
            sum = sum + arr[i][j];
        }
        cout << sum << endl;
    }
    int target;
    cin >> target;
    if(ispresent(arr,target)){
        cout<<"Present"<<endl;
    }else{
        cout<<"Absent"<<endl;
    }
    colsum(arr);
    return 0;
}