#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 1000000
typedef struct{
	int IsExist;
	int C,CR;
	int M,MR;
	int E,ER;
	int A,AR;
}SList;
int cmp(const void *a,const void *b){
	return *(int*)b-*(int*)a;
}
int main(){
	int N,M;
	SList *report;
	int *id;
	int i,j;
	int ID,*CS,*ES,*MS,*AS;
	int rank;
	char c='B';
	scanf("%d%d",&N,&M);
	rank=N;
	report=(SList*)malloc(sizeof(SList)*MAXNUM);
	CS=(int*)malloc(sizeof(int)*N);
	MS=(int*)malloc(sizeof(int)*N);
	ES=(int*)malloc(sizeof(int)*N);
	AS=(int*)malloc(sizeof(int)*N);
	id=(int*)malloc(sizeof(int)*M);
	for(i=0;i<MAXNUM;i++){
		report[i].IsExist=0;
		report[i].C=0;
		report[i].CR=0;
		report[i].E=0;
		report[i].ER=0;
		report[i].M=0;
		report[i].MR=0;
		report[i].A=0;
		report[i].AR=0;
	}
	for(i=0;i<N;i++){
		scanf("%d %d %d %d",&ID,&CS[i],&MS[i],&ES[i]);
		report[ID].C=CS[i];
		report[ID].M=MS[i];
		report[ID].E=ES[i];
		
		AS[i]=(CS[i]+MS[i]+ES[i])/3;
		
		report[ID].A=AS[i];
		report[ID].IsExist=1;
	}
	qsort(CS,N,sizeof(CS[0]),cmp);
	qsort(MS,N,sizeof(MS[0]),cmp);
	qsort(ES,N,sizeof(ES[0]),cmp);
	qsort(AS,N,sizeof(AS[0]),cmp);
	for(i=0;i<M;i++){
		scanf("%d",&id[i]);
	}
	for(i=0;i<M;i++){
		rank=N;
		if(report[id[i]].IsExist==1){
			j=0;
			while(report[id[i]].C<CS[j]){
				j++;
			}
			report[id[i]].CR=j+1;
			j=0;
			while(report[id[i]].M<MS[j]){
				j++;
			}
			report[id[i]].MR=j+1;
			j=0;
			while(report[id[i]].E<ES[j]){
				j++;
			}
			report[id[i]].ER=j+1;
			j=0;
			while(report[id[i]].A<AS[j]){
				j++;
			}
			report[id[i]].AR=j+1;

			if(report[id[i]].AR<rank){
				rank=report[id[i]].AR;
				c='A';
			}
			if(report[id[i]].CR<rank){
				rank=report[id[i]].CR;
				c='C';
			}
			if(report[id[i]].MR<rank){
				rank=report[id[i]].MR;
				c='M';
			}
			if(report[id[i]].ER<rank){
				rank=report[id[i]].ER;
				c='E';
			}

			printf("%d %c\n",rank,c);
		}else{
			printf("N/A\n");
		}
	}
	return 0;
}