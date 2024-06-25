#include <iostream>
using namespace std;
bool findingElement(int a[][4],int n,int size)
{
    int s= 0,e=size*4-1;
    int mid = s+(e-s)/2;
    while (s<=e)    
    {
        if (a[mid/4][mid%4]==n)
        {
            return 1;
        }
        if (a[mid/4][mid%4]>n)
        {
            e=mid-1;
        }else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return 0;
}
int main()
{
    int arr[3][4],n;
    cout<<"Enter the number that you are enter"<<endl;
    cin>>n;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }
    bool isFound = findingElement(arr,n,3);
    if (isFound)
    {
        cout << "The Element that you are Enter is Found" << endl;
    }
    else
    {
        cout << "The Element that you are Enter is not Found" << endl;
    }
    return 0;
}