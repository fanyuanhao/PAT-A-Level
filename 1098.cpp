#include <iostream>
using namespace std;
int main(){
	FILE *fin;
	fin=fopen("input.txt","r");
	//fin=stdin;
	//��������
	int N;
	fscanf(fin,"%d",&N);
	int *a,*b;
	a=(int *)malloc(sizeof(int)*N);
	b=(int *)malloc(sizeof(int)*N);
	int i;
	for(i=0;i<N;i++){
		fscanf(fin,"%d",&a[i]);
	}
	for(i=0;i<N;i++){
		fscanf(fin,"%d",&b[i]);
	}
	//���ж�
	for(i=0;i<N-1;i++){
		if(b[i+1]<b[i]){	
			break;
		}
	}
	int temp1=i+1;
	int flag=0;
	for(i=i+1;i<N;i++){
		if(a[i]!=b[i]){
			flag=1;
			break;
		}
	}
	int first=1;
	if(flag==0){
		printf("Insertion Sort\n");
		int temp=b[temp1];
		int j;
		for(j=temp1;temp<b[j-1];j--){
			b[j]=b[j-1];
		}
		b[j]=temp;
		for(j=0;j<N;j++){
			if(first){
				first=0;
			}else{
				printf(" ");
			}
			printf("%d",b[j]);
		}
	}else{
		printf("Heap Sort\n");
		//Ѱ��Ҫ�����λ��
		int j;
		for(j=N-1;j>=0;j--){
			if(b[j]<b[0]){
				break;
			}
		}
		int temp=b[j];
		b[j]=b[0];
		b[0]=temp;
		int flag=j;//��flag��¼λ��
		//�������¹���
		int Child;
		for(j=0;2*j+1<flag;j=Child){
			Child=2*j+1;
			if(Child+1<flag&&b[Child]<b[Child+1]){
				Child++;
			}
			if(temp<b[Child]){
				b[j]=b[Child];
			}else{
				break;
			}
		}
		b[j]=temp;//ʹ��j������Child�ǿ��ǲ��ù��˵����
		for(j=0;j<N;j++){
			if(first){
				first=0;
			}else{
				printf(" ");
			}
			printf("%d",b[j]);
		}	
	}
	fclose(fin);
	return 0;
}