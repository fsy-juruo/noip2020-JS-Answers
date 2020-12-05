#include<bits/stdc++.h>
//#define getchar nc
using namespace std;
inline char nc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
	register int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-48;ch=getchar();}
	return x*f;
}
int n,m,top;
int col[55][405],sum[55];
pair<int,int> sta[820005];
inline void add(register int u,register int v){
	sta[++top]=make_pair(u,v); 
	col[v][++sum[v]]=col[u][sum[u]];
	col[u][sum[u]--]=0;
//	assert(sum[v]<=m);
//	assert(sum[u]>=0);
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read(),m=read();
	for(register int i=1;i<=n;++i){
		for(register int j=1;j<=m;++j)
			col[i][j]=read();
		sum[i]=m;
	}
	for(register int i=1;i<n;++i){
		int cnti=0,s=0;
		for(register int j=1;j<=m;++j) if(col[i][j]==i) ++cnti;
		for(register int j=1;j<=cnti;++j) add(n,n+1);
		for(register int j=m;j>=1;--j) if(col[i][j]==i) add(i,n); else add(i,n+1);
		for(register int j=1;j<=cnti;++j) add(n,i);
		for(register int j=1;j<=cnti;++j) add(n+1,n);
		s+=cnti;
		for(register int j=s+1;j<=m;++j) add(n+1,i);
//		for(register int i=1;i<=n;++i){
//			for(register int j=1;j<=sum[i];++j)
//				cerr<<col[i][j];
//			cerr<<endl;
//		}
		for(register int j=i+1;j<n;++j){
			cnti=0;
			for(register int k=1;k<=m;++k) if(col[j][k]==i) ++cnti;
			for(register int k=1;k<=cnti;++k) add(n,n+1);
			for(register int k=m;k>=1;--k) if(col[j][k]==i) add(j,n); else add(j,n+1);
//			assert(sum[n]==m);
			for(register int k=s+1;k<=m;++k) add(i,j);
			for(register int k=1;k<=cnti;++k) add(n,i);
			for(register int k=1;k<=cnti;++k) add(n+1,n);
			s+=cnti;
			for(register int k=s+1;k<=m;++k) add(n+1,i);
			while(sum[n+1]) add(n+1,j);
//			assert(sum[j]<=m);
//			for(register int k=1;k<=m;++k) assert(sum[k]==m);
		}
//		cerr<<s<<endl;
		cnti=0;
		for(register int j=s+1;j<=m;++j) if(col[i][j]==i) ++cnti;
		for(register int j=1;j<=cnti;++j) add(n,n+1);
		for(register int j=m;j>=s+1;--j) if(col[i][j]==i) add(i,n); else add(i,n+1);
//		for(register int j=1;j<=n+1;++j) cerr<<sum[j]<<" ";
//		cerr<<endl;
//		for(register int j=m;j>=1;--j) cerr<<col[n][j]<<" ";
		for(register int j=m;j>=1;--j) if(col[n][j]==i) add(n,i); else add(n,n+1);
		for(register int j=1;j<=m;++j) add(n+1,n);
//		for(register int j=1;j<=n+1;++j) cerr<<sum[j]<<" ";
//		cerr<<endl;
	}
	printf("%d\n",top);
	for(register int i=1;i<=top;++i)
		printf("%d %d\n",sta[i].first,sta[i].second);
	return 0;
}

