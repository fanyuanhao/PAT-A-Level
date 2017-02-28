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
	G->N++;//PBMC��������
	//��ʼ��ͼ
	for(i=0;i<G->N;i++){
		G->Distance[i]=inf;
		G->Visited[i]=false;
		for(j=0;j<G->N;j++){
			G->Edge[i][j]=inf;
		}
	}
	//����ͼ�Ķ�����Ϣ
	for(i=1;i<G->N;i++){
		fscanf(fin,"%d",&G->VertexBikeNum[i]);
	}
	//����ͼ�ı���Ϣ
	int A,B;
	for(i=0;i<G->e;i++){
		fscanf(fin,"%d %d",&A,&B);
		fscanf(fin,"%d",&G->Edge[A][B]);
		G->Edge[B][A]=G->Edge[A][B];
	}
	Dijkstra(G);
	/*����
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
	//��ʼ������
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
		//Ѱ�ҵ�ǰ��̾���
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
		//����·������
		for(j=0;j<G->N;j++){
			if(!G->Visited[j]){
				if(G->Distance[j]>G->Edge[k][j]+min){
					G->Distance[j]=G->Edge[k][j]+min;
					allPath[j].clear();//�ҵ���С���ˣ����֮ǰ��¼�ĸ��ڵ�
					allPath[j].push_back(k);
				}else if(G->Distance[j]==G->Edge[k][j]+min){
					allPath[j].push_back(k);//ÿ����㶼��¼�����еĸ��ڵ�
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
		/*��Ϊ��STL�����Ե�ʱ�����ñ�ĺ�����
		���ǽ���ȥdfs�����Ǳ�ĺ���Ҳ����ú����������F10�Ļ���ֱ���������õĺ�����*/
		possiblePath.pop_back();
	}
}