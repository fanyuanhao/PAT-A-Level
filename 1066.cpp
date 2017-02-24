#include <iostream>
using namespace std;
typedef struct node{
	int Data;
	struct node *left;
	struct node *right;
}Tree;
Tree* InsertAVL(Tree *T,int data);
int GetHeight(Tree *T);
Tree* Left(Tree *T){
	//旋转的是时A、B代替
	Tree* A=T;
	Tree* B=T->left;
	A->left=B->right;
	B->right=A;
	return B;
}
Tree* Right(Tree *T){
	Tree* A=T;
	Tree* B=T->right;
	A->right=B->left;
	B->left=A;
	return B;
}
Tree *LeftRight(Tree* T){
	T->left=Right(T->left);
	T=Left(T);
	return T;
}
Tree *RightLeft(Tree* T){
	T->right=Left(T->right);
	T=Right(T);
	return T;
}
int main(){
	FILE *fin;
	fin=fopen("input.txt","r");
	//fin=stdin;
	Tree *T;
	int N;
	fscanf(fin,"%d",&N);
	//T=(Tree*)malloc(sizeof(Tree));
	T=NULL;
	int i,data;
	for(i=0;i<N;i++){
		fscanf(fin,"%d",&data);
		T=InsertAVL(T,data);
	}
	printf("%d",T->Data);
	fclose(fin);
	return 0;
}
Tree* InsertAVL(Tree *T,int data){
	if(T==NULL){
		T=(Tree*)malloc(sizeof(Tree));
		T->Data=data;
		T->left=NULL;
		T->right=NULL;
		return T;
	}else{
		if(data<T->Data){
			T->left=InsertAVL(T->left,data);
			if(GetHeight(T->left)-GetHeight(T->right)>1){
				if(data<T->left->Data){
					T=Left(T);
				}else{
					T=LeftRight(T);
				}
			}
		}else{
			T->right=InsertAVL(T->right,data);
			if(GetHeight(T->right)-GetHeight(T->left)>1){
				if(data>T->right->Data){
					T=Right(T);
				}else{
					T=RightLeft(T);
				}
			}
		}
		return T;
	}
}
int GetHeight(Tree *T){
	int hl,hr,maxh;
	if(T!=NULL){
		hl=GetHeight(T->left);
		hr=GetHeight(T->right);
		maxh=max(hl,hr);
		return maxh+1;
	}else{
		return 0;
	}
}