#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int v[100][100];
	int *vsize;
}TreeNode;
int maxdepth=-1;
void dfs(TreeNode* Node,int *level,int index,int depth);
int main(){
	int N,M;
	TreeNode *Node;
	int i,j;
	int node,K;
	int* level;
	scanf("%d%d",&N,&M);
	/*allocate space*/
	Node=(TreeNode*)malloc(sizeof(TreeNode));
	//Node->v=(int**)malloc(sizeof(int*)*(N+1));//indexΪ0�Ĳ����data
	
	Node->vsize=(int*)malloc(sizeof(int)*(N+1));//vsize express һάarray�Ĵ�С
	
	/*supposed there are N level,every level don't have leafnode*/
	level=(int*)malloc(sizeof(int)*N);
	for(i=0;i<N;i++){
		level[i]=0;
	}
	/*initialize*/
	for(i=0;i<N+1;i++){
		Node->vsize[i]=0;
		for(j=0;j<N;j++){
			Node->v[i][j]=0;
		}
	}

	for(i=0;i<M;i++){
		scanf("%d %d",&node,&K);
		Node->vsize[node]=K;//node���ӽ��ĸ���
		for(j=0;j<K;j++){
			scanf("%d",&(Node->v[node][j]));
			//�������õ�node�����±������֮����child's value�ݹ��ʱ��
			//�����Ƿ�parent from small to big˳������,���ܶ�Ӧ����
		}
	}
	dfs(Node,level,1,0);
	for(i=0;i<=maxdepth;i++){//care about the maxdepth don't like N or M
		if(i==maxdepth){
			printf("%d",level[i]);
		}else{
			printf("%d ",level[i]);
		}
	}
	return 0;
}
void dfs(TreeNode* Node,int *level,int index,int depth){
	int i;
	if(Node->vsize[index]==0){
		level[depth]++;
		//ȷ�������ȣ�֮����������ʱ��ñ���
		if(depth>maxdepth){
			maxdepth=depth;
		}
		return;
	}
	for(i=0;i<Node->vsize[index];i++){
		dfs(Node,level,Node->v[index][i],depth+1);
	}
}