#include <bits/stdc++.h>
using namespace std;

unsigned long long read(){
	unsigned long long x=0;char w=0,ch=0;
	while(!isdigit(ch))w|=ch=='-',ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return w?-x:x;
}

struct edge{unsigned long long nxt,to,dis;
}e[500010];
unsigned long long cnt,head[100010];
void add(unsigned long long from,unsigned long long to,unsigned long long dis){
	e[++cnt].nxt=head[from];e[cnt].to=to;e[cnt].dis=dis;head[from]=cnt;
	
}

struct fenshu{unsigned long long p,q;
}fen[100010];
//unsigned long long p[100010]={0},q[100010]={1};
void pp(unsigned long long i){
	cout<<fen[i].p<<" "<<fen[i].q<<endl;
}
unsigned long long gcd(unsigned long long n,unsigned long long m){
	if(n<=m)swap(n,m);
	if(m==0)return n;
	return gcd(n%m,m);
}
fenshu jia(unsigned long long j,unsigned long long k){
	unsigned long long n=fen[j].p,m=fen[j].q,p=fen[k].p,q=fen[k].q;
	unsigned long long ansp,ansq,ansgcd;
	ansp=n*q+m*p;ansq=m*q;ansgcd=gcd(ansp,ansq);
	ansp/=ansgcd;ansq/=ansgcd;
	return ((fenshu){ansp,ansq});
	
}

//good


priority_queue<unsigned long long> q;

unsigned long long d[100010];

void dij(unsigned long long s){
	
	q.push(s);
	while(!q.empty()){
		unsigned long long x=q.top();
		q.pop();
		if(d[x]!=0){
		fen[x].q*=d[x];
		for(unsigned long long i=head[x];i;i=e[i].nxt)
		{
			unsigned long long y=e[i].to;
			//cout<<fen[y].p<<" "<<fen[y].q<<fen[x].p<<" "<<fen[x].q<<endl;
			fenshu an=jia(y,x);
			
			
			fen[y].p=an.p;
			fen[y].q=an.q;
			//cout<<y<<":";pp(y);
			q.push(y);
		}}
		if(d[x]!=0)fen[x].p*=0,fen[x].q=1;
		//cout<<x<<":";pp(x);
	}
	
}








int  main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	unsigned long long n=read(),m=read();//cout<<1;
	//cout<<n<<" "<<m<<endl;
	
	unsigned long long uu,vv;
	for(unsigned long long i=1;i<=n;i++){
		d[i]=read();
		for(unsigned long long j=1;j<=d[i];j++)
		    uu=read(),add(i,uu,1);
		fen[i].q=1;fen[i].p=0;
	}
	for(unsigned long long i=1;i<=m;i++){
		fen[i].p=1;fen[i].q=1;
		
	}
	
	for(unsigned long long i=1;i<=m;i++){
		
		dij(i);
	}
	
	
	for(unsigned long long i=1;i<=n;i++){
		if(d[i]==0)pp(i);
	}
	/*
	for(int i=1;i<=n;i++){
		pp(i);
	}
	        return 0;
	
	*/
	
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

//¿ªlonglong 

