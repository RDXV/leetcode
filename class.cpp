#include <iostream>
#include <string>
using namespace std;

class emp
{
private:
    /* data */
    int ecode;

public:
    int sal;
    string name, desg;
    void input(int, int, string, string);
    void show();
    emp(/* args */);
    ~emp();
};

emp::emp(/* args */)
{
    cout << "constructor envoked \n";
}

emp::~emp()
{
}
void emp::input(int _ec, int _sal, string _name, string _desg)
{
    this->ecode = _ec;
    this->sal = _sal;
    this->name = _name;
    this->desg = _desg;
}
void emp::show()
{
    cout << "name is " << this->name << "\n";
    cout << "salary is " << this->sal << "\n";
    cout << "desg is " << this->desg << "\n";
}

int main()
{
    emp employee;
    int sal, ecode;
    string desg, name;
    cin >> ecode >> sal >> name >> desg;
    employee.input(ecode, sal, name, desg);
    employee.show();
}
