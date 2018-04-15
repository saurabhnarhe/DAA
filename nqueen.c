#include<stdio.h>
#include<math.h>

int x[20],count=0;

void queen(int row,int n);
int main()
{
	int n;
	printf("\n enter number of queens:");
	scanf("%d",&n);
	queen(1,n);
	return 0;
}

void print(int n)
{
	int i,j; 
	printf("\n\nSolution %d:\n\n",++count);
	
	
	for(i=1;i<=n;i++)
	{
		printf("\n\n");
		for(j=1;j<=n;j++)
		{
			if(x[i]==j)
				printf("\tQ%d",i);
			else
				printf("\t*");	
		}
	}
}
int place(int row,int col)
{	int i;
	for(i=1;i<=row-1;i++)//
	{
		if(x[i]==col)
			return 0;
		else
			if(abs(x[i]-col)==abs(i-row))
			return 0;
		
	}	
	return 1;
}
void queen(int row,int n)
{
	int i;
	for(i=1;i<=n;i++) //
	{
		if(place(row,i))
		{
			x[row]=i;
			if(row==n)
			print(n);
			else
			queen(row+1,n);
		}
	}
				
}
	
