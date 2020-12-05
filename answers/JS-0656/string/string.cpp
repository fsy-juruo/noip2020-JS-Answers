#include<bits/stdc++.h>
using namespace std;
string st;
int cnta[1100000];
int cntb[1100000];
bool s[30];
int l;
void cnt(){
	int ts;
	memset(s,0,sizeof(s));
	ts=0;
	for(int i=1;i<=l;i++){
		s[st[i]-'a']^=1;
		if(s[st[i]-'a'])ts++;
		else ts--;
		cnta[i]=ts;
	}
	memset(s,0,sizeof(s));
	ts=0;
	for(int i=l;i>=1;i--){
		s[st[i]-'a']^=1;
		if(s[st[i]-'a'])ts++;
		else ts--;
		cntb[i]=ts;
	}
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	int T,ans,nct;
	cin>>T;
	while(T--){
		ans=0;
		cin>>st;
		l=st.size();
		st=' '+st;
		cnt();
		for(int i=1;i<l-1;i++){
			for(int j=i+1;j<l;j++){
				for(int k=j;k<l;k+=j){
					if(cnta[i]<=cntb[k+1])
						ans++;
					if(st.substr(k+1-j,j)!=st.substr(k+1,j))
						break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
