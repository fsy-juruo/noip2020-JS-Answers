#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=a;i<=b;++i)
#define dec(i,a,b) for(register int i=a;i>=b;--i)
#define il inline
typedef long long ll;
using namespace std;

il void filejudge(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
}

namespace io{
	il int read(){
		int x=0;char ch=getchar();bool f=0;
		while(!isdigit(ch)){if(ch=='-') f=1; ch=getchar();}
		while(isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
		return f?-x:x;
	}
}
using io::read;

const int N=(1<<21);
int a[N],c[N],nxt[N],mx[N],n;
ll ans;
bool table[27];char s[N];
#define lowbit(x) (x&-x)
int tr[30];

il void init(){
	scanf("%s",s+1);
	n=strlen(s+1);
	ans=0;
	rep(i,1,n) nxt[i]=a[i]=c[i]=mx[i]=0;
	rep(i,1,27) tr[i]=0;
}
il void clear_table(){
	rep(i,0,25) table[i]=0;	
}
il void kmp(){
	int j=0;
	rep(i,2,n-1){
		while(j && s[i]!=s[j+1]) j=nxt[j];
		if(s[i]==s[j+1]) j++;
		nxt[i]=j;
	}
	dec(i,n-1,1){
		if(nxt[i+1]==nxt[i]+1) mx[i]=mx[i+1];
		else mx[i]=i;
	}
	int res;
	clear_table(); res=0;
	dec(i,n,1){
		if(table[s[i]-'a']==0) table[s[i]-'a']=1,res++;
		else table[s[i]-'a']=0,res--;
		c[i]=res;
	}
	clear_table(); res=0;
	rep(i,1,n){
		if(table[s[i]-'a']==0) table[s[i]-'a']=1,res++;
		else table[s[i]-'a']=0,res--;
		a[i]=res;		
	}
	rep(i,1,n-1){
		if(nxt[i]*2==i){
			int len=mx[i];
			int num=len/nxt[i];
			int c0=c[mx[i]+1];
			int c1=c[mx[i]+1-nxt[i]];			
			ll cnt;
			rep(x,1,nxt[i]-1){
				cnt=0;
				for(register int k=1;k*2<=num;k++){
					int tmp1=(num/k)-1;
					int tmp2=num%k;
					tmp2%=2;
					int cc;
					if(tmp2==0) cc=c0;
					else cc=c1;
					if(k%2) cnt++;
					if(a[x]<=cc) ans+=1ll*cnt*tmp1;
				}
			}
			clear_table(); res=0;
			dec(x,nxt[i]-1,1){
				cnt=0;
				if(table[s[i]-'a']==0) table[s[i]-'a']=1,res++;
				else table[s[i]-'a']=0,res--;
				for(register int k=2;k*2<=num;k++){
					int tmp1=(num/k)-1,tmp2=num%k;
					tmp2%=2;
					int cc;
					if(tmp2==0) cc=c0;
					else cc=c1;
					if((k%2)==0) cnt++;
					if(res<=cc) ans+=tmp1;				
				}				
			}
			cnt=0;
			for(register int k=2;k*2<=num;k++){
				int tmp1=(num/k)-1;
				int tmp2=num%k;
				tmp2%=2;
				int cc;
				if(tmp2==0) cc=c0;
				else cc=c1;
				if((k%2)==0) cnt++;
				if(a[nxt[i]]<=cc) ans+=1ll*cnt*tmp1;
			}
			cnt=0;
			for(register int k=3;k*2<=num;k++){
				int tmp1=(num/k)-1;
				if((k%2)==1) cnt++;
				ans+=1ll*cnt*tmp1;
			}
		}
	}
}

il void add(int u){
	for(register int i=u;i;i-=lowbit(i))
		tr[i]++;
}
il ll query(int u){
	int res=0;
	for(register int i=u;i<=27;i+=lowbit(i))
		res+=tr[i];
	return res;
}

il void find(){
	add(c[n]+1);
	dec(i,n-2,1){
		ans+=(ll)(query(a[i]+1));
		add(c[i+1]+1);
	}
	printf("%lld\n",ans);
}

int main(){
	filejudge();
	int Q=read();
	while(Q--){
		init();
		kmp();
		find();
	}
	return 0;
}
