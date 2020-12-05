#include<bits/stdc++.h>
using namespace std;
int n,cji;
map<string,int>ccf;
long long l;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		l=s.size();
		for(int i=l-1;i>=0;i++){
			if(ccf[s[i]]==0){
				ccf[s[i]]=1;
				cji++;
			}else if(ccf[s[i]]==1){
				ccf[s[i]]=0;
				cji--;
			}
		}
		
	}
	return 0;
}
