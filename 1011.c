#include <stdio.h>
int main(){
	int maxindex=0;
	char c[3]={'W','T','L'};
	double a[3][3];
	int i=0,j=0;
	double odd=1.0,max;
	for(i=0;i<3;i++){
		scanf("%lf %lf %lf",&a[i][0],&a[i][1],&a[i][2]);
	}
	for(i=0;i<3;i++){
		max=1.0;
		for(j=0;j<3;j++){
			if(a[i][j]>max){
				max=a[i][j];
				maxindex=j;
			}
		}
		odd*=max;
		printf("%c ",c[maxindex]);
	}
	printf("%.2lf",(odd*0.65-1)*2);

	return 0;
}