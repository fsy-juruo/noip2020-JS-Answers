#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,m,ans;
string s;
inline int calc(string str){
	int times[10005],ans=0;
	memset(times,0,sizeof(times));
	for(int i=0;i<str.size();i++){
//		cout<<s[i]<<" ";
		times[str[i]]++;
	}
//	cout<<endl;
	for(int i='a';i<='z';i++){
//		if(times[i]!=0)cout<<i<<" "<<times[i]<<endl;
		if(times[i]%2==1)ans++;
	}
	return ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>s;ans=0;
//		cout<<s.size()<<endl;
		for(register int i=1;i<s.size()-1;i++){
			string s1="",s2="";
			for(register int j=0;j<=i;j++)
				s1+=s[j];
			for(register int j=i+1;j<s.size();j++)
				s2+=s[j];
			int cs2=calc(s2);
//			cout<<s1<<" "<<s2<<" "<<cs2<<endl;
			for(register int j=1;j<=s1.size()/2;j++){
				int flag=0;
				if(s1.size()%j!=0)continue;
				else{
					int tmp=s1.size()/j;
					for(int k=0;k<tmp;k++){
						char stmp=s1[k];
						for(int t=1;t<j;t++){
							if(stmp!=s1[k+t*tmp]){
								flag=1;break;
							}
						}
						if(flag==1)break;
					}
					if(flag==1)continue;
					string stmp="";
					for(int k=0;k<tmp-1;k++){
						stmp+=s1[k];
						if(calc(stmp)<=cs2){
							ans++;
//							cout<<stmp<<" "<<calc(stmp)<<" "<<s2<<" "<<cs2<<endl;
						}
					}
//					cout<<j<<endl;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
