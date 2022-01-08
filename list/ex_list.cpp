#include <iostream>
#include <list>
#include <array>
#include <algorithm>

using namespace std;

int main ()
{
    auto print = [](const int& n) { std::cout << ' ' << n; };

    list mylist = {0,1,2,3,4,5}; //c++17 allows it
    
    std::cout << "mylist:";
    std::for_each(mylist.begin(), mylist.end(), print);
    auto it = mylist.begin();
    std::advance(it, 2);
    mylist.erase(it);
    mylist.emplace_front(10);
    mylist.emplace_back(10);
    std::cout << "\nmylist:";
    std::for_each(mylist.begin(), mylist.end(), print);
    it=mylist.begin();
    std::advance(it,3);
    *it+=20;

    std::cout << "\nmylist:";
    std::for_each(mylist.begin(), mylist.end(), print);
    std::cout<<std::endl;

    return 0;
}