#include <stdio.h>
int main(){
	int K;
	scanf("%d",&K);
	int a[K];
	int i,first=0,last=0,tempfirst;
	for(i=0;i<K;i++){
		scanf("%d",&a[i]);
	}
	int ThisSum=0,MaxSum=-1;//要是负数和0的话最大子列和为0，所以MaxSum设为-1 
	for(i=0;i<K;i++){
		ThisSum+=a[i];
		if(ThisSum>MaxSum){
			MaxSum=ThisSum;
			first=tempfirst;
			last=i;
		}
		if(ThisSum<0){
			ThisSum=0;//前n项和为负数，则舍弃
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
