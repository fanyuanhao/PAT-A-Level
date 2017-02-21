#include <stdio.h>
int main(){
	int M;
	struct node{
		char ID[17];
		int SignInTime;
		int SignOutTime;
	};
	scanf("%d",&M);
	int i,h,m,s;
	struct node record[M];
	for(i=0;i<M;i++){
		scanf("%s",record[i].ID);
		scanf("%d:%d:%d",&h,&m,&s);
		record[i].SignInTime=(h*100+m)*100+s;
		scanf("%d:%d:%d",&h,&m,&s);
		record[i].SignOutTime=(h*100+m)*100+s;
	}
	int min=record[0].SignInTime,max=record[0].SignOutTime;
	int i_min=0,i_max=0;
	for(i=1;i<M;i++){
		if(record[i].SignInTime<min){
			min=record[i].SignInTime;
			i_min=i;
		}
		if(record[i].SignOutTime>max){
			max=record[i].SignOutTime;
			i_max=i;
		}
	}
	printf("%s %s",record[i_min].ID,record[i_max].ID);
	return 0;
}
