#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	cin >> k;
	// sort(a);
	sort(a, a + n);
	for (auto i = 0; i < n; i++)
	{
		/* code */ cout << a[i] << " ";
	}

	cout << "\n"
		 << a[k - 1];
}