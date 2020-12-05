#include<bits/stdc++.h>
using namespace std;
int t,g[2500000],f[2500000],q[2500000],a[2500000],c[2500000];
string s,s2,s3;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	int i,j,n,p,k,l;
	long long ans;
	while(t--){
		memset(g,0,sizeof(g));
		memset(f,0,sizeof(f));
		cin>>s;
		l=0;
		ans=0;
		n=s.size();
		f[s[0]]++;
		a[0]=1;
		for(i=1;i<n;i++){
			a[i]=a[i-1];
			f[s[i]]++;
			if(f[s[i]]%2)a[i]++;
			else a[i]--;
		}
		c[n-1]=1;
		g[s[n-1]]++;
		for(i=n-2;i>=0;i--){
			c[i]=c[i+1];
			g[s[i]]++;
			if(g[s[i]]%2)c[i]++;
			else c[i]--;
		}
		s2=s[0];
		for(i=1;i<n-1;i++){
			s2+=s[i];
			l=0;
			for(j=i;j<n-1;j+=i+1){
				s3="";
				for(k=l;k<=j;k++){
					s3+=s[k];
				}
				if(s2!=s3)break;
				l=j+1;
				for(k=0;k<i;k++){
					if(c[l]>=a[k]){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
