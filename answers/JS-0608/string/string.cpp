#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,si,a,b,c,ans,m;
int w[135],p[135];string s,z,ab;
inline bool ch(string aa,string ss){
	if(ss.size()%aa.size())return 0;
	int k=ss.size()/aa.size();string u="";
	while(k--)u+=aa;return u==ss;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>t;while(t--){
		memset(w,0,sizeof(w));
		cin>>s;ans=0;z="";si=s.size();
		if(si<=1000){
			for(int l=0;l<si-1;++l){
				memset(w,0,sizeof(w));
				z+=s[l];for(int i=l+1;i<si;++i)++w[s[i]];
				m=0;for(int i='a';i<='z';++i)if(w[i]&1)++m;
				for(int i=1;i<=z.size();++i)
				if(ch(z.substr(0,i),z)){
					memset(p,0,sizeof(p));int op=0;
					for(int j=0;j<i-1;++j){
						if(p[z[j]]&1)--op;
						else ++op;++p[z[j]];
						if(op<=m)++ans;
					}
				}
			}
		}
		else for(b=2;b<si;++b){
			a=(si-1)/b;for(int i=1;i<=a;++i)
			{c=i*b;ans+=((si-c)&1?b-1:(b-1)>>1);}
		}
		cout<<ans<<endl;
	}
}
