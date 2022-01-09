#include <iostream>
#include <algorithm>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

vector<string> removeVowels(vector<string> input)
{
    constexpr string_view vowels = "aAeEiIoOuUyY";
    for (auto& str : input)
        for (auto vowel : vowels)
            str.erase( remove( str.begin(), str.end(), vowel ), str.end() );

    return input;
}

int main ()
{
    vector<string> input={"abcde", "aabbbccabc", "qwerty"};
    vector<string> output=removeVowels(input);

    cout<<"Input:"<<endl;
    for (auto str : input)
        cout<<"   "<<str<<endl;

    cout<<"\nOutput:"<<endl;
    for (auto str : output)
        cout<<"   "<<str<<endl;

    return 0;
}