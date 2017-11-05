#include "tree.h"

struct node *root=NULL;

int main()
{
	struct timeval  tv1, tv2;
	int test;
	int n,i,j,l,num,t;
	char string[1000][1000],c[1000];
	int k=5;
	
	scanf("%d",&test);
	
	while(test>0)
	{
		scanf("%d\n",&num);
		for(i=0;i<num;i++)
		{
			scanf("%s",string[i]);
		}
		
		gettimeofday(&tv1, NULL);	

		for(t=0;t<num;t++)
		{
			n=strlen(string[t]);
			for(i=0;i<n-k+1;i++)
			{
				l=0;
				for(j=i;j<i+k;j++)
				{
					c[l++]=string[t][j];
				}
				
				insert(c);
			}
		}
		traverse();
		
		gettimeofday(&tv2, NULL);

		printf ("Total time = %f seconds\n",
		   (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
		   (double) (tv2.tv_sec - tv1.tv_sec));
		
		test--;
	}
	return 0;
}
