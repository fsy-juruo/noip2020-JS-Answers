#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
const int MOD=1e9+7;
int n,k;
long long w[10],s[10],z[10],f[10];
int a[500010],b[500010];
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	read(n);read(k);
	long long ans=1;
	for(int i=1;i<=k;i++){
		read(w[i]);
		ans=(ans*w[i])%MOD;
	}
	
	for(int i=1;i<=n;i++){
		read(a[i]);read(b[i]);
	}
	int tot=0;
	long long last=0;
	bool flg=0;
	int fl=0;
	while(1){
		tot=tot%n+1;
		s[a[tot]]+=b[tot];
		if(s[a[tot]]<=z[a[tot]]&&s[a[tot]]>=f[a[tot]]){
			if(fl==0){
				fl=2;
			}else{
				fl=1;
			}
		}else{
			fl=0;
		}
		z[a[tot]]=max(z[a[tot]],s[a[tot]]);
		f[a[tot]]=min(f[a[tot]],s[a[tot]]);
//		if(step%n==0){
//			step++;
//			for(int i=1;i<=k;i++)cout<<s[i]<<" "<<z[i]<<" "<<f[i]<<endl;
//			cout<<step<<endl;
//		} 
		if(fl==1){
			ans=(ans+last)%MOD;
			if(tot==n&&flg==0){
				for(int i=1;i<=k;i++){
					if(s[i])flg=1;
				}	
				if(flg==0){
					cout<<-1<<endl;
					return 0;
				}
			}
			continue;
		}
		long long s1=1;
		for(int i=1;i<=k;i++){
			if(w[i]-z[i]+f[i]<=0){
				cout<<ans<<endl;
				return 0;
			}else{
				s1=s1*(w[i]-z[i]+f[i])%MOD;
			}
		}
		if(fl==2)last=s1;
//		for(int i=1;i<=k;i++)cout<<z[i]<<' '<<f[i]<<" "<<s[i]<<endl;
//		cout<<endl;
		ans=(ans+s1)%MOD;
//		cout<<step<<endl;
		if(tot==n&&flg==0){
			for(int i=1;i<=k;i++){
				if(s[i])flg=1;
			}	
			if(flg==0){
				cout<<-1<<endl;
				return 0;
			}
		}
	}
	return 0;
}

