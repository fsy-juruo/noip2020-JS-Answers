#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int read() {
	int f=1,x=0;
	char ch;
	do {
		ch=getchar();
		if(ch=='-')f=-1;
	} while(ch<'0'||ch>'9');
	do {
		x=x*10+ch-'0';
		ch=getchar();
	} while(ch>='0'&&ch<='9');
	return f*x;
}
int gcd(int a,int b) {
	if(b==0) {

		return a;
	}
	gcd(b,a%b);
}
ll lcm(int a,int b) {
	return (ll)a/gcd(a,b)*b;
}
struct edge {
	int to,next;
} e[2000005];
struct fs {
	ll p,q;
} Fs[100005];
int head[100005],In[100005];
int n,m,s,cnt;
ll num[100005];
queue<int>q;
void add_edge(int u,int v) {
	e[++cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void bfs(int I) {
	q.push(I);
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		if(num[u]>0) {
			for(int i=head[u]; i; i=e[i].next) {
				int v=e[i].to;
				ll lm;
				lm=lcm(Fs[v].q,Fs[u].q*num[u]);
				Fs[v].p=Fs[u].p*lm/(Fs[u].q*num[u])+Fs[v].p*lm/(Fs[v].q);
				Fs[v].q=lm;
				ll gd;
				gd=gcd(lm,Fs[v].p);
				Fs[v].p/=gd;
				Fs[v].q/=gd;
				//cout<<v<<endl;
				//cout<<Fs[v].p<<" "<<Fs[v].q<<"\n";
				q.push(v);
			}
			Fs[u].p=0;
			Fs[u].q=1;
		}

	}
}
int main() {
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		Fs[i].p=0;
		Fs[i].q=1;
	}
	for(int i=1; i<=n; i++) {
		num[i]=read();
		for(int j=1; j<=num[i]; j++) {
			int v;
			v=read();
			add_edge(i,v);
			In[v]++;
		}
	}
	//cout<<endl;
	int cnt=0;
	for(int i=1; i<=n; i++) {
		if(num[i]==0)cnt++;
	}
	if(cnt==1) {
		cout<<"1 "<<"1";
	} 
	else if(m==1){
		for(int i=1; i<=n; i++) {
			if(In[i]==0) {
				Fs[i].p=1;
				bfs(i);
			}
		}
		//cout<<endl;
		for(int i=1; i<=n; i++) {
			if(num[i]==0)cout<<Fs[i].p<<" "<<Fs[i].q<<"\n";
		}
	}
	return 0;
}
