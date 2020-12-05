#include<bits/stdc++.h>
using namespace std;
#define reg register
typedef long long ll;
inline int read(){
	int x=0,f=1;char c;
	while((c=getchar())<'0'||c>'9') if(c=='-') f=0;
	while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?x:-x;
}
int t;
string s;ll ans=0;
int main()
{
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	t=read();
	while(t--){
		cin>>s;
		reg int n=s.size()-1;ans=0;
		for(reg int i=0;i<n;i++){
			for(reg int j=n;j>i;j--)
				for(reg int k=i+i+1;k<j;k++)
					if(j%(k+1)==0) ans++;
		}
		printf("%d",ans);
	}
	return 0;
}
