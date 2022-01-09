#include <iostream>
#include <forward_list>
#include <algorithm>

using namespace std;

int main ()
{
    auto print = [](const int& n) { std::cout << ' ' << n; };

    forward_list flist = {0,1,2,3,4,5,6}; //possible since c++17
    
    std::cout << "flist:";
    std::for_each(flist.begin(), flist.end(), print);
    auto it = flist.begin();
    std::advance(it, 2);
    flist.erase_after(it);
    flist.emplace_after(flist.before_begin(),10);
    
    it=flist.before_begin();
    std::advance(it, std::distance(it, flist.end())-1);
    flist.emplace_after(it,10);

    std::cout << "\nflist:";
    std::for_each(flist.begin(), flist.end(), print);
    it=flist.begin();
    std::advance(it,3);
    *it+=20;

    std::cout << "\nflist:";
    std::for_each(flist.begin(), flist.end(), print);
    
    
    std::cout<<std::endl;
    return 0;
}