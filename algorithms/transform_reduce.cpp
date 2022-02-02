#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main ()
{
    std::vector<int> v(1000);
    std::iota(begin(v), end(v), 1);

    std::cout<<"Suma liczb od 1 do 1000: "<<std::accumulate(begin(v), end(v),0)<<std::endl;

    auto v2 = v;
    std::for_each(
                    begin(v2),
                    end(v2),
                    [](auto &i)
                    {
                        auto r = i % 4;
                        if (r==1) i=-1;
                        else if (r==2 || r == 0) i=0;
                        else i=1;
                    }
                );

    std::cout<<"v1 head: ";
    for (int i=0; i<10; i++) std::cout<<v2.at(i)<<" ";
    std::cout<<std::endl;

    int dotprod = std::inner_product(begin(v),end(v), begin(v2),0);
    std::cout<<"inner product of v and v2: "<<dotprod<<std::endl;

    int sumifv2positive = std::transform_reduce(begin(v), end(v), begin(v2), 0, std::plus<>(),[](int a, int b){
        if (b==1) return a;
        else return 0;
    });
    std::cout<<"trensform_reduce: (sum elements from v, if corresponding elements of v2 are positive): "<<dotprod<<std::endl;
    

    return 0;
}