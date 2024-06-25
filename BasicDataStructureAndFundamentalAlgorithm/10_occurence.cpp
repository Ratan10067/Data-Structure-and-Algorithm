#include <iostream>
using namespace std;
void findingoccurence(int a[], int size, int b[])
{
    int ans = 1,answer;
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (a[i]==b[j])
            {
                answer = ++ans;
                b[i] = answer;
            }
            
        }
        ans=1;
    }
    for (int k = 0; k < size; k++)
    {
       cout<<b[k]<<" "; 
    }
    
    
}
int main()
{
    int arr[] = {23, 12, 12, 23, 12, 12, 12, 23};
    int brr[8];
    findingoccurence(arr, 8, brr);
    return 0;
}