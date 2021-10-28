#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

#define LOG(x) std::cout << x << std::endl

int main()
{
    // // ExampleOne
    // std::unordered_set<std::string> dictionary = {"stop", "pots", "tops", "opts", "post", "spot"};
    
    // std::string word = "stop";

    // sort(word.begin(), word.end());
    // do{
    //     std::cout << word << (dictionary.count(word)?" IS A WORD!\n" : "\n");
    // } while (std::next_permutation(word.begin(), word.end()));
    
    // ExampleTwo
    std::string x = "1234";

    do{
        LOG(x);
    } while (std::next_permutation(x.begin(), x.end()));
    return 0;
}