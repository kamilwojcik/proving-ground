#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>

int main()
{
    std::vector<std::pair<int, std::string>> v { 
        {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"} 
        };

    std::vector<int> v2;

    std::transform(begin(v), end(v), back_inserter(v2), [](auto& vpair){return vpair.first;});

    std::cout<<"Output int vector: ";
    std::for_each(begin(v2), end(v2), [](auto i){std::cout<<i<<" ";});
    std::cout<<std::endl;

    std::vector<std::string> v3;

    std::transform(
        begin(v),
        end(v),
        back_inserter(v3),
        [](auto& vpair){ return std::string(vpair.second) + std::string(":") + std::to_string(vpair.first);}
        );

    std::cout<<"Output string vector: ";
    std::for_each(begin(v3), end(v3), [](auto i){std::cout<<i<<" ";});
    std::cout<<std::endl;

    std::vector<char> v4;
    std::generate_n(back_inserter(v4),
        13,
        [c{char{63}}]() mutable {return c+=2;}
        );

    std::cout<<"Output char vector: ";
    std::for_each(begin(v4), end(v4), [](auto i){std::cout<<i<<" ";});
    std::cout<<std::endl;
    return 0;
}