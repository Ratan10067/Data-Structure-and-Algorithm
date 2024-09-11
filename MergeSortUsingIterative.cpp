#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to merge two sorted arrays
vector<int> merge(const vector<int> &left, const vector<int> &right)
{
    vector<int> result;
    int i = 0, j = 0;

    // Merge the two arrays
    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
        {
            result.push_back(left[i++]);
        }
        else
        {
            result.push_back(right[j++]);
        }
    }

    // Append remaining elements from left
    while (i < left.size())
    {
        result.push_back(left[i++]);
    }

    // Append remaining elements from right
    while (j < right.size())
    {
        result.push_back(right[j++]);
    }

    return result;
}

// Function to perform iterative merge sort using queue
vector<int> mergeSort(vector<int> &arr)
{
    queue<vector<int>> q;

    // Push each element of the array as a separate subarray into the queue
    for (int i = 0; i < arr.size(); ++i)
    {
        q.push(vector<int>{arr[i]});
    }

    // Continue merging until there is only one array in the queue
    while (q.size() > 1)
    {
        // Take two subarrays from the queue
        vector<int> left = q.front();
        q.pop();
        vector<int> right = q.front();
        q.pop();

        // Merge the two subarrays and push the result back into the queue
        q.push(merge(left, right));
    }

    // The last array in the queue is the sorted array
    return q.front();
}

int main()
{
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};

    cout << "Original array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    vector<int> sortedArr = mergeSort(arr);

    cout << "Sorted array: ";
    for (int num : sortedArr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
