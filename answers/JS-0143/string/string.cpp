#include<bits/stdc++.h>
using namespace std;
const int N=(1<<20)+10;
int t,len,fa[N],fc[N],zm[26];
char s[N];
long long ans;
void work(int a,int r){
	int l1=1,l2=r+1;
	if(fa[a]<=fc[l2])ans++;
	bool flag=1;
	while(l2+r-1<len){
		for(int i=0;i<r;i++){
			if(s[l1+i]!=s[l2+i]){
				flag=0;
				break;
			}
		}
		if(!flag)break;
		l1=l2;
		l2+=r;
		if(fa[a]<=fc[l2])ans++;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%s",s+1);
		len=strlen(s+1);
		memset(zm,0,sizeof(zm));
		memset(fa,0,sizeof(fa));
		memset(fc,0,sizeof(fc));
		for(int i=1;i<=len;i++){
			zm[s[i]-'a']++;
			for(int j=0;j<26;j++){
				if(zm[j]&1)fa[i]++;
			}
		}
		memset(zm,0,sizeof(zm));
		for(int i=len;i>=1;i--){
			zm[s[i]-'a']++;
			for(int j=0;j<26;j++){
				if(zm[j]&1)fc[i]++;
			}
		}
		int c;
		for(int i=1;i<len-1;i++){
			for(int j=i+1;j<len;j++){
				work(i,j);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
