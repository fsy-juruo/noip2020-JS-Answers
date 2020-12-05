#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	cin>>t;
	int f1[70000],f2[70000];
	while(t--){
		memset(f1,0,sizeof(f1));
		memset(f2,0,sizeof(f2));
		string s;
		cin>>s;
		int len=s.size();
		f1[0]=1;
		f2[len-1]=1;
		for(int i=1;i<len-2;i++){
			int tot=1;
			for(int j=0;j<i;j++){
				if(s[j]==s[i])tot++;
			}
			if(tot%2==1)f1[i]=f1[i-1]+1;
			else f1[i]=f1[i-1]-1;
			//cout<<f1[i]<<endl;
		}
		for(int i=len-2;i>1;i--){
			int tot=1;
			for(int j=len-1;j>i;j--){
				if(s[j]==s[i])tot++;
			}
			if(tot%2==1)f2[i]=f2[i+1]+1;
			else f2[i]=f2[i+1]-1;
			//cout<<f2[i]<<endl;
		}
		int ans=0;
		for(int i=0;i<len-2;i++){
			for(int j=len-1;j>i+1;j--){
				if(f1[i]<=f2[j])ans++;
			}
		}
		bool flag=0,flag1=1;int sum=0;string s1;
		if(len>30000){
			for(int i=2;i<len/2;i++){
				ans+=len/i;
			}
		}
		else
		for(int i=0;i<len-2;i++){
			if(flag&&s1[sum]!=s[i]){
				flag=0;
				for(int j=0;j<sum;j++){
					if(s1[j]!=s[j]){
						flag1=0;break;
					}
				}
				if(flag1&&i!=len-sum-2)ans+=sum;
				break;
			}s1[sum]=s[i];
			if(s1[sum]==s[i]){
				flag=1;
			}
			else{
				flag=0;break;
			}
			sum++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
