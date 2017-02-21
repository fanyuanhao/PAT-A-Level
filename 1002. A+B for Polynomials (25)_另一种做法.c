#include <stdio.h>
#include <stdlib.h>
typedef struct node List;
struct node {
	int exponent;
	double coefficient;
	struct node *next;
};
List* makelist();
void attach(int a,double b,List* *p);
List* makelist3(List* ka,List* kb);
int main(){
	int KA,KB,cnt=0;
	scanf("%d",&KA);
	List *ka=(List *)malloc(sizeof(List));
	List *kb=(List*)malloc(sizeof(List));
	ka=makelist();
	scanf("%d",&KB);
	kb=makelist();

	List *s=makelist3(ka,kb);
	List *temp=s;
	for(s=s->next;s!=NULL;s=s->next){
		cnt++;
	}
	s=temp;
	if(cnt==0){
		printf("0"); 
	}else{
		printf("%d ",cnt);
		for(s=s->next;s!=NULL;s=s->next){
			if(s->next!=NULL){//不是最后一个结点的条件 
				printf("%d %.1lf ",s->exponent,s->coefficient);
			}else{
				printf("%d %.1lf",s->exponent,s->coefficient);
			}
		}
	}


	return 0;
	
}

List* makelist(){
	int exp=0;
	double coef=0;
	char c;
	List *head=NULL;
	do{
		scanf("%d%lf",&exp,&coef);
		
		c=getchar();
	
			List *p=(List*)malloc(sizeof(List));
			p->exponent=exp;
			p->coefficient=coef;
			p->next=NULL;
			List *last=head;
			if(last!=NULL){
				while(last->next){
					last=last->next;
				}
				last->next=p;
			}else{
				head=p;
			}
	}while(c!='\n');
	return head;
}
List* makelist3(List* ka,List* kb){
	List *front,*rear,*temp;//指针都要标个星号 
	double sum;
	rear=(List*)malloc(sizeof(struct node));
	front=rear;
	while(ka&&kb){
		if(ka->exponent>kb->exponent){
			attach(ka->exponent,ka->coefficient,&rear);
			ka=ka->next;	
		}else if(ka->exponent==kb->exponent){
			sum=ka->coefficient+kb->coefficient;
			if(sum){
				attach(ka->exponent,sum,&rear);
			}
			ka=ka->next;
			kb=kb->next;
		}else{
			attach(kb->exponent,kb->coefficient,&rear);
			kb=kb->next;
		}
	}

	
	while(ka){
		attach(ka->exponent,ka->coefficient,&rear);
		ka=ka->next;
	}
	while(kb){
		attach(kb->exponent,kb->coefficient,&rear);
		kb=kb->next;
	}
	return front;
}
void attach(int a,double b,List* *p){
	List *s=(List*)malloc(sizeof(List));
	s->exponent=a;
	s->coefficient=b;
	s->next=NULL;
	(*p)->next=s;
	*p=s;
}
