#include <iostream>
using namespace std;
typedef struct{
	int id;
	int data;
}Node;
const int Max=100000;
typedef struct{
	int next;
	int Data;
}NODE;
int cmp(const void *a,const void *b){
	Node *A=(Node*)(a);
	Node *B=(Node*)(b);
	return A->data-B->data;
}
int main(){
	FILE *fin;
	fin=fopen("input.txt","r");
	//fin=stdin;
	//	int temp;
	int N;
	int head;
	fscanf(fin,"%d%d",&N,&head);
	int i;
	Node *List;
	List=(Node*)malloc(sizeof(Node)*N);
	NODE node[Max];
	for(i=0;i<Max;i++){
		node[i].Data=0;
		node[i].next=-2;
	}
	int id;
	int ptr;
	int cnt=0;
	for(i=0;i<N;i++){
		fscanf(fin,"%d",&id);
		fscanf(fin,"%d %d",&node[id].Data,&node[id].next);
	}
	ptr=head;
	for(i=0;ptr!=-1;i++){
		List[i].data=node[ptr].Data;
		List[i].id=ptr;
		ptr=node[ptr].next;
		if(ptr==-2){
			break;
		}
	}
	cnt=i;
	if(cnt==0){
		printf("0 -1");
	}else{
		qsort(List,cnt,sizeof(List[0]),cmp);
		printf("%d %05d\n",cnt,List[0].id);
		for(i=0;i<cnt-1;i++){
			printf("%05d %d %05d\n",List[i].id,List[i].data,List[i+1].id);
		}
		printf("%05d %d -1\n",List[i].id,List[i].data);		
	}
	fclose(fin);
	return 0;
}