# include<bits/stdc++.h>
using namespace std;
# define ll long long
# define int ll
const int maxn=1e5+1;

ll read(){
	ll s=0,w=1;
	char ch=getchar();
	while (ch<'0' || ch>'9'){
		if (ch=='-'){
			w=-1;
		}
		ch=getchar();
	}
	while (ch>='0' && ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}

int n,m,p[maxn],q[maxn],v[maxn],pre[maxn];
int head[maxn],in[maxn],cnt,ans,num[maxn];
struct Edge{
	int to,next;
} e[maxn];

void add(int x,int y){
//	cout<<"ASDsad";
	
	e[++ans].to=y;
	e[ans].next=head[x];
	head[x]=ans;
//	cout<<x<<' '<<head[x]<<' '<<e[ans].to<<' '<<e[ans].next<<' '<<ans<<endl;
}

ll gcd(ll x,ll y){
	return (y==0)?x:gcd(y,x%y);
}

void dfs(int x){
//	vis[]
//	if (pre[x]) return ;
	if (pre[x]){
		int d=gcd(p[x],q[x]);
		p[x]/=d;
		q[x]/=d;
		return ;
	}
//	cout<<"ASd";
//	cout<<head[x];
	for (int i=head[x];i;i=e[i].next){
//		cout<<"Asdasd";
		int y=e[i].to;
//		cout<<x<<' '<<y<<' '<<p[y]<<' '<<q[y]<<' '<<p[x]<<' '<<q[x]<<endl;
//		if (p[y])
		p[y]=num[x]*p[y]*q[x]+p[x]*q[y];
		q[y]=num[x]*q[y]*q[x];
//		cout<<x<<' '<<y<<' '<<p[y]<<' '<<q[y]<<endl;
		
		dfs(y);
//		int d=gcd()
	}
	p[x]=0;
	q[x]=1;
}

signed main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();
	m=read();
//	cout<<endl<<"asdsad"<<gcd(4,2)<<endl<<"ASDSAd";
	for (int i=1;i<=n;i++){
		num[i]=read();
		if (!num[i]){
			v[++cnt]=i;
			pre[i]=cnt;
//			cout<<i<<endl;
		}
		for (int j=1;j<=num[i];j++){
			int y=read();
//			cout<<""
			add(i,y);
			in[y]++;
		}
	}
	for (int i=1;i<=n;i++){
		if (!in[i]){
			p[i]=1;
		}
//		cout<<in[i]<<'0 '<<i<<endl;
		q[i]=1;
	}
	for (int i=1;i<=n;i++){
		if (!in[i]){
//			cout<<"ASD";
			dfs(i);
		}
	}
	for (int i=1;i<=cnt;i++){
		int d=gcd(p[v[i]],q[v[i]]);
//		int d=1;
		cout<<p[v[i]]/d<<' '<<q[v[i]]/d<<endl;
	}
	return 0;
}

