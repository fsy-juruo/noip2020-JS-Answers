#include<bits/stdc++.h>
using namespace std;
template<typename T> void fr(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+c-48;
	x*=f;
}
template<typename T> void fw(T x){
	if(x<0) x=-x,putchar('-');
	if(x>9) fw(x/10);
	putchar(x%10+48);
}
template<typename T> void fwk(T x){fw(x);putchar(' ');}
template<typename T> void fwl(T x){fw(x);puts("");}
int t;
char c[1<<21];int l;
unsigned long long ans=0;
inline bool check(int cnt,int len){
	for(int i=1;i<=len;i++){
		char ts=c[i];
		for(int j=1;j<cnt;j++)
			if(c[i+j*len]!=ts)return 0;
	}
	return 1;
}
inline int cont(int l,int r){
	int h[30];
	memset(h,0,sizeof(h));
	for(int i=l;i<=r;i++){
		h[c[i]-'a'+1]++;
	}
	int cnt=0;
	for(int i=1;i<=26;i++) cnt+=(h[i]&1);
	return cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	fr(t);
	while(t--){
		l=0;
		ans=0;
		bool flg=1;
		do{
			c[++l]=getchar();
			if(l>1){
				if(c[l]!=c[l-1]) flg=0;
			}
		}while(c[l]!='\n');
		l--;
		if(l<3)puts("0");
		if(l==3)puts("1");
		if(flg){
			for(int i=1;i<=l-2;i++){
				if(i&1){
					int k=l-i;
					for(int j=2;j<=k;j++){
						if(k%j==0){
							ans+=j-1;
						}
					}
				}else{
					int k=l-i;
					for(int j=3;j<=k;j++){
						if(k%j==0){
							ans+=(j+1)>>1-1;
						}
					}
				}
			}
		}else{
			for(int i=2;i<l;i++){
				for(int j=1;j<=(i>>1);j++){
					if(i%j==0){
						int k=i/j;
						if(check(j,k)){
							int cntc=cont(i+1,l);
							for(int ii=1;ii<k;ii++)
								ans+=(cont(1,ii)<=cntc);
						}
					}
				}
			}
		}
		fwl(ans);
	}
	return 0;
}

