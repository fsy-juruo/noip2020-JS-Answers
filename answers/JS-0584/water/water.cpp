//gzz
#include<queue>
#include<cstdio>
#include<iostream>
#include<algorithm>
#define rep(i,j,k) for (long long i=j;i<=k;++i)
#define dep(i,j,k) for (long long i=j;i>=k;--i)
#define M(a,b) memset(a,b,sizeof(a))
#define C(a,b) memcpy(a,b,sizeof(a))
#define FILE "water"
using namespace std;
struct node{
	long long p,q;
}ans[100005];
struct node2{
	long long id,in,to[10];
}h[100005];
long long gcd(long long a,long long b){
	if (b==0) return a;
	else return gcd(b,a%b);
}
long long lcm(long long a,long long b){
	return a*b/gcd(a,b);
}
bool cmp(node2 x,node2 y){
	return x.in<y.in;
}
bool cmp2(node2 x,node2 y){
	return x.id<y.id;
}
long long n,m,y,z,anss,len[100005],chu[100005],que[100005];
int main(){
	freopen(FILE".in","r",stdin);
	freopen(FILE".out","w",stdout);
	cin>>n>>m;rep(i,1,n) h[i].id=i;
	rep(i,1,n){
		long long x;cin>>x;len[i]=x;
		if (x==0) chu[++anss]=i;
		rep(j,1,len[i]){
			cin>>x;
			h[i].to[j]=x;
			h[x].in++;
		}
	}
	sort(h+1,h+1+n,cmp);long long num,nn=n,l=1,r=1;
	rep(i,1,n){
		if (h[i].in!=0){
			num=i-1;
			break;
		}
		que[r]=h[i].id;r++;ans[h[i].id].p=ans[h[i].id].q=1;
	}
	sort(h+1,h+1+n,cmp2);	
	while (nn!=0){
		nn-=num;long long numm=num;num=0;
		rep(i,1,numm){
			long long now=que[l];l++;
			rep(j,1,len[now]){
				long long v=h[now].to[j],qq,pp,q1=ans[v].q,p1=ans[v].p,q2=ans[now].q*len[now],p2=ans[now].p;				
				if (q1==0 && p1==0){
					qq=q2,pp=p2;
				}
				else{
					qq=q1*q2;pp=p1*q2+p2*q1;
					long long gg=gcd(qq,pp);
					qq/=gg;pp/=gg;
				}
				ans[v].q=qq;ans[v].p=pp;h[v].in--;
				if (h[v].in==0) ++num,que[r]=h[v].id,r++;
			}
		}
	}
	rep(i,1,anss){
		long long qq=ans[chu[i]].q,pp=ans[chu[i]].p;
		long long gg=gcd(qq,pp);
		qq/=gg;pp/=gg;
		cout<<pp<<' '<<qq<<endl;
	}
	return 0;
}
