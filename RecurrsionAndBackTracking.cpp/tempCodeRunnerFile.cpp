int n = arr.size();
    vector<int> subVal;
    for (int i = 0; i < (1<<n); i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if((i>>j)&1)subVal.push_back(arr[j]);
        }
        subVal.push_back(sum);
    }
    sort(subVal.begin(),subVal.end());
    return subVal;
}