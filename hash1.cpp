#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    freopen("output.txt", "w", stdout);
    unordered_map<string, int> map1;
    map1["hello"] = 2;
    map1["world"] = 1;
    map1["varun"] = 4;
    map1.insert(make_pair("yo", 10));
    string key = "yo", key2 = "yoyo";
    if (map1.find(key) == map1.end())
    {
        cout << "Key not found";
    }
    else
    {
        cout << "Key found " << key;
    }
    if (map1.find(key2) == map1.end())
    {
        cout << "\nKey " << key2 << " not found \n";
    }
    else
    {
        cout << "Key " << key2 << " found";
    }
    // for (auto x : map1)
    // {
    //     cout << x.first << " " << x.second << "\n";
    // }
    for (auto i = map1.begin(); i != map1.end(); i++)
    {
        cout << i->first << " " << i->second << "\n";
    }
}