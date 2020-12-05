#include<bits/stdc++.h>
using namespace std;
int n,m,d[100003],cntfa[100003];
vector<int>v[100003];
char c;long long ret;
long long read(){
	ret=0;c='.';
	while(c<'0'||c>'9')c=getchar();
	while(c<='9'&&c>='0')ret=ret*10+c-'0',c=getchar();
	return ret;
}
long long gcd(long long x,long long y){
	if(x<y)swap(x,y);
	if(y==0)return x;
	return gcd(y,x%y);
}
long long p[100003],q[100003];
int nowok[100003],s;
bool vis[100003];
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();m=read();
	for(int i=0;i<n;i++){
		d[i]=read();
		for(int j=0;j<d[i];j++){
			int sn=read();
			v[i].push_back(sn-1);
			cntfa[sn-1]++;
		}q[i]=1;
	}s=m-1;
	for(int i=0;i<m;i++){
		nowok[i]=i;
		p[i]=1;
	}
	while(s!=-1){
		int now=nowok[s--];
		q[now]=q[now]*d[now];
		long long gcder=gcd(p[now],q[now]);
		p[now]/=gcder;q[now]/=gcder;
		for(int i=0;i<d[now];i++){
			long long newq=q[v[now][i]]*q[now]/gcd(q[v[now][i]],q[now]);
			long long newp=p[now]*newq/q[now]+p[v[now][i]]*newq/q[v[now][i]];
			p[v[now][i]]=newp;q[v[now][i]]=newq;cntfa[v[now][i]]--;
			gcder=gcd(p[v[now][i]],q[v[now][i]]);
			p[v[now][i]]/=gcder;q[v[now][i]]/=gcder;
			if(cntfa[v[now][i]]==0&&d[v[now][i]])nowok[++s]=v[now][i],vis[v[now][i]]=1;
		}
	}
	for(int i=0;i<n;i++)
		if(d[i]==0)
			printf("%lld %lld\n",p[i],q[i]);
	return 0;
}//tourist bless me!
