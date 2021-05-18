#include <iostream>
#include <chrono>
#include <thread>
#define m 1000000007
using namespace std;
void calc()
{
	int x = 5, n = 11;
	long long int sum = 0;
	// if sum is declaared as int then you get ambiguous output
	sum += x;
	while (n--)
	{
		sum += (sum % m);
		cout << sum << "\n";
	}
}
int main()
{
	using std::chrono::duration;
	using std::chrono::duration_cast;
	using std::chrono::high_resolution_clock;
	using std::chrono::milliseconds;

	auto t1 = high_resolution_clock::now();
	calc();
	auto t2 = high_resolution_clock::now();
	auto ms_int = duration_cast<milliseconds>(t2 - t1);

	/* Getting number of milliseconds as a double. */
	duration<double, std::milli> ms_double = t2 - t1;

	std::cout << ms_int.count() << "ms\n";
	std::cout << ms_double.count() << "ms";
}
