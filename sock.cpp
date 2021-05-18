#include<iostream>

int main()
{
	int n;
	std::cin>>n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		std::cin>>arr[i];
	}
	bool ispair[n]={false};
	int pair=0;
	// ispair[0]=true;
	for(auto i=0;i<n;i++)
	{
		if (ispair[i]==false)
		{
			for(auto j=i+1;j<n;j++)
		{
			if (arr[i]==arr[j])
			{
				ispair[i]=ispair[j]=true;
				pair++;
				break;
			}
		}
		}
		
	}
	std::cout<<"The total pairs are "<<pair;
}	