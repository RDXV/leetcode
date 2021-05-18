#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(string str)
{
    int i, j, len = str.length();
    bool flag = true;
    if (len == 0 || len == 1)
        return true; // is a palindrome
    for (i = 0, j = len - 1; i <= len / 2, j >= len / 2; i++, j--)
    {
        if (str[i] != str[j])
        {
            flag = false;
        }
    }
    if (flag)
    {
        return true;
    };

    return false;
}

void threeDigit()
{
    int n1 = 101, n2 = 101, i, j;
    long long val, max = 0;
    string value;
    for (i = n1; i <= 999; i++)
    {
        for (j = n1 + 1; j <= 999; j++)
        {
            val = i * j;
            value = to_string(val);
            if (isPalindrome(value))
            {
                if (val > max)
                {
                    max = val;
                }
            }
        }
    }
    cout << "max is " << max;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    // int n = 5;
    // string n2;
    // n2 = to_string(n);
    // n2 = n2 + " hello";
    // cout << n2;
    threeDigit();
    string str;
    cin >> str;
    bool val = isPalindrome(str);
    if (val)
    {
        cout << "is palindrome";
    }
    else
    {
        cout << "not palindrome";
    }
}
