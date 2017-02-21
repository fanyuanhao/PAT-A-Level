#include <iostream>
using namespace std;
const int MaxChoiceNum=5;
typedef struct{
	int GE;
	int GI;
	double final;
	int num;
	int choice[MaxChoiceNum];
	int school;
}Student;
typedef struct{
	int quota;
	int StudentNum;
}School;
int cmp(const void *a,const void *b){
	Student A=*(Student*)a;
	Student B=*(Student*)b;
	if(A.final==B.final){
		if(A.GE==B.GE){
			return 0;
		}else{
			return B.GE-A.GE;
		}
	}else{
		return B.final-A.final;
	}
}
int cmp1(const void *a,const void *b){
	Student A=*(Student*)a;
	Student B=*(Student*)b;
	if(A.school==B.school){
		return A.num-B.num;
	}else{
		return A.school-B.school;
	}
}
void InitStudent(Student *stu,FILE *fin,int N,int K);
void InitSchool(School *sch,FILE *fin,int M);
int main(){
	FILE *fin;
	fin=fopen("input.txt","rb");
	//fin=stdin;
	int N,M,K;
	fscanf(fin,"%d %d %d",&N,&M,&K);
	Student *stu;
	stu=(Student*)malloc(sizeof(Student)*N);
	//读入学校的招生名额
	School *sch;
	sch=(School*)malloc(sizeof(Student)*M);
	InitSchool(sch,fin,M);
	//读入学生的数据
	InitStudent(stu,fin,N,K);
	//对学生的成绩排序
	qsort(stu,N,sizeof(stu[0]),cmp);
	//测试排序是否正确
	int i,j;
	/*
	for(i=0;i<N;i++){
		printf("%d\n",stu[i].num);
	}
	cout<<endl;
	*/
	//判断学生能不能上某个学校
	
	for(i=0;i<N;i++){
		if((i>0)&&(stu[i].final==stu[i-1].final)&&(stu[i].GE==stu[i-1].GE)){
			for(j=0;j<K;j++){
				if(sch[stu[i].choice[j]].StudentNum<sch[stu[i].choice[j]].quota||(stu[i].choice[j]==stu[i-1].school)){
					sch[stu[i].choice[j]].StudentNum++;
					stu[i].school=stu[i].choice[j];
					break;
				}
			}
		}else{
			for(j=0;j<K;j++){
				if(sch[stu[i].choice[j]].StudentNum<sch[stu[i].choice[j]].quota){
					sch[stu[i].choice[j]].StudentNum++;
					stu[i].school=stu[i].choice[j];
					break;
				}
			}
		}
		
	}
	//输出
	int first;
	//按学校排序，对学生排序
	qsort(stu,N,sizeof(stu[0]),cmp1);
	for(i=0;i<M;i++){
		first=1;
		for(j=0;j<N;j++){
			if(stu[j].school==i){
				if(first){
					first=0;
				}else{
					printf(" ");
				}
				printf("%d",stu[j].num);
			}
		}
		printf("\n");
	}
	fclose(fin);
	return 0;
}
void InitStudent(Student *stu,FILE *fin,int N,int K){
	for(int i=0;i<N;i++){
		fscanf(fin,"%d %d",&stu[i].GE,&stu[i].GI);
		stu[i].final=(stu[i].GE+stu[i].GI)/2;
		stu[i].school=-1;
		stu[i].num=i;
		for(int j=0;j<K;j++){
			fscanf(fin,"%d",&stu[i].choice[j]);
		}
	}
}
void InitSchool(School *sch,FILE *fin,int M){
	for(int i=0;i<M;i++){
		fscanf(fin,"%d",&sch[i].quota);
		sch[i].StudentNum=0;
	}
}