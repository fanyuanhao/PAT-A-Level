#include <stdio.h>
#include <stdlib.h> 
static int j;
typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}List;
List* BulidTree(int post[],int in[],int N);
void PreOrder(List *T);
int main(){
	int N;
	scanf("%d",&N);
	int post[N],in[N];
	int i;
	for(i=0;i<N;i++){
		scanf("%d",&post[i]);
	}
	for(i=0;i<N;i++){
		scanf("%d",&in[i]);
	}
	List *ROOT=BulidTree(post,in,N);
	PreOrder(ROOT);
	return 0;
} 
List* BulidTree(int post[],int in[],int N){//N��ʾ���������н��ĸ��� 
	if(N==0){
		return NULL;
	}else{
		List *root=(List*)malloc(sizeof(struct node));
		root->data=post[N-1];
		for(j=0;j<N;j++){
			if(in[j]==root->data){
				break;
			}
		}
		root->left=BulidTree(post,in,j);
		root->right=BulidTree(post+j,in+j+1,N-j-1);//����ָ�������ƶ�jλ���������Ķ����Ͳ����� 
		return root;
	}
}
void PreOrder(List *T){
	if(T!=NULL){
		printf("%d ",T->data);
		PreOrder(T->left);
		PreOrder(T->right);
	}
}
