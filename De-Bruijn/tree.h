#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>

struct node
{
	char key[1000];
	struct node *left;
	struct node *right;
};

void insert(char[]);
struct node *insertr(struct node *,struct node *);
void traverse();
int inOrder(struct node *,char[][1000],int);
void graph(char[][1000],int);
void euler(int[][1000],int,char[][1000]);
int oddDegreeVertex(int[][1000],int);
int degree (int,int[][1000],int);
int printEulerTour(int,int[][1000],int,int[],int[],int,int);
int isVaildNextEdge (int,int,int[][1000],int);
int DFSCount (int,int[],int[][1000],int);
void removeEdge (int,int,int[][1000],int);
void addEdge (int,int,int[][1000],int);
void assemble(int[1000],int[1000],int,char[][1000]);
