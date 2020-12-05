#include<bits/stdc++.h>
using namespace std;
int t;
bool vis[30];
bool vis2[30];
string s2;
string st[10];
bool check(int q){
	if(s2.size()%q)return false;
	string s0=s2.substr(0,q);
	for(int i=q;i<s2.size();i+=q){
		if(s2.substr(i,q)!=s0)return false;
	} 
	return true;
}
void work(string s){
	long long sum=0;
	int c=0;
	memset(vis,0,sizeof(vis));
	for(int i=s.size()-1;i>1;i--){
		if(vis[s[i]-96]==0){
			c++;
		}else{
			c--;
		}
		vis[s[i]-96]^=1;//Ωÿ»°c 
		s2=s.substr(0,i);
		int t=0,d=0;
		memset(vis2,0,sizeof(vis2));
		for(int j=0;j<s2.size();j++){//—∞’“—≠ª∑Ω⁄ab 
			if(vis2[s[j]-96]==0){
				d++;
			}else d--;
			vis2[s[j]-96]^=1;
			if(d<=c)t++;
			if(check(j+2))sum+=t;
		}
	}
	cout<<sum<<endl;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(int l=1;l<=t;l++){
		cin>>st[l];
		work(st[l]);
	}
	return 0;
}

