#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    vector v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9}; //since c++17

    auto print_el = [](auto i){cout<<i<<" ";};

    cout<<"v: ";
    for_each(begin(v), end(v), print_el);
    cout<<endl;

    cout<<"Ile elementów jest większych lub równych 5: "<< count_if(begin(v), end(v),[](auto i){return i>=5;}) <<endl;
    cout<<"Czy istnieje element mniejszy od 1: "<< (any_of(begin(v), end(v),[](auto i){return i<1;}) ? "tak." : "nie.") <<endl;
    cout<<"Czy wszystkie elementy są większe od 1: " << (all_of(begin(v), end(v), [](auto i){return i>1;}) ? "tak." : "nie." ) <<endl;

    vector<int> v_out;
    for_each(begin(v), end(v), [&v_out](int i){if (i>6) v_out.push_back(i);});

    cout<<"Elementy większe od 6: ";
    for_each(begin(v_out), end(v_out), print_el);
    cout<<endl;

    cout<<"Elementy 2, 4, 6 lub 8:"<<endl;
    copy_if(begin(v),
            end(v),
            ostream_iterator<int>(cout, " "),
            [](auto& i){return i == 2 || i == 4 || i == 6 || i == 8;}
            );
    cout<<endl;

    vector subsequence1 {6,6};
    auto searchit = search(begin(v), end(v), begin(subsequence1), end(subsequence1));
    if (searchit != end(v))
    {
        cout<<"Pierwsza para tych szóstek: "<<*searchit<<", "<<*(++searchit)<<endl;
    }
    else cout<<"Sorry, nie ma (6,6)!"<<endl;

    vector subsequence2 {7,7};
    searchit = search(begin(v), end(v), begin(subsequence2), end(subsequence2));
    if (searchit != end(v))
    {
        cout<<"Pierwsza para siódemek: "<<*searchit<<", "<<*(++searchit)<<endl;
    }
    else cout<<"Sorry, nie ma (7,7)!"<<endl;

    auto itadj = adjacent_find(begin(v), end(v));
    if (itadj != end(v))
    {
        cout<<"Pierwsza para tych samych elementów: "<<*itadj<<", "<<*(++itadj)<<endl;
    }
    else cout<<"Sorry, nie ma pary takich samych elementów obok siebie!"<<endl;

    return 0;
}