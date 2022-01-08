#include <iostream>
#include <vector>

#include "Vprint.h"

using namespace std;

int main ()
{
    vector vec = {1,2,4,5,6}; //possible since c++17
    Vprint(vec);
    vec.erase(vec.begin());
    Vprint(vec);
    vec.emplace_back(5);
    vec.emplace(vec.begin(),12);
    Vprint(vec);

    cout<<"Size: "<<vec.size()<<"\nMax size: "<<vec.max_size()<<"\nCapacity: "<<vec.capacity()<<endl;
    vec.clear();
    cout<<"--------After clear--------\nSize: "<<vec.size()<<"\nCapacity: "<<vec.capacity()<<endl;

    return 0;
}