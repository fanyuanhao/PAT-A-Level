#include <iostream>
#include <vector>
using namespace std;
vector<vector <int>> T;
vector<int> Max;
int maxheight=0;
void dfs(int tmp,int height,bool* Visited);
int main(){
	FILE *fin;
	fin=fopen("input.txt","r");
	//fin=stdin;
	int N;
	double P,r;
	fscanf(fin,"%d %lf %lf",&N,&P,&r);
	int i;
	bool *Visited;
	Visited=(bool*)malloc(sizeof(bool)*N);
	for(i=0;i<N;i++){
		Visited[i]=false;
	}
	T.resize(N+1);
	int temp,tmp;
	for(i=0;i<N;i++){
		fscanf(fin,"%d",&temp);
		if(temp==-1){
			tmp=i;
		}else{
			T[temp].push_back(i);
		}
	}
	dfs(tmp,0,Visited);
	for(i=0;i<maxheight;i++){
		P+=P*r/100;
	}
	printf("%.2lf %d",P,Max.size());
	fclose(fin);
	return 0;
}
void dfs(int tmp,int height,bool* Visited){
	if(height>maxheight){
		maxheight=height;
		Max.clear();
		Max.push_back(tmp);
	}else if(height==maxheight){
		Max.push_back(tmp);
	}
	int i;
	Visited[tmp]=true;
	for(i=0;i<T[tmp].size();i++){
		if(!Visited[T[tmp][i]]){
			dfs(T[tmp][i],height+1,Visited);
		}
	}
}