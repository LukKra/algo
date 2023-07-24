#include "include/insertionSort.hpp"
#include <vector>

template <typename T>
void printVec(std::vector<T> vec)
{
    for(auto& el : vec)
    {
        std::cout<<el<< " ";
    }
    std::cout<<std::endl;
}

int main()
{
    std::vector<int> vec{3,5,2,8,11};
    printVec(vec);

    std::cout<<"sort with default\n";
    algos::insertionSort(vec.begin(), vec.end());
    
    std::cout<<"sort with greater\n";
    algos::insertionSort(vec.begin(), vec.end(), std::greater<>{});

    std::cout<<"sort with lambda\n";
    algos::insertionSort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {return a < b;});

    std::sort(vec.begin(), vec.end());

    return 0;
}