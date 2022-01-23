#include <iostream>
#include <algorithm>

#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <string>

template<typename Iter>
auto middle(Iter first, Iter last)
{
    std::advance(first, std::distance(first,last)/2);
    return *first;
}

int main()
{
    std::forward_list<int> fl {1,2,3,4,5};
    std::list<int> l {1,2,3,4,5};
    std::deque<int> d {1,2,3,4,5};
    
    std::array<int, 5> a {1,2,3,4,5};
    std::vector<int> v {1,2,3,4,5};
    std::string s = "12345";

    std::cout<<"Forward list:"<<middle(fl.begin(), fl.end())<<std::endl;
    std::cout<<"List:"<<middle(l.begin(), l.end())<<std::endl;
    std::cout<<"Deque:"<<middle(d.begin(), d.end())<<std::endl;
    std::cout<<"Vector:"<<middle(v.begin(), v.end())<<std::endl;
    std::cout<<"Array:"<<middle(a.begin(), a.end())<<std::endl;
    std::cout<<"String:"<<middle(s.begin(), s.end())<<std::endl;
    
    return 0;
}