#include<cstdio>
#include<iostream>
#include<cstring>
#define LL long long
using namespace std;
string c,s,s1,s2;
int q1[1007],h1[1007];
bool q[30][1007],h[30][1007];
LL ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T; cin>>T;
	while (T){
		memset(q,false,sizeof(q));
		memset(h,false,sizeof(h));
		memset(q1,0,sizeof(q1));
		memset(h1,0,sizeof(h1));
		ans=0;
		cin>>c;
		int n=c.size();
		for (int i=0;i<n;i++){
			int tmp=c[i]-'a'+1,temp=c[n-i]-'a'+1;
			for (int j=1;j<=26;j++) if (i!=0) q[j][i]=q[j][i-1],h[j][n-i]=h[j][n-i+1];
			if (q[tmp][i]) q[tmp][i]=false;
			else q[tmp][i]=true;
			if (h[temp][n-i]) h[temp][n-i]=false;
			else h[temp][n-i]=true;
		}
		for (int i=0;i<n;i++){
			for (int j=1;j<=26;j++){
				if (q[j][i]) q1[i]++;
				if (h[j][n-i]) h1[n-i]++;
			}
		}
		s=c[0],s1=c[0];
		for (LL i=1;i<=n-1;i++){
			s=s+c[i];s2=s;s1=s1+c[i];
			LL tot=0;
			while (s2==s1){
				tot++;
				bool tof=true;
				for (int j=1;j<=i;j++){
					if (i+j>n-1){
						tof=false;
						break;
					}
					s1=s1+c[i+j];
				}
				if (!tof) break;
				s2=s2+s;
			}
			for (int j=1;j<i;j++){
				for (int k=1;k<=tot;k++){
					if (q1[j]<=h1[k*i+1]) ans++;
				}
			}
		}
		T--;
		cout<<ans<<endl;
	}
	return 0;
}
