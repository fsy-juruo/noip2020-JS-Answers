#include<bits/stdc++.h>
using namespace std;
int w[2333],st[2333],d[2333],ans,n,k;
int now[2333],s[2333];

/*
3 2
3 3 
1 1 
2 -1 
1 1
*/
inline int read(){
//	ll x;
//	cin>>x;
//	return x;
	int s=0,w=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s*=10;
		s+=ch-'0';
		ch=getchar();
	}
	return s*w;
}
void getans(){
	int i;
	for(i=1;i<=k;++i){
		s[i]=now[i];
//		cout<<s[i]<<' ';
	}
//	cout<<endl;
	while(1){
		for(i=1;i<=n;++i){
			s[st[i]]+=d[i];
			++ans;
			if(s[st[i]]<1||s[st[i]]>w[st[i]]){
				return;
			}
		}
	}
}
void dfs(int x,int k){
	int i;
	if(x==k+1){
		getans();
		return;
	}
	for(i=1;i<=w[x];++i){
		now[x]=i;
		dfs(x+1,k);
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(),k=read();
	int i,j;
	for(i=1;i<=k;++i)w[i]=read();
	for(i=1;i<=n;++i){
		st[i]=read();
		d[i]=read();
	}
	dfs(1,k);
	cout<<ans;
}
