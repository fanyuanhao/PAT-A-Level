#include <stdio.h>
#include <stdlib.h>
int main(){
	int m,n,k;
	scanf("%d%d%d",&m,&n,&k);
	typedef struct{
		int data[m];
		int top;
	} Stack;
	int i,j,count,cnt=0;
	Stack *PtrS=(Stack*)malloc(sizeof(Stack));//分配空间 
	int b[k];
	int v[n];
	for(i=0;i<k;i++){
		for(j=0;j<n;j++){
			scanf("%d",&v[j]);
		}
		count=0;
		PtrS->top=-1;
		for(j=0;j<n;j++){
			PtrS->top++;
			//printf("%d\n",PtrS->top);
			if(PtrS->top>=m){
				break;
			}
			PtrS->data[PtrS->top]=j+1;//插入 
			
			while((PtrS->top!=-1)&&(PtrS->data[PtrS->top]==v[count])){
				PtrS->top--;//删除 
				count++; 
			}
		}
		if(count==n){
			printf("YES\n");//输出格式要换行 
		}else{
			printf("NO\n");
		}
	}

	return 0;
} 
