#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main ()
{
    auto print = [](const int& n) { std::cout << ' ' << n; };

    deque<int> dq; //possible since c++17
    for (int i=0; i<5; i++) dq.push_front(i);


    cout << "dq:";
    for_each(dq.begin(), dq.end(), print);
    
    auto it =  dq.begin();
    advance(it, 1);
    it = ++dq.erase(it);
    it = dq.erase(it);
    cout << "\nit: "<<*it<<" \ndq after 2nd and 4th elements were removed:\n";
    for_each(dq.begin(), dq.end(), print);
    
    dq.push_back(30);
    dq.push_front(30);
    cout << "\ndq after push_front and push_back:\n";
    for_each(dq.begin(), dq.end(), print);
    
    it=dq.begin();
    advance(it, 3);
    *it+=20;
    cout << "\ndq after 20 was added to the 4th element:\n";
    for_each(dq.begin(), dq.end(), print);
    
    cout<<endl;

    return 0;
}