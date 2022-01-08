#include <iostream>
#include <forward_list>
#include <algorithm>

using namespace std;

int main ()
{
    auto print = [](const int& n) { std::cout << ' ' << n; };

    forward_list flist = {0,1,2,3,4,5,6}; //c++17 allows it
    
    std::cout << "flist:";
    std::for_each(flist.begin(), flist.end(), print);
    auto it = flist.begin();
    std::advance(it, 2);
    flist.erase_after(it);
    flist.emplace_after(flist.before_begin(),10);
    auto next_it = flist.begin();
    while (next_it != flist.end())
    {
        it=next_it;
        next_it++;
    }
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