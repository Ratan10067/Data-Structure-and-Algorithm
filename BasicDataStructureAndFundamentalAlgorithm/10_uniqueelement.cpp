#include <iostream>
using namespace std;
int findingunique(int a[], int size)
{
    int ans =0 ;
    for (int i = 0; i < size; i++)
    {
        ans = ans^a[i];
    }
    return ans;
    
}
int main()
{
    int arr[] = {1, 23, 1, 4, 4, 23, 21};
    int answer = findingunique(arr,7);
    cout<<answer<<endl;
    return 0;
}