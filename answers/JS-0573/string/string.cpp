#include<bits/stdc++.h>
using namespace std;
int T,ans,len;
string s;
int check(int lenth){
	string tmp="";
	for(int i=0;i<lenth;i++)tmp+=s[i];
	for(int i=lenth;i<len/lenth*lenth;i+=lenth){
		string t="";
		for(int j=i;j<=i+lenth;j++){
			t+=s[j];
		}
	cout<<lenth<<' '<<t<<' '<<tmp<<endl;
		if(t!=tmp)return 0;
	}
	return 1;
}
void doit(int x,int y){
	
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>s;
		len=s.size();
		for(int i=1;i<=len;i++){
			if(check(i)){
//				doit(i,len%i);
//				cout<<i<<endl;
			}
		}
	}
}
/*
3
nnrnnr
zzzaab
mmlmmlo
*/
