#include<bits/stdc++.h>
#define re register
#define ll long long
using namespace std;
template<typename T> void fr(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+c-48;
	x*=f;
}
template<typename T> void fw(T x){
	if(x<0) x=-x,putchar('-');
	if(x>9) fw(x/10);
	putchar(x%10+48);
}
template<typename T> void fwk(T x){fw(x);putchar(' ');}
template<typename T> void fwl(T x){fw(x);puts("");}
struct node{
	ll fz,fm;
//	int num;
}temp,p[101000];
inline ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
inline void ease(int a)
{
	ll c=gcd(p[a].fz,p[a].fm);
	p[a].fz/=c;
	p[a].fm/=c;
}
int n,m,d[101000],tar;
vector<int>way[101000];
//queue<node>q;
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	fr(n);fr(m);
	for(re int i=1;i<=n;i++){
		fr(d[i]);
		for(re int j=1;j<=d[i];j++){
			fr(tar);
			way[i].push_back(tar);
		}
	}
	/*for(int i=1;i<=m;i++){
		temp.fz=1;temp.fm=1;temp.num=i;
		q.push(temp);
	}
	while(!q.empty())
	{
		for(int i=0;i<vector[q.])q.front().num
	}*/
	for(re int i=1;i<=m;i++){
		p[i].fz=1;
		p[i].fm=1;
	}
	for(re int i=1;i<=n;i++)p[i].fm=1;

/*	for(int i=1;i<=n;i++){
		for(int j=0;j<d[i];j++)fwk(way[i][j]);
		puts("");
	}*/

	for(re int i=1;i<=12;i++){
		for(int j=1;j<=n;j++)
		if(p[j].fz&&d[j]!=0){
//			cout<<1<<endl;
			for(re int k=0;k<d[j];k++){
				p[way[j][k]].fz=p[way[j][k]].fz*p[j].fm*d[j]+p[j].fz*p[way[j][k]].fm;
				p[way[j][k]].fm=p[way[j][k]].fm*p[j].fm*d[j];
				ease(way[j][k]);
			}
			p[j].fz=0;
		}
	}
//	cout<<1<<endl;
	for(int i=1;i<=n;i++){
		if(p[i].fz!=0){
			ease(i);
			printf("%lld %lld\n",p[i].fz,p[i].fm);
		}
	}
	return 0;
}

