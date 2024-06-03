#include<iostream>
using namespace std;
int gcd(int x,int y){
    if(x==0){
        return x;
    }
    if(y==0){
        return y;
    }
    while (x!=y)
    {
        if (x>y)
        {
            x = x - y;
        }else{
            y=y-x;
        }
        
        
    }
    return x;
}
int main(){
int a,b;
cout<<"Enter the values of a and b";
cin>>a>>b;
int ans= gcd(a,b);
cout<<ans<<endl;
return 0;
}