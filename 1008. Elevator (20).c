#include <stdio.h>
int main(){
	int N;
	scanf("%d",&N);
	int a[N+1];
	int i,sum=0;
	a[0]=0;//≥ı º≤„ «0≤„ 
	for(i=1;i<=N;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=N;i++){
		if(a[i]>a[i-1]){
			sum+=(a[i]-a[i-1])*6+5;
		}else{
			sum+=(a[i-1]-a[i])*4+5;
		}
	}
	printf("%d",sum);
}
