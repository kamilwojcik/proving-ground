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
    vector<int> vec = {1,2,3,4,5};

    Vprint(vec);

    return 0;
}