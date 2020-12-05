#include<bits/stdc++.h>
using namespace std;
int h[110];
int a[1000010];
int c1[2000010],c2[2000010];
string st;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(h,0,sizeof(h));
		memset(a,0,sizeof(a));
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		cin>>st;
		int n=st.size();
		for(int i=1;i<=n;i++){
			if(h[st[i-1]-'a'+1]%2==0)c1[i]=c1[i-1]+1;
			else c1[i]=c1[i-1]-1;
			h[st[i-1]-'a'+1]++;
		}
		memset(h,0,sizeof(h));
		for(int i=n;i>=1;i--){
			if(h[st[i-1]-'a'+1]%2==0)c2[i]=c2[i+1]+1;
			else c2[i]=c2[i+1]-1;
			h[st[i-1]-'a'+1]++;
		}
		for(int d=2;d<n;d++){
			string s0=st.substr(0,d);
			for(int i=1;i<=n/d;i++){
				string s1=st.substr(i*d,d);
				if(s0!=s1){
					a[d]=i;
					break;
				}
			}
			if(d*a[d]==n)a[d]--;
		}
	//	for(int i=1;i<=n;i++){
	//		cout<<c1[i]<<" ";
	//	}
		int ans=0;
		for(int d=2;d<n;d++){
			int x1=c2[a[d]*d+1],t1=0;
			int x2=c2[a[d]*d-d+1],t2=0;
			for(int i=1;i<d;i++){
				if(c1[i]<=x1)t1++;
				if(c1[i]<=x2)t2++;
			}
			ans+=t2*(a[d]/2)+t1*(a[d]-a[d]/2);
		}
		cout<<ans<<endl;
	}
	return 0;
}
