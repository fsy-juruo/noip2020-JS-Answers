#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		string s;
		cin>>s;
		map<char,int> mpc;
		int cc=0;
		string ab=s;
		string c="";
		int ans=0;
		map<pair<string,string>,bool> used;
		for(int i=1;i<s.size()-1;++i){
			ab=ab.substr(0,ab.size()-1);
			c=s[s.size()-i]+c;
			mpc[s[s.size()-i]]++;
			if(mpc[s[s.size()-i]]%2==1){
				cc++;
			}
			else{
				cc--;
			}
			for(int len=2;len<=ab.size();++len){
				if(ab.size()%len!=0){
					continue;
				}
				int pre=0,now=len;
				bool ok=1;
				for(;ok&&now<len;pre=now,now+=len){
					for(int i=pre,j=now;i<now;++i,++j){
						if(ab[i]!=ab[j]){
							ok=0;
							break;
						}
					}
				}
				if(!ok){
					continue;
				}
				string x=ab.substr(0,len);
				map<char,int> mpa;
				int ca=0;
				string a="";
				for(int lena=1;lena<len;++lena){
					a+=x[lena-1];
					mpa[x[lena-1]]++;
					if(mpa[x[lena-1]]%2==1){
						ca++;
					}
					else{
						ca--;
					}
					if(ca<=cc){
						if(used[make_pair(a,c)]){
							continue;
						}
						used[make_pair(a,c)]=1;
						ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
