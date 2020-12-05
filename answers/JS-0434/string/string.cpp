//WSQ
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
int T;
char s[1048580];
int pre[1048580],suff[1048580];
ll ans;
void init(){
	memset(pre,0,sizeof(pre));
	memset(suff,0,sizeof(suff));
	ans=0;
}
ll sum[30];
bool check(int x,int y,int z){
	for(int i=1;i<=x+y;i++)
		for(int j=1;j<z;j++)if(s[i]!=s[(x+y)*j+i])return false;
	return true;
}
bool type1=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%s",s+1);
		memset(sum,0,sizeof(sum));
		int n=strlen(s+1);
		for(int i=1;i<n;i++)if(s[i]!=s[i+1])type1=0;
		for(int i=1;i<=n;i++){
			sum[s[i]-96]++;
			if(sum[s[i]-96]&1)pre[i]=pre[i-1]+1;
			else pre[i]=pre[i-1]-1;
		}
		memset(sum,0,sizeof(sum));
		for(int i=n;i>=1;i--){
			sum[s[i]-96]++;
			if(sum[s[i]-96]&1)suff[i]=suff[i+1]+1;
			else suff[i]=suff[i+1]-1;
		}
		if(type1){
			for(int i=3;i<=n;i++){
				int j=i-1;
				int len=n-i+1;
				if(len%2==0)ans=ans+(ll)(j-1>>1);
				else ans=ans+(ll)(j-1);
				for(int k=2;k*k<=j;k++)if(j%k==0){
					int kk=j/k;
					if(len%2==0)ans=ans+(ll)(kk-1>>1);
					else ans=ans+(ll)(kk-1);
					if(kk!=k){
						if(len%2==0)ans=ans+(ll)(k-1>>1);
						else ans=ans+(ll)(k-1);
					}
				}
			}
			printf("%lld\n",ans);
			continue;
		}
		for(int i=1;i<n;i++)
			for(int j=1;i+j<n;j++){
				int k=1;
				while((i+j)*k<n){
					if(!check(i,j,k))break;
					if(pre[i]<=suff[(i+j)*k+1])ans++;
					k++;
				}
			}
		printf("%lld\n",ans);
	}
	return 0;
}
