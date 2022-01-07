#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <map>

using namespace std;

template<typename K, typename V>
map<K, V> createMap (const vector<K> & key_vec, const list<V> & val_list)
{
    map<K, V> ans;
    
    auto li = val_list.begin();
    auto vi = key_vec.begin();
    
    while ( vi != key_vec.end() && li != val_list.end() )
    {
        ans.emplace(*vi, *li);
        vi++;
        li++;
    }
    
    return ans;
}

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::list<std::string> list{"One", "Two", "Three", "Four", "Five"};
    
    auto map = createMap(vec, list);

    for (const auto& pair : map)
        std::cout << pair.first << " | " << pair.second << '\n';

    return 0;
}    


