// https://www.hackerrank.com/challenges/counting-valleys/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	cout<<n*3<<"\n";
	for(int i=0;i<n;i++)
	{
		cout<<i%10<<"\n";
	}
}