#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    // freopen("output.txt", "w", stdout);
    unordered_map<string, int> map1;
    map1["hello"] = 2;
    map1["world"] = 1;
    map1["varun"] = 4;
    map1.insert(make_pair("yo", 10));
    string key = "yo";
    if (map1.find(key) == map1.end())
    {
        cout << "Key not found";
    }
    else
    {
        cout << "Key found " << key;
    }
    // for (auto x : map1)
    // {
    //     cout << x.first << " " << x.second << "\n";
    // }
}