#include<bits/stdc++.h>
#define maxn 100005
#define maxm 1000006
using namespace std;
template<typename TP>
inline void read(TP &num7){
	long long val7=0;int w7=1;
	char ch7=getchar();
	while(ch7<'0'||ch7>'9'){if(ch7=='-')w7=-1;ch7=getchar();}
	while(ch7>='0'&&ch7<='9'){val7=(val7<<3)+(val7<<1)+ch7-'0';ch7=getchar();}
	num7=val7*w7;
}
int n,M;//M!=numedge
long long gcd(long long a,long long b){
	return b==0?a:gcd(b,a%b);
}
int indu[maxn],outdu[maxn];
int ver[maxm],head[maxn],nexts[maxm],tot=1;
inline void add(int x,int y){
	ver[++tot]=y;nexts[tot]=head[x];head[x]=tot;
}
int ST[maxn];
struct fenshu{
	long long p,q;
};
inline fenshu pplus(long long p1,long long q1,long long p2,long long q2){
	fenshu ret;
	ret.p=p1*q2+p2*q1;
	ret.q=q1*q2;
	long long GCD=gcd(ret.p,ret.q);
	ret.p/=GCD;ret.q/=GCD;
	return ret;
}
fenshu sum[maxn];
int cnt[maxn];
queue<int>que;
void work(){
	int i,x,y;
	while(que.size())que.pop();
	for(i=1;i<=M;i++){
		que.push(ST[i]);
		sum[ST[i]].p=1;sum[ST[i]].q=1;
	}
	fenshu t;
	while(!que.empty()){
		x=que.front();que.pop();
		t=sum[x];
		for(i=head[x];i;i=nexts[i]){
			y=ver[i];
			sum[y]=pplus(sum[y].p,sum[y].q,t.p,(t.q)*outdu[x]);
			cnt[y]++;
			if(cnt[y]==indu[y]){//!!!
				que.push(y);
			}
		}
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n);read(M);
	int i,j,y;
	for(i=1;i<=n;i++){
		read(outdu[i]);
		for(j=1;j<=outdu[i];j++){
			read(y);
			add(i,y);
			indu[y]++;
		}
	}
	for(i=1;i<=n;i++)
	if(!indu[i])
	ST[++ST[0]]=i;
	for(i=1;i<=n;i++){
		sum[i].p=0;sum[i].q=1;
	}
	work();
	for(i=1;i<=n;i++){
		if(outdu[i])continue;
		fenshu t=sum[i];
		long long GCD=gcd(t.p,t.q);
		t.p/=GCD;t.q/=GCD;
		cout<<t.p<<" "<<t.q<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
