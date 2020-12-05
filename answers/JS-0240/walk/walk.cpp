#include<bits/stdc++.h>
using namespace std;
int n,k;

int st[100],pos[100],w[100];
int c[100005],d[100005];
long long ans=0;
void wk(){
	for(int i=1;i<=k;i++){
		pos[i]=st[i];
//		cout<<st[i]<<' ';
	}
	int f=0;
	for(int i=1;;i=i%n+1){
		pos[c[i]]+=d[i];
		ans++;
		if(pos[c[i]]<1||pos[c[i]]>w[c[i]])break;
		if(i==1&&f==1){
			int ff=0;
			for(int j=1;j<=k;j++){
				if(pos[j]!=st[j]){
					ff=1;break;
				}
			}
			if(ff==0){
				ans=-1;break;
			}
		}
		f=1;
	}
//	cout<<ans-ls<<endl;
}
void dfs(int x){
	if(x==k){
		wk();
		return;
	}
	for(int i=1;i<=w[x+1];i++){
		st[x+1]=i;
		dfs(x+1);
		if(ans==-1)return;
	}
}
int mxd,mnd,stp[300005];
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++)cin>>w[i];
	for(int i=1;i<=n;i++)cin>>c[i]>>d[i];
	if(n<=1000)
		dfs(0);
	else ans=-1;
	cout<<ans<<endl;
}
