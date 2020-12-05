#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=(1<<20)+5;
int n,sum[N],rsum[N],c[N];
bool jox[30];
char s[N];
ll ans;
void add(int x,int k){
	while(x<=n){
		c[x]+=k;
		x+=x&(-x);
	}
}
int ask(int x){
	int ss=0;
	while(x){
		ss+=c[x];
		x-=x&(-x);
	}
	return ss;
}
bool chk(int a,int b,int c){
	for(int i=0;i<c;++i){
		if(s[a+i]!=s[b+i]) return 0;
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);
		n=strlen(s+1);
		ans=0;
		if(n<=1000){
			memset(jox,0,sizeof(jox));
			for(int i=1;i<=n;++i){
				jox[s[i]-'a']^=1;
				sum[i]=sum[i-1]+(jox[s[i]-'a']?1:(-1));
			}
			memset(jox,0,sizeof(jox));
			for(int i=n;i>=1;--i){
				jox[s[i]-'a']^=1;
				rsum[i]=rsum[i+1]+(jox[s[i]-'a']?1:(-1));
			}	
			for(int i=2;i<n;++i){
				for(int k=1;k<i;++k){
					if(sum[k]<=rsum[i+1]){
						++ans;
					}
				}
				for(int j=2;j<=i/2;++j){
					if(i%j) continue;
					bool f=0;
					for(int k=1;k<i;k+=j){
						if(!chk(1,k,j)){
							f=1;
							break;
						}
					}
					if(f) continue;
					for(int k=1;k<j;++k){
						if(sum[k]<=rsum[i+1]){
							++ans;
						}
					}
				}
			}
		}else{
			for(int i=2;i<n;++i){
				int ao,aj,co,cj;
				int ss=(n-1)/i;
				if(i%2==0){
					if(n%2==1){
						ans+=1ll*(i-1)*ss;
					}else{
						ao=(i-1)/2;
						ans+=1ll*ao*ss;
					}
				}else{
					ao=(i-1)/2,aj=i-ao-1;
					if(n%2==0){
						co=ss/2,cj=ss-co;
					}else{
						cj=ss/2,co=ss-cj;
					}
					ans+=1ll*aj*cj+1ll*ao*ss;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
