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
	Stack *Top=(Stack*)malloc(sizeof(Stack));//����ͷ��� 
	Top->next=NULL;
	
	int b[k];
	int v[n];
	for(i=0;i<k;i++){
		for(j=0;j<n;j++){
			scanf("%d",&v[j]);
		}
		count=0;
		for(j=0;j<n;j++){
		
			//���� 
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
				free(First);//ɾ�� 
				count++; 
			}
		}
		//Top->next=NULL;
		//ÿ�������ж���󣬰Ѹ����е����н�����
		//��Ϊ˳��洢���Ը��ǣ�����ʽ�洢һֱ�� 
		while(Top->next!=NULL){
			Stack *First;
			First=Top->next;
			Top->next=First->next; 
			free(First);
		} 
		
		if(count==n){
			printf("YES\n");//�����ʽҪ���� 
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
