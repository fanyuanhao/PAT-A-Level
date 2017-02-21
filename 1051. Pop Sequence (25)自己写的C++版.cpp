#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main(){
	int m,n,k;
	cin>>m>>n>>k;
	int i,j,count;
	/*new一个动态数组 
	int *v;
	v=new int[m];
	*/
	vector <int> v(n);
	//创建一个Stack变量
	
	for(i=0;i<k;i++){
		for(j=0;j<n;j++){
			cin>>v[j];
		}
		count=0;
		stack <int> s;//每次都创建一个堆栈 
		for(j=0;j<n;j++){
			s.push(j+1);
			if(s.size()>m){
				break;
			}
			while(!s.empty()&&(s.top()==v[count])){
				s.pop();
				count++;
			}
		}
		if(count==n){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	} 
	return 0;
} 
