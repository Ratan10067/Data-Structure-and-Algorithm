#include<iostream>
using namespace std;
void printSpiralArray(int a[][4],int m,int n){
    int sum=0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<a[i][j]<<" ";
            sum+=a[i][j];
        }
        for (int k = 1; k < m; k++)
        {
            cout<<a[k][n-1]<<" ";
            sum+=a[k][n-1];
        }
        for (int t = n-2; t >= 0; t--)
        {
            cout<<a[m-1][t]<<" ";
            sum+=a[m-1][t];
        }
        for (int y = m-2; y >=1; y--)
        {
            cout<<a[y][0]<<" ";
        }
        
        cout<<sum<<endl;
        break;
        
        
    }
    
}
int main(){
int arr[5][4];
for (int i = 0; i < 5; i++)
{
    for (int j = 0; j < 4; j++)
    {
        cin>>arr[i][j];
    }
    
}
printSpiralArray(arr,5,4);
return 0;
}