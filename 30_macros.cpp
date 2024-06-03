#include<iostream>
using namespace std;
#define multiply(a,b) (a*b)  // yahi hai macroa aur kuch nhi hai bahut simple hai
inline int getmax(int &a,int &b){
return (a>b) ?a:b;
}
int main(){
int a=9;
int b=10;
//>>>>>>>>>>>>############# Aur ha global variable ka use nhi krna bad practise hai sala koi nhi function usko change kr skta hai
cout<<multiply(a,b)<<endl;

int ans =getmax(a,b);
cout<<ans<<endl;
return 0;
}