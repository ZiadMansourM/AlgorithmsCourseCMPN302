#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define LOG(x) cout << x << endl

// fact: calculate factorial of a gaven number
unsigned long long int fact(int n);
// countWays: Count number of combunations
int countWays(int digits, int ones);
// countOnes: returns number of ones in a binary string
int countOnes(const string& s);
// generateCombinations: generate string combinations
void generateCombinations(vector<string>& vec, string s, const int digits, const int ones, int& index);

int main()
{
    // ---------------------------> Testing
    // int N=1, H=1;
    // while (true)
    // {
    //     for(N=H; N<=16; N++)
    //     {
    //         LOG("--------------- NEW LEVEL ----------------");
    //         int num = countWays(N, H);
    //         cout << "N: " << N << ", H: " << H << ", num: " << num << endl;
    //         vector<string> vec(num);
    //         int index = 0;
    //         string s = "";
    //         generateCombinations(vec, s, N, H, index);
    //         cout << "vec size: " << vec.size() << endl;
    //         LOG("vec elements:");
    //         for (auto it=vec.begin(); it!=vec.end(); it++)
    //             cout << *it << endl;
    //     }
    //     H++;
    //     if (H>16)
    //         break;
    // }

    int N, H;
    cin >> N >> H;

    int num = countWays(N, H);
    // LOG(num);
    
    vector<string> vec(num);
    int index = 0;
    string s = "";
    generateCombinations(vec, s, N, H, index);

    // LOG("Vector size:");
    // LOG(vec.size());
    for (auto it=vec.begin(); it!=vec.end(); it++)
        cout << *it << endl;
    
    return 0;
}

unsigned long long int fact(int n)
{
    if (n==0 || n==1)
        return 1;
    return n * fact(n-1);
}

int countWays(int digits, int ones)
{
    unsigned long long int first = fact(digits); 
    unsigned long long int second = fact(digits-ones); 
    unsigned long long int last = fact(ones); 
    unsigned long long int result = first/(second*last);
    return (int)result;
}

int countOnes(const string& s)
{
    int count = 0;
    for(char c: s)
    {
        if (c == '1')
            count++;
    }
    return count;
}

void generateCombinations(vector<string>& vec, string s, const int digits, const int ones, int& index)
{
    if ((int)s.size() == digits)
    {
        bool valid = countOnes(s)==ones;
        if (valid)
        {
            vec[index] = s;
            index++;
        }
        return;
    }
    generateCombinations(vec, s+"0", digits, ones, index);
    generateCombinations(vec, s+"1", digits, ones, index);
}