#include <iostream>
using namespace std;
void palindrome(string &str,int i, int j)
{
    if (i>j)
    {
        return;
    }
    swap(str[i],str[j]);
    palindrome(str,++i,--j);
}
int main()
{
    string s = "abcdef";
    int i=0,j=5;
    palindrome(s,i,j);
    cout<<s<<endl;
    return 0;
}