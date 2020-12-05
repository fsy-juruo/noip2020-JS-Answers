#include<stdio.h>
int t,n;
char s[1<<16];
long long alpha[1<<16][140],pre[1<<16][30];
long long dp[1<<16],dt[1<<16][30];
int max(int a,int b){
	return a>b?a:b;
}
int same(int a,int b,int c){
	for(int i=a;i<=b;i++) if(s[i]!=s[i+c]) return 0;
	return 1;
}
void start(){
	for(int i=0;s[i]!='\0';i++) n=i;
	for(int i=0;i<=n;i++) for(int j=0;j<=28;j++) dp[i]=0ll,dt[i][j]=0ll,alpha[i][j+97]=0;
	alpha[0][(int)s[0]]++; 
	for(int i=1;i<=n;i++){
		for(char c='a';c<='z';c++){
			alpha[i][(int)c]=alpha[i-1][(int)c];
			if(s[i]==c) alpha[i][(int)c]++;
		}
	}
	for(int i=0;i<=n-2;i++){
		int jn=0;
		for(char c='a';c<='z';c++) if(alpha[i][int(c)]%2==1) jn++;
		for(int j=i+1;j<=n-1;j++)
		for(int k=1;k<=n/(j+1);k++)
		if(same(0,j,(k-1)*(j+1))) dt[j+(k-1)*(j+1)][jn]++;
	}
	for(int i=1;i<=n;i++) pre[i][0]=dt[i][0];
	for(int i=1;i<=n;i++) for(int j=1;j<=28;j++) pre[i][j]=pre[i][j-1]+dt[i][j];
}
long long get(){
	long long ans=0ll;
	for(int i=n;i>=1;i--){
		int jn=0;
		for(char c='a';c<='z';c++) if((alpha[n][int(c)]-alpha[i-1][(int)c])%2==1) jn++;
		ans+=pre[i-1][jn];
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		for(int i=0;i<=1<<15;i++) s[i]=0;
		scanf("%s",s);start();
		long long ans=get();
		printf("%lld\n",ans);
	}
	return 0;
}
