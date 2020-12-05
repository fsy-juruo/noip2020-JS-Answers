//REMEMBER TO ENABLE freopen(). - Salicia
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int T;
unsigned int sol = 0;
bool validity(string A,string C) {
	int aa[26],cc[26],cna=0,cnc=0;
	for(int i=0;i<A.length();i++) {
		aa[A[i]-'a']++;
	}
	for(int i=0;i<C.length();i++) {
		cc[C[i]-'a']++;
	}
	for(int i=0;i<26;i++) {
		if(aa[i]%2==1) cna++;
		if(cc[i]%2==1) cnc++;
		
	}
}
string get_slice(string s,int l,int r) {
	string qwq = "";
	for(int i=l;i<=r;i++) {
		qwq += s[i];
	}
	return qwq;
}
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	for(int qwq=1;qwq<=T;qwq++) {
		string p;
		cin>>p;
		for(int i=p.length()-1;i>=2;i--) {
			string c = slice(i,p.length()-1);
			for(int j=0;j<)
		}
	}
	return 0;
}
