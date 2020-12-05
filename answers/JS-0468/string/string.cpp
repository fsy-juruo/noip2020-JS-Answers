#include<bits/stdc++.h>
using namespace std;

int T,Max,l,ti;
long long ans;
char h;
string s;
int a[1100000],b[1100000];
int ha[51000],hsh[51000];
int sm[101000];
unsigned long long sum[1100000],f[1100000];

template <typename T> void read(T &x){
	x=0;char h=getchar();
	for (;!isdigit(h);h=getchar()) ;
	for (; isdigit(h);h=getchar()) x=(x<<3)+(x<<1)+h-48;
}


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	read(T);
	f[0]=1;for (int i=1;i<=1050000;i++) f[i]=f[i-1]*131;
	while(T--){
		s="";h=getchar();
		while('a'<=h && h<='z') {s+=h;h=getchar();}
		l=s.size();
		for (int i='a';i<='z';i++) ha[i]=hsh[i]=0;
		a[0]=b[0]=0;sum[0]=s[0];
		for (int i=1;i<=l;i++) {
			a[i]=b[i]=0;
			sum[i]=sum[i-1]*f[1]+s[i];
		}
		a[0]=b[l-1]=1;ha[s[0]]++;hsh[s[l-1]]++;
		Max=1;ans=0;
		for (int i=1;i<l;i++){
			ha[s[i]]++;
			if (ha[s[i]]%2==1) a[i]=a[i-1]+1;
					   else a[i]=a[i-1]-1;
			hsh[s[l-i-1]]++;
			if (hsh[s[l-i-1]]%2==1) b[l-i-1]=b[l-i]+1;
								   else b[l-i-1]=b[l-i]-1;
//			cout<<hsh[s[l-i-1]]<<' '<<b[i]<<' '<<b[i+1]<<endl;
			Max=max(max(a[i],b[i]),Max);
//			cout<<i<<' '<<a[i]<<' '<<b[i]<<endl;
		}
//		for (int i=0;i<l;i++) cout<<a[i]<<' ';cout<<endl;
//		for (int i=0;i<l;i++) cout<<b[i]<<' ';cout<<endl;
		for (int i=0;i<=Max;i++) sm[i]=0;
//		for (int i=l-1;i>=2;i--){
//			sm[b[i]]++;
//			for (int j=a[i-2];j<=Max;j++) ans+=sm[j];
//		}
		for (int i=0;i<l-2;i++){
			sm[a[i]]++;
			for (int j=b[i+2];j>=0;j--) ans+=sm[j];
		}
//		cout<<ans<<endl;
		for (int i=0;i<=Max;i++) sm[i]=0;
		sm[a[0]]++;
		for (int i=2;i*2<=l;i++){
			ti=i;
			while (ti+i<l){
				if (sum[i-1]!=sum[ti+i-1]-sum[ti-1]*f[i]) break;
				for (int j=b[ti+i];j>=0;j--) ans+=sm[j];
//				if (a[i-1]<=b[ti+i]) ans+=i-1;
				ti+=i;
//				ans--;
			}
			sm[a[i-1]]++;
//			if (i==12) cout<<ans<<' '<<i<<' '<<ti-i<<endl;
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
