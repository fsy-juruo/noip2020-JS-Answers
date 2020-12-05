#include<bits/stdc++.h>
using namespace std;

int T,ans;
string s;
bool check(int t,int ed){
	for (int i=0;i<ed;i++){
		if (s[i]!=s[i+t]) return false;
	}
	return true;
}
int f(int st,int ed){
	int a[30];
	memset(a,0,sizeof(a));
	for (int i=st;i<=ed;i++){
		int ch=s[i]-'a'+1;
		a[ch]^=1;
	}
	int num_c=0;
	for (int i=1;i<=26;i++){
		if (a[i]) num_c++;
	}
	return num_c;
}
int find(int c){
	int n=c,num_c=f(c,s.length()-1),ans=0;
//	cout<<num_c<<" ";
	for (int i=2;i<=n;i++){
		if (!(n%i))
		if (check(i,c-i)){
			for (int j=0;j<i-1;j++){
				if (f(0,j)<=num_c) ans++;
			}
		}
	}
	return ans;
}
void read(){
	char c=getchar();
	while (c>='a'&&c<='z'){
		s+=c;
		c=getchar();
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	int a,b,c;
	for (int t=1;t<=T;t++){
		read();
		ans=0;
		for (int i=2;i<s.length();i++){
			ans+=find(i);
//			cout<<ans<<" ";
		}
		cout<<ans<<endl;
		s="";
	}
	return 0;
}
