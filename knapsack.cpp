#include<iostream>
#include<algorithm>
#include <map>
// algorithm header file for max function
using namespace std;
int main()
{	int n;
	cin>>n;
	int wt[n],val[n];
	for(int i=0;i<n;i++)
	{
		cin>>wt[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>val[i];
	}
	int W;
	cin>>W;
	int K[n+1][W+1];
	// Reason is that columns must be W+1 for all weight values till W with initial value as 0
	// rows are n+1 because for n values of weight and values to be checked plus initial 0 value
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<W+1;j++)
		{
			if(i==0||j==0)
			{
				K[i][j]=0;
			}
			else if(wt[i-1]<=j)
				// dont replace j by W in the above condition
			{
				K[i][j]=max({val[i-1]+K[i-1][j-wt[i-1]],K[i-1][j],K[i][j-1]});
			}
			else{
				K[i][j]=K[i-1][j];
			}
		}
	}

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=W;j++)
		{
			cout<<K[i][j]<<" ";
		}
		cout<<"\n";
	}

}