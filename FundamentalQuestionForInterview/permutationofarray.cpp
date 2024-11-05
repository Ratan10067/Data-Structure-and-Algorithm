#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cout<<typeid(t).name()<<endl;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v;
        vector<vector<int> > ans;
        vector<int> num;
        for (int i = 1; i <= n; i++)
        {
            v.push_back(i);
        }
        for (int i = 0; i < n; i++)
        {
            num.clear();
            for (int j = 0; j <n; j++)
            {
                swap(v[i], v[j]);
                for (int k = 0; k < n; k++)
                {
                    num.push_back(v[k]);
                }
                swap(v[i],v[j]);
                ans.push_back(num);
                if (v[v.size()-1]-v[0]==1)
                {
                   reverse(num.begin(),num.end());
                   ans.push_back(num);
                }
            }
        }
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[0].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}