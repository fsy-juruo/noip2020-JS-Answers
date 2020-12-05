#include<bits/stdc++.h>
using namespace std;
int n,m;
bool g[100005],y[100005];
struct node{
	long long mot,son;
}num[100005];
vector <int> w[100005];
inline int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x;
}
int mbys(int a,int b){
	int bcs=a;
	int cs=b;
	int ys=a%b;
	while(ys){
		bcs=cs;
		cs=ys;
		ys=bcs%cs;
	}
	return cs;
}
void pullwater(int x,int mw,int sw){
	if(y[x]) {
		int a=mbys(num[x].mot,mw);
		int mm=num[x].mot*mw/a;
		int ss=mw/a*num[x].son+num[x].mot/a*sw;
		int b=mbys(mm,ss);
		num[x].mot=mm/b;
		num[x].son=ss/b;
	}
	else for(int i=0;i<w[x].size();i++){
		pullwater(w[x][i],mw*w[x].size(),sw);

	}
}
int main(){
    freopen("water.in","r",stdin);
    freopen("water.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		int cnt;
		cnt=read();
		if(cnt==0) {
			y[i]=1;
			num[i].mot=1;
			num[i].son=0;
		}
		for(int j=1;j<=cnt;j++){
			int a=read();
			w[i].push_back(a);
			g[a]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(!g[i]) pullwater(i,1,1);
	}
	for(int i=1;i<=n;i++){
		if(y[i]) printf("%lld %lld\n",num[i].son,num[i].mot);
	}
	return 0;
}
