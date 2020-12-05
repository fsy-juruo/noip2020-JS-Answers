#include<bits/stdc++.h>
#define N 1005
using namespace std;
typedef long long ll;
ll n,ans,now,nxt[N],sum[30][N];
char ch[N];
bool vis[30];
ll read(){
	ll f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f*x;
}
namespace Subtask1{
	ll calc(int pos){
		ll tot=0;
		for(int j=1;j<=26;j++)
			if(sum[j][pos]&1)
				tot++;
		return tot;
	}
	bool check(int len,int pos){
		if(pos%len!=0)return 0;
		for(int i=1;i<pos/len;i++)
			for(int j=1;j<=len;j++)
				if(ch[i*len+j]!=ch[j])
					return 0;
		return 1;
	}
	void work(){
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++)sum[ch[i]-'a'+1][i]++;
		for(int i=1;i<=26;i++)
			for(int j=1;j<=n;j++)
				sum[i][j]+=sum[i][j-1];
		for(int i=3;i<=n;i++){
			now=0;
			for(int j=1;j<=26;j++)
				if((sum[j][n]-sum[j][i-1])&1)now++;
			for(int j=1;j<i;j++){
				if(calc(j)>now)continue;
				for(int k=1;k+j<i;k++){
					if(check(k+j,i-1))ans++;
				}
			}
		}
		printf("%lld\n",ans);
		ans=0;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll T=read();while(T--){
		scanf("%s",ch+1);
		n=strlen(ch+1);
		Subtask1::work();
	}
	return 0;
}

