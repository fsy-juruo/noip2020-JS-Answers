#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define gc getchar
using namespace std;

inline int read(){
	int x=0,y=1;char c=gc();while(c<'0'||c>'9'){if(c=='-') y=-1;c=gc();}
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=gc();return (y==1)?x:-x;
}

const int N=1005;
int n,t,sum[N][30],ans;
char s[N];

inline int calc(int l,int r){
	int res=0;
	for(int i=0;i<26;i++){
		int x=sum[r][i]-sum[l-1][i];
		if(x&1) res++;
	}
	return res;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%s",s+1);
		n=strlen(s+1);
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++){
			for(int j=0;j<26;j++){
				sum[i][j]=sum[i-1][j];
			}
			sum[i][s[i]-'a']++;
		}
		ans=0;
		for(int i=1;i<n;i++){
			int num=calc(1,i);
			for(int j=i+1;j<n;j++){
				int cnt=0;
				while(1){
					if(j*(cnt+1)>=n) break;
					bool im=0;
					for(int k=j*cnt+1;k<=j*(cnt+1);k++){
						if(s[k]!=s[k-j*cnt]){
							im=1;break;
						}
					}
					if(im) break;
					if(calc(j*(cnt+1)+1,n)>=num) ans++;
					cnt++;
				}
			}
			
		}
		printf("%d\n",ans);
	}
	
	return 0;
}

















