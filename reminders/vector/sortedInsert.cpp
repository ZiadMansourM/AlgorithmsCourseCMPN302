#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

#define LOG(x) cout << x << endl

void sorted_insert(vector<string>& vec, string s)
{
    auto it = upper_bound(vec.cbegin(), vec.cend(), s);
    vec.insert(it, s);
}

int main()
{
    vector<string> vec = {"0011", "0101", "1001", "1010", "1100"};
    string s = "0110";
    
    sorted_insert(vec, s);

    cout << "The vector elements are: " << endl;
    for (auto it = vec.begin(); it != vec.end(); it++)
        cout << *it << " = " << stoi(*it, 0, 2) << endl;
    
    return 0;
}