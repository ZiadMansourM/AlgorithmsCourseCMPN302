#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
/*
    > fstream library contains three classes:
        1- ofstream: creates & writes to files
        2- ifstream: reads from files
        3- fstream: creates, reades and writes to files 
*/
#include <fstream>
// to measure performance
#include <chrono>
// to use floor
#include <math.h>
// to use infinty
#include <climits>

#define LOG(x) std::cout << x << std::endl

void printv(std::vector<int> v)
{
    for(auto it=v.begin(); it!=v.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}


void read_data_file(const std::string input_file_name, std::vector<int>& datav);
void output_data_file(const std::string output_file_name, const std::vector<int>& datav);
void output_speed_test(const std::string speed_test_file_name, long long duration);
// merge sort func
void merge(std::vector<int>& internalv, int start, int middle, int end);
void merge_sort(std::vector<int>& internalv, int start, int end);
// quick sort func
void exchange(int& first, int& second);
int partition(std::vector<int>& internalv, int start, int end);
void quick_sort(std::vector<int>& internalv, int start, int end);


class BaseSort
{
    public:
    virtual std::vector<int> sort(const std::vector<int>& datav) = 0;
};

class SelectionSort : public BaseSort
{
    public:
    std::vector<int> sort(const std::vector<int>& datav) override;
};

class InsertionSort : public BaseSort
{
    public:
    std::vector<int> sort(const std::vector<int>& datav) override;
};

class MergeSort : public BaseSort
{
    public:
    std::vector<int> sort(const std::vector<int>& datav) override;
};

class QuickSort : public BaseSort
{
    public:
    std::vector<int> sort(const std::vector<int>& datav) override;
};

class HybridSort : public BaseSort
{
    public:
    std::vector<int> sort(const std::vector<int>& datav) override;
};

BaseSort* get_sorting_algorithm(const std::string algo_num);

int main(int argc, char** argv) {
    // read command line arguments
    const std::string algo_num = argv[1];
    const std::string input_file_name = argv[2];
    const std::string output_file_name = argv[3];
    const std::string speed_test_file_name = argv[4];
    // input data vector
    std::vector<int> datav;
    // sorted vector
    std::vector<int> sortedv;

    read_data_file(input_file_name, datav);

    BaseSort* SortingAlgorithm = get_sorting_algorithm(algo_num);

    auto start = std::chrono::high_resolution_clock::now();
    sortedv = SortingAlgorithm->sort(datav);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();

    output_data_file(output_file_name, sortedv);
    output_speed_test(speed_test_file_name, duration);

    LOG("size of datav: " << datav.size());
    LOG("is output correct: ");
    if (std::is_sorted(sortedv.begin(), sortedv.end()))
        LOG("TRUE");
    else
        LOG("FALSE");
    return 0;
}

std::vector<int> SelectionSort::sort(const std::vector<int>& datav)
{
    LOG("SelectionSort");
    std::vector<int> internalv(datav);
    for(int i=0; i<internalv.size(); i++)
    {
        int minElementIndex = std::min_element(internalv.begin()+i, internalv.end()) - internalv.begin();
        exchange(internalv[i], internalv[minElementIndex]);
    }
    return internalv;
}

void binary_insertion_sort(std::vector<int>& internalv, int start, int end)
{
    for(int j=start+1; j<=end; j++)
    {
        int key = internalv[j];
        int i = j-1;
        while(i>start-1 && internalv[i]>key)
        {
            internalv[i+1] = internalv[i];
            i--;
        }
        internalv[i+1] = key;
    }
}

std::vector<int> InsertionSort::sort(const std::vector<int>& datav)
{
    LOG("InsertionSort: ");
    std::vector<int> internalv(datav);
    binary_insertion_sort(internalv, 0, internalv.size()-1);
    return internalv;
}

void merge(std::vector<int>& internalv, int start, int middle, int end)
{
    // construct left and right vectors
    int lv_size = middle - start + 2;
    int rv_size = end - middle + 1;
    std::vector<int> lv(lv_size), rv(rv_size);
    // intialize left vector
    for(int i=0; i<lv_size; i++)
        lv[i] = internalv[start + i];
    lv[lv_size-1] = INT_MAX;
    // intialize right vector
    for(int i=0; i<rv_size; i++)
        rv[i] = internalv[middle + i + 1];
    rv[rv_size-1] = INT_MAX;
    // merge
    int lv_ptr=0, rv_ptr=0;
    for(int ref=start; ref<end+1; ref++)
    {
        if(lv[lv_ptr] <= rv[rv_ptr])
        {
            internalv[ref] = lv[lv_ptr];
            lv_ptr++;
        }
        else
        {
            internalv[ref] = rv[rv_ptr];
            rv_ptr++;
        }
    }
}

void merge_sort(std::vector<int>& internalv, int start, int end)
{
    if (start < end)
    {
        int middle = floor((start+end)/2);
        merge_sort(internalv, start, middle);
        merge_sort(internalv, middle+1, end);
        merge(internalv, start, middle, end);
    }
}

std::vector<int> MergeSort::sort(const std::vector<int>& datav)
{
    LOG("MergeSort: ");
    std::vector<int> internalv(datav);
    merge_sort(internalv, 0, internalv.size()-1);
    return internalv;
}

void exchange(int& first, int& second)
{
    int temp = first;
    first = second;
    second = temp;
}

int partition(std::vector<int>& internalv, int start, int end)
{
    int pivot = internalv[end];
    // i: index of last element in the smaller group
    int i = start - 1;
    for(int j=start; j<end; j++)
    {
        if(internalv[j]<=pivot)
        {
            i++;
            exchange(internalv[i], internalv[j]);
        }
    }
    exchange(internalv[i+1], internalv[end]);
    return i+1;
}

int random(int start, int end)
{
    srand(time(nullptr));
    int random = start + rand() % (end - start);
    return random; 
}

int randomized_partition(std::vector<int>& internalv, int start, int end)
{
    int i = random(start, end);
    exchange(internalv[end], internalv[i]);
    return partition(internalv, start, end);
}

void quick_sort(std::vector<int>& internalv, int start, int end)
{
    if(start < end)
    {
        int middle = randomized_partition(internalv, start, end);
        quick_sort(internalv, start, middle-1);
        quick_sort(internalv, middle+1, end);
    }
}

std::vector<int> QuickSort::sort(const std::vector<int>& datav)
{
    LOG("QuickSort: ");
    std::vector<int> internalv(datav);
    quick_sort(internalv, 0, internalv.size()-1);
    return internalv;
}

std::vector<int> HybridSort::sort(const std::vector<int>& datav)
{
    LOG("HybridSort");
    std::vector<int> internalv(datav);
    const int RUN = 32;
    for(int i=0; i<internalv.size(); i+=RUN)
        binary_insertion_sort(internalv, i, std::min((i+RUN-1), (int)internalv.size()-1));
    for(int slab_size=RUN; slab_size<internalv.size(); slab_size*=2)
    {
        for(int start=0; start<internalv.size(); start+=2*slab_size)
        {
            int middle = start+slab_size-1;
            int end = std::min((start+2*slab_size-1), (int)internalv.size()-1);
            if (middle < end)
                merge(internalv, start, middle, end);
        }
    }
    return internalv;
}


void read_data_file(const std::string input_file_name, std::vector<int>& datav)
{
    std::ifstream MyReadFile(input_file_name);
    std::string data;
    while(std::getline(MyReadFile, data))
    {
        datav.push_back(std::stoi(data));
    }
    MyReadFile.close();
}

void output_data_file(const std::string output_file_name, const std::vector<int>& datav)
{
    std::ofstream OutputFile(output_file_name);
    for(auto it = datav.begin(); it!=datav.end(); it++)
    {
        OutputFile << *it << "\n";
    }
    OutputFile.close();
}

void output_speed_test(const std::string speed_test_file_name, long long duration)
{
    std::ofstream SpeedTestOutputFile(speed_test_file_name);
    SpeedTestOutputFile << duration;
    SpeedTestOutputFile.close();
}

BaseSort* get_sorting_algorithm(const std::string algo_num) 
{
    if (algo_num == "0")
        return new SelectionSort();
    else if (algo_num  == "1")
        return new InsertionSort();
    else if (algo_num  == "2")
        return new MergeSort();
    else if (algo_num  == "3")
        return new QuickSort();
    else if (algo_num  == "4")
        return new HybridSort();
    return nullptr;
}