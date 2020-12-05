#include<bits/stdc++.h>
using namespace std;

inline int read(){
	int ans=0,f=1;
	char ch=getchar();
	if(ch=='-') f=-1;
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9'){
		ans=(ans<<1)+(ans<<3)+(ch^'0');
		ch=getchar();
	}
	
	return ans*f;
}

int n,m;
int a[55][405];
signed main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read(),m=read();
	register int i,j,k;
	
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
			a[i][j]=read();

	vector<pair<int,int> > op;
	int cnt=0;
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			if(a[i][j]!=a[i][j-1]&&j!=1){
				for(k=m;k>=j;--k){
					op.push_back(make_pair(i,n+1));
					++cnt;
				}
			}
		}
	}
	
	printf("%d\n",cnt);
	for(i=0;i<cnt;++i) printf("%d %d\n",op[i].first,op[i].second);
	return 0;
}
