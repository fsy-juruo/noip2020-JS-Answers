#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int N=500009;
int n,k,ans;
int w[N];
int c[N],d[N];
struct loc {
	int a[N];
}p;
bool f=1;
inline int check() {
	int pos=1,s=0;
	loc tp=p;
	while (tp.a[c[pos]]+d[pos]<=w[c[pos]] && tp.a[c[pos]]+d[pos]>=1) {
		tp.a[c[pos]]+=d[pos];
		s++;
		pos=(pos+1)%n;
		if (pos==0) {
			pos=n;
			tp.a[c[pos]]+=d[pos];
			bool fl=0;
			for (int i=1;i<=k;i++) {
				if (p.a[i]!=tp.a[i]) {
					fl=1;
					break;
				}
			}
			tp.a[c[pos]]-=d[pos];
			if (!fl) {
				f=0;
				return -1;
			}
		}
	}
	return s+1;
}
int main() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=k;i++)
		cin>>w[i];
	for (int i=1;i<=n;i++)
		cin>>c[i]>>d[i];
	if (k>5) {
		cout<<-1<<endl;
		return 0;
	}
		if (k==1) {
			for (p.a[1]=1;p.a[1]<=w[1];p.a[1]++) {
				int tmp=check();
				if (tmp==-1) {
					f=0;
					break;
				}
				(ans+=tmp)%=mod;
			}
		}
		else if (k==2) {
			for (p.a[1]=1;p.a[1]<=w[1];p.a[1]++) {
				for (p.a[2]=1;p.a[2]<=w[2];p.a[2]++) {
					int tmp=check();
					if (tmp==-1) {
						f=0;
						break;
					}
					(ans+=tmp)%=mod;
				}
			}
		}
		else if (k==3) {
			for (p.a[1]=1;p.a[1]<=w[1];p.a[1]++) {
				for (p.a[2]=1;p.a[2]<=w[2];p.a[2]++) {
					for (p.a[3]=1;p.a[3]<=w[3];p.a[3]++) {
						int tmp=check();
						if (tmp==-1) {
							f=0;
							break;
						}
						(ans+=tmp)%=mod;
					}
				}
			}
		}
		else if (k==4) {
			for (p.a[1]=1;p.a[1]<=w[1];p.a[1]++) {
				for (p.a[2]=1;p.a[2]<=w[2];p.a[2]++) {
					for (p.a[3]=1;p.a[3]<=w[3];p.a[3]++) {
						for (p.a[4]=1;p.a[4]<=w[4];p.a[4]++) {
							int tmp=check();
							if (tmp==-1) {
								f=0;
								break;
							}
							(ans+=tmp)%=mod;
						}
					}
				}
			}
		}
		else if (k==5) {
			for (p.a[1]=1;p.a[1]<=w[1];p.a[1]++) {
				for (p.a[2]=1;p.a[2]<=w[2];p.a[2]++) {
					for (p.a[3]=1;p.a[3]<=w[3];p.a[3]++) {
						for (p.a[4]=1;p.a[4]<=w[4];p.a[4]++) {
							for (p.a[5]=1;p.a[5]<=w[5];p.a[5]++) {
								int tmp=check();
								if (tmp==-1) {
									f=0;
									break;
								}
								(ans+=tmp)%=mod;
							}
						}
					}
				}
			}
		}
		if (!f)
			cout<<-1<<endl;
		else
			cout<<ans<<endl;
	return 0;
}
