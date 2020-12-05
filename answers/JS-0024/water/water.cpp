//GZZ保佑
//T1 像是拓扑排序 
#include<cstdio>
using namespace std;
int n,head[100005],next[500005],num[500005],tot,in_[100005];
int que[100005],m,d[100005],x,l,r;
long long p[100005],q[100005];
void add(int x,int y){tot++;next[tot]=head[x];head[x]=tot;num[tot]=y;}
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
void yue(long long &p,long long &q){
	long long a=gcd(p,q);p/=a;q/=a;
}
void chu(long long &p,long long &q,long long x){// p/qx;
	if(x==0)return;q*=x;yue(p,q);
}
void plas(long long &p1,long long &q1,long long p2,long long q2){//p1/q1 +p2/q2
	if(q1==0){p1=p2;q1=q2;return;}
	long long num=gcd(q1,q2);
	long long nq1=q1/num;nq1*=q2;
	long long num_1=nq1/q1,num_2=nq1/q2;
	long long np1=p1*num_1+p2*num_2;
	yue(np1,nq1);
	
//	long long np12=p1*q2+p2*q1;
//	long long nq12=q1*q2;
//	yue(np12,nq12);
//	if(np1!=np12||nq1!=nq12){
//		printf("%d %d %d %d",p1,q1,p2,q2);
//		return;
//	}
	
//开个long long 不加优化还是会溢出啊	
	p1=np1;q1=nq1;
}
void bfs(){
	int now=0;;
	while(l<=r){
		now=que[l];
		chu(p[now],q[now],d[now]);
		for(int i=head[now];i;i=next[i]){
			int u=num[i];
			plas(p[u],q[u],p[now],q[now]);
			in_[u]--;
			if(in_[u]==0){r++;que[r]=u;}
		}
		l++;
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		for(int j=1;j<=d[i];j++){
			scanf("%d",&x);
			add(i,x);in_[x]++;
		}
	}
	for(int i=1;i<=n;i++)if(in_[i]==0){
		p[i]=q[i]=1;
		r++;que[r]=i;
	}
	l=1;bfs();
	for(int i=1;i<=n;i++)if(d[i]==0)
	printf("%lld %lld\n",p[i],q[i]);
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0
0
*/
