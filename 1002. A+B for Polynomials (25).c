#include <stdio.h>
int main(){
	int KA,KB;
	scanf("%d",&KA);
	
	struct node{
		int exponent;
		double coefficient;
	};
	
	struct node a[KA];
	int i,j,k;
	for(i=0;i<KA;i++){
		scanf("%d%lf",&a[i].exponent,&a[i].coefficient);
	}
	scanf("%d",&KB);
	struct node b[KB];
	for(j=0;j<KB;j++){
		scanf("%d%lf",&b[j].exponent,&b[j].coefficient);
	}
	struct node c[20];
	
	for(i=0,j=0,k=0;i<KA&&j<KB;k++){
		if(a[i].exponent>b[j].exponent){
			c[k].exponent=a[i].exponent;
			c[k].coefficient=a[i].coefficient;
			i++;
		}else if(a[i].exponent==b[j].exponent){
			c[k].exponent=a[i].exponent;
			c[k].coefficient=a[i].coefficient+b[j].coefficient;
			i++;
			j++;
		}else{
			c[k].exponent=b[j].exponent;
			c[k].coefficient=b[j].coefficient;
			j++;
		}
	}
	
	while(i==KA&&j<KB){
		c[k].exponent=b[j].exponent;
		c[k].coefficient=b[j].coefficient;
		j++;
		k++;
	}
	
	while(i<KA&&j==KB){
		c[k].exponent=a[i].exponent;
		c[k].coefficient=a[i].coefficient;
		i++;
		k++;
	}
	int cnt=0;
	struct node d[20];
	for(i=0;i<k;i++){
		if(c[i].coefficient!=0){
			d[cnt].coefficient=c[i].coefficient;
			d[cnt].exponent=c[i].exponent;
			cnt++;
		}
	}
	
	
	if(cnt!=0){
		printf("%d ",cnt);
		for(i=0;i<cnt-1;i++){
			printf("%d %.1lf ",d[i].exponent,d[i].coefficient);
		}
		printf("%d %.1lf",d[i].exponent,d[i].coefficient);
	}else{
		printf("%d",cnt);
	}
	
	return 0;
}
