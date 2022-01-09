#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    array<int, 10> bob;
    array<int, 10> dod;

    bob.fill(5);
    bob[3]=3;

    auto print = [](const int& n) { std::cout << ' ' << n; };
 
    // Print state before swap
    std::cout << "bob:";
    std::for_each(bob.begin(), bob.end(), print);
    std::cout << "\n" "dod  :";
    std::for_each(dod.begin(), dod.end(), print);
    std::cout << '\n';
 
    std::cout << "-- SWAP\n";
    std::swap(bob, dod);

    // Print state before swap
    std::cout << "bob:";
    std::for_each(bob.begin(), bob.end(), print);
    std::cout << "\n" "dod  :";
    std::for_each(dod.begin(), dod.end(), print);
    std::cout << '\n';
}