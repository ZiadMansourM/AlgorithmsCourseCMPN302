#include <iostream>
#include <cstring>

#define LOG(x) std::cout << x << std::endl

int main()
{
    LOG("_POINTERS_");
    int* ptr = nullptr;
    int var = 8;
    LOG(&var);
    ptr = &var;
    LOG(ptr);
    LOG(*ptr);


    LOG("Pointers Exercise");
    int* buffer = new int[8];
    memset(buffer, 0, 8);
    int** D_ptr = &buffer;
    LOG(*buffer);
    delete[] buffer;

    LOG(**D_ptr);
    return 0;
}