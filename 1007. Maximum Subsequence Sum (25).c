#include <stdio.h>
int main(){
	int K;
	scanf("%d",&K);
	int a[K];
	int i,first=0,last=0,tempfirst;
	for(i=0;i<K;i++){
		scanf("%d",&a[i]);
	}
	int ThisSum=0,MaxSum=-1;//Ҫ�Ǹ�����0�Ļ�������к�Ϊ0������MaxSum��Ϊ-1 
	for(i=0;i<K;i++){
		ThisSum+=a[i];
		if(ThisSum>MaxSum){
			MaxSum=ThisSum;
			first=tempfirst;
			last=i;
		}
		if(ThisSum<0){
			ThisSum=0;//ǰn���Ϊ������������
			tempfirst=i+1;
		}
	}
	if(MaxSum==-1){
		printf("0 %d %d",a[0],a[K-1]);
	}else{
		printf("%d %d %d",MaxSum,a[first],a[last]);
	}
	return 0;
} 
