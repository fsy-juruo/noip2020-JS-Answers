#include<bits/stdc++.h>
using namespace std;
const int maxn=1050000;
int T;
int suf[maxn],pre[maxn];
int num[30];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		memset(suf,0,sizeof(suf));
		memset(pre,0,sizeof(pre));
		memset(num,0,sizeof(num));
		int len=s.length();
		pre[0]=1;
		num[s[0]-96]++;
		for(int i=1;i<len;i++){
			if(num[s[i]-96]%2==0){
				pre[i]=pre[i-1]+1;
			}
			else pre[i]=pre[i-1]-1;
			num[s[i]-96]++;
		}
		memset(num,0,sizeof(num));
		suf[len-1]=1;
		num[s[len-1]-96]++;
		for(int i=len-2;i>=0;i--){
			if(num[s[i]-96]%2==0){
				suf[i]=suf[i+1]+1;
			}
			else suf[i]=suf[i+1]-1;
			num[s[i]-96]++;
		}
		int cnt1=0,cnt2=0;
		long long ans=0;
		for(int i=len-1;i>=2;i--){
			cnt1=suf[i];
			//cout<<cnt1<<endl;
			for(int j=2;j<=i;j++){
				if(i%j!=0)continue;
				bool flag=true;
				for(int k=0;k<j;k++){
					char c=s[k];
					
					for(int l=k;l<i;l+=j){
						if(s[l]!=c){
							flag=false;
							break;
						}
					}
					if(flag==false){
						break;
					}
				}
				if(flag==false)continue;
				for(int k=0;k<j-1;k++){
					cnt2=pre[k];
					//cout<<cnt2<<endl;
					if(cnt2>cnt1){
						continue;
					}
					ans++;
				}
			}
			//cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
}
