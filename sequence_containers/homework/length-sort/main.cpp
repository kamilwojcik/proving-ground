#include <iostream>
#include <string>
#include <forward_list>
#include <deque>
#include <algorithm>

#include "sort.hpp"

using namespace std;

int main ()
{
    forward_list<std::string> word_list {"Three", "One", "Four", "Two"};
    
    auto print = [](std::string word){std::cout<<"\'"<<word<<"\' ";};

    std::cout<<"Input: \n";
    for_each(word_list.begin(), word_list.end(), print);

    auto sorted_deque = lengthSort(word_list);

    std::cout<<"\n\nOutput: \n";
    for_each(sorted_deque.begin(), sorted_deque.end(), print);
    cout<<endl;
    
    return 0;
}


    