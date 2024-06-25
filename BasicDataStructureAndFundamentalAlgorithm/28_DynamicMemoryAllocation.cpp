#include<iostream>
using namespace std;
int func(int a[],int n){
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum=sum+a[i];
    }
    return sum;
}
int main(){
int n;
cin>>n;
int *arr=new int[n];
for (int i = 0; i < n; i++)
{
    cin>>arr[i];
}
cout<<3[arr]<<endl;
int ans = func(arr,n);
cout<<ans;
delete []arr;
return 0;
}