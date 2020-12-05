#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f*=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x*=10;
		x+=ch-'0';
		ch=getchar();
	}
	return x*f;
}
queue<int>f;
struct ccf{
	int t;//排出管道的数量
	long long p,q;//p分子  Q分母 
	queue<int>pq;
}a[50010];
int ans[50010];
int pu[50010];
long long gcd(long long m,long long n){
	if(n==0)return m;
	return gcd(n,m%n);
}
void padd(long long a1,long long b1,long long &a2,long long &b2){
	if(a2==0){
		a2=a1;
		b2=b1;
	}else{
		a2=a1*b2+a2*b1;
		b2*=b1;
	}
	
	long long kel=gcd(a2,b2);
	a2/=kel;
	b2/=kel;
}
bool flg[50010];
void print(){
	for(int i=1;i<=pu[0];i++){
		cout<<a[pu[i]].p<<" "<<a[pu[i]].q<<"\n";
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	int n,m;
	n=read();
	m=read();
	
	for(int i=1;i<=n;i++){
		a[i].t=read();
		for(int j=1;j<=a[i].t;j++){
			int s=read();
			a[i].pq.push(s);
			ans[s]=1;
		}
		a[i].p=0;
		a[i].q=1;
		if(a[i].t==0){
			pu[0]++;
			pu[pu[0]]=i;
		}
	} 
	
	for(int i=1;i<=n;i++){
		if(ans[i]==0){
			f.push(i);
			a[i].p=1;
			flg[i]=1;
		}
	}
	
	while(!f.empty()){
		int x=f.front();
		f.pop();
		
		if(a[x].t==0){continue;}
		a[x].q*=a[x].t;
		int g=gcd(a[x].p,a[x].q);
		a[x].p/=g;
		a[x].q/=g;
		queue<int>nq=a[x].pq;
		while(!a[x].pq.empty()){
			int tmp=a[x].pq.front();
			
			padd(a[x].p,a[x].q,a[tmp].p,a[tmp].q);
			if(flg[tmp]==0)f.push(tmp);
			a[x].pq.pop();
		}
		a[x].pq=nq;
		if(a[x].t!=0)a[x].p=0;
	}
	print();
	return 0;
}
