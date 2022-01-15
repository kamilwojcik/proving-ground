#include <iostream>
#include <string>
#include <vector>

#include "vowel.hpp"

using namespace std;

int main ()
{
    vector<string> mystr={"abcde", "aabbbccabc", "qwerty"};
    cout<<"\nBeofre remove_vowels:"<<endl;
    
    cout<<"Input:"<<endl;
    for (auto str : mystr)
        cout<<"   "<<str<<endl;

    removeVowels(mystr);

    cout<<"\nAfter remove_vowels:"<<endl;
    for (auto str : mystr)
        cout<<"   "<<str<<endl;

    return 0;
}