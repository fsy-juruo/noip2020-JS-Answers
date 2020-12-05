#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
inline int read(){
	int ret=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			w=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret*w;
}
void print(int x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>=10){
		print(x/10);
		putchar('0'+x%10);
	}
	if(x<=9){
		putchar('0'+x);
	}
}
struct Edge{
	int to;
	int nxt;
}e[N];
struct Water{
	int a;
	int b;
}w[N];
int n,m,cnt,tmp,s,cntout,d[N],first[N],rd[N];
vector<int> v;
void add_edge(int u,int v){
	cnt++;
	e[cnt].to=v;
	e[cnt].nxt=first[u];
	first[u]=cnt;
}
int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}
Water Divide(Water x,int y){
	int g=gcd(x.a,y);
	x.a/=g;
	y/=g;
	x.b*=y;
	return x;
}
Water Plus(Water x,Water y){
	Water ret;
	int l=x.b*y.b/gcd(x.b,y.b);
	int u=(l/x.b)*x.a+(l/y.b)*y.a;
	int g=gcd(l,u);
	ret.a=u/g;
	ret.b=l/g;
	return ret;
}
void solve(){
	while(v.size()>cntout){
		for(int i=0;i<v.size();i++){
			int u=v[i];
			if(rd[u]==0&&w[u].a>0&&d[u]>0){
				for(int j=first[u];j!=-1;j=e[j].nxt){
					int v=e[j].to;
					rd[v]--;
					w[v]=Plus(Divide(w[u],d[u]),w[v]);
				}
				v.erase(v.begin()+i);
			}
		}
	}
	for(int i=0;i<v.size();i++){
		int u=v[i];
		print(w[u].a);
		putchar(' ');
		print(w[u].b);
		putchar('\n');
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	memset(first,-1,sizeof(first));
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		w[i].a=0,w[i].b=1;
		d[i]=read();
		if(d[i]==0){
			cntout++;
		}
		for(int j=1;j<=d[i];j++){
			tmp=read();
			add_edge(i,tmp);
			rd[tmp]++;
		}
		v.push_back(i);
	}
	for(int i=1;i<=n;i++){
		if(rd[i]==0){
			w[i].a=1;
			w[i].b=1;
		}
	}
	solve();
	return 0;
}
