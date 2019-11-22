#include<stdio.h>

struct node
{
	unsigned dist[20];
	unsigned from[20];
}rt[10];

int main()
{
	int dmat[20][20];
	int n,i,j,k,count=0;
	printf("\nEnter the number of nodes : ");
	scanf("%d",&n);
	printf("\nEnter the cost matrix :\n");
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{	
			scanf("%d",&dmat[i][j]);
			dmat[i][i]=0;
			rt[i].dist[j]=dmat[i][j];
			rt[i].from[j]=j;
		}
		do
		{	
			count=0;
			for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			for(k=0;k<n;k++)
				if(rt[i].dist[j]>dmat[i][k]+rt[k].dist[j])
				{
					rt[i].dist[j]=rt[i].dist[k]+rt[k].dist[j];
					rt[i].from[j]=k;
					count++;
				}
		}while(count!=0);
		for(i=0;i<n;i++)
		{
			printf("\n\nState value for router %d is \n",i+1);
			for(j=0;j<n;j++)
			{
				printf("\t\nnode %d via %d Distance%d",j+1,rt[i].from[j]+1,rt[i].dist[j]);
			}
		}	
	printf("\n\n");
}
/*
OUTPUT
Enter the number of nodes : 4

Enter the cost matrix :
0 2 7 3
2 0 1 4
7 1 0 6
3 4 6 0


State value for router 1 is 
	
node 1 via 1 Distance0	
node 2 via 2 Distance2	
node 3 via 2 Distance3	
node 4 via 4 Distance3

State value for router 2 is 
	
node 1 via 1 Distance2	
node 2 via 2 Distance0	
node 3 via 3 Distance1	
node 4 via 4 Distance4

State value for router 3 is 
	
node 1 via 2 Distance3	
node 2 via 2 Distance1	
node 3 via 3 Distance0	
node 4 via 2 Distance5

State value for router 4 is 
	
node 1 via 1 Distance3	
node 2 via 2 Distance4	
node 3 via 2 Distance5	
node 4 via 4 Distance0
*/
