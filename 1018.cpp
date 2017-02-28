#include <iostream>
#include <vector>
using namespace std;
const int Max=510;
const int inf=9999;
typedef struct{
	int VertexBikeNum[Max];
	int Edge[Max][Max];
	int Distance[Max];
	bool Visited[Max];
	int N;
	int Problem;
	int e;
	int cmax;
}MGraph;
vector<int> allPath[Max];
vector<int> possiblePath;
vector<int> bestPath;
int minsend=inf;
int mincollect=inf;
void dfs(int v,MGraph *G);
void Dijkstra(MGraph *G);
int main(){
	FILE *fin;
	fin=fopen("input.txt","r");
	//fin=stdin;
	MGraph *G;
	G=(MGraph*)malloc(sizeof(MGraph));
	fscanf(fin,"%d %d %d %d",&G->cmax,&G->N,&G->Problem,&G->e);
	int i,j;
	G->N++;//PBMC包含进来
	//初始化图
	for(i=0;i<G->N;i++){
		G->Distance[i]=inf;
		G->Visited[i]=false;
		for(j=0;j<G->N;j++){
			G->Edge[i][j]=inf;
		}
	}
	//读入图的顶点信息
	for(i=1;i<G->N;i++){
		fscanf(fin,"%d",&G->VertexBikeNum[i]);
	}
	//读入图的边信息
	int A,B;
	for(i=0;i<G->e;i++){
		fscanf(fin,"%d %d",&A,&B);
		fscanf(fin,"%d",&G->Edge[A][B]);
		G->Edge[B][A]=G->Edge[A][B];
	}
	Dijkstra(G);
	/*测试
	for(i=0;i<G->N;i++){
		printf("%d %d\n",i,G->Distance[i]);
	}

	*/
	dfs(G->Problem,G);
	printf("%d 0",minsend);
	for(i=bestPath.size()-2;i>=0;i--){
		printf("->%d",bestPath[i]);
	}
	printf(" %d",mincollect);
	fclose(fin);
	return 0;
}
void Dijkstra(MGraph *G){
	int i,j,k;
	int min;
	//初始化距离
	for(i=0;i<G->N;i++){
		G->Distance[i]=G->Edge[0][i];
	}
	for(i=0;i<G->N;i++){
		if(G->Distance[i]<inf){
			allPath[i].push_back(0);
		}
	}
	G->Distance[0]=0;
	G->Visited[0]=true;

	for(i=1;i<G->N;i++){
		//寻找当前最短距离
		min=inf;
		for(j=0;j<G->N;j++){
			if(!G->Visited[j]&&G->Distance[j]<min){
				min=G->Distance[j];
				k=j;
			}
		}
		if(min==inf){
			return;
		}
		G->Visited[k]=true;
		//更新路径长度
		for(j=0;j<G->N;j++){
			if(!G->Visited[j]){
				if(G->Distance[j]>G->Edge[k][j]+min){
					G->Distance[j]=G->Edge[k][j]+min;
					allPath[j].clear();//找到更小的了，清空之前记录的父节点
					allPath[j].push_back(k);
				}else if(G->Distance[j]==G->Edge[k][j]+min){
					allPath[j].push_back(k);//每个结点都记录它所有的父节点
				}
			}
		}
	}
}
void dfs(int v,MGraph *G){
	possiblePath.push_back(v);
	if(v==0){
		int send=0,collect=0;
		for(int i=possiblePath.size()-2;i>=0;i--){
			int t=possiblePath[i];
			if(G->VertexBikeNum[t]>G->cmax/2){
				collect+=G->VertexBikeNum[t]-G->cmax/2;
			}else if(G->VertexBikeNum[t]<G->cmax/2){
				collect-=G->cmax/2-G->VertexBikeNum[t];
				if(collect<0){
					send=send-collect;
					collect=0;
				}
			}
		}
		if(send<minsend){
			minsend=send;
			mincollect=collect;
			bestPath=possiblePath;
		}else if(send==minsend&&collect<mincollect){
			mincollect=collect;
			bestPath=possiblePath;
		}
		return;
	}
	for(int i=0;i<allPath[v].size();i++){
		dfs((int)allPath[v][i],G);
		/*因为是STL，调试的时候会调用别的函数，
		不是进不去dfs，而是别的函数也会调用函数，如果按F10的话，直接跳过调用的函数了*/
		possiblePath.pop_back();
	}
}