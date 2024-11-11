#include<bits/stdc++.h>
using namespace std;

struct MinHeapNode
{
	char data;
	unsigned freq;
	MinHeapNode *left,*right;
	
	MinHeapNode(char data,unsigned freq)
	{
		left = right = NULL;
		this -> data = data;
		this -> freq = freq;
	}
};
struct compare
{
	bool operator()(MinHeapNode *l,MinHeapNode *r)
	{
		return (l -> freq > r -> freq);
	}
};
void printCodes(MinHeapNode *root,string str)
{
	if(!root)
		return;
	
	if(root -> data != '$')
		cout<<root -> data <<" : "<<str<<endl;
	
	printCodes(root -> left,str+"0");
	printCodes(root -> right,str+"1");
}
void HuffmanCodes(char data[],int freq[],int size)
{
	struct MinHeapNode *left,*right,*top;
	priority_queue<MinHeapNode*,vector<MinHeapNode*>,compare> minHeap;
	int i;
	for(i=0;i<size;i++)
	{
		minHeap.push(new MinHeapNode(data[i],freq[i]));
	}
	while(minHeap.size() != 1)
	{
		left = minHeap.top();
		minHeap.pop();
		
		right = minHeap.top();
		minHeap.pop();
		
		top = new MinHeapNode('$',left->freq + right->freq);
		top->left = left;
		top->right = right;
		minHeap.push(top);
	}
	cout<<"\nThe huffman encoding for the charachters is "<<endl;
	printCodes(minHeap.top(),"");
}
int main()
{
	int n;
	cout<<"\nEnter the Number of characters : ";
	cin>>n;
	
	char* arr = new char[n];
	int* freq = new int[n];
	
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter character: ";
		cin>>arr[i];
		cout<<"\nEnter frequency: ";
		cin>>freq[i];
	}
	HuffmanCodes(arr,freq,n);
	delete[] arr;
	delete[] freq;
	return 0;
}
