#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main(){
	int m,n,k;
	cin>>m>>n>>k;
	int i,j,count;
	/*newһ����̬���� 
	int *v;
	v=new int[m];
	*/
	vector <int> v(n);
	//����һ��Stack����
	
	for(i=0;i<k;i++){
		for(j=0;j<n;j++){
			cin>>v[j];
		}
		count=0;
		stack <int> s;//ÿ�ζ�����һ����ջ 
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
