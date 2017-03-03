#include <iostream>
#include <map>
#include <string>
#include <set>
#include <fstream>
using namespace std;
map<string,set<int>> title,author,key,publisher,year;
void query(map<string,set<int>> &K,string &str);
int main(){
	int N;
	ifstream file("input.txt");
	streambuf *cinbackup;
	cinbackup=cin.rdbuf(file.rdbuf());
	cin.rdbuf(cinbackup);
	cin>>N;
	//printf("%d",N);
	int i;
	int id;
	string stitle,sauthor,skey,spublisher,syear;
	for(i=0;i<N;i++){
		cin>>id;
		cin.get();
		getline(cin,stitle);
		title[stitle].insert(id);
		getline(cin,sauthor);
		author[sauthor].insert(id);
		while(cin>>skey){
			key[skey].insert(id);
			char c;
			c=cin.get();
			if(c=='\n'){
				break;
			}
		}
		getline(cin,spublisher);
		publisher[spublisher].insert(id);
		getline(cin,syear);
		year[syear].insert(id);
	}
	int M;
	cin>>M;
	for(i=0;i<M;i++){
		int num;
		string s;
		cin>>num;
		cin.get();
		cin.get();
		getline(cin,s);
		cout<<num<<": "<<s<<endl;
		if(num==1) query(title,s);
		if(num==2) query(author,s);
		if(num==3) query(key,s);
		if(num==4) query(publisher,s);
		if(num==5) query(year,s);
	}
	
	return 0;
}
void query(map<string,set<int>> &K,string &str){
	if(K.find(str)==K.end()){
		printf("Not Found\n");
	}else{
		for(set<int>::iterator it=K[str].begin();it!=K[str].end();it++){
			printf("%07d\n",*it);
		}
	}
}