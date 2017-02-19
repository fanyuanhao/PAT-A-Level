#include <iostream>
using namespace std;
const int MaxVertexNum=505;
const int INFINITY=505;
const int MaxSize=50;

typedef struct{
	//int Vertices[MaxVertexNum];
	int Distance[MaxVertexNum][MaxVertexNum];
	int Cost[MaxVertexNum][MaxVertexNum];
	int D[MaxVertexNum];
	int C[MaxVertexNum];
	int P[MaxVertexNum];
	int n,e,s,d;
}MGraph;
void Dijkstra(MGraph *G,int v0);
void CreateMGraph(MGraph *G,FILE *fin);
int main(){
	FILE *fin;	
	fin=fopen("input.txt","r");
	//fin=stdin;
	int Parent[MaxSize];
	int top=-1;
	MGraph *G;
	G=(MGraph*)malloc(sizeof(MGraph));
	CreateMGraph(G,fin);
	Dijkstra(G,G->s);
	int temp=G->d;
	while(temp!=G->s){
		Parent[++top]=temp;
		temp=G->P[temp];
	}
	Parent[++top]=G->s;
	while(top!=-1){
		cout<<Parent[top--]<<" ";
	}
	cout<<G->D[G->d]<<" "<<G->C[G->d];
	fclose(fin);
	return 0;
}
void CreateMGraph(MGraph *G,FILE *fin){
	
	fscanf(fin,"%d %d %d %d",&G->n,&G->e,&G->s,&G->d);
	int i,j,k;
	for(i=0;i<G->n;i++){
		for(j=0;j<G->n;j++){
			G->Cost[i][j]=INFINITY;
			G->Distance[i][j]=INFINITY;
		}
	}
	for(k=0;k<G->e;k++){
		fscanf(fin,"%d %d",&i,&j);
		fscanf(fin,"%d %d",&G->Distance[i][j],&G->Cost[i][j]);
		G->Distance[j][i]=G->Distance[i][j];
		G->Cost[j][i]=G->Cost[i][j];
	}
	
}
void Dijkstra(MGraph *G,int v0){
	bool Final[MaxVertexNum];
	int i,j,k,min_d,min_c;
	for(i=0;i<G->n;i++){
		Final[i]=false;
		G->D[i]=G->Distance[v0][i];
		G->C[i]=G->Cost[v0][i];
	}
	for(j=0;j<G->n;j++){
		if(G->D[j]<INFINITY){
			G->P[j]=v0;
		}
	}
	G->D[v0]=0;
	Final[v0]=true;
	for(i=1;i<G->n;i++){
		min_d=INFINITY-1;
		min_c=INFINITY-1;
		for(j=0;j<G->n;j++){
			if(!Final[j]){
				if(G->D[j]<=min_d){
					if(G->D[j]<min_d){
						min_d=G->D[j];
						k=j;
					}
					if(G->C[j]<min_c){
						min_c=G->C[j];
						k=j;
					}
				}
			}
		}
		if(min_d<INFINITY){
			Final[k]=true;
		}else{
			break;
		}
		for(j=0;j<G->n;j++){
			if(!Final[j]&&(min_d+G->Distance[k][j])<=G->D[j]){
				if(min_d+G->Distance[k][j]<G->D[j]){
					G->D[j]=min_d+G->Distance[k][j];
					G->C[j]=min_c+G->Cost[k][j];
					G->P[j]=k;
				}
				
				if(min_c+G->Cost[k][j]<G->C[j]){
					G->C[j]=min_c+G->Cost[k][j];
					G->P[j]=k;
				}
				
			}
		}
	}
}