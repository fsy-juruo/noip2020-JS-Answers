#include<bits/stdc++.h>
#define MAXN 100000+10
using namespace std;
int n,m;
vector<int> out[MAXN];
int in[MAXN],to[MAXN];
struct node{
	long long p,q;//  p/q
}w[MAXN];
void add(int x,long long p,long long q)
{
	if(w[x].p==0&&w[x].q==0)
	{
		w[x].p=p;w[x].q=q;
		return;
	}
	w[x].p=w[x].p*q+p*w[x].q;w[x].q*=q;
	int g1=__gcd(w[x].q,w[x].p);
	w[x].p/=g1;w[x].q/=g1;
}
#define F "water"//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int main(){
	freopen(F".in","r",stdin);
	freopen(F".out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		int d,x;cin>>d;
		for(int j=1;j<=d;++j){
			cin>>x;
			out[i].push_back(x);
			in[x]++;to[i]++;
		}
	}
	for(int i=1;i<=n;++i) if(!in[i]) w[i].p=w[i].q=1;
/*	for(int i=1;i<=n;++i)
	{
		cout<<i<<endl;
		for(int j=0;j<out[i].size();++j)
		  cout<<out[i][j]<<' ';
		cout<<endl<<in[i]<<' '<<to[i]<<endl;
		cout<<w[i].p<<' '<<w[i].q<<endl<<endl;
	}	*/
	int num=0,rest=n;
	for(int i=1;i<=n;++i) if(!to[i]) num++;
	while(rest>num){
		for(int i=1;i<=n;++i)
		  if(!in[i]){
		  	for(int j=0;j<out[i].size();++j)
		  	  add(out[i][j],w[i].p,w[i].q*out[i].size()),in[out[i][j]]--;
		  	rest--;
		  }
	}
	for(int i=1;i<=n;++i)
	  if(!to[i]) cout<<w[i].p<<' '<<w[i].q<<endl;
	return 0;
}

