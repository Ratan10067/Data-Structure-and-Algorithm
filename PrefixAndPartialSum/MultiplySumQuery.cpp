/*
Problem Statement :
Description
Given an array of N integers and Q queries. In each query two integers L, R is given, you have to find (A[L] + A[L+1]*2 + A[L+2]*3 + A[L+3]*4...A[R]*(R-L+1)) % 10^9+7.

Input Format
The first line contains two space-separated integers N, Q where 1<=N<=10^6, 1<=Q<=10^6.

Next line contains N space-separated integers (-1e9<=Ai<=1e9).

Next Q lines contain two space-separated integers L, R where 1<=L<=R<=N.

Output Format
For each query print the value of (A[L] + A[L+1]*2 + A[L+2]*3 + A[L+3]*4...A[R]*(R-L+1)) % 10^9+7 in a new line.


*/

#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
#define mod 1000000007
signed main()
{
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin>>n>>q;
    int arr[n];
    lli prefix[n];
    lli brr[n],crr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]<0)arr[i]+=mod;
        // arr[i]%=mod;
        if(i)
            prefix[i]=(arr[i]%mod + prefix[i-1]%mod)%mod;
        else
            prefix[i] = arr[i]%mod;
        brr[i] = (1LL*arr[i]*i)%mod;
        if(i)
            crr[i]=(brr[i]%mod + crr[i-1]%mod)%mod;
        else
            crr[i] = brr[i]%mod;
    }
    while(q--)
    {
        int L,R;
        cin>>L>>R;
        L--;R--;
        if(L==0)
        {
        	lli ans = (crr[R]%mod + prefix[R]%mod)%mod;
        	ans = (ans+mod)%mod;
            cout<<ans<<"\n";
        }
        else
        {
            lli ans = (crr[R]%mod + mod - crr[L-1]%mod + (1-L)*(prefix[R]%mod + mod - prefix[L-1]%mod)%mod);
            ans = (ans+mod)%mod;
            cout<<ans<<"\n";
        }
    }
    return 0;
}