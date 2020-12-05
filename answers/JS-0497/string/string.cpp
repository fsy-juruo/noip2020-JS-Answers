#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int m,n,va[150],vc[150],sa=0,sc=0,ans=0;
void work1(){
	for(int i=0;i<n-2;i++){
		int x=s[i]-'0';
		if(va[x]%2==0){
			va[x]++,sa++;
		}
		else if(va[x]%2==1){
			va[x]++,sa--;
		}
		sc=0;memset(vc,0,sizeof(vc));
		for(int j=i+2;j<n;j++){
			int y=s[j]-'0';
			if(vc[y]%2==0){
				vc[y]++,sc++;
			}
			else if(vc[y]%2==1){
				vc[y]++,sc--;
			}
		}
		if(sa<=sc)ans++;
		//cout<<sc<<endl;
		for(int j=i+2;j<n-1;j++){
			int y=s[j]-'0';
			if(vc[y]%2==0){
				vc[y]--,sc++;
			}
			else if(vc[y]%2==1){
				vc[y]--,sc--;
			}
			if(sa<=sc)ans++;
			//cout<<sa<<" "<<sc<<":"<<endl;
		}
		//cout<<i<<" "<<ans<<endl;
	}
}
char a[200000];
int tot=0,l,p;
int judge(){
	for(int i=1;i<n;i++){
		int k=(i+1)%tot;int p=0;
		if(a[k]==s[i])continue;
		else{
			for(int j=i+1;j<i+1+i+1;j++){
				if(s[j]!=s[j-i-1]){
					p=1;
					break;
				}
			}
			if(2*(i+1)<n&&p==0){
				int t=tot;
				for(int j=t;j<=i;j++){
					a[++tot]=s[j];
				}
			}
		}
		if(p==1)l=i;
	}
	//cout<<l<<endl;
	if(tot*2<s.size()&&tot>1)return 1;
	else return 0;
}
void work2(){
	tot=0;sc=0,sa=0;
	memset(va,0,sizeof(va));
	memset(vc,0,sizeof(vc));
	a[++tot]=s[1];
	p=judge();
	if(p){
		//for(int i=1;i<=tot;i++)cout<<a[i]<<" ";
		//cout<<l<<endl;
		for(int i=l;i<n;i++){
			int y=s[i]-'0';
			if(vc[y]%2==0){
				vc[y]++,sc++;
			}
			else if(vc[y]%2==1){
				vc[y]++,sc--;
			}
		}
		//cout<<sc<<endl;
		for(int i=0;i<tot-1;i++){
			int x=s[i]-'0';
			if(va[x]%2==0){
				va[x]++,sa++;
			}
			else if(va[x]%2==1){
				va[x]++,sa--;
			}
			if(sa<=sc)ans++;
		}
	}
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>m;
	for(int t=1;t<=m;t++){
		cin>>s;
		memset(va,0,sizeof(va));
		memset(vc,0,sizeof(vc));
		n=s.size();sa=0,sc=0,ans=0;
		work1();
		//cout<<<<endl;
		work2();
		//if(p==1)ans-=1;
		cout<<ans<<endl;
	}
}
