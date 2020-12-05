#include <bits/stdc++.h>
using namespace std;
int t;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a;
		long long ans=0;
		int len=a.size();
		for(int j=1;j<=len-2;j++){
			
			for(int k=1;k<=len-j-1;k++){
				if(len-j-k==j&&len-j-k==k)continue;
				if(j%2==1&&k%2==0)continue;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
