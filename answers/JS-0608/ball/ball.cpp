#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=b;++i)
#define pb push_back
using namespace std;
int n,m,a[55][405],si[55];
vector<int>sa,sb;
void move(int f,int t){
	a[t][++si[t]]=a[f][si[f]];
	--si[f];sa.pb(f);sb.pb(t);
}
void work(int r){
	if(r<2){
		cout<<sa.size()<<endl;
		int p=sa.size()-1;F(i,0,p)
		cout<<sa[i]<<' '<<sb[i]<<endl;
		exit(0);
	}
	int t[55]={0},s,ms=0;
	for(int i=1;i<=r;++i)++t[a[i][m]];
	for(int i=1;i<=n;++i)if(t[i]>ms){s=i;ms=t[i];}
	for(int i=1;i<=n;++i)if(a[i][m]==s)move(i,r+1);
	int nt=1;while(si[r+1]<m){
		for(int i=1;i<=r&&a[nt][si[nt]]!=s;++i)
		while(nt!=i&&si[i]<m&&si[nt]&&a[nt][si[nt]]!=s)move(nt,i);
		while(si[nt]&&a[nt][si[nt]]==s)move(nt,r+1);
		if(nt==r)nt=1;else ++nt;
	}
	for(int i=1;i<r;++i)while(si[i]<m)move(r,i);
	work(r-1);
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;for(int i=1;i<=n;++i)si[i]=m;
	F(i,1,n)F(j,1,m)cin>>a[i][j];work(n);
}
