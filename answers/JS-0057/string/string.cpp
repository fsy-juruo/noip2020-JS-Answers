#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define rg register
#define inf 0x7f7f7f7f
inline int read(){
	rg int ret=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret*f;
}
int t,n,cnt[35],tot,ans;
char s[2<<21];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	t=read();
	while(t--){
		scanf("%s",s); n=strlen(s); ans=0;
		for(rg int i=0;i<n;++i){
			if(cnt[s[i]-'a']==0) ++tot;
			++cnt[s[i]-'a'];
		}
		bool fla=1;
		for(rg int i=1;i<n-1;++i){
			int ln=n-i; ans+=ln-1;
			for(rg int j=2;j*j<=ln;++j){
				if(ln%j==0){
					if(ln/j<2) continue;
					int tp=ln/j;
					for(rg int k=0;k<tp;++k){
						for(rg int g=2;g<=j;++g){
							if(s[(g-1)*tp+k]!=s[k]){
								fla=0; break;
							}
						}
						if(fla==0) break;
					}
					if(fla==1) ans+=tp-1;
				}
			}
		}
		printf("%d\n",ans);
	}
}
