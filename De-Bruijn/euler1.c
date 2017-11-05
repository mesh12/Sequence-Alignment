# include "tree.h"

void euler(int debruijn[][1000],int n,char string[][1000])
{
	int vertex = 0;
	int source[1000],destination[1000],k,k1,j;
	int i=0;
	k=k1=0;
	
	if (oddDegreeVertex(debruijn,n) != -1)
	{
		vertex = oddDegreeVertex(debruijn,n);

	}

      i=printEulerTour(vertex,debruijn,n,source,destination,k,k1);
      
      assemble(source,destination,i,string);
      
}

int oddDegreeVertex (int debruijn[][1000],int n)
{
	int vertex ,i;
	
	vertex=-1;

        for (i=0;i<n;i++) 
	{
		if ((degree(i,debruijn,n) % 2) != 0)
		{
			vertex = i;
			break;
		}

        }

        return vertex;

}

int degree (int vertex,int debruijn[][1000],int n)
{
	int degree = 0;
	int i;
	
        for (i=0;i<n;i++)

        {

            if (debruijn[vertex][i] == 1 )

            {

                degree++;

            }

        }

        return degree;
}

int printEulerTour (int vertex,int debruijn[][1000],int n,int source[],int destination[],int k,int k1)
{
	int i,c;
	c=0;
	
	for (i=0;i<n;i++)
	  {
        	if(debruijn[vertex][i] == 1 && isVaildNextEdge(vertex,i,debruijn,n))
		{
			source[k++]=vertex;
			destination[k1++]=i;
                  removeEdge(vertex,i,debruijn,n);
                  c=1+printEulerTour(i,debruijn,n,source,destination,k,k1);
		}	
	  }
	  
	  return c;
}

int isVaildNextEdge (int x, int y,int debruijn[][1000],int n)

{

	int count = 0;
	int i;
	int visited[n+1];		


        for (i=0;i<n;i++)

        {

            if (debruijn[x][i] == 1)

            {

                count++;

            }

        }

 

        if (count == 1 )

        {   

            return 1;

        }

        int count1 = DFSCount(x, visited,debruijn,n);


        removeEdge(x, y,debruijn,n);

        for (i=0;i<n;i++)

        {

            visited[i] = 0;

        }
        
        int count2 = DFSCount(x, visited,debruijn,n);

       addEdge(x,y,debruijn,n);

       return (count1 > count2 ) ?0:1;
}

int DFSCount (int x, int visited[],int debruijn[][1000],int n)
{

        visited[x] = 1;

        int count = 1;

        int j = 1;

 

        while (j <n)

        {

            if(debruijn[x][j] == 1 && visited[j] == 0)

            {

                count += DFSCount(j, visited,debruijn,n);

            }

            j++;

        }

        return count;

}

void removeEdge (int i, int j,int debruijn[][1000],int n)
{
	debruijn[i][j]  = 0;
	

}

void addEdge (int i, int j,int debruijn[][1000],int n)
{
	debruijn[i][j]=1;
	
}
