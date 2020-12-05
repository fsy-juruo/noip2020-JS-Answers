#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+10;
void file(string s){freopen((s+".in").c_str(),"r",stdin),freopen((s+".out").c_str(),"w",stdout);}
int read(){
	int a=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		a=a*10+ch-'0';
		ch=getchar();
	}
	return a*f;
}

struct node{
	int to,next;
}edge[MAXN<<1];
int head[MAXN],cnt;
void addedge(int x,int y){
	edge[++cnt]=(node){y,head[x]};
	head[x]=cnt;
}

int gcd(int a,int b){return (b==0)?a:gcd(b,a%b);}
int lcm(int a,int b){return a/gcd(a,b)*b;}

struct divnum{
	int p,q;
	void yf(){
		int g=gcd(p,q);
		p/=g,q/=g;
	}
	void print(){yf();cout<<p<<' '<<q<<endl;}
	divnum(){q=1;}
}num[MAXN];

divnum Add(divnum a,divnum b){
	divnum re;
	re.q=lcm(a.q,b.q);
	re.p=a.p*re.q/a.q+b.p*re.q/b.q;
	re.yf();
	return re;
}

divnum Div(divnum a,int b){
	a.q*=b;
	a.yf();
	return a;
}

queue<int> q;
int n,m;
int ind[MAXN],outd[MAXN];

void topo(){
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=edge[i].next){
			int y=edge[i].to;
			num[y]=Add(num[y],Div(num[x],outd[x]));
			ind[y]--;
			if(ind[y]==0){
				q.push(y);
			}
		}
	}
}

signed main(){
	file("water");
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		outd[i]=read();
		for(int j=1;j<=outd[i];++j){
			int x=read();
			addedge(i,x);
			ind[x]++;
		}
	}
	for(int i=1;i<=m;++i){
		num[i].p=1;
		if(ind[i]==0)q.push(i);
	}
	topo();
	for(int i=1;i<=n;++i){
		if(outd[i]==0)num[i].print();
	}
	return 0;
}

