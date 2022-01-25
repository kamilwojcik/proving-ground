#include <iostream>
#include <algorithm>
#include <deque>

struct Point { int x, y; };

void print_deqpoint(std::deque<Point> to_print)
{
    std::cout<<"{";
    for (const auto& pt : to_print)
        std::cout<<"{"<<pt.x<<", "<<pt.y<<"} ";
    std::cout<<"}"<<std::endl;
}

int main()
{
    std::deque<Point> d = {{1, 3}, {0, 0}, {1, 2}, {2, 4}, {4, 1}, {0, 2}, {2, 2}};

    std::cout<<"Initial deque state: ";
    print_deqpoint(d);

    auto pointXcompare = [](Point p1, Point p2){return p1.x > p2.x;};
    auto pointYcompare = [](Point p1, Point p2){return p1.y > p2.y;};

    std::cout<<"Is sorted regarding x? "<<std::boolalpha<<std::is_sorted(begin(d), end(d), pointXcompare)<<std::endl;
    std::cout<<"Is sorted regarding y? "<<std::boolalpha<<std::is_sorted(begin(d), end(d), pointYcompare)<<std::endl;
    
    std::cout<<"   Stable sort x:\n";
    std::stable_sort(begin(d), end(d), pointXcompare);
    std::cout<<"Is sorted regarding x? "<<std::boolalpha<<std::is_sorted(begin(d), end(d), pointXcompare)<<std::endl;
    std::cout<<"Current deque state: ";
    print_deqpoint(d);

    std::cout<<"   Sort y:\n";
    std::stable_sort(begin(d), end(d), pointYcompare);
    std::cout<<"Is sorted regarding y? "<<std::boolalpha<<std::is_sorted(begin(d), end(d), pointYcompare)<<std::endl;
    std::cout<<"Current deque state: ";
    print_deqpoint(d);

    return 0;
}