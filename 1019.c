#include <stdio.h>
int Switch(int *a,int N,int b);
void palindromic(int *a,int length);
int main(){
	int N,b,length,i;
	int a[32];
	scanf("%d %d",&N,&b);
	//进制转换并用数组存储
	if(N==0){
		printf("Yes\n");
		printf("0");
		return 0;
	}
	length=Switch(a,N,b);
	palindromic(a,length);
	//判断是否是回文数
	for(i=length-1;i>0;i--){
		printf("%d ",a[i]);
	}
	printf("%d\n",a[i]);
	return 0;
}
int Switch(int *a,int N,int b){
	int i=0,k=0;
	for(i=0;N!=0;i++){
		a[i]=N%b;
		N/=b;
		k++;
	}
	return k;
}
void palindromic(int *a,int length){
	int i;
	int flag=1;
	for(i=0;i<length/2;i++){
		if(a[i]!=a[length-1-i]){
			printf("No\n");
			flag=0;
			break;
		}
	}
	if(flag){
		printf("Yes\n");
	}
}