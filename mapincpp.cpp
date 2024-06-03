#include<iostream>
#include<map>
#include <chrono>
using namespace std::chrono;
using namespace std;

int main(){
    auto start = high_resolution_clock::now();
    map<int, int> mp;
    mp.insert({10, 4});
    mp.insert({3, 4});
    mp.insert({5, 4});
    mp.insert({2, 4});
    mp.insert({1, 4});
    auto it = mp.begin();
    while (it != mp.end())
    {
        cout << it->first << " " << it->second << endl;
        ++it;
}
auto stop = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(stop - start);
cout << "Time taken by function : " << duration.count() << " microseconds"<<endl;
return 0;
}