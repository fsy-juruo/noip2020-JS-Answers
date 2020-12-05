#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>inline void read(T& FF){
	FF=0;T RR=1;char CH=getchar();
	for(;!isdigit(CH);CH=getchar())if(CH=='-')RR=-1;
	for(;isdigit(CH);CH=getchar())FF=(FF<<1)+(FF<<3)+(CH^48);
	FF*=RR;
}
const ll MOD1=1000000007,MOD2=998244353,MOD3=20071211;
string st;
ll h[150],f[1500010],t[1500010],k[1500010][31],a1[1500010],a2[1500010],a3[1500010],b1[1500010],b2[1500010],b3[1500010];
//vector<pair<string,int> >mp[MOD];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;read(T);
	while(T--){
//		for(int i=0;i<MOD;i++)mp[i].clear();
		cin>>st;
		int n=st.size(),ans=0;st=' '+st;
		memset(h,0,sizeof(h));
		a1[1]=a2[1]=a3[1]=st[1]-97;b1[1]=b2[1]=b3[1]=1;
		for(int i=2;i<=n;i++){
			b1[i]=b1[i-1]*26%MOD1;
			b2[i]=b2[i-1]*26%MOD2;
			b3[i]=b3[i-1]*26%MOD3;
			a1[i]=(a1[i-1]+(st[i]-97)*b1[i]%MOD1)%MOD1;
			a2[i]=(a2[i-1]+(st[i]-97)*b2[i]%MOD2)%MOD2;
			a3[i]=(a3[i-1]+(st[i]-97)*b3[i]%MOD3)%MOD3;
//			cout<<(st[i]-97)*b[i]<<endl;
		}
//		for(int i=1;i<=n;i++)cout<<a[i]<<" "<<b[i]<<endl;
		for(int i=1;i<=n;i++){
			if((++h[st[i]])%2)f[i]=f[i-1]+1;
			else f[i]=f[i-1]-1;
			for(int j=0;j<=26;j++)k[i][j]=k[i-1][j];
			k[i][f[i]]++;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=26;j++)
				k[i][j]+=k[i][j-1];
		memset(h,0,sizeof(h));
		for(int i=n;i;i--){
			if((++h[st[i]])%2)t[i]=t[i+1]+1;
			else t[i]=t[i+1]-1;
		}//return 0;
//		string a="";a=a+st[1];
//		ll x=(st[1]-97),y=26;
		for(int i=2;i<n;i++){
//			a=a+st[i];
//			x=(x+y*(st[i]-97)%MOD)%MOD;y=y*26%MOD;
//			cout<<x<<endl;
//			for(int j=0;j<mp[x].size();j++)//{
//				if(mp[x][j].first==a)ans+=k[mp[x][j].second-1][t[i+1]];
//			}
			ans+=k[i-1][t[i+1]];
//			cout<<i<<" "<<k[i-1][t[i+1]]<<" "<<t[i+1]<<endl;
//			string b=a[i];//ll k=x,z=y;
			ll x1=a1[i],x2=a2[i],x3=a3[i],y1=1,y2=1,y3=1;
			for(int j=i*2;j<n;j+=i){
				y1=y1*b1[i+1]%MOD1;
				y2=y2*b2[i+1]%MOD2;
				y3=y3*b3[i+1]%MOD3;
				x1=(x1+a1[i]*y1%MOD1)%MOD1;
				x2=(x2+a2[i]*y2%MOD2)%MOD2;
				x3=(x3+a3[i]*y3%MOD3)%MOD3;
//				y=y*b[i+1]%MOD;
//				cout<<i<<" "<<j<<" "<<x1<<" "<<a1[j]<<" "<<x2<<" "<<a2[j]<<" "<<x3<<" "<<a3[j]<<endl;
				if(x1==a1[j]&&x2==a2[j]&&x3==a3[j])ans+=k[i-1][t[j+1]];
//				b=b+a[i];//k=(k+x*z%MOD)%MOD;z=z*y%MOD;
//				cout<<" "<<k<<endl; 
//				mp[k].push_back(make_pair(b,i));
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

