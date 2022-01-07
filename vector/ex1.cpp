#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void Vprint (const vector<T> & vec_to_print)
{
    cout<<"[ ";
    for (auto i :vec_to_print) cout<<i<<" ";
    cout<<"]"<<endl;
}

int main ()
{
    vector<int> vec = {1,2,4,5,6};
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