#include <bits/stdc++.h>
using namespace std;
int tower_of_hanoi(int x, int source, int target, int aux)
{
    if (x == 0)
        return 1;
    int sum1 = tower_of_hanoi(x - 1, source, aux, target);
    cout << "Move Disc " << x << " from " << source << " to " << target << endl;
    int sum2 = tower_of_hanoi(x - 1, aux, target, source);
    return sum1 + sum2 + 1;
}
int main()
{
    int x;
    cin >> x;
    cout << tower_of_hanoi(x - 1, 1, 3, 2) << endl;
    return 0;
}