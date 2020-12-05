#include<bits/stdc++.h>
#define N 500010
#define MOD 1000000007
using namespace std;
inline int read(){
	int f=1,x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int n,k,w[N],u[N],v[N];
int ans;
void dfs5(int a1,int b1,int c1,int d1,int e1){
	int a=a1,b=b1,c=c1,d=d1,e=e1;
	while(1){
		for(int i=1;i<=n;++i){
			if(u[i]==1) a+=v[i];
			if(u[i]==2) b+=v[i];
			if(u[i]==3) c+=v[i];
			if(u[i]==4) d+=v[i];
			if(u[i]==5) e+=v[i];
			ans=(ans+1)%MOD;
			if(a>w[1]||a<1) return;
			if(b>w[2]||b<1) return;
			if(c>w[3]||c<1) return;
			if(d>w[4]||d<1) return;
			if(e>w[5]||e<1) return;
		}
		if(a==a1&&b==b1&&c==c1&&d==d1&&e==e1){
			printf("-1\n");
			exit(0);
		}
	}
}
void dfs4(int a1,int b1,int c1,int d1){
	int a=a1,b=b1,c=c1,d=d1;
	while(1){
		for(int i=1;i<=n;++i){
			if(u[i]==1) a+=v[i];
			if(u[i]==2) b+=v[i];
			if(u[i]==3) c+=v[i];
			if(u[i]==4) d+=v[i];
			ans=(ans+1)%MOD;
			if(a>w[1]||a<1) return;
			if(b>w[2]||b<1) return;
			if(c>w[3]||c<1) return;
			if(d>w[4]||d<1) return;
		}
		if(a==a1&&b==b1&&c==c1&&d==d1){
			printf("-1\n");
			exit(0);
		}
	}
}
void dfs3(int a1,int b1,int c1){
	int a=a1,b=b1,c=c1;
	while(1){
		for(int i=1;i<=n;++i){
			if(u[i]==1) a+=v[i];
			if(u[i]==2) b+=v[i];
			if(u[i]==3) c+=v[i];
			ans=(ans+1)%MOD;
			if(a>w[1]||a<1) return;
			if(b>w[2]||b<1) return;
			if(c>w[3]||c<1) return;
		}
		if(a==a1&&b==b1&&c==c1){
			printf("-1\n");
			exit(0);
		}
	}
}
void dfs2(int a1,int b1){
	int a=a1,b=b1;
	while(1){
		for(int i=1;i<=n;++i){
			if(u[i]==1) a+=v[i];
			if(u[i]==2) b+=v[i];
			ans=(ans+1)%MOD;
			if(a>w[1]||a<1) return;
			if(b>w[2]||b<1) return;
		}
		if(a==a1&&b==b1){
			printf("-1\n");
			exit(0);
		}
	}
}
void dfs1(int a1){
	int a=a1;
	while(1){
		for(int i=1;i<=n;++i){
			if(u[i]==1) a+=v[i];
			ans=(ans+1)%MOD;
			if(a>w[1]||a<1) return;
		}
		if(a==a1){
			printf("-1\n");
			exit(0);
		}
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=k;++i)
		w[i]=read();
	for(int i=1;i<=n;++i)
		u[i]=read(),v[i]=read();
	if(k==5){
		for(int a=1;a<=w[1];++a){
			for(int b=1;b<=w[2];++b){
				for(int c=1;c<=w[3];++c){
					for(int d=1;d<=w[4];++d){
						for(int e=1;e<=w[5];++e){
							dfs5(a,b,c,d,e);
						}
					}
				}
			}
		}
	}
	if(k==4){
		for(int a=1;a<=w[1];++a){
			for(int b=1;b<=w[2];++b){
				for(int c=1;c<=w[3];++c){
					for(int d=1;d<=w[4];++d){
						dfs4(a,b,c,d);
					}
				}
			}
		}
	}
	if(k==3){
		for(int a=1;a<=w[1];++a){
			for(int b=1;b<=w[2];++b){
				for(int c=1;c<=w[3];++c){
					dfs3(a,b,c);
				}
			}
		}
	}
	if(k==2){
		for(int a=1;a<=w[1];++a){
			for(int b=1;b<=w[2];++b){
				dfs2(a,b);
			}
		}
	}
	if(k==1){
		for(int a=1;a<=w[1];++a){
			dfs1(a);
		}
	}
	printf("%d\n",ans%MOD);
	return 0;
}


