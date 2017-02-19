#include <stdio.h>
#include <stdlib.h>
#define MaxVertexNum 1000
#define FALSE 0
#define TRUE 1
typedef struct node{
	int AdjN;
	struct node *next;
}EdgeNode;
typedef struct{
	int Vertex;
	EdgeNode *FirstEdge;
}VertexNode;
typedef struct{
	VertexNode AdjList[MaxVertexNum];
	int n,e,k;
	int check[MaxVertexNum];

}ALGraph;
int visited[MaxVertexNum];
void CreatGraph(ALGraph *G);
int DFS_ALG(ALGraph *G);
void dfs(ALGraph *G,int i);
void clear(ALGraph *G);
int main(){
	int i=0;
	ALGraph *G;
	G=(ALGraph*)malloc(sizeof(ALGraph));
	CreatGraph(G);
	if((G->n==1)||(G->k==0)){
		printf("0");
		return 0;
	}
	for(i=0;i<G->k;i++){
		visited[G->check[i]]=TRUE;
		printf("%d\n",DFS_ALG(G)-1);
		clear(G);
	}
	return 0;
}
void CreatGraph(ALGraph *G){
	EdgeNode *edge;
	int i;
	int temp1,temp2;
	scanf("%d %d %d",&G->n,&G->e,&G->k);
	for(i=1;i<G->n+1;i++){
		G->AdjList[i].FirstEdge=NULL;
		G->AdjList[i].Vertex=0;
	}
	for(i=0;i<G->e;i++){
		edge=(EdgeNode*)malloc(sizeof(EdgeNode));
		scanf("%d%d",&temp1,&temp2);
		edge->AdjN=temp2;
		edge->next=G->AdjList[temp1].FirstEdge;
		G->AdjList[temp1].FirstEdge=edge;
		//邻接表存储时，因为是无向图，以他们各自我顶点的都要存储
		edge=(EdgeNode*)malloc(sizeof(EdgeNode));
		edge->AdjN=temp1;
		edge->next=G->AdjList[temp2].FirstEdge;
		G->AdjList[temp2].FirstEdge=edge;
	}
	for(i=0;i<G->k;i++){
		scanf("%d",&G->check[i]);
	}
	for(i=1;i<G->n+1;i++){
		visited[i]=FALSE;
	}
}
int DFS_ALG(ALGraph *G){
	int i;
	int ContectNum=0;
	for(i=1;i<G->n+1;i++){
		if(!visited[i]){
			dfs(G,i);
			ContectNum++;//表示连通分量的个数,进一次表示有一个连通分量
		}
	}
	return ContectNum;
}
void dfs(ALGraph *G,int i){
	EdgeNode *p;
	visited[i]=TRUE;
	for(p=G->AdjList[i].FirstEdge;p!=NULL;p=p->next){
		if(!visited[p->AdjN]){
			dfs(G,p->AdjN);
		}
	}
}
void clear(ALGraph *G){
	int i;
	for(i=1;i<G->n+1;i++){
		visited[i]=FALSE;
	}
}