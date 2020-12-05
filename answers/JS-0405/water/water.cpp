#include <bits/stdc++.h>
#define MAXN 100005
#define ull unsigned long long
using namespace std;
inline ull read(){
	ull num=0,zf=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')zf=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar();
	}
	return zf*num;
}
ull n,m,u;
queue<ull> q;
vector<ull> a[MAXN];
ull in[MAXN],out[MAXN];
ull son[MAXN],mum[MAXN];
ull gcd(ull x,ull y){
	if(y==0)return x;
	return gcd(y,x%y);
}
void make(ull f,ull d,ull b,ull c){//cout<<f<<endl;
	ull x=son[f],y=mum[f];//cout<<"("<<endl;
	b*=c;
	ull j=x,k=y;
	if(x!=0){
		y=k*b;
		x=b*j+d*k;
	}
	else{
		y=b;x=d;
	}
	//cout<<x<<' '<<y<<endl;
	j=x;k=y;
	j=gcd(j,k);
	x/=j;y/=j;
	son[f]=x;mum[f]=y;
	return ;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		out[i]=read();
		for(int j=1;j<=out[i];j++){
			u=read();
			a[i].push_back(u);
			//cout<<i<<' '<<u<<endl;
			in[u]++;
		}
	}
	for(int i=1;i<=m;i++){
		q.push(i);
		son[i]=mum[i]=1;
	}
		
	while(!q.empty()){
		int h=q.front();q.pop();
		for(int i=0;i<out[h];i++){//cout<<h<<' '<<i<<endl;
			make(a[h][i],son[h],mum[h],out[h]);//cout<<"@"<<endl;
			in[a[h][i]]--;//cout<<"$"<<endl;
			if(in[a[h][i]]==0)q.push(a[h][i]);//cout<<"!"<<endl;
		}
		if(out[h])son[h]=0;
	}
	//cout<<"%"<<endl;
	for(int i=1;i<=n;i++)
	if(son[i]){
		printf("%lld %lld\n",son[i],mum[i]);
	}
	return 0;
}
