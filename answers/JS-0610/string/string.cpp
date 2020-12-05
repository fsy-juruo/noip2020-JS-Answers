#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define rint register unsigned long long

int t,n,len,tot[1500000],tor[1500000],f,ans,x,abl;
char s[1500000],ch;
bool cnt[1000];

inline void re(int &x){
	while(isspace(ch=getchar())); x=ch&15;
	while(isdigit(ch=getchar())) x=x*10+(ch&15);
}

signed main(){
	freopen("string.in","r",stdin); freopen("string.out","w",stdout);
	re(t);
	for(rint ti=1;ti<=t;++ti){
		while(isspace(ch=getchar()))
			;
		for(rint i='a';i<='z';++i) cnt[i]=0;
		memset(tot,0,(n+1)<<4); memset(tor,0,(n+2)<<4);
		s[n=1]=ch; cnt[s[1]]=1; tot[1]=1;
		while(islower(s[++n]=getchar())){
			if(cnt[s[n]]) tot[n]=tot[n-1]-1;
			else tot[n]=tot[n-1]+1;
			cnt[s[n]]^=1;
		}
		--n;
		for(rint i='a';i<='z';++i) cnt[i]=0;
		for(rint i=n;i;--i){
			if(cnt[s[i]]) tor[i]=tor[i+1]-1;
			else tor[i]=tor[i+1]+1;
			cnt[s[i]]^=1;
		}
		ans=0;
		for(rint al=1;al<n;++al){
			for(rint cl=1;cl+al<n;++cl){
//					printf("%llu %llu %llu %llu\n",al,tot[al],cl,tor[n+1-cl]);
				if(tot[al]<=tor[n+1-cl]){
					x=n-cl;
					for(rint i=1;i*i<=x;++i)
						if(x%i==0){
							abl=i;
							if(abl>al){
								f=1;
								for(rint j=0;f&&j+abl+cl<=n;j+=abl)
									for(rint k=1;k<=abl;++k)
										if(s[k]!=s[j+k]){
											f=0; break;
										}
								ans+=f;
//								if(f) printf("%llu %llu %llu\n",al,abl-al,cl);
							}
							if(i*i!=x){
								abl=x/i;
								if(abl>al){
									f=1;
									for(rint j=0;f&&j+abl+cl<=n;j+=abl)
										for(rint k=1;k<=abl;++k)
											if(s[k]!=s[j+k]){
												f=0; break;
											}
									ans+=f;
//									if(f) printf("%llu %llu %llu\n",al,abl-al,cl);
								}
							}
						}
				}
			}	
		}
		printf("%llu\n",ans);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
