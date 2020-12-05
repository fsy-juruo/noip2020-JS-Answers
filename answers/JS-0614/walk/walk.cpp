#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int maxn=5e5+5,maxk=10+5;
int w[maxk];
int n,k,ans;
struct node{
	int c,d;
}z[maxn];
int walk1(int u,int v,int t){
	int i;
	int a=u,b=v,c=t;
	int cnt=0;
	for(i=1;i<=n;i++){
		cnt++;
		if(z[i].c==1)
			u+=z[i].d;
		if(z[i].c==2)
			v+=z[i].d;
		if(z[i].c==3)
			t+=z[i].d;
		if(u>w[1]||v>w[2]||t>w[3]||u<1||v<1||t<1)
			return cnt;
	}
	if(a==u&&b==v&&c==t)
		return -1;
	while(u<=w[1]&&u>=1&&v<=w[2]&&v>=1&&t<=w[3]&&t>=1){
		i=(cnt%n)+1;
		cnt++;
		if(z[i].c==1)
			u+=z[i].d;
		if(z[i].c==2)
			v+=z[i].d;
		if(z[i].c==3)
			t+=z[i].d;
	}
	return cnt;
}
void solve1(){
	int i,j,k,x;
	for(i=1;i<=w[1];i++)
		for(j=1;j<=w[2];j++)
			for(k=1;k<=w[3];k++){
				x=walk1(i,j,k);
				if(x<0){
					printf("-1\n");
					return;
				}
				ans=(ans+x)%mod;
			}
	printf("%d\n",ans);
}
int walk2(int a,int b,int c,int d){
	int i;
	int cnt=0;
	int a1=a,b1=b,c1=c,d1=d;
	for(i=1;i<=n;i++){
		cnt++;
		if(z[i].c==1)
			a+=z[i].d;
		if(z[i].c==2)
			b+=z[i].d;
		if(z[i].c==3)
			c+=z[i].d;
		if(z[i].c==4)
			d+=z[i].d;
		if(a>w[1]||b>w[2]||c>w[3]||d>w[4]||a<1||b<1||c<1||d<1)
			return cnt;
	}
	if(a1==a&&b1==b&&c1==c&&d1==d)
		return -1;
	while(a<=w[1]&&a>=1&&b<=w[2]&&b>=1&&c<=w[3]&&c>=1&&d<=w[4]&&d>=1){
		i=(cnt%n)+1;
		cnt++;
		if(z[i].c==1)
			a+=z[i].d;
		if(z[i].c==2)
			b+=z[i].d;
		if(z[i].c==3)
			c+=z[i].d;
		if(z[i].c==4)
			d+=z[i].d;
	}
	return cnt;
}
void solve2(){
	int a,b,c,d=1,x;
	for(a=1;a<=w[1];a++)
		for(b=1;b<=w[2];b++)
			for(c=1;c<=w[3];c++)
				for(d=1;d<=w[4];d++){
					x=walk2(a,b,c,d);
					if(x<0){
						printf("-1\n");
						return;
					}
					ans=(ans+x)%mod;
				}
	printf("%d\n",ans);
}
int walk3(int a,int b,int c,int d,int e){
	int i;
	int cnt=0;
	int a1=a,b1=b,c1=c,d1=d,e1=e;
	for(i=1;i<=n;i++){
		cnt++;
		if(z[i].c==1)
			a+=z[i].d;
		if(z[i].c==2)
			b+=z[i].d;
		if(z[i].c==3)
			c+=z[i].d;
		if(z[i].c==4)
			d+=z[i].d;
		if(z[i].c==5)
			e+=z[i].d;
		if(a>w[1]||b>w[2]||c>w[3]||d>w[4]||e>w[5]||a<1||b<1||c<1||d<1||e<1)
			return cnt;
	}
	if(a1==a&&b1==b&&c1==c&&d1==d&&e1==e)
		return -1;
	while(a<=w[1]&&a>=1&&b<=w[2]&&b>=1&&c<=w[3]&&c>=1&&d<=w[4]&&d>=1&&e<=w[5]&&e>=1){
		i=(cnt%n)+1;
		cnt++;
		if(z[i].c==1)
			a+=z[i].d;
		if(z[i].c==2)
			b+=z[i].d;
		if(z[i].c==3)
			c+=z[i].d;
		if(z[i].c==4)
			d+=z[i].d;
		if(z[i].c==5)
			e+=z[i].d;
	}
	return cnt;
}
void solve3(){
	int a,b,c,d,e,x;
	for(a=1;a<=w[1];a++)
		for(b=1;b<=w[2];b++)
			for(c=1;c<=w[3];c++)
				for(d=1;d<=w[4];d++)
					for(e=1;e<=w[5];e++){
						x=walk3(a,b,c,d,e);
						if(x<0){
							printf("-1\n");
							return;
						}
						ans=(ans+x)%mod;
					}
	printf("%d\n",ans);
}
int walk4(int a,int x,int l,int r){
	int i;
	long long cnt=0;
	long long p;
	if(a-l<1||a+r>w[1]){
		for(i=1;i<=n;i++){
			cnt++;
			a+=z[i].d;
			if(a<1||a>w[1])
				return cnt;
		}
	}
	if(x>0){
		p=(w[1]-a)/x;
		a=a+p*x;
		cnt=p*n%mod;
		for(i=1;i<=n;i++){
			cnt++;
			a+=z[i].d;
			if(a<1||a>w[1])
				return cnt%mod;
		}
	}
	if(x<0){
		x*=-1;
		p=(a-1)/x;
		cnt=p*n%mod;
		for(i=1;i<=n;i++){
			cnt++;
			a+=z[i].d;
			if(a<1||a>w[1])
				return cnt%mod;
		}
	}
}
void solve4(){
	int l,r,x,t,i;
	l=r=x=0;
	for(i=1;i<=n;i++){
		x+=z[i].d;
		l=min(l,x);
		r=max(r,x);
	}
	if(x==0&&1+r<=w[1]&&w[1]-l>0){
		printf("-1");
		return;
	}
	for(i=1;i<=w[1];i++){
		t=walk4(i,l,r,x);
		ans=(ans+t)%mod;
	}
}
int walk5(int a,int b){
	int cnt=0,i;
	int a1=a,b1=b;
	for(i=1;i<=n;i++){
		cnt++;
		if(z[i].c==1)
			a+=z[i].d;
		if(z[i].c==2)
			b+=z[i].d;
		if(a>w[1]||a<1||b>w[2]||b<1)
			return cnt;
	}
	if(a1==a&&b1==b)
		return -1;
	while(a<=w[1]&&a>=1&&b<=w[2]&&b>=1){
		i=(cnt%n)+1;
		cnt++;
		if(z[i].c==1)
			a+=z[i].d;
		if(z[i].c==2)
			b+=z[i].d;
	}
	return cnt;
}
void solve5(){
	int a,b,x;
	for(a=1;a<=w[1];a++)
		for(b=1;b<=w[2];b++){
			x=walk5(a,b);
			if(x<0){
				printf("-1\n");
				return;
			}
			ans=(ans+x)%mod;
		}
	printf("%d\n",ans);
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	int i;
	for(i=1;i<=k;i++)
		scanf("%d",&w[i]);
	for(i=1;i<=n;i++)
		scanf("%d%d",&z[i].c,&z[i].d);
	if(k==3){
		solve1();
		return 0;
	}
	if(k==4){
		solve2();
		return 0;
	}
	if(k==5){
		solve3();
		return 0;
	}
	if(k==1){
		solve4();
		return 0;
	}
	if(k==2){
		solve5();
		return 0;
	}
	printf("-1");
	return 0;
}
