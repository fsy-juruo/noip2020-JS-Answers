#include<bits/stdc++.h>
using namespace std;
int T;
string s;
int f1[30],f2[30];//97-122
bool check(int l1,int l2){
	memset(f1,0,sizeof(f1));memset(f2,0,sizeof(f2));
	int p=0;
	for(int i=1;i<=l1;i++) f1[int(s[p++])-97]++;
	p=s.size()-l2;
	for(int i=1;i<=l2;i++) f2[int(s[p++])-97]++;
	int num1=0,num2=0;
	for(int i=0;i<30;++i) if(f1[i]%2) num1++;
	for(int i=0;i<30;++i) if(f2[i]%2) num2++;
	return num1<=num2;
}
#define F "string"//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int main(){
	freopen(F".in","r",stdin);
	freopen(F".out","w",stdout);
	cin>>T;
	while(T--)
	{
		int ans=0;
		cin>>s;
		
		for(int i=1;i<=s.size()-1;++i){
			for(int j=1;j<=s.size()-i-1;++j){
				if(!check(i,j)) continue;
				for(int k=1;k<s.size()-i-j;++k){
					if(s.size()-i-j-k==i+k){
						int p=0;
						bool f=1;
						for(int c=i+k;c<=s.size()-j-1;++c)
						  if(s[i]!=s[p++]) f=0;
						if(f) {ans++;}
					}
					
				}
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

