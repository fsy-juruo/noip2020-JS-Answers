#include <bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int n,k,ans=0;
vector<int> w,s;
int a[12];
int c[500010],b[500010];
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		cin>>c[i]>>b[i];
	}
	if(k==1){
		for(int i=1;i<=a[1];++i){
			w.clear();
			w.push_back(0);
			w.push_back(i);
			s=w;
			bool signn=0;
			while(signn==0){
				for(int j=1;j<=n;++j){
					
					if(w[c[j]]+b[j]>a[c[j]]){
						ans=(ans+a[c[j]]-w[c[j]]+1)%MOD;
						signn=1;
						goto v;
					}
					else if(w[c[j]]+b[j]<=0){
						ans=(ans+w[c[j]])%MOD;
						signn=1;
						goto v;
					}
					else {
						w[c[j]]+=b[j];
						ans=(ans+abs(b[j]))%MOD;
					}
				}
				for(int l=1;l<=k;++l){
					if(w[l]!=s[l])
						goto v;
				}
				cout<<-1<<endl;
				return 0;
				v:;
			}
		}
	}
	if(k==2){
		for(int i2=1;i2<=a[1];++i2)
		for(int i=1;i<=a[2];++i){
			w.clear();
			w.push_back(0);
			w.push_back(i2);
			w.push_back(i);
			s=w;
			bool signn=0;
			while(signn==0){
				for(int j=1;j<=n;++j){
					
					if(w[c[j]]+b[j]>a[c[j]]){
						ans=(ans+a[c[j]]-w[c[j]]+1)%MOD;
						signn=1;
						goto v2;
					}
					else if(w[c[j]]+b[j]<=0){
						ans=(ans+w[c[j]])%MOD;
						signn=1;
						goto v2;
					}
					else {
						w[c[j]]+=b[j];
						ans=(ans+abs(b[j]))%MOD;
					}
				}
				for(int l=1;l<=k;++l){
					if(w[l]!=s[l])
						goto v2;
				}
				cout<<-1<<endl;
				return 0;
				v2:;
			}
		}
	}
	if(k==3){
		for(int i3=1;i3<=a[1];++i3)
		for(int i2=1;i2<=a[2];++i2)
		for(int i=1;i<=a[3];++i){
			w.clear();
			w.push_back(0);
			w.push_back(i3);
			w.push_back(i2);
			w.push_back(i);
			s=w;
			bool signn=0;
			while(signn==0){
				for(int j=1;j<=n;++j){
					
					if(w[c[j]]+b[j]>a[c[j]]){
						ans=(ans+a[c[j]]-w[c[j]]+1)%MOD;
						signn=1;
						goto v3;
					}
					else if(w[c[j]]+b[j]<=0){
						ans=(ans+w[c[j]])%MOD;
						signn=1;
						goto v3;
					}
					else {
						w[c[j]]+=b[j];
						ans=(ans+abs(b[j]))%MOD;
					}
				}
				for(int l=1;l<=k;++l){
					if(w[l]!=s[l])
						goto v3;
				}
				cout<<-1<<endl;
				return 0;
				v3:;
			}
		}
	}
	if(k==4){
		for(int i4=1;i4<=a[1];++i4)
		for(int i3=1;i3<=a[2];++i3)
		for(int i2=1;i2<=a[3];++i2)
		for(int i=1;i<=a[4];++i){
			w.clear();
			w.push_back(0);
			w.push_back(i4);
			w.push_back(i3);
			w.push_back(i2);
			w.push_back(i);
			s=w;
			bool signn=0;
			while(signn==0){
				for(int j=1;j<=n;++j){
					
					if(w[c[j]]+b[j]>a[c[j]]){
						ans=(ans+a[c[j]]-w[c[j]]+1)%MOD;
						signn=1;
						goto v4;
					}
					else if(w[c[j]]+b[j]<=0){
						ans=(ans+w[c[j]])%MOD;
						signn=1;
						goto v4;
					}
					else {
						w[c[j]]+=b[j];
						ans=(ans+abs(b[j]))%MOD;
					}
				}
				for(int l=1;l<=k;++l){
					if(w[l]!=s[l])
						goto v4;
				}
				cout<<-1<<endl;
				return 0;
				v4:;
			}
		}
	}
	if(k==5){
		for(int i5=1;i5<=a[1];++i5)
		for(int i4=1;i4<=a[2];++i4)
		for(int i3=1;i3<=a[3];++i3)
		for(int i2=1;i2<=a[4];++i2)
		for(int i=1;i<=a[5];++i){
			w.clear();
			w.push_back(0);
			w.push_back(i5);
			w.push_back(i4);
			w.push_back(i3);
			w.push_back(i2);
			w.push_back(i);
			s=w;
			bool signn=0;
			while(signn==0){
				for(int j=1;j<=n;++j){
					
					if(w[c[j]]+b[j]>a[c[j]]){
						ans=(ans+a[c[j]]-w[c[j]]+1)%MOD;
						signn=1;
						goto v5;
					}
					else if(w[c[j]]+b[j]<=0){
						ans=(ans+w[c[j]])%MOD;
						signn=1;
						goto v5;
					}
					else {
						w[c[j]]+=b[j];
						ans=(ans+abs(b[j]))%MOD;
					}
				}
				for(int l=1;l<=k;++l){
					if(w[l]!=s[l])
						goto v5;
				}
				cout<<-1<<endl;
				return 0;
				v5:;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
