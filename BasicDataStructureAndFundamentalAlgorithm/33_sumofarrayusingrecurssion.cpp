#include<iostream>
using namespace std;
int sum=0;
int sumArray(int arr[],int size,int lastitem=16){
    sum = sum+arr[0];
    if(size==1){
        return 1;
    }
    sumArray(arr+1,size-1);
    return sum;
}
int main(){
int arr[]={11,12,13,14,15,16};
int answer=sumArray(arr,6,16);
cout<<answer<<"\n";
return 0;
}