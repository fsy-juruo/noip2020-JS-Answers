#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int n,k;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
namespace A{//30pts
	int delta[11],maxd[11],mind[11];
	int w[11],pl[11],ans;
	struct move{
		int c,d;
	}a[110];
	void zou(){
		int tmp[11];
		for(int i=1;i<=k;i++)tmp[i]=pl[i];
		int i=1;
		while(1){
			tmp[a[i].c]+=a[i].d;
			ans++;
			if(tmp[a[i].c]<=0||tmp[a[i].c]>w[a[i].c])return;
			i++;
			if(i==n+1)i=1;
		}
	}
	void dfs(int x){
		if(x==k+1)zou();
		for(int i=1;i<=w[x];i++){
			pl[x]=i;
			dfs(x+1);
		}
	}
	void solve(){
		for(int i=1;i<=k;i++){
			w[i]=read();
		}
		for(int i=1;i<=n;i++){
			a[i].c=read();
			a[i].d=read();
			delta[a[i].c]+=a[i].d;
			maxd[a[i].c]=max(maxd[a[i].c],delta[a[i].c]);
			mind[a[i].c]=min(mind[a[i].c],delta[a[i].c]);
		}
		bool flag1=false,flag2=false;
		for(int i=1;i<=k;i++){
			if(maxd[i]-mind[i]>w[i])flag1=true;
			if(delta[i]!=0)flag2=true;
		}
		if(!flag1&&!flag2){
			printf("-1\n");
			return;
		}
		dfs(1);
		printf("%lld\n",ans%mod);
	}
}
namespace B{//10pts
	const int N=1e5+10;
	int len,delta[11],w[11],pre[N],maxd[11],mind[11];//first appear
	map<int,int>mp;
	int ans;
	struct move{
		int c,d;
	}a[N];
	void solve(){
		len=read();
		w[1]=len;
		for(int i=1;i<=n;i++){
			a[i].c=read();
			a[i].d=read();
			pre[i]=pre[i-1]+a[i].d;
			if(!mp[pre[i]])mp[pre[i]]=i;
			delta[a[i].c]+=a[i].d;
			maxd[a[i].c]=max(maxd[a[i].c],delta[a[i].c]);
			mind[a[i].c]=min(mind[a[i].c],delta[a[i].c]);
		}
		bool flag1=false,flag2=false;
		for(int i=1;i<=k;i++){
			if(maxd[i]-mind[i]>w[i])flag1=true;
			if(delta[i]!=0)flag2=true;
		}
		if(!flag1&&!flag2){
			printf("-1\n");
			return;
		}
		if(pre[n]>=0){
			for(int i=1;i<=len;i++){
				int num=(n-i+1)/pre[n];
				ans+=num*n;
				if(num*pre[n]+i>n)continue;
				ans+=mp[n-i+1];
				ans%=mod;
			}
		}
		else{
			for(int i=1;i<=len;i++){
				int num=i/pre[n];
				ans+=num*n;
				if(i-pre[n]*num<=0)continue;
				ans+=mp[-i];
				ans%=mod;
			}
		}
		printf("%lld\n",ans);
	}
}
namespace C{
	void solve(){
		
	}
}
namespace D{
	void solve(){
		
	}
}
signed main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(),k=read();
//	printf("%d %d\n",n,k);
	if(n<=100)A::solve();
	else if(k==1)B::solve();
	else if(k==2)C::solve();
	else D::solve();
	return 0;
}

