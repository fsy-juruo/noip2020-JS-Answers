#include<bits/stdc++.h>
using namespace std;
int min(int x,int y){
	if(x>y)return y;
	return x;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T,ans=0,p=0;
	cin>>T;
	string str;
	for(int i=1;i<=T;++i){
		p=0;
		cin>>str;
		for(int j=1;j<=str.length()-2;++j){
			p+=min(j,str.length()-j-1);
		}
		cout<<p<<endl;
	}
}
