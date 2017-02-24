#include <iostream>
#include <cmath>
using namespace std;
int main(){
	FILE *fin;
	fin=fopen("input.txt","rb");
	//fin=stdin;
	long long a,b,c,sum;
	int T;
	int i;
	fscanf(fin,"%d",&T);
	for(i=1;i<=T;i++){
		fscanf(fin,"%lld %lld %lld",&a,&b,&c);
		sum=a+b;
		//先考虑溢出的情况
		if(a>0&&b>0&&sum<=0){
			printf("Case #%d: true\n",i);
		}else if(a<0&&b<0&&sum>=0){
			printf("Case #%d: false\n",i);
		}else if(a+b>c){
			printf("Case #%d: true\n",i);
		}else{
			printf("Case #%d: false\n",i);
		}
	}
	fclose(fin);
	return 0;
}