#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using  namespace std;

int main()
{
    random_device r_dev; //generates random seed
    mt19937_64 m64_engine {r_dev()}; //set mersenne 64-bit engine with random seed - why not?
    uniform_int_distribution<int> distribution{1, 42};
    
    auto gen_rnd = [&m64_engine, &distribution](){return distribution(m64_engine);};

    vector<int> vec(20);

    generate(vec.begin(), vec.end(), gen_rnd);

    [&vec](){cout<<"[";
            for (auto &i : vec)
                cout<<i<<", ";
            cout<<"]"<<endl;
            }();

    auto printint = [](int i){cout<<i<<" ";};
    for_each(begin(vec), end(vec), printint);
    cout<<endl;
    return 0;
}