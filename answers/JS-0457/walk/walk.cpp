#include<bits/stdc++.h>
using namespace std;
int n,k,w[13],c[500003],d[500003];
vector<int>pth,tmp;
long long ans;
void calc(){tmp=pth;
	for(int i=0;i<10000;i++){
		ans++;
		tmp[c[i%n]]+=d[i%n];
		if(tmp[c[i%n]]<0)return;
		if(tmp[c[i%n]]>=w[c[i%n]])return;
	}
	cout<<-1;
	exit(0);
}
void dfs(int x){
	if(x==k)
		calc();
	else
		for(int i=0;i<w[x];i++){
			pth.push_back(i);
			dfs(x+1);
			pth.pop_back();
		}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<k;i++)
		cin>>w[i];
	for(int i=0;i<n;i++){
		cin>>c[i]>>d[i];
		c[i]--;
	}
	dfs(0);
	cout<<ans;
	return 0;
}//tourist bless me!
