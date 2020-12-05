#include<bits/stdc++.h>
using namespace std;
#define CIN int
#define reg register
#define ma(a,b) make_pair(a,b)
CIN rf(){
	CIN num=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		num=num*10+c-'0';
		c=getchar();
	}
	return num*f;
}
inline long long gcd(long long a,long long b){
	long long c=a%b;
	if(c==0)return b;
	return gcd(b,c);
}
struct node{
	vector<int>c;
	int r;
	long long p,q;//	p/q	
}a[100011];
long long P,Q;
void yf(long long P1,long long Q1){
	P=P1;Q=Q1;
	long long x=gcd(P,Q);
	P=P/x;Q=Q/x;	
}
int m,n;
int O[100011],cnt=0;
queue<int>D;
void BFS(){
	while(D.size()){
		int x=D.front();
		for(reg int i=0;i<a[x].c.size();++i){
			long long z=a[x].p,zz=a[x].q*a[x].c.size();			
			a[a[x].c[i]].p*=zz;
			z*=a[a[x].c[i]].q;
			a[a[x].c[i]].p+=z;
			a[a[x].c[i]].q*=zz;
			yf(a[a[x].c[i]].p,a[a[x].c[i]].q);
			a[a[x].c[i]].p=P;a[a[x].c[i]].q=Q;	
			a[a[x].c[i]].r--;
			if(a[a[x].c[i]].r==0)			
				D.push(a[x].c[i]);
		}
		if(a[x].c.size()>0){
			a[x].p=0;a[x].q=1;
		}
		D.pop();
	}
}
int main()
{
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=rf(),m=rf();
	for(reg int i=1;i<=n;++i){
		a[i].q=1;
		int d=rf();
		for(reg int j=1;j<=d;++j){
			int x=rf();
			a[i].c.push_back(x);
			a[x].r++;
		}
	}
	
	for(reg int i=1;i<=n;++i){
		if(a[i].c.size()==0){
			O[++cnt]=i;
		}
		if(a[i].r==0){
			a[i].p=1;
			D.push(i);
		}
	}
	BFS();
	for(reg int i=1;i<=cnt;++i){
		printf("%d %d\n",a[O[i]].p,a[O[i]].q);
	}
	return 0;
}
//zz rp++
