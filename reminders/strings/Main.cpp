#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl

void PrintString(const std::string& s);

int main()
{
    // string API: http://www.cplusplus.com/reference/string/string/ 
    // a string is an array of char
    // the following is a C style of making strings
    const char* msg = "Ziad Mansour"; // strings are immutable
    LOG(msg);

    char name[5] = { 'Z', 'i', 'a', 'd', '\0' };
    LOG(name);
    
    std::string str = "Hello world"; // const char array
    str += " Mr. Ziad";

    bool contains = str.find("Mr") != std::string::npos;
    LOG(contains);
    
    LOG(str.size());
    PrintString(str);
    return 0;
}

void PrintString(const std::string& s)
{
    LOG(s);
}