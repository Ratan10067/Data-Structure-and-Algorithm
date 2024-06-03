#include<bits/stdc++.h>
using namespace std;
// using lli long long int;
int gcd(int a,int b)
{
    if (a==0)
    {
        return b;
    }
    return gcd(b%a,a);
}

int main(){
int a,b;
cin>>a>>b;
int ans = gcd(a,b);
cout<<"GCD of two numbers is : "<<ans<<endl;
cout<<"LCM of two numbers is : "<<(a*b)/ans<<endl;
return 0;
}