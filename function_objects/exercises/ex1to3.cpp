#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    auto l1=[](int a, int b){return a*b;};

    int a=3, b=4;
    cout<<"L1 a=3, b=4, l1(a,b)= "<<l1(a,b)<<endl;

    auto l2= [](string s){return ((string)"\"")+s+"\"";};
    string st="krowa";
    cout<<"L2(krowa) = "<<l2(st)<<endl;

    int starcounter=0;

    auto starprinter = [&starcounter](){starcounter++;
                                        for (int i=0; i<starcounter; i++) cout<<"*";
                                        cout<<endl;
                                        };

    cout<<"Starprinter:\n";
    starprinter();
    starprinter();
    starprinter();

    return 0;
}