#include <iostream>
#include <vector>
using namespace std;
vector<vector <int>> ALG;
vector<int> Max;
vector<int> result;
void dfs(int i,bool *Visited,int height);
int maxheight=0;
int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}
int main(){
	FILE *fin;
	fin=fopen("input.txt","r");
	//fin=stdin;
	int N;
	fscanf(fin,"%d",&N);
	bool *Visited;
	Visited=(bool*)malloc(sizeof(bool)*(N+1));
	int i;
	for(i=1;i<=N;i++){
		Visited[i]=false;
	}
	ALG.resize(N+1);//vector重置大小，比数组方便多了
	int A,B;
	for(i=0;i<N-1;i++){
		fscanf(fin,"%d %d",&A,&B);
		ALG[A].push_back(B);
		ALG[B].push_back(A);
	}
	int cnt=0;
	for(i=1;i<=N;i++){
		if(!Visited[i]){
			dfs(i,Visited,1);
			cnt++;
		}
	}
	if(cnt!=1){
		printf("Error: %d components",cnt);
	}else{
		for(i=1;i<=N;i++){
			Visited[i]=false;
		}
		for(i=0;i<Max.size();i++){
			result.push_back(Max[i]);//把所有的都转存到另一个vector中
		}
		int tmp=Max[0];
		Max.clear();
		result.push_back(tmp);
		dfs(tmp,Visited,1);
		for(i=0;i<Max.size();i++){
			result.push_back(Max[i]);
		}
		int *r;
		int size=result.size();
		r=(int *)malloc(sizeof(int)*size);
		for(i=0;i<size;i++){
			r[i]=result[i];
		}
		qsort(r,size,sizeof(r[0]),cmp);
		
		for(i=0;i<size;i++){
			if(i!=0&&r[i]==r[i-1]){
				continue;
			}else{
				printf("%d\n",r[i]);
			}
		}
	}
	fclose(fin);
	return 0;
}
void dfs(int i,bool *Visited,int height){
	if(height>maxheight){
		maxheight=height;
		Max.clear();
		Max.push_back(i);
	}else if(height==maxheight){
		Max.push_back(i);	
	}
	Visited[i]=true;
	int j;
	for(j=0;j<ALG[i].size();j++){
		if(!Visited[ALG[i][j]]){
			dfs(ALG[i][j],Visited,height+1);
		}
	}
}