#include<bits/stdc++.h>
using namespace std;
int T,a[27],c[27];
string s,A,B,C;
int counta(){
	int ans=0;
	for(int i=0;i<26;i++){
		if(a[i]%2==1) ans++;
	}return ans;
}
int countc(){
	int ans=0;
	for(int i=0;i<26;i++){
		if(c[i]%2==1) ans++;
	}return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while(T--){
		A="";
		for(int i=0;i<26;i++) a[i]=0;
		cin>>s;
		int ans=0;
		int len=s.length();
		for(int i=0;i<len-2;i++){
			A+=s[i];
			a[s[i]-'a']++;
			B="";
			for(int j=i+1;j<len-1;j++){
				B+=s[j];
				string D=A+B,E="";
				int rightpos=j+1;
				if(rightpos+j+1<len) E=s.substr(rightpos,j+1);
				while(E==D){
					rightpos+=j+1;
					if(rightpos+j+1>=len) break;
					E=s.substr(rightpos,j+1);
				}
				C="";
				for(int i=0;i<26;i++) c[i]=0;
				for(int k=rightpos;k<len;k++){
					C+=s[k];
					c[s[k]-'a']++;
				}
				if(countc()>=counta()){
//					cout<<A<<' '<<B<<' '<<C<<counta()<<' '<<countc()<<endl;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
}
