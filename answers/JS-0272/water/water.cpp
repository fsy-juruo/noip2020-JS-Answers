#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int f=1;
	char ch;
	long long k=0;
	ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		k=k*10+ch-'0';
		ch=getchar();
	}
	return k*f;
}
int n,m;
struct Info{
	long long zi,mu;
}a[100004];//记录每个排水口当前水量的分子、分母 
void work(int c,long long d,long long e){//分数加法 
	int r=a[c].zi,s=a[c].mu;
	 a[c].zi=r*e+s*d;
	 a[c].mu=s*e;
	 int p=__gcd(a[c].zi,a[c].mu);
	 a[c].zi/=p,a[c].mu/=p;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)a[i].zi=1,a[i].mu=1;
	for(int i=m+1;i<=n;i++)a[i].zi=0,a[i].mu=1;
	for(int i=1;i<=n;i++){
		int x;
		x=read();
		for(int j=1;j<=x;j++){
			int q;
			q=read();
			work(q,a[i].zi,a[i].mu*x);
		}
		if(x==0){
			cout<<a[i].zi<<' '<<a[i].mu<<endl;
		}
	}
	return 0;
}


