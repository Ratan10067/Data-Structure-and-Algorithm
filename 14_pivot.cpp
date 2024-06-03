#include<iostream>
using namespace std;
int getpivot(int a[],int n){
    int s=0,e=n-1,mid=s+(e-s)/2;
    while (s<e)
    {
        if (a[mid]>=a[0])
        {
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}
int main(){
int arr[6]={10,18,1,2,3,4};
cout<<"the pivot index is : "<<getpivot(arr,6)<<endl;
return 0;
}