#include<bits/stdc++.h>
using namespace std;
int t;
string str;
int qz[1010][6],hz[1010][6],sum1[26][6],sum2[26][6];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>str;
		int len=str.size();
		str=" "+str;
		if(len<=1001){
			for(int i=1;i<=len;i++){
				sum1[str[i]-'a'][t]++;
				if(sum1[str[i]-'a'][t]%2)qz[i][t]=qz[i-1][t]+1;
				else qz[i][t]=qz[i-1][t]-1;
			}
			for(int i=len;i>=1;i--){
				sum2[str[i]-'a'][t]++;
				if(sum2[str[i]-'a'][t]%2)hz[i][t]=hz[i+1][t]+1;
				else hz[i][t]=hz[i+1][t]-1;
			}
			int cnt=0;
			for(int a=1;a<=len-2;a++)
				for(int b=1;b<=len-a-1;b++)
					for(int i=1;(a+b)*i<len;i++){
						int flag=true;
						string sub=str.substr(1,a+b);
						for(int j=1;j<=i;j++)
							if(str.substr(1+(a+b)*(j-1),a+b)!=sub){
								flag=false;
								break;
							}
						if(flag&&hz[(a+b)*i+1][t]>=qz[a][t])
							cnt++;
					}
			cout<<cnt<<endl;
		}
	}
	return 0;
}

