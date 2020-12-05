#include <bits/stdc++.h>
#include <queue>
#include <cmath>
using namespace std;
int T;
bool maxp[27];
bool maxpa[27];
bool pre[27][1001];
bool prea[27][1001];
int sum[1001];
int suma[1001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while(T){
		T--;
		int ans=0;
		//memset(pre,0,sizeof(pre));
		//memset(sum,0,sizeof(sum));
		
		string s;
		cin>>s;
		int l=s.length();
		bool flag=true;
		for(int i=0;i<s.length()-1;i++){
			if(s[i]!=s[i+1]){
				flag=false;
			}
		}
		
		if(flag){
			if(l%2==0){
				int t=l/2;
				int su=(t-2)*(t-1);
				ans+=su;
				cout<<ans<<endl;
			}
			else {
				
			}
		}else {
			for(int i=l-1;i>=0;i--){
				for(int j=1;j<=26;j++){
					if(j!=s[i]-'a'+1)
					pre[j][l-i]=pre[j][l-i-1];
				}
				pre[s[i]-'a'+1][l-i]=!pre[s[i]-'a'+1][l-i-1];
				cout<<s[i]-'a'+1<<" "<<pre[s[i]-'a'+1][l-i]<<" "<<	maxp[s[i]-'a'+1]<<endl;
			}
			for(int i=l-1;i>=0;i--){
				for(int j=1;j<=26;j++){
					sum[l-i]+=pre[j][l-i];
				}
			}
			for(int i=0;i<=l-1;i++){
				for(int j=1;j<=26;j++){
					if(j!=s[i]-'a'+1)
					prea[j][i+1]=prea[j][i];
				}
				prea[s[i]-'a'+1][i+1]=!prea[s[i]-'a'+1][i];
			}
			for(int i=1;i<=l;i++){
				for(int j=1;j<=26;j++){
					suma[i]+=prea[j][i];
				}
			}
			int minlen=10000001;
			for(int i=1;i<=l;i++){
				if(l%i==0){
					int q=l/i;
					for(int j=0;j<q;j++){
						for(int k=0;k<=i-1;k++){
							if(s[j*i+k]==s[j*i+i+k]){
								minlen=i;
								break;
							}
						}
					}
				}
			}
			for(int i=2;i<=l-1;i++){
				int lc=l-i;
				int fc=sum[lc];
				for(int j=1;j*j<=i;j++){
					int tq=i/j;
					if((i%j==0&&tq%minlen==0)||j==1){
						for(int k=1;k<=j;k++){
							if(suma[i]>fc)continue;
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}
