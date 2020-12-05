#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int T,n;
char ch[N];
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
namespace A{
	const int M=2020;
	const int mod=20050311;
	int num[30],pre[M],suf[M],tot;
	int haha[M][M],ans;
	int power(int x,int y){
		int tmp=1;
		while(y){
			if(y&1)tmp=tmp*x%mod;
			x=x*x%mod;
			y>>=1;
		}
		return tmp;
	}
	void solve(){
		ans=0;
		memset(haha,0,sizeof haha);
		memset(num,0,sizeof num);
		memset(pre,0,sizeof pre);
		memset(suf,0,sizeof suf);
		tot=0;
		for(int i=1;i<=n;i++){
			haha[i][i]=ch[i]-'a'+1;
			for(int j=1;j<i;j++){
				haha[j][i]=haha[j][i-1]*100%mod+ch[i]-'a'+1;
			}
		}
		for(int i=1;i<=n;i++){
			if(num[ch[i]-'a'+1]==1){
				tot--;
				num[ch[i]-'a'+1]=0;
				pre[i]=tot;
			}
			else{
				tot++;
				num[ch[i]-'a'+1]=1;
				pre[i]=tot;
			}
		}
		memset(num,0,sizeof num);
		tot=0;
		for(int i=n;i>=1;i--){
			if(num[ch[i]-'a'+1]==1){
				num[ch[i]-'a'+1]=0;
				tot--;
				suf[i]=tot;
			}
			else{
				num[ch[i]-'a'+1]=1;
				tot++;
				suf[i]=tot;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=1;k*j<n;k++){
					if(haha[1][j]==haha[j*(k-1)+1][j*k]){
						if(suf[j*k+1]>=pre[i])ans++;
					}
					else break;
				}
			}
		}
		printf("%lld\n",ans);
	}
}
namespace B{
	vois solve(){
		
	}
}
signed main(){//48pts
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	T=read();
	while(T--){
		memset(ch,0,sizeof ch);
		scanf("%s",ch+1);
		n=strlen(ch+1);
		if(n<=2000)A::solve();
		else B::solve();
	}
	return 0;
}

