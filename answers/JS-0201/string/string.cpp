#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=110,TMPMAX=1e6+10;
int T;
char str[MAXN];
int len;
int f[MAXN],g[MAXN][MAXN],pre[MAXN]; //f(i):i..len ,g(i,j):split i to j parts pre(i):1..i
int tong[30];
long long ans,val[TMPMAX];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	scanf("%d",&T);
	while(T--){
		scanf("%s",str+1);
		len = strlen(str+1);
		ans=0;
		int only = 0;
		for(int i=1;i<=len;i++){
			int idx = str[i];
			if(only == 0) only = idx;
			else if(only != idx)only = -1;
		} 
		memset(val,0,sizeof val);
		if(only != -1){
			for(int i=1;i<=len;i++){
				for(int j=i;j<=len;j+=i){
					int oth = len-j;
					if(oth % 2 == 1){
						//奇数
						val[j] += i-1; 
					}else{
						//偶数v
						val[j] += (i-1)/2; 
					}
				}
			}
			for(int j=len-1;j>=2;j--){
				ans += val[j];
			}
			printf("%lld\n",ans);
			continue;
		} 
		memset(f,0,sizeof f);
		memset(g,0,sizeof g); 
		memset(tong,0,sizeof tong);
		memset(pre,0,sizeof pre);
		//预处理f 
		for(int i=len;i>=1;i--){
			tong[str[i]-'a']++;
			for(int j=0;j<26;j++){
				if(tong[j] % 2 == 1){
					f[i]++;
				}
			}
		}
		//预处理pre
		memset(tong,0,sizeof tong);
		for(int i=1;i<=len;i++){
			tong[str[i]-'a']++;
			for(int j=0;j<26;j++){
				if(tong[j] % 2 == 1){
					pre[i]++;
				}
			}
		} 
		//预处理g
		for(int i=1;i<=len;i++){
			g[i][1] = 1;
			for(int j=2;j<=i;j++){
				if(i%j)continue;
				int sz = i/j; 
				int flag = 1;
				for(int cnt = 1;cnt<=sz;cnt++){
					if(str[cnt] != str[i-sz+cnt]){
						flag = 0;
						break;
					}
				}
				if(flag){
					g[i][j] = g[i-sz][j-1];
				}
			}
		} 
		for(int end=len;end>=3;end--){
			//C:[end,len]
			for(int start=1;start<end-1;start++){
				//A:[1,start]
				if(pre[start] > f[end])continue;	
				for(int j=1;start+j<=end-1;j++){
					//|B|:j
					int sz = start+j;
					if((end-1)%sz)continue;
					int ds = (end-1)/sz;
					if(g[end-1][ds]){
						ans++;
					}
				}
			} 
		} 
		printf("%lld\n",ans);
	}
	
	return 0;
}
