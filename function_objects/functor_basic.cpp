#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class mod6zero
{
    int times_called = 0;

public:
    int HowManyTimesCalled()
    {
        return times_called;
    }

    bool operator() (int given_number)
    {
        times_called++;
        bool ans = (given_number % 6 == 0);
        if (ans) cout<<"6 is a vidisor of "<<given_number<<endl;
        else cout<<"6 is NOT a vidisor of "<<given_number<<endl;
        cout<<"Times called: "<<times_called<<endl;
        return ans;
    }
};




int main()
{
    mod6zero is6divisor;
    cout<<"How many times called: "<<is6divisor.HowManyTimesCalled()<<endl;
    cout<<"Is 6 a divisor of 5? "<<endl;
    bool result = is6divisor(5);
    cout<<"returned value: "<<result<<endl;
    cout<<"How many times called: "<<is6divisor.HowManyTimesCalled()<<endl;
    

    cout<<"\nUsing functor with for_each:"<<endl;
    vector<int> vec {3,6,5,12,22,11,24};
    for_each(vec.begin(), vec.end(), is6divisor);

    cout<<"\nAfter for_each:\nHow many times called: "<<is6divisor.HowManyTimesCalled()<<endl;
    
    return 0;
}