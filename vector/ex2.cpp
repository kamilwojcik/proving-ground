#include <iostream>
#include <vector>

#include "Vprint.h"

using namespace std;

int main ()
{
    vector<int> vec;
    cout<<"Size: "<<vec.size()<<"\nMax size: "<<vec.max_size()<<"\nCapacity: "<<vec.capacity()<<endl;
    vec.resize(10,5);
    cout<<"--------After resize--------\nSize: "<<vec.size()<<"\nCapacity: "<<vec.capacity()<<endl;
    Vprint(vec);

    vec.reserve(20);
    cout<<"--------After reserve--------\nSize: "<<vec.size()<<"\nCapacity: "<<vec.capacity()<<endl;
    vec.shrink_to_fit();
    cout<<"--------After shrink to fit--------\nSize: "<<vec.size()<<"\nCapacity: "<<vec.capacity()<<endl;
    
    return 0;
}