#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rep2(i,j,k) for(int i=j;i>=k;i--)
using namespace std;
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);putchar('\n');
}
char S[1050000];
unsigned long long base=131;unsigned long long powe[1050000];unsigned long long hhh[1050000];
inline bool chk(int l1,int r1,int l2,int r2){
	unsigned long long n1=hhh[r1]-powe[r1-l1+1]*hhh[l1-1];
	unsigned long long n2=hhh[r2]-powe[r2-l2+1]*hhh[l2-1];
	return (n1==n2);
}
int cnt[30];int pre[1050000];int suf[1050000];

int tree[30];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	powe[0]=1;
	rep(i,1,(1<<20))powe[i]=powe[i-1]*base;
	
	int T;scanf("%d",&T);
	while(T--){
		rep(i,0,26)tree[i]=0;
		scanf("%s",S+1);int n=strlen(S+1);
		
		rep(i,1,n)hhh[i]=hhh[i-1]*base+(unsigned long long)S[i];
		rep(i,1,26)cnt[i]=0;
		rep(i,1,n){
			cnt[S[i]-'a'+1]++;
			pre[i]=pre[i-1]+((cnt[S[i]-'a'+1]&1)?1:-1);
		}
		rep(i,1,26)cnt[i]=0;
		rep2(i,n,1){
			cnt[S[i]-'a'+1]++;
			suf[i]=suf[i+1]+((cnt[S[i]-'a'+1]&1)?1:-1);
		}	

		long long ans=0;
		rep(i,1,n){
			for(int j=i;j<n;j+=i){
				if(!chk(1,i,j-i+1,j))break;
				ans+=tree[suf[j+1]];
			}
			rep(j,pre[i],26)tree[j]++;
		}
		write(ans);
	}
	return 0;
}

