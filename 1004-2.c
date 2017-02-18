#include <stdio.h>
#include <stdlib.h>
#define MaxNodeNum 101
typedef struct l{
	int node;
	struct l *next;
}Child;
typedef struct{
	int PNode;
	Child *firstnode;
}Parent;
typedef struct{
	Parent parent[MaxNodeNum];
	int N;
	int M;
	int level[MaxNodeNum];
	int maxdepth;
}Tree;
void CreatTree(Tree *T);
void dfs(Tree *T,int index,int depth);
int main(){
	Tree *T;
	int i;
	T=(Tree*)malloc(sizeof(Tree));
	CreatTree(T);
	dfs(T,1,1);
	for(i=1;i<=T->maxdepth;i++){
		if(i==T->maxdepth){
			printf("%d",T->level[i]);
		}else{
			printf("%d ",T->level[i]);
		}
	}
	return 0;
}
void CreatTree(Tree *T){
	int K;
	int i,j;
	int index;
	Child *child; 
	scanf("%d %d",&T->N,&T->M);
	for(i=1;i<MaxNodeNum;i++){
		T->parent[i].firstnode=NULL;
		T->level[i]=0;//��Ϊ������ڵ�һ��
	}
	T->maxdepth =-1;
	for(i=0;i<T->M;i++){//Ϊ����child��node��ֵ��parent��index��Ӧ����01����Ӧparent�±�Ϊ1
		scanf("%d %d",&index,&K);
		T->parent[index].PNode=index;
		/*
		������Ϊ�˽����±�͸��ڵ�ֵ�Ķ�Ӧ��ϵ
		���scanf("%d %d",&T->parent[i].PNode,&K);�±�͸��ڵ�ֵ����Ӧ���ᵼ�¸���child�н���ֵ��Ӧ���±겻�Ǹ��ڵ�ֵ���±�
		*/
		for(j=0;j<K;j++){
			child=(Child*)malloc(sizeof(Child));
			scanf("%d",&child->node);//��Ȼchild��һ��ָ���������child->node���ǣ�������Ҫ��&
			child->next=T->parent[index].firstnode;
			T->parent[index].firstnode=child;
		}
	}
}
void dfs(Tree *T,int index,int depth){
	Child *p;
	if(T->parent[index].firstnode==NULL){
		T->level[depth]++;
		if(depth>T->maxdepth){
			T->maxdepth=depth;
		}
		return;
	}
	for(p=T->parent[index].firstnode;p!=NULL;p=p->next){
		dfs(T,p->node,depth+1);
	}
}