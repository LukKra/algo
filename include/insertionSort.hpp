#include <iterator>
#include <algorithm>
#include <iostream>
#include <type_traits>

namespace algos{

    template<typename Iter>
    struct defaultComp
    {
        using ValueType = typename std::iterator_traits<Iter>::value_type;
        constexpr bool operator()(ValueType&& a, ValueType&& b) const
        {
            return a < b;
        }
    };
    
    
    template <typename iterator, typename compare = defaultComp<iterator>>
    void insertionSort(iterator beg, iterator end, compare comp = compare{})
    {
        if(beg == end)
            return;
            
        for(iterator i = beg + 1; i != end; ++i)
        {
            if(comp.operator()(*i,*beg))
            {
                std::cout<<"pred is true for "<<*i<<" and "<< *beg << "\n";
            }
            else
            {
                std::cout<<"pred is false for "<<*i<<" and "<< *beg << "\n";
            }
        }
        return;
    }

}