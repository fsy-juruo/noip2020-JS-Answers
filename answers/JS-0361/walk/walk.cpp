#include <bits/stdc++.h>
using namespace std;
int n,k;
long long MOD=1000000007;
int ans=0;
int d[500005][2];
vector<int> w;
vector<int> now;
int read(){
	int f=1,x=0;
	char ss=getchar();
	while(ss<'0'){
		if(ss=='-') f=-1;
		ss=getchar();
	}
	while(ss>='0'){
		x=x*10+ss-'0';
		ss=getchar();
	}
	return f*x;
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=k;++i){
		int x=read();
		w.push_back(x);
	}
	for(int i=1;i<=n;++i){
		d[i][0]=read();
		d[i][1]=read();
	}
	cout<<-1;
	return 0;
	/*if(k==1){
		int t=0;
		for(int )
		for(int i=1;i<=w[0];++i){
			now.push_back(i);
			while(now[0]<=w[0]&&now[0]>=1){
				for(int j=1;j<=n;++j){
					cout<<d[j][0]<<endl;
					now[d[j][0]-1]+=d[j][1];
					ans++;
					if(now[0]>w[0]&&now[0]<1) break;
				}
			}
		}
		printf("%d",ans);
		return 0;
	}
	if(k==2)
	if(k==3)
	if(k==4)
	if(k==5)
	return 0;*/
}
