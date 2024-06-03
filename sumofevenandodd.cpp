#include<iostream>
using namespace std;

int main(){
int n;
cin>>n;
int sum1=0,sum2=0;
while (n!=0)
{
    int ans = n%10;
    if (ans%2==0)
    {
        sum1=sum1+ans;
    }else{
        sum2=sum2+ans;
    }
    
   n= n/10;
}
cout<<sum1<<" "<<sum2<<endl;
return 0;
}