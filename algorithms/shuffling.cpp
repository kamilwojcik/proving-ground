#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
#include <random>

int main()
{
    std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};
    std::cout<<"Vector v - initial state: ";
    std::for_each(begin(v), end(v), [](auto i){std::cout<<i<<" ";});
    std::cout<<std::endl;

    std::sort(begin(v), end(v));
    std::cout<<"Vector v - after sort: ";
    std::for_each(begin(v), end(v), [](auto i){std::cout<<i<<" ";});
    std::cout<<std::endl;

    v.erase(std::unique(begin(v), end(v)), end(v));
    std::cout<<"Vector v - after uniqie-erase: ";
    std::copy(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "));
    std::cout<<std::endl;

    std::random_device rdev;
    std::mt19937_64 rgen(rdev());
    std::shuffle(begin(v), end(v), rgen);

    std::cout<<"Vector v - after shuffle: ";
    std::copy(begin(v), end(v), std::ostream_iterator<int>(std::cout, " "));
    std::cout<<std::endl;

    return 0;
}