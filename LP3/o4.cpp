#include<iostream>
#include<iomanip>
using namespace std;

int max(int a,int b)
{
	return (a > b) ? a: b;
}
void printTable(int K[100][100],int n,int W)
{
	cout<<"\nCurrent Table State "<<endl;
	for(int i =0;i<=n;i++)
	{
		for(int w=0;w<=W;w++)
		{
			cout<<setw(4)<<K[i][w];
		}
		cout<<endl;
	}
	cout<<endl;
}
int knapsack(int W,int wt[],int val[],int n)
{
	int K[100][100];
	for(int i=0;i<=n;i++)
	{
		for(int w =0;w<=W;w++)
		{
			if(i==0 || w==0)
			{
				K[i][w] = 0;
			}
			else if(wt[i-1] <= w)
			{
				int include_item = val[i-1] + K[i-1][w-wt[i-1]];
				int exclude_item = K[i-1][w];
				K[i][w] = max(include_item,exclude_item);
			}
			else
			{
				K[i][w] = K[i-1][w];
			}
			printTable(K,n,W);
		}
	}
	
	int res = K[n][W];
	int w =W;
	int included[]={0};
	
	for(int i=n;i>0;i--)
	{
		if(res != K[i-1][w])
		{
			included[i] = 1;
			res -= val[i-1];
			w -= wt[i-1];
		}
		else
		{
			included[i] =0;
		}
	}
	cout<<"\nThe 0/1 representation is : ";
	for(int i=0;i<n;i++)
	{
		cout<<" "<<included[i]<<" ";
	}
	return K[n][W];
}
int main()
{
	int n;
	cout<<"\nEnter the number of objects : ";
	cin>>n;
	
	int W;
	cout<<"\nEnter the capacity of the knapsack : ";
	cin>>W;
	
	int val[n];
	int wt[n];
	
	for(int i =0;i<n;i++)
	{
		cout<<"\nEnter the value of the knapsack : ";
		cin>>val[i];
		cout<<"\nEnter the weight of the knapsack : ";
		cin>>wt[i];
	}
	
	int a = knapsack(W,wt,val,n);
	cout<<"\nMaximun profit is : "<<a;
	return 0;
}
