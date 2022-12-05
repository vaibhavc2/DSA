#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

// Unordered map: here search() and other functions are implemented through hash tables and hence time complexity is O(1)

int main(int argc, char const *argv[])
{
    map<char, string> m;
    m['a'] = "Apple";
    m['d'] = "Dog";
    m['c'] = "Cat";
    m['b'] = "Ball";

    for (auto e : m)
        cout << e.first << " : " << e.second << endl;

    unordered_map<char, string> umap;
    umap['a'] = "Apple";
    // umap.at('b') = "Ball"; // wrong way!
    umap['d'] = "Dog";
    umap['c'] = "Cat";
    umap['b'] = "Ball";

    // it doesnot arrange in any order and hence the iterator goes from the last in first out! whereas the map arranges them in ascending order

    // auto it = umap.find('c');
    unordered_map<char, string>::iterator it = umap.find('c');

    cout << endl;
    for (auto itr = umap.find('c'); itr != umap.end(); itr++)
        cout << (*itr).first << " : " << (*itr).second << endl;

    return 0;
}