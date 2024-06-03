#include<iostream>
using namespace std;

int main(){
int m,n;
cin>>m;
cin>>n;
int **arr=new int*[m];
for (int i = 0; i < m; i++)
{
    arr[i]=new int[n];
}
for (int i = 0; i < m; i++)
{
    for (int j = 0; j < n; j++)
    {
        cin>>arr[i][j];
    }
}
for (int i = 0; i < m; i++)
{
    for (int j = 0; j < n; j++)
    {
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}
//releasing memory

for (int i = 0; i < m; i++)
{
    delete []arr[i];
}
delete []arr;
return 0;
}