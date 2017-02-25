/*
1067. Sort with Swap(0,*) (25)

时间限制
150 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
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
这道题有点难度难，
1题目类型是模拟题，主要是它给定一种操作，通过自己所学的知识编程去模拟这种操作。
2编程过程中一定要一个除了迭代器外一个变量对应一个变量名，在这道题中，先通过值和所在位置的数组b中，找到0所在所在的位置，0所在的位置也是要和0交换的值，一开始我index0表示0元素所在的位置，同时也表示要和0交换的值，一会自己就乱套了。
3如果弹出控制台窗口一直不输出的话，可能是写了死循环。
4这道题循环结束的条件不太好找
5已知a[0]==0的情况下，找下一个a[i]!=i的数的时候，不要每次都从0开始，否则会运行超时，用一个变量标记一下上次a[i]!=i时i的值。
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
		b[a[i]]=i;//存储每个值的位置
	}
	int cnt=0;
	int index0,index;//index0表示0所在的位置（要和0交换的元素），index表示要和0交换的元素B所在的位置
	int B;//表示要和0交换的元素
	int flag=0;
	int last=0;
	while(flag!=1){
		flag=1;
		if(a[0]==0){//如果a[0]是0的情况下
			for(i=last;i<N;i++){//避免重复寻找
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
		while(a[0]!=0){//如果a[0]不是0的情况
			flag=0;
			index0=b[0];
			B=b[0];
			index=b[B];
			//交换
			a[index0]=B;
			a[index]=0;
			//更新0交换的元素的位置
			b[B]=index0;
			//更新0所在的位置
			b[0]=index;
			cnt++;
		}
	}
	
	printf("%d",cnt);
	fclose(fin);
	return 0;
}