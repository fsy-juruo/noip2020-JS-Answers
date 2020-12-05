#include<bits/stdc++.h>
using namespace std;
int t,ans,num[60];
string s,a,b,c;
bool check(string A,string C) {
	int na=0;
	int nc=0;
	memset(num,0,sizeof(num));
	for(int i=0; i<A.size(); i++) {
		num[A[i]-'A']++;
	}
	for(int i=0; i<=57; i++) {
		if(num[i]%2==1) na++;
	}
	memset(num,0,sizeof(num));
	for(int i=0; i<C.size(); i++) {
		num[C[i]-'A']++;
	}
	for(int i=0; i<=57; i++) {
		if(num[i]%2==1) nc++;
	}
	if(na<=nc) return true;
	else return false;
}
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	scanf("%d",&t);
	for(int i=1; i<=t; i++) {
		ans=0;
		cin>>s;
		for(int j=1; j<=s.size()-2; j++) {
			a="";
			for(int k=0; k<j; k++)
				a+=s[k];
			for(int g=1; g<=s.size()-1-j; g++) {
				b="";
				for(int k=j; k<g+j; k++)
					b+=s[k];
				string ss=a+b;
				int h=0;
				for(h=0; h<=s.size()/ss.size(); h++) {
					if(s.find(ss,ss.size()*h)!=ss.size()*h)break;
					else {
						c="";
						if((g+j)*(h+1)<s.size()) {
							for(int k=(g+j)*(h+1); k<s.size(); k++)
								c+=s[k];
							if(check(a,c)) {
								ans++;
							}
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
