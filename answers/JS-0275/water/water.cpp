#include<bits/stdc++.h>
using namespace std;
struct fs{
	long long a,b;
}w[200000];
queue<long long> q;
long long head[200000],v[200000],next[200000],tt=0;
long long I[200000],O[200000],z[200000];
void ljb(long long x,long long y){
	tt++;
	next[tt]=head[x];
	v[tt]=y;
	head[x]=tt;
	return;
}
long long gcd(long long x,long long y){
	if(y==0)return x;
	return gcd(y,x%y);
}
fs yf(fs x){
	if(x.b==1)return x;
	long long t=gcd(x.a,x.b);
	x.a/=t;
	x.b/=t;
	return x;
}
fs pluss(fs t1,fs t2){
	t1.a*=t2.b;
	
	t2.a*=t1.b;
	fs t3;
	t3.a=t1.a+t2.a;
	t3.b=t1.b*t2.b;
	//cout<<t1.a<<' '<<t2.a<<endl;
	t3=yf(t3);
	//cout<<t3.a<<' '<<t3.b<<endl;
	return t3;
}
int main(){
freopen("water.in","r",stdin);
freopen("water.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<=n;i++){
		w[i].b=1;
		head[i]=-1;
	}
	for(long long i=1;i<=n;i++){
		//cout<<n<<endl;
		long long t;
		cin>>t;
		O[i]=t;
		//cout<<t<<endl;
		for(long long j=1;j<=t;j++){
			long long to;
			cin>>to;
			I[to]++;
			ljb(i,to);
		}
	}
	O[0]=m;
	for(long long i=1;i<=n;i++){
		if(!I[i]){
			I[i]=1;
			ljb(0,i);
		}
	}
	w[0].a=m;
	q.push(0);
	while(!q.empty()){
		long long t=q.front();
		q.pop();
		//cout<<t<<endl;
		if(O[t])
		w[t].b*=O[t];
		w[t]=yf(w[t]);
		for(long long i=head[t];i!=-1;i=next[i]){
			//cout<<i<<endl;
			z[v[i]]++;
			w[v[i]]=pluss(w[v[i]],w[t]);
			if(z[v[i]]==I[v[i]]){
				q.push(v[i]);
			}
		}
		if(O[t])w[t].a=0;
	}
	for(long long i=1;i<=n;i++){
		//cout<<w[i].a<<' '<<w[i].b<<endl;
		if(w[i].a)
			cout<<w[i].a<<' '<<w[i].b<<endl;
	}
//	long long tt,tt1,tt2,tt3;
//	cin>>tt>>tt1>>tt2>>tt3;
//	fs ttt,tttt;
//	ttt.a=tt;
//	ttt.b=tt1;
//	tttt.a=tt2;
//	tttt.b=tt3;
//	ttt=pluss(ttt,tttt);
//	cout<<ttt.a<<' '<<ttt.b<<endl;
return 0;
}

