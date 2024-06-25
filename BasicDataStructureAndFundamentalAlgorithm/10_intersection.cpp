#include<iostream>
using namespace std;
void findingintersection(int a[],int b[],int n,int m){
    int crr[8],ans=0;
    for (int i = 0; i < m; i++)
    {
        for (int  k = i+1; k < m; k++)
        {
            if (b[i]==b[k]) 
            {
                b[k]=-23121;
            }
            
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int  k = i+1; k < m; k++)
        {
            if (a[i]==a[k]) 
            {
                a[k]=-112321;
            }
            
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i]==b[j])
            {
                crr[i] = a[i];
                ans++;
            }
            
        }
        
    }
    for (int k = 0; k < ans+1; k++)
    {
        cout<<crr[k]<<" ";
    }
    cout<<"\n";
}
int main(){
int arr[4] = {5,4,3,2},brr[3]={4,3,2};
findingintersection(arr,brr,4,3);
return 0;
}