#include<iostream>
using namespace std;

int fibo_recursive(int n)
{
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	return fibo_recursive(n-1) + fibo_recursive(n-2);	
}
void print_fibo_recursive_sequence(int n)
{
	for(int i=0;i<=n;i++)
	{
		cout<<fibo_recursive(i)<<" ";
	}
	cout<<endl;
}
int print_fibo_iterative_sequence(int n)
{
	int a =0,b=1,c;
	cout<<a<<" ";
	for(int i=1;i<=n;i++)
	{
		cout<<b<<" ";
		c = a+b;
		a = b;
		b = c;
	}
	return a;
}
int main()
{
	
	while(true)
	{
		int n;
		int ch;
		cout<<"\nEnter n: ";
		cin>>n;
		cout<<"\n--------------Menu--------------"<<endl;
		cout<<"1.Recursive"<<endl;
		cout<<"2.Non-Recursive"<<endl;
		cout<<"3.Exit"<<endl;
		cout<<"\n Enter you choice : ";
		cin>>ch;
		
		if(ch==1)
		{
			cout<<"\nFibbonaci sequence upto "<<n<<" is : ";
			print_fibo_recursive_sequence(n);
			int a = fibo_recursive(n);
			cout<<n<<"th fibonacci number is : "<<a<<endl;
		}
		else if(ch == 2)
		{
			cout<<"\nFibbonaci sequence upto "<<n<<" is : ";
			int a = print_fibo_iterative_sequence(n);
			cout<<endl<<n<<"th fibonacci number is : "<<a<<endl;
		}
		else
		{
			break;
		}
	}
	return 0;
}

