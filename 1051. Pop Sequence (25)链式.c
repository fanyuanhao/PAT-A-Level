#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *next;
} Stack;
int StackSize(Stack *S);
int main(){
	int m,n,k;
	scanf("%d%d%d",&m,&n,&k);

	int i,j,count;
	Stack *Top=(Stack*)malloc(sizeof(Stack));//建立头结点 
	Top->next=NULL;
	
	int b[k];
	int v[n];
	for(i=0;i<k;i++){
		for(j=0;j<n;j++){
			scanf("%d",&v[j]);
		}
		count=0;
		for(j=0;j<n;j++){
		
			//插入 
			Stack *p=(Stack*)malloc(sizeof(Stack));
			p->data=j+1;
			p->next=Top->next;
			Top->next=p;
			
			if(StackSize(Top)>m){
				break;
			}
			while((Top->next!=NULL)&&(Top->next->data==v[count])){
				Stack *First;
				First=Top->next;
				Top->next=First->next; 
				free(First);//删除 
				count++; 
			}
		}
		//Top->next=NULL;
		//每个序列判断完后，把该序列的所有结点清空
		//因为顺序存储可以覆盖，而链式存储一直存 
		while(Top->next!=NULL){
			Stack *First;
			First=Top->next;
			Top->next=First->next; 
			free(First);
		} 
		
		if(count==n){
			printf("YES\n");//输出格式要换行 
		}else{
			printf("NO\n");
		}
	}

	return 0;
} 
int StackSize(Stack *S){
	int cnt=0;
	Stack *p=S->next;
	while(p){
		cnt++;
		p=p->next;
	}
	return cnt;
}
