#include<bits/stdc++.h>

using namespace std;
string fp(string s,int p) {
	if(p==1)return s;
	string S="";
	string t=fp(s,p/2);
	S=t+t;
	if(p&1)S=S+s;
	return S;
}
int cal(string s) {
	int n=0;
	int f[128]= {};
	for(int i=0; i<s.size(); i++) {
		f[s[i]]^=1;
		n+=(f[s[i]]?1:-1);
	}
	return n;
}
string s;
int T;
int main() {
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	cin>>T;
	//int n;
	//cin>>n;
	while(T--) {
		int ans=0;
		cin>>s;
		/*s="";
		for(int i=1;i<=n;i++){
			int x=rand()%26;
			s+=char(x+97);
		}*/
		for(int i=1; i<s.size()-1; i++) {
			string w=s.substr(0,i+1);
			for(int j=1; j<=s.size()/(i+1)+1; j++) {

				string W=fp(w,j);
				//cout<<j<<" "<<w<<" "<<W<<" "<<s.find(W)<<endl;
				if(s.find(W)>s.size()||s.size()==j*(i+1))break;
				string c=s.substr(j*(i+1));
				int x=cal(c),f[128]= {},k=0;
				//int cnt=0;

				for(int i=0; i<w.size()-1; i++) {
					f[w[i]]^=1;
					k+=(f[w[i]]?1:-1);
					if(k<=x)ans++;//,cnt++;//cout<<w.substr(0,i+1)<<" "<<w.substr(i+1)<<endl;
				}
				//cout<<w<<" "<<W<<" "<<c<<" "<<x<<" "<<cnt<<endl;
			}
		}

		cout<<ans<<endl;
	}
	return 0;
}

