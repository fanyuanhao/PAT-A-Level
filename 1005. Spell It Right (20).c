#include <stdio.h>
#include <string.h>
int main(){
	char a[102];
	scanf("%s",a);
	int i=0;
	int len=strlen(a);
	int c[3];
	char *b[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	int sum=0;
	int cnt=0;
	for(i=0;i<len;i++){
		sum+=a[i]-'0';
	}
	if(sum==0){
		printf("zero");
	}
	i=0;
	while(sum){
		c[i]=sum%10;
		sum/=10;
		i++;
	}
	cnt=i;
	for(i=cnt-1;i>=0;i--){
		if(i==0){
			printf("%s",b[c[i]]);
		}else{
			printf("%s ",b[c[i]]);
		}
	}
	return 0;
}
