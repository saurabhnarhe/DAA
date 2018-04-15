#include<iostream>
using namespace std;

typedef struct fil
{
	char name[20];
	int size;
}fil;

void mergesort(fil A[],int low,int mid,int high)
{
	int a=mid-low+1;
	int b=high-mid;
	
	fil left[100],right[100];
	
	for(int i=0;i<a;i++)
	{
		left[i]=A[low+i];
	}
	for(int j=0;j<b;j++)
	{
		right[j]=A[mid+j+1];
	}
	
	int i=0,j=0,k=low;
	while(i<a && j<b)
	{
		if(left[i].size<right[j].size)
		{
			A[k]=left[i];
			i++;
		}
		else if(left[i].size>right[j].size)
		{
			A[k]=right[j];
			j++;
			
		}
		k++;
	}
	
	while(i<a)
	{
		A[k]=left[i];
		i++;
		k++;
	}
	while(j<b)
	{
		A[k]=right[j];
		j++;
		k++;
		
	}
}

void sort(fil A[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		sort(A,low,mid);
		sort(A,mid+1,high);
		mergesort(A,low,mid,high);
	}
	
}

int main()
{

	fil A[100],B[20][20];
	int l[20]={0},sa[20];
	int m,n,sz,flag;
	cout<<"\nenter the num of files:";
	cin>>n;
	cout<<"\nenter the num of tapes:";
	cin>>m;
	cout<<"\nenter the size of tapes:";
	cin>>sz;
	
	for(int i=0;i<m;i++)
		sa[i]=sz;
		
	cout<<"\nenter the name and size of files:";
	for(int i=0;i<n;i++)
	{
		cout<<"\nenter name and size of file:"<<i+1;
		cin>>A[i].name>>A[i].size;
	}
	
	sort(A,0,n-1);

	for(int i=0;i<n;i++)
	{
		cout<<"\t"<<A[i].name<<"----->"<<A[i].size;
	}
	
	//checking remaining size of tapes
	
	for(int i=0;i<n;i++)
	{
		if(sa[i%m]>=A[i].size)
		{
			B[i%m][l[i%m]]=A[i];
			l[i%m]++;
			sa[i%m]=sa[i%m]-A[i].size;
		}
		else
		{
			cout<<"\n no space available.."<<endl;
			break;
		}
	}

	for(int i=0;i<m;i++) {
		printf("\nTape %d", i);
		for(int j=0;j<l[i];j++) {
			printf("\t%s -> %d", B[i][j].name, B[i][j].size);
		}
	}
		
	return 0;
}
