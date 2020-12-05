#include <bits/stdc++.h>
#define rept(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,a) rept(i,0,a)
#define re return
#define sz(a) ((int)a.size())
#define fill(a,t) memset(a,t,sizeof a)
#define all(a) a.begin(),a.end()
#define erase_end(a) if(sz(a))a.erase(a.end()-1)
#define erase_str(a) if(sz(a))a.erase(a.begin())
#define pb push_back
#define int long long
using namespace std;
const int Inf=1000000000;
int read(){
	int f=1,cur=0;
	char ch=cin.get();
	while ((ch<'0' || ch>'9') && ch!='-')  ch=cin.get();
	if (ch=='-') f=-1;
	else cur=ch-'0';
	ch=cin.get();
	while (ch>='0' && ch<='9')  cur=10*cur+ch-'0',ch=cin.get();
	re f*cur;
}
struct num{
	int p,q;
}cur[100005];
int gcd(int a,int b){
	if (b) re gcd(b,a%b);
	else re a;
}
void add(num&a,num b){
	a.p*=b.q;
	b.p*=a.q;
	a.q*=b.q;
	a.p+=b.p;
	int c=gcd(a.p,a.q);
	a.p/=c;
	a.q/=c;
}
void dev(num&a,int b){
	a.q*=b;
	int c=gcd(a.p,a.q);
	a.p/=c;
	a.q/=c;
}
int a[100005],mi[100005];
vector<int>v[100005];
vector<int>non;
signed main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n=read(),m=read();
	rep(i,n){
		a[i]=read();
		mi[i]=Inf;
		rep(j,a[i]){
			v[i].pb(read()-1);
			mi[i]=min(mi[i],v[i][sz(v[i])-1]);
		}
		if (!a[i])
			non.pb(i);
	}
	rep(i,m){
		cur[i].p=1;
	}
	rep(i,n){
		cur[i].q=1;
	}
	int fl=1;
	while (fl){
		fl=0;
	//	rep(i,n){
	//		cout<<cur[i].p<<' '<<cur[i].q<<'\n';
	//	}cout<<"\n\n\n\n\n\n\n\n\n\n\n";
		rep(i,n){
			if (mi[i]<i && cur[i].p>0)  fl=1;
			if (!a[i]) continue;
			if (cur[i].p){
				dev(cur[i],a[i]);
				rep(j,a[i])
					add(cur[v[i][j]],cur[i]);
				cur[i].p=0;
				cur[i].q=1;
			}
		}
	}
	rep(i,sz(non)){
		cout<<cur[non[i]].p<<' '<<cur[non[i]].q<<'\n';
	}
	re 0;
}

/****************** /
		1、检查附初值
		2、检查数组大小，绝对不MLE
		3、检查会不会爆int
		4、对拍查错
/ ******************/
