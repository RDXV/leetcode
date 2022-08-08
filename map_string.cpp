#include <iostream>
#include <sstream>
#include <stdio.h>
#include <unordered_map>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string str;
    // cin >> str;
    getline(cin, str);
    // take string and print the total number of occurances of each word
    // example - geeks for geeks practice
    // geeks-2 , for-1, practice-1
    unordered_map<string, int> nmap;
    stringstream ss(str);
    string word;
    // clear() — to clear the stream
    // str() — to get and set string object whose content is present in stream.
    // operator << — add a string to the stringstream object.
    // operator >> — read something from the stringstream object,
    while (ss >> word)
    {
        nmap[word]++;
    }
    for (auto i = nmap.begin(); i != nmap.end(); i++)
    {
        cout << i->first << " " << i->second << "\n";
    }
    /*
    To count words in a string with spaces we use stringstream,
    int countWords(string str)
{
    // breaking input into word using string stream
    stringstream s(str); // Used for breaking words
    string word; // to store individual words
  
    int count = 0;
    while (s >> word)
        count++;
    return count;
}
*/
}