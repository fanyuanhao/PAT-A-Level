#include <iostream>
using namespace std;
const int black=6174;
int number[4];
int jianshu[4];
int beijianshu[4];
int cmp1(const void *a,const void *b){
	return *(int*)b-*(int*)a;
}
int cmp2(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}
void getnumber(int num){
	for(int i=0;i<4;i++){
		number[i]=num%10;
		num=num/10;
	}
}
void getjianshu(){
	for(int i=0;i<4;i++){
		jianshu[i]=number[i];
	}
	qsort(jianshu,4,sizeof(jianshu[0]),cmp2);
}
void getbeijianshu(){
	for(int i=0;i<4;i++){
		beijianshu[i]=number[i];
	}
	qsort(beijianshu,4,sizeof(beijianshu[0]),cmp1);
}
int qiucha(){
	int JIANSHU=jianshu[0]*1000+jianshu[1]*100+jianshu[2]*10+jianshu[3];
	int BEIJIANSHU=beijianshu[0]*1000+beijianshu[1]*100+beijianshu[2]*10+beijianshu[3];
	int CHA=BEIJIANSHU-JIANSHU;
	return CHA;
}
int main(){
	int N;
	scanf("%d",&N);
	int cha=N;
	
	if(cha%1111==0){
		printf("%d - %d = %04d",cha,cha,cha-cha);
	}else if(cha==6174){
		printf("7641 - 1467 = 6174");
	}else{
		while(cha!=black){
			getnumber(cha);
			getjianshu();
			getbeijianshu();
			cha=qiucha();
			printf("%04d",beijianshu[0]*1000+beijianshu[1]*100+beijianshu[2]*10+beijianshu[3]);
			printf(" - ");
			printf("%04d",jianshu[0]*1000+jianshu[1]*100+jianshu[2]*10+jianshu[3]);
			
			printf(" = ");
			printf("%04d\n",cha);
		}
	}
	return 0;
}