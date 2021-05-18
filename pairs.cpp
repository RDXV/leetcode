// https://practice.geeksforgeeks.org/problems/number-of-pairs-1587115620/1
/*
Given two arrays X and Y of positive integers, find the number of pairs such that x^y > y^x 
(raised to power of) where x is an element from X and y is an element from Y.

Example 1:

Input: 
M = 3, X[] = [2 1 6] 
N = 2, Y[] = [1 5]
Output: 3
Explanation: 
The pairs which follow x^y > y^x are 
as such: 2^1 > 1^2,  2^5 > 5^2 and 6^1 > 1^6 .
Example 2:

Input: 
M = 4, X[] = [2 3 4 5]
N = 3, Y[] = [1 2 3]
Output: 5
Explanation: 
The pairs for the given input are 
2^1 > 1^2 , 3^1 > 1^3 , 3^2 > 2^3 , 4^1 > 1^4 , 
5^1 > 1^5 .

Your Task:
This is a function problem. You only need to complete the function countPairs() that takes X, Y, M, N as parameters 
and returns the total number of pairs.

Expected Time Complexity: O((N + M)log(N)).
Expected Auxiliary Space: O(1).
*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int i,j,n,m;
	cin>>n>>m;
	int a[n],b[m];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	for (int i = 0; i < m; ++i)
	{
		cin>>b[i];
	}
int c=0;
int first,second;
for(i=0;i<n;i++)
{
	for(j=0;j<m;j++)
	{	first=pow(a[i],b[j]);
		second=pow(b[j],a[i]);
		if(first<second)
		{	
			c++;
			cout<<pow(b[j],a[i])<<" > "<<pow(a[i],b[j])<<"\n";
		}
	}
}
cout<<"\n"<<c;
}