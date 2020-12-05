#include <bits/stdc++.h>
using namespace std;
int check(string s){
	int t=0, c[26];
	for (int i=0; i<=25; i++) c[i]=0;
	for (int i=0; i<s.size(); i++) c[s[i]-'a']++;
	for (int i=0; i<=25; i++)
		if (c[i]%2!=0) t++;
	return t;
}
int main(){
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	int t, ans=0;
	cin >> t;
	for (int i=1; i<=t; i++){
		string s;
		cin >> s;
		bool e=false;
		for (int i=1; i<s.size(); i++)
			if (s[i]!=s[0]){e=true;break;}
		if (e){
			for (int j=s.size()-1; j>=2; j--){
				int c=check(s.substr(j, s.size()-j));
				for (int k=1; k<=j/2; k++)
					if (j%k==0){
						bool f=false;
						for (int x=k; x<j; x++)
							if (s[x%k]!=s[x]) {f=true;break;}
						if (f) continue;
						for (int x=1; x<k; x++){
							int a=check(s.substr(0, x));
							if (a>c) continue;
							ans++;
						}
					}
				int k=j;
				for (int x=k; x<j; x++)
					if (s[x%k]!=s[x]) break;
				for (int x=1; x<k; x++){
					int a=check(s.substr(0, x));
					if (a>c) continue;
					ans++;
				}
			}
			cout << ans << endl;
			ans=0;
		}
		else{
			long long x=0;
			for (int j=1; j<s.size()-1; j++){
				if (j%2==0){
					if (s.size()%2==0) x+=(s.size()-j)/2-1;
					else x+=(s.size()-j)/2;
				}
				else x+=(s.size()-j-1);
				for (int k=1; k<=(s.size()-j)/2; k++)
					if ((s.size()-j)%k==0){
						if (j%2==0){
							if (k%2==0) x+=k/2-1;
							else x+=k/2;
						}
						else x+=k-1;
					}
			}
			cout << x << endl;
		}
	}
	return 0;
}
