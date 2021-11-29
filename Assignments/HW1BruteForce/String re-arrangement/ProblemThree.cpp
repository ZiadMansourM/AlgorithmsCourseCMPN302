#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <climits>

#define LOG(x) std::cout << x << std::endl


std::vector<int> CountLetters(const std::string &s);
void ContainSameLetters(const std::vector<std::string>& inputs, bool& Impossible);
void rotate(std::string &s);
void MoveMatch(std::vector<std::string> inputs, bool& Impossible, int& count, int i, int j);

int main()
{   
    int N;
    std::cin >> N;
    std::vector<std::string> inputs(N);
    for(int i=0; i<N; i++)
    {
        std::string s;
        std::cin >> s;
        inputs[i] = s;
    }
    bool Impossible = false;
    // ------------------> [0] check strings conatin same letters
    ContainSameLetters(inputs, Impossible);
    // ------------------> [1] try moving then matching
    int min_count=INT_MAX;
    if (!Impossible)
    {
        for(int i=0; i<(int)inputs.size(); i++)
        {
            if (Impossible) break;
            int count=0;
            for(int j=0; j<(int)inputs.size(); j++)
            {
                if (Impossible) break;
                if (j==i) continue;
                MoveMatch(inputs, Impossible, count, i, j);
            }
            if (count<min_count)
                min_count=count;
        }
    }

    if (Impossible)
        LOG(-1);
    else
        LOG(min_count);
    return 0;
}

std::vector<int> CountLetters(const std::string &s)
{
    // -----------------------> count letters occurences
    std::vector<int> countLetters(26, 0);
    for (int i = 0; i<(int)s.length(); i++)
    {
        char c = tolower(s[i]);
        if (c < 'a' || c > 'z') continue;
        countLetters[c-'a'] += 1;
    }
    return countLetters;
}

void ContainSameLetters(const std::vector<std::string>& inputs, bool& Impossible)
{
    // ILOV: InputsLettersOccurenceVector
    std::vector<std::vector<int>> ILOV(inputs.size(), std::vector<int>(inputs.size(), 0));
    for(int i=0; i<(int)inputs.size(); i++)
    {
        ILOV[i] = CountLetters(inputs[i]);
    }
    std::vector<int> dumVec = ILOV[0];
    for(int i=1; i<(int)inputs.size(); i++)
    {
        if(ILOV[i]!=dumVec)
        {
            Impossible = true;
            break;
        }
    }
}

void rotate(std::string &s) 
{
    for (int i = 1; i<(int)s.size(); i++)
        std::swap(s[i-1], s[i]);
}

void MoveMatch(std::vector<std::string> inputs, bool& Impossible, int& count, int i, int j)
{
    int k=0;
    while(inputs[i]!=inputs[j])
    {
        rotate(inputs[j]);
        count++;
        if (k>(int)inputs[j].length())
        {
            Impossible = true;
            break;
        }
        k++;
    }
}