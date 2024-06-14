#include <bits/stdc++.h>
using namespace std;
// Function to find the next permutation
bool nextPermutation(vector<int> &sequence)
{
    int n = sequence.size();
    int i = n - 2;

    while (i >= 0 && sequence[i] >= sequence[i + 1])
    {
        i--;
    }

    if (i < 0)
    {
        return false; // No more permutations
    }

    int j = n - 1;
    while (sequence[j] <= sequence[i])
    {
        j--;
    }

    std::swap(sequence[i], sequence[j]);
    std::reverse(sequence.begin() + i + 1, sequence.end());

    return true; // Next permutation found
}
int main()
{
    vector<int> sequence = {1, 2, 3};

    // cout << "Original sequence: ";
    // for (int val : sequence)
    // {
    //     cout << val << " ";
    // }
    // cout << endl;

    // cout << "All permutations: " << endl;
    do
    {
        for (int val : sequence)
        {
            cout << val << " ";
        }
        cout << endl;
    } while (nextPermutation(sequence));
    return 0;
}