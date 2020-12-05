#include<bits/stdc++.h>
using namespace std;
int T,ansa,ansc,ans;
long long d[1000];
string s;
int c[30],a[30];
inline int read()
{
	int x=0,y=1;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')y=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*y;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	T=read();
	while(T--){
		cin>>s;
		bool f=true;
		for(int i=0;i<s.size()-1;i++){
			if(s[i]!=s[i+1])f=false;
		}
		if(s.size()<=100&&!f){
			for(int i=0;i<=s.size()-3;i++){
				c[s[s.size()-i-1]-'a']++;
				if(c[s[s.size()-i-1]-'a']%2!=0)ansc++;
				else ansc--;
				for(int j=0;j<=s.size()-i-3;j++){
					a[s[j]-'a']++;
					if(a[s[j]-'a']%2!=0)ansa++;
					else if(a[s[j]-'a']%2==0)ansa--;
					if(ansa<=ansc)ans++;
				}
			}
			printf("%d",ans+1);
			return 0;
		}
		if(f){
			d[3]=1;d[4]=2;d[5]=6;d[6]=7;
			for(int i=8;i<=s.size();i++)d[i]=d[i-1]+d[i-2];
			printf("%d",d[s.size()]);
			return 0;
		}
	}
}

