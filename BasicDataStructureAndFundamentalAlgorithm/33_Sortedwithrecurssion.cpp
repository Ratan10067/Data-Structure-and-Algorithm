#include<iostream>
using namespace std;
bool issorted(int *arr,int size){
    if(size==0||size==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        return issorted(arr+1,size-1);
    }
}
int main(){
int arr[]={11,12,13,14,15,16};
bool ans = issorted(arr,6);
if(ans){
    cout<<"Given Array is Sorted"<<endl;
}
else{
    cout<<"Given Array is not Sorted"<<endl;
}
return 0;
}