#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int s=0,f=1;
	char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')f=-1,ch=getchar();
	while(ch>='0'&&ch<='9')s=(s<<1)+(s<<3)+ch-48,ch=getchar();
	return s*f;
}int a[26],b[26],c[26],d[26];
bool check(int x){
	int s1=0,s2=0;
	for(int i=0;i<26;++i){
		if((a[i]*x)%2)++s1;
		if((d[i]-((a[i]+b[i])*x))%2)++s2;
	}return (s1<=s2);
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t=read();
	while(t--){
		int ans=0;
		string s,s1="",s2,s3;cin>>s;
		for(int j=0;j<26;++j)d[j]=a[j]=0;
		for(int i=0;i<s.size();++i)++d[s[i]-'a'];
		for(int i=0;i<s.size()-2;++i){
			s1+=s[i];s2="";++a[s[i]-'a'];
			for(int j=0;j<26;++j)b[j]=0;
			for(int j=i+1;j<s.size()-1;++j){
				s2+=s[j];++b[s[j]-'a'];
				int cnt=1;s3=s1+s2;
				while(s3.size()*cnt<s.size()){
					int f=1;
					for(int k=(s3.size())*(cnt-1);k<=(s3.size())*cnt-1;++k){
						if(s[k]!=s3[k-(s3.size())*(cnt-1)]){
							f=0;break;
						}
					}if(!f)break;
					if(check(cnt)){++ans;break;}
					++cnt;
				}
			}
		}printf("%d\n",ans);
	}
	return 0;
}


