#include <stdio.h>
#include <stdlib.h>
#define HourNum 24 
typedef struct{
	char name[21];
	int month;
	int day;
	int hour;
	int minute;
	char IsOn[10];
}UserData;
int main(){
	int *price;
	int i;
	FILE *fin,*fout;
	int N;
	UserData *userdata;
	fin=fopen("data.in","rb");
	fout=fopen("data.out","wb");
	//fin=stdin;
	fout=stdout;
	price=(int*)malloc(sizeof(int)*HourNum);
	for(i=0;i<HourNum;i++){
		fscanf(fin,"%d",&price[i]);
	}
	fscanf(fin,"%d",&N);
	userdata=(UserData*)malloc(sizeof(UserData)*N);
	for(i=0;i<N;i++){
		fscanf(fin,"%s %d:%d:%d:%d %s",&userdata[i].name,&userdata[i].month,&userdata[i].day,&userdata[i].hour,&userdata[i].minute,&userdata[i].IsOn);
	}

	/*
	测试输入是否正确
	for(i=0;i<N;i++){
		fprintf(fout,"%s %02d:%02d:%02d:%02d %s\r\n",userdata[i].name,userdata[i].month,userdata[i].day,userdata[i].hour,userdata[i].minute,userdata[i].IsOn);
	}
	*/

	fclose(fin);
	fclose(fout);
	return 0;
}