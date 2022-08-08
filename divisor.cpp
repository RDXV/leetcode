#include <iostream>
using namespace std;

int main()
{
    // Alice has first turn and if n=2 then alice wins, n=3 then bob wins and n=4 then alice again
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "false";
    }
    else
    {
        n = n % 2;
    }
    if (n)
    {
        cout << "false";
    }
    else
    {
        cout << "true";
    }
}