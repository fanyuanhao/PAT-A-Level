#include <stdio.h>
int main(){
	int K1,K2;
	typedef struct node{
		int exp;
		double coef;
	}Poly;
	scanf("%d",&K1);
	Poly a[K1];
	int i,j,cnt=0;
	for(i=0;i<K1;i++){
		scanf("%d%lf",&a[i].exp,&a[i].coef);
	}
	scanf("%d",&K2);
	Poly b[K2];
	for(i=0;i<K2;i++){
		scanf("%d%lf",&b[i].exp,&b[i].coef);
	}
	Poly c[K1*K2];//这里是K1*K2 
	for(i=0;i<K1;i++){
		for(j=0;j<K2;j++){
			c[cnt].exp=a[i].exp+b[j].exp;
			c[cnt].coef=a[i].coef*b[j].coef;
			cnt++; 
		}
	}
	int max=c[0].exp;
	//建立一个下标是指数，值为系数的数组，初始化为0 
	double Coef[max+1];
	for(i=0;i<=max;i++){
		Coef[i]=0;
	}
	for(i=0;i<cnt;i++){
		Coef[c[i].exp]+=c[i].coef;
	}
	cnt=0;
	for(i=0;i<=max;i++){
		if(Coef[i]!=0){
			cnt++;
		} 
	}
	j=0;
	printf("%d ",cnt);
	for(i=max;i>=0;i--){
		if(Coef[i]!=0){
			j++;
			if(j!=cnt){
				printf("%d %.1lf ",i,Coef[i]);
			} else{
				printf("%d %.1lf",i,Coef[i]);
			}
		} 
	}
	return 0;
} 
