#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MaxDigit 20
#define false 0
#define true 1
int IsPrime(int n);
int convert(int n,int d);
int main(){
	int n,d;
	int i=0,j=0;
	int len;
	int *array;
	array=(int*)malloc(sizeof(int)*MaxDigit);
	while(scanf("%d",&n)!=EOF){
		if(n<0){
			break;
		}
		scanf("%d",&d);//这步读入要放在判断素数之前，因为如果放在后面并且它本身就是素数的话，不会把进制数据读到d
		//convert(n,d);
		if(IsPrime(n)==0){
			printf("No\n");	
			continue;
		}
		
		i=0;
		while(n!=0){
			array[i]=n%d;
			n=n/d;
			i++;
		}
		len=i;
		for(i=0;i<len;i++){
			n=n*d+array[i];
		}
		if(IsPrime(n)){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}
int IsPrime(int n){
	int i=2;
	if(n==1||n==0){
		return false;
	}
	for(i=2;i<=sqrt((double)n);i++){//注意这里i从2开始，判断条件是<=，还要有强制类型转换
		if(n%i==0){
			return false;
		}
	}
	return true;
}
/*
void convert(int n,int d){
	int *array;
	int i=0;
	int len;
	array=(int*)malloc(sizeof(int)*MaxDigit);
	
	while(n!=0){
		array[i]=n%d;
		n=n/d;
		i++;
	}
	len=i;
	for(i=len-1;i>=0;i--){
		printf("%d",array[i]);
	}
	printf("\n");
}
*/