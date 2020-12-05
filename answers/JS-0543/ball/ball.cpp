#include<bits/stdc++.h>
using namespace std;
stack<int>b[120];
int k,op[1000000],t[1000000],n,m;
void move(int x,int v){
	int col=b[x].top();
	while(1){
		if(b[x].size()<=0)break;
		if(b[x].top()!=col)break;//puts("A");
		if(b[v].size()>=m)break;//puts("A");
		if(b[x].top()!=col)break;//puts("A");
		
		++k;
		op[k]=x,t[k]=v;
		b[v].push(col);
		b[x].pop();
	}
}
inline int read(){
	int s=0,w=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s*=10;
		s+=ch-'0';
		ch=getchar();
	}
	return s*w;
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read(),m=read();
	int i,j;
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			b[i].push(read());
		}
	}

for(int p=1;p<=1000;++p){
		for(i=1;i<=n+1;++i){
		for(j=1;j<=n+1;++j){
			if(b[i].size()==0||b[j].size()>=m)continue;
			if(b[j].size()==0||i!=j&&b[i].top()==b[j].top()){
			//	cout<<i<<' '<<j<<' '<<m<<endl;
				if(b[i].size()>b[j].size())move(i,j);
				else move(j,i);
			}
		}
	}
}
	printf("%d\n",k);
	for(i=1;i<=k;++i){
		printf("%d %d\n",op[i],t[i]);
	}
}
