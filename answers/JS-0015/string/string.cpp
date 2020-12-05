#include<bits/stdc++.h>
using namespace std;

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch!='-' and (ch>'9' or ch<'0')) ch=getchar();
	if(ch=='-') f=-f,ch=getchar();
	while(ch>='0' and ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
const int nn=1024*1024+10;
int T;char str[nn];
int kmp[nn];int cnt[nn][26];
int status[26],sum[nn];
int aba[nn],mob[nn];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%s",str+1);memset(status,0,sizeof status);
		kmp[1]=0;int n=strlen(str+1);
		for(int i=2;i<=n;i++){
			int j=i-1;
			while(j and str[kmp[j]+1]!=str[i]) j=kmp[j];
			kmp[i]=kmp[j];
			if(str[kmp[j]+1]==str[i]) kmp[i]++;
		}
		for(int i=1;i<=n;i++){
			aba[i]=-1;
			int c=str[i]-'a';
			status[c]^=1;sum[i]=sum[i-1]+(status[c]==1)*2-1;
			for(int j=0;j<26;j++) cnt[i][j]=cnt[i-1][j]+(j>=sum[i]);
		}
		
		memset(status,0,sizeof status);int now=0;
		long long ans=0;
		for(int d=n;d>=3;d--){
			int c=str[d]-'a';status[c]^=1;now=now+(status[c]==1)*2-1;
			int i=d-1;
			if(kmp[i] and i%(i-kmp[i])==0)
				aba[i]=now,mob[i]=i-kmp[i];
			ans+=cnt[i-1][now];
		}
		for(int i=2;i<=n;i++) for(int j=i+i;j<=n;j+=i) if(aba[j]!=-1) if(i%mob[j]==0)
			ans+=cnt[i-1][aba[j]];//,cout<<j<<":"<<ans;
		printf("%lld\n",ans);
	}
	
	
	return 0;
}
/*
1
mmlmmlo
*/

