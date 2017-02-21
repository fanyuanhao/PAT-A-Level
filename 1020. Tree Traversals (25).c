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
List* BulidTree(int post[],int in[],int N){//N表示的是子树中结点的个数 
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
		root->right=BulidTree(post+j,in+j+1,N-j-1);//数组指针往后移动j位，左子树的东西就不管了 
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
