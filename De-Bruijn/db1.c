#include "tree.h"

void graph(char string[][1000],int n)
{
	int i,j,l,k,m;
	char k1[1000][1000],k2[1000][1000];
	int debruijn[1000][1000];
	int len=strlen(string[0]);
	for(i=0;i<n;i++)
	{
		strcpy(k1[i],string[i]+1);
		strncpy(k2[i],string[i],len-1);
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(strcmp(k1[i],k2[j])==0)
				debruijn[i][j]=1;
			else
				debruijn[i][j]=0;
		}
	}
				
	m=n+1;
	euler(debruijn,m,string);

}

void assemble(int source[1000],int destination[1000],int m,char string[][1000])
{
	int i,j,k,len,len1;
	char result[5000];
	
	len1=strlen(string[0]);
	
	for(i=0;i<m;i++)
	{
		k=i-1;
		
		if(i==0)
		{
			strcpy(result,string[source[i]]);
			len=strlen(result);
			result[len++]=string[destination[i]][len1-1];
		}
		
		else
		{
			if(source[i]==destination[k])
			{
				result[len++]=string[destination[i]][len1-1];
			}
		}
	}
	

	result[len]='\0';
	
	printf("\nRESULT:  %s\n",result);

}
