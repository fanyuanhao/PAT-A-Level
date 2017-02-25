/*
1067. Sort with Swap(0,*) (25)

ʱ������
150 ms
�ڴ�����
65536 kB
���볤������
16000 B
�������
Standard
����
CHEN, Yue
Given any permutation of the numbers {0, 1, 2,..., N-1}, it is easy to sort them in increasing order. But what if Swap(0, *) is the ONLY operation that is allowed to use? For example, to sort {4, 0, 2, 1, 3} we may apply the swap operations in the following way:

Swap(0, 1) => {4, 1, 2, 0, 3}
Swap(0, 3) => {4, 1, 2, 3, 0}
Swap(0, 4) => {0, 1, 2, 3, 4}

Now you are asked to find the minimum number of swaps need to sort the given permutation of the first N nonnegative integers.

Input Specification:

Each input file contains one test case, which gives a positive N (<=105) followed by a permutation sequence of {0, 1, ..., N-1}. All the numbers in a line are separated by a space.

Output Specification:

For each case, simply print in a line the minimum number of swaps need to sort the given permutation.

Sample Input:
10 3 5 7 2 6 4 9 0 8 1
Sample Output:
9
������е��Ѷ��ѣ�
1��Ŀ������ģ���⣬��Ҫ��������һ�ֲ�����ͨ���Լ���ѧ��֪ʶ���ȥģ�����ֲ�����
2��̹�����һ��Ҫһ�����˵�������һ��������Ӧһ������������������У���ͨ��ֵ������λ�õ�����b�У��ҵ�0�������ڵ�λ�ã�0���ڵ�λ��Ҳ��Ҫ��0������ֵ��һ��ʼ��index0��ʾ0Ԫ�����ڵ�λ�ã�ͬʱҲ��ʾҪ��0������ֵ��һ���Լ��������ˡ�
3�����������̨����һֱ������Ļ���������д����ѭ����
4�����ѭ��������������̫����
5��֪a[0]==0������£�����һ��a[i]!=i������ʱ�򣬲�Ҫÿ�ζ���0��ʼ����������г�ʱ����һ���������һ���ϴ�a[i]!=iʱi��ֵ��
*/

#include <iostream>
using namespace std;
int main(){
	int N;
	int *a,*b;
	FILE *fin;
	fin=fopen("input.txt","r");
	//fin=stdin;
	fscanf(fin,"%d",&N);
	a=(int *)malloc(sizeof(int)*N);
	b=(int *)malloc(sizeof(int)*N);
	int i;
	for(i=0;i<N;i++){
		fscanf(fin,"%d",&a[i]);
		b[a[i]]=i;//�洢ÿ��ֵ��λ��
	}
	int cnt=0;
	int index0,index;//index0��ʾ0���ڵ�λ�ã�Ҫ��0������Ԫ�أ���index��ʾҪ��0������Ԫ��B���ڵ�λ��
	int B;//��ʾҪ��0������Ԫ��
	int flag=0;
	int last=0;
	while(flag!=1){
		flag=1;
		if(a[0]==0){//���a[0]��0�������
			for(i=last;i<N;i++){//�����ظ�Ѱ��
				if(a[i]!=i){
					a[0]=a[i];
					b[a[i]]=0;
					a[i]=0;
					b[0]=i;
					cnt++;
					flag=0;
					last=i;
					break;
				}
			}
		}
		while(a[0]!=0){//���a[0]����0�����
			flag=0;
			index0=b[0];
			B=b[0];
			index=b[B];
			//����
			a[index0]=B;
			a[index]=0;
			//����0������Ԫ�ص�λ��
			b[B]=index0;
			//����0���ڵ�λ��
			b[0]=index;
			cnt++;
		}
	}
	
	printf("%d",cnt);
	fclose(fin);
	return 0;
}