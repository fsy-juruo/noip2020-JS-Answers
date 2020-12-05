#include <bits/stdc++.h>
using namespace std;
int T;
long long ans;
string str;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		cin>>str;
	}
	for(int i=1;i<=T;i++){
		ans=0;
		int l = str.length();
		for(int j=1;j<=l-2;j++){
			for(int k=1;k<=l-2;k++){
				for(int h=1;h<=l/2;h++){
					long long cnt = pow(j+k,h);
					if(cnt>=l)
						continue;
					if(j%2==1 && (l-cnt)%2==0)
						continue;
					else
						ans += 1;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
