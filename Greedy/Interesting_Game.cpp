/*
Problem Statement :
Description
Alice and Bob are playing a new game, which is very interesting and fun. The game is as follows:

The game starts with two n-sized integer arrays, A and B, and is played by two players, P1 and P2.
The players move in alternating turns, with P1 always moving first. During each move, the current player must choose an integer, i, such that 0 ≤ i ≤ n - 1. If the current player is P1, then  P1 receives Ai points; if the current player is P2, then P2 receives Bi points.
Each value of i can be chosen only once. That is, if a value of i is already chosen by some player, none of the players can re-use it. So, the game always ends after n moves.
The player with the maximum number of points wins.
The arrays A and B are accessible to both the players P1 and P2. So the players make an optimal move at every turn.
Given the values of n, A, and B, can you determine the outcome of the game? P1 is Alice and P2 is Bob.
Print ‘Alice’ if Alice will win, 'Bob' if Bob will win, or 'Tie' if they will tie. Assume both players always move optimally.

Input Format
The first line of input contains one integer T (1 ≤ T ≤ 10) — the number of test cases. Then T test cases follow.
The first line of each test case contains N (2 ≤ N ≤ 1000), the number of elements in arrays A and B.
The second line contains N space-separated integers A1, A2, ..., AN - the elements of array A.
The third line contains N space-separated integers B1, B2, ..., BN - the elements of array B.

Output Format
For each test case, print one of the following predicted outcomes of the game on a new line:

Print 'Alice' if Alice will win.
Print 'Bob' if Bob will win.
Print 'Tie' if the two players will tie.


Solution :
Lets take an example : A = [ a , x ] B = [ b , y ] If I am player
1
1: if I pick the first , my score is a , my opponents score is y If I pick the second , my score is x , my opponents score is b Condition for first choice to be better than second choice is that if I score better than my opponents score in first choice
a−y>x−b
a+b>x+y

After some thinking one may conclude, that in an optimal play the sequence of cards must have descending values.

*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second

using ii = pair<int, int>;

bool cmp(ii a, ii b) { return a.F + a.S > b.F + b.S; }

void solve()
{
    int n;
    cin >> n;
    int a[n], b[n];
    vector<ii> arr;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        arr.push_back({a[i], b[i]});

    sort(arr.begin(), arr.end(), cmp);
    int sum1 = 0, sum2 = 0;
    bool found = true;
    for (int i = 0; i < n; i++)
    {
        if (found)
        {
            sum1 += arr[i].F;
        }
        else
        {
            sum2 += arr[i].S;
        }
        found = !found;
    }

    if (sum1 > sum2)
        cout << "Alice" << endl;
    else if (sum1 == sum2)
        cout << "Tie" << endl;
    else
        cout << "Bob" << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _t = 1;
    cin >> _t;
    while (_t--)
    {
        solve();
    }
}
