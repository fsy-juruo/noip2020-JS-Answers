#include<bits/stdc++.h>
using namespace std;

long long ans;
int t,s[1050000][30];
string str;

void work1(){
	int len=str.size()-1;
	for(int i=0;i<=len;i++){
		for(int j=0;j<26;j++)
			if(i>0)s[i][j]=s[i-1][j];
		s[i][str[i]-'a']++;
	}
	/*for(int i=0;i<=len;i++){
		for(int j=0;j<26;j++)
			if(s[i][j])cout<<s[i][j]<<' ';
		cout<<endl;
	}*/
	for(int i=0;i<=len-2;i++)
		for(int j=len;j>i+1;j--){
			int f1=0,f2=0;
			for(int k=0;k<26;k++){
				if(s[i][k]%2==1)f1++;
				if((s[len][k]-s[j-1][k])%2==1)f2++;
			}
			if(f1<=f2)ans++;
		}
	cout<<ans<<endl;
}

int main(){
        freopen("string.in","r",stdin);
        freopen("string.out","w",stdout);
	cin>>t;
	for(int l=1;l<=t;l++){
		cin>>str;
		memset(s,0,sizeof(s));
		ans=0;
		work1();//暴力
	}
        return 0;
}

