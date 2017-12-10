/*
Authors : Raksha and Shobhana Ganesh
Term : January 2015 - May 2015
Analysis and design of algorithms project
*/

#include<stdio.h>
#include<string.h>
#include<sys/time.h>

int assembly(char[900][900],int,int[900][900],int [900][900]);
int score(char [900],char [900],int[900][900]);
int simval(char,char);
int Max(int,int,int);
void alignment(char[900],char[900],char[900],char[900],int[900][900]);
void reverse(char[]);
int assemblyProcess(char[900][900],int,int[900][900],int,int,int[900][900]);
void merge(int ,int,int,int,int,int,int [900][900],char [900][900]);
void changeS(int,int ,int ,int *,int *,int *,int [900][900]);


int main()
{

	struct timeval  tv1, tv2;
	int test;
	int i;
	int n;//number of strings
	//int m;//length of strings
	char input[900][900];
	int M[900][900];
	int S[900][900];
	
	scanf("%d",&test);
	
	while(test>0)
	{
	
		scanf("%d\n",&n);
		//scanf("%d\n",&m);
		for(i=0;i<n;i++)
		{
			scanf("%s",input[i]);
		}
	
		gettimeofday(&tv1, NULL);	
	
		int new=assembly(input,n-1,M,S);
	
		printf("\n%s\n",input[new]);
	
		gettimeofday(&tv2, NULL);

		printf ("Total time = %f seconds\n",
		   (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
		   (double) (tv2.tv_sec - tv1.tv_sec));
		   
		   test--;
	}
	
	return 0;
}

int assembly(char input[900][900],int n,int M[900][900],int S[900][900])
{
	int i,j,k;
	int max,maxi,maxj;
	
	max=-9000;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n;j++)
		{
			S[i][j]=-1;
		}
	}
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			S[i][j]=score(input[i],input[j],M);
			
			if(S[i][j]>max)
			{
				max=S[i][j];
				maxi=i;
				maxj=j;
			}
		}
	}
	
	int new=assemblyProcess(input,n,S,maxi,maxj,M);
	return new;
	
}

int assemblyProcess(char input[900][900],int n,int S[900][900],int maxi,int maxj,int M[900][900])
{
	int x,new,mod;
	int i,j;
	int max;
	int n1=n;
	x=n-1;
	
	while(x>=0)
	{
		if(maxi<maxj)
		{
			new=maxi;
			mod=maxj;
		}
		
		else
		{
			new=maxj;
			mod=maxi;
		}
		
		merge(maxi,maxj,new,mod,n1,n,M,input);
		
		max=-900;
		changeS(n,new,mod,&max,&maxi,&maxj,S);
		
	x--;
	n1--;
	}
return new;
}

void merge(int maxi,int maxj,int new,int mod,int n1,int n,int M[900][900],char input[900][900])
{
	char A[900],B[900];
		
		int k=0;
		int i;
		
		
		int sc=score(input[maxi],input[maxj],M);
		
		alignment(A,B,input[maxi],input[maxj],M);
		
		while(k!=(strlen(A)) && k!=(strlen(B)))
		{
			if(A[k]=='-')
			{
				input[new][k]=B[k];
			}
			
			else
			{
				input[new][k]=A[k];
			}
			
			k++;
		}
		
		if(k!=strlen(A))
		{
			while(k!=strlen(A)-1)
			{
				input[new][k]=A[k];
				k++;
			}
		}
		
		else if(k!=strlen(B))
		{
			while(k!=strlen(B)-1)
			{
				input[new][k]=B[k];
				k++;
			}
		}
		
		
		for(i=0;i<=n1;i++)
		{
			input[mod][i]='z';
		}
		
}

void changeS(int n,int new,int mod,int *max,int *maxi,int *maxj,int S[900][900])
{
	int i,j,t,q;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i!=mod && j!=mod && S[i][j]>0)
			{
				if(i==new)
				{
					if(new<j)
						t=S[new][j];
					else t=S[j][new];
					if(mod<j)
						q=S[mod][j];
					else q=S[j][mod];
					S[i][j]=t>q?t:q;
				}	
					
				if(j==new)
				{
					if(new<i)
						t=S[new][i];
					else t=S[i][new];
					if(mod<i)
						q=S[mod][i];
					else q=S[i][mod];
					S[i][j]=t>q?t:q;
				}	
				
				if(S[i][j]>*max)
				{
					*max=S[i][j];
					*maxi=i;
					*maxj=j;
				}
			}
			else
				S[i][j]=-1;
		}
	}
}

int simval(char a,char b)
{
	if(a==b)
		return 2;
	else
		return -1;
}

int score(char str1[900],char str2[900],int M[900][900])
{
	int gap=-1;
	int n=strlen(str1);
	int m=strlen(str2);
	int mi,mj;
	//int M[n][m];
	
	int i,j;
	
	for(i=0;i<n;i++)
		M[i][0]=0;
		
	for(j=0;j<m;j++)
		M[0][j]=0;
		
	for(i=1;i<n;i++)
	{
		for(j=1;j<m;j++)
		{
			M[i][j]=Max(M[i-1][j-1]+simval(str1[i],str2[j]),M[i-1][j]+gap,M[i][j-1]+gap);
		}
	}
	
	int maxi=M[0][m-1];
	
	for(i=1;i<n;i++)
	{
		if(M[i][m-1]>=maxi)
		{
			maxi=M[i][m-1];	
			mi=i;
		}
	}
	
	int maxj=M[n-1][0];
	
	for(j=1;j<m;j++)
	{
		if(M[n-1][j]>=maxj)
		{
			maxj=M[n-1][j];	
			mj=j;
		}
	}
	
	
	if(maxi>maxj)
		return maxi;
	else
		return maxj;
}

int Max(int a,int b,int c)
{
	if(a>=b && a>=c)
	return a;
	
	else if(b>=a && b>=c)
	return b;
	
	else 
	return c;
}

void alignment(char A[900],char B[900],char str1[900],char str2[900],int M[900][900])
{
	int n,m,i,j,k,h,flag;
	
	n=strlen(str1);
	m=strlen(str2);
	
	i=n-1;
	j=m-1;
	
	flag=0;
	
	k=h=0;
	
	while(i>0 && j>0)
	{
		int val=Max(M[i-1][j-1],M[i-1][j],M[i][j-1]);
		
		if( M[i-1][j-1]==val)
		{
			A[k++]=str1[i];
   			B[h++]=str2[j];
			i--;
			j--;
			
		}
		
		else if(M[i-1][j]==val)
		{
			A[k++]=str1[i];
   			B[h++]='-'; 
    			i--;
    			
		}
		
		else if(M[i][j-1]==val)
  		{
    			A[k++]='-';
    			B[h++]=str2[j];
    			j--;
    		
  		}
	}
	
	if(i==0)
	{
		A[k++]=str1[0];
		B[h++]=str2[j];
		j--;
		while(j>=0)
		{
			A[k++]='-';
			B[h++]=str2[j];
			j--;
		}
	}
	
	else if(j==0)
	{
		B[h++]=str2[0];
		A[k++]=str1[i];
		i--;
		while(i>=0)
		{
			B[h++]='-';		
			A[k++]=str1[i];
			i--;
		}
	}
	

	A[k]='\0';
	B[h]='\0';
	
	reverse(A);
	reverse(B);
	
	
}

void reverse(char c[900])
{
	int i,j,len;
	char temp;
	
	len=strlen(c);
	
	i=0;
	j=len-1;
	
	while(i<j)
	{
		temp=c[i];
		c[i]=c[j];
		c[j]=temp;
		i++;
		j--;
	}
}
