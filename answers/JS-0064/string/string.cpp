#include<bits/stdc++.h>
#define fz1(i,n) for((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for((i)=(n);(i)>=1;(i)--)
#define fz0k(i,n) for((i)=0;(i)<(n);(i)++)
#define fz0g(i,n) for((i)=0;(i)<=(n);(i)++)
using namespace std;
long long ans;
int n,m,i,j,t,pre[1100005],suf[1100005];
char s[1100005];int cnt[26],sc;
int nxt[1100005];
int sp[28];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%s",s+1);
		n=strlen(s+1);
		pre[0]=suf[n+1]=0;
		memset(cnt,0,sizeof(cnt));sc=0;
		fz1(i,n){
			cnt[s[i]-'a']^=1;
			if(cnt[s[i]-'a']) sc++;else sc--;
			pre[i]=sc;
		}
		memset(cnt,0,sizeof(cnt));sc=0;
		fd1(i,n){
			cnt[s[i]-'a']^=1;
			if(cnt[s[i]-'a']) sc++;else sc--;
			suf[i]=sc;
		}
		nxt[1]=0;
		j=0;
		for(i=2;i<=n;i++){
			while(j&&s[i]!=s[j+1]) j=nxt[j];
			if(s[i]==s[j+1])j++;
			nxt[i]=j;
		}
		fz0g(i,26)sp[i]=0;ans=0;
		for(i=2;i<n;i++){
			for(j=pre[i-1];j<=26;j++){
				sp[j]++;
			}
			for(j=i;j<n;j+=i){
				if(j>i&&i%(j-nxt[j])!=0) break;
				ans+=sp[suf[j+1]];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
