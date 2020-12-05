#include<bits/stdc++.h>
using namespace std;
//#define CIN int
#define reg register
const long long p=13331;
//CIN rf(){
//	CIN num=0,f=1;
//	char c=getchar();
//	while(c>'9'||c<'0'){
//		if(c=='-')f=-1;
//		c=getchar();
//	}
//	while(c>='0'&&c<='9'){
//		num=num*10+c-'0';
//		c=getchar();
//	}
//	return num*f;
//}
int T;
unsigned long long H[5400][5400];
int f[30];
int g[32769];
int w[32769];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		memset(g,0,sizeof g);
		memset(w,0,sizeof w);
		int ans=0;
		string s;
		cin>>s;
		int l=s.length();
		for(reg int i=0;i<l;++i){
			H[i][i]=s[i]-'a'+1;
		}
		for(reg int i=0;i<l;++i){
			for(reg int j=i+1;j<l;++j){
				H[i][j]=H[i][j-1]*p+(s[j]-'a'+1);
			}
		}
		
		memset(f,0,sizeof f);
		for(reg int i=0;i<l;++i){
			++f[s[i]-'a'];
			for(reg int j=0;j<=25;++j)
				if(f[j]&1)++g[i];			
		}
		memset(f,0,sizeof f);
		for(reg int i=l-1;i>=0;--i){
			++f[s[i]-'a'];
			for(reg int j=0;j<=25;++j)
				if(f[j]&1)++w[i];
		}
		
		for(reg int i=1;i<l-1;++i){
			unsigned long long t=H[0][i];//AB
			int lt=i+1;
			for(reg int k=0;k<lt-1;++k){//A
				int FA=g[k];
				for(reg int j=1;j*lt<l;++j){
					if(H[(j-1)*lt][j*lt-1]==t){
						if(FA<=w[j*lt])
						++ans;
					}
					else break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
//zz rp++

