#include<bits/stdc++.h>
#define MAXN (1<<20)+5
#define ll long long
using namespace std;
int f[MAXN],F1[MAXN],F2[MAXN],T,a[MAXN],n;
int vis[10005];
char C[MAXN];
struct tree
{
	ll c[MAXN];
	inline void init(){memset(c,0,sizeof(c));}
	inline int lowbit(int x){return x&-x;}
	void add(int x)
	{
		int i=x;
		while(i<=n+1){
			c[i]++;
			i+=lowbit(i);
		}
	}
	ll query(int x)
	{
		int i=x;
		ll ans=0;
		while(i){
			ans+=c[i];
			i-=lowbit(i);
		}
		return ans;
	}
}Tree;
void read()
{
	char ch;
	while(ch<'a' || ch>'z') ch=getchar();
	while(ch>='a' && ch<='z') a[++n]=ch,ch=getchar();
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		Tree.init();
		memset(f,0,sizeof(f));
		memset(F1,0,sizeof(F1));
		memset(F2,0,sizeof(F2));
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis)); n=0;
		read(); 
		int now1=0,now2=0;//1 ji 2 ou
		for(int i=1;i<=n;i++){
			vis[a[i]]++;
			if(vis[a[i]]==1) now1++;
			else{
				if(vis[a[i]]%2) now2--,now1++;
				else now2++,now1--;
			}
			F1[i]=now1;
		}
		memset(vis,0,sizeof(vis)); now1=now2=0;
		for(int i=n;i>=1;i--){
			vis[a[i]]++;
			if(vis[a[i]]==1) now1++;
			else{
				if(vis[a[i]]%2) now2--,now1++;
				else now2++,now1--;
			}
			F2[i]=now1;
		}
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			int str=1;
			if(vis[i]) continue;
			while(1){
				int flag=1;
				if(str*i+i>n) break;
				for(int j=1+str*i;j<=i+str*i;j++)
				if(a[j]!=a[j-str*i]){
					flag=0; break;
				}
				if(flag) str++;
				else break;
			}
			for(int j=1;j<=str;j++){
				vis[j*i]=1;
				f[j*i]=str/j-1;
			}
		}
		Tree.add(F1[1]+1);
		ll Ans=0;
		for(int i=2;i<=n-1;i++){
			for(int j=i;j<=i+f[i]*i;j+=i) 
			if(j<n) Ans+=Tree.query(F2[j+1]+1);
			Tree.add(F1[i]+1);
		}
		printf("%lld\n",Ans);
	}
	return 0;
}
