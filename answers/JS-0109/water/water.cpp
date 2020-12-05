#include<bits/stdc++.h>
using namespace std;
const int M=100005;
#define F(i,a,b) for(int i=a;i<=b;++i)
typedef long long LL;
//typedef pair<int,int> PII;
//#define MP(a,b) make_pair(a,b)
typedef vector<LL>  vec;
LL llrd(){LL aaa;scanf("%lld",&aaa);return aaa;}
//void intpf(int aaa){printf("%d",aaa);return;}
//void vecpf(vec aaa){intpf(aaa[0]);F(i,1,aaa.size()-1)printf(" %d",aaa[i]);printf("\n");}
int n,m;
bool vis[M];
struct Node{
	LL p,q;vec to;int d;
}pipe[M];
LL gcd(LL aa,LL bb){
	if(aa==0)return bb;
	return bb==0?aa:gcd(bb,aa%bb);
}
Node jia(Node aa,Node bb){
	LL c=aa.p*bb.q+aa.q*bb.p,d=aa.q*bb.q;
	Node naa;LL g=gcd(c,d);
	naa.p=c/g;naa.q=d/g;
	return naa;
}
void solve(int j){
	pipe[j].q*=pipe[j].to[0];
	F(i,1,pipe[j].to[0]){
		int nex=pipe[j].to[i];
		pipe[nex].d--;
		Node w=jia(pipe[j],pipe[nex]);
		pipe[nex].q=w.q;pipe[nex].p=w.p;
	}
}
void work(){
	F(i,1,11){
		F(j,1,n){
			if(!vis[j]&&pipe[j].d==0&&pipe[j].to[0]!=0){
				solve(j);vis[j]=1;
			}
		}
	}
	
	F(i,1,n)if(pipe[i].to[0]==0)printf("%lld %lld\n",pipe[i].p,pipe[i].q);
	return;
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	F(i,1,n){
		pipe[i].to.push_back(llrd());
		
		F(j,1,pipe[i].to[0]){pipe[i].to.push_back(llrd());pipe[pipe[i].to[j]].d++;}
		if(i<=m)pipe[i].p=1;
		pipe[i].q=1;
	}
	
	work();
	
	
	return 0;
}
