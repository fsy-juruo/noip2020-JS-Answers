#include<stdio.h>
#define N 100011
long long gcd(long long a,long long b){
	long long tmp;
	if(a<b)
		tmp=a,a=b,b=tmp;
	while(b){
		tmp=a%b,a=b,b=tmp;
	}
	return a;
}
struct factor_number{//a/b
	long long a,b;
	factor_number(){
		this->a=0;
		this->b=1;
	}
	factor_number(long long a,long long b){
		this->a=a;
		this->b=b;
	}
	factor_number operator+(const factor_number &c){
		factor_number ans(a*c.b+c.a*b,c.b*b);
		long long tmp=gcd(ans.a,ans.b);
		ans.a/=tmp;
		ans.b/=tmp;
		return ans;
	}
	factor_number operator/(long long c){
		factor_number ans(a,b*c);
		long long tmp=gcd(ans.a,ans.b);
		ans.a/=tmp;
		ans.b/=tmp;
		return ans;
	}
};
struct edge{
	int index;
	edge *next;
	edge(int index,edge *next){
		this->index=index;
		this->next=next;
	}
};
int indegree[N],n,q[N],tail,head,d[N];
edge *G[N];
void add_edge(int start,int end){
	G[start]=new edge(end,G[start]);
}
void del(){
	int i;
	for(i=1;i<=n;++i){
		edge *p=G[i],*tmp;
		while(p){
			tmp=p->next;
			delete p;
			p=tmp;
		}
	}
}
factor_number wushui[N];
void tuopupaixv(){
	factor_number tmp;
	int i,to;
	edge *p;
	for(i=1;i<=n;++i)
		for(p=G[i];p;p=p->next)
			indegree[p->index]++;
	for(i=1;i<=n;++i)
		if(!indegree[i]){
			q[tail++]=i;
			wushui[i]=factor_number(1,1);
		}
	while(head!=tail){
		i=q[head++];
		tmp=wushui[i]/d[i];
		for(p=G[i];p;p=p->next){
			to=p->index;
			wushui[to]=wushui[to]+tmp;
			indegree[to]--;
			if(!indegree[to])
				q[tail++]=to;
		}
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int m,i,j,e;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%d",d+i);
		for(j=0;j<d[i];++j){
			scanf("%d",&e);
			add_edge(i,e);
		}
	}
	
	tuopupaixv();
	for(i=1;i<=n;++i)
		if(!G[i])//wushuipaifangdian
			printf("%lld %lld\n",wushui[i].a,wushui[i].b);
	del();
	return 0;
}
