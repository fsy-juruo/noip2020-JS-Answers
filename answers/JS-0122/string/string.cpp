#include <bits/stdc++.h>
using namespace std;
const int N=1050009;
int T;
int ans;
string s;
struct node {
	vector<int>lth;
}a[N];
int cnt[29],odd;
int dcnt[29],dodd;
void Subtask1() {
	for (int i=0;i<s.size();i++)
		a[i].lth.clear();
	for (int i=1;i<=s.size()/2;i++) {
		int k=1;
		for (int j=i+1;j<s.size();j++) {
			if (s[j]==s[j-(i+1)*k] && j-(i+1)*k==i) {
				k++;
				a[j].lth.push_back(i);
			}
			if (s[j]!=s[j-i*k-1])
				break;
		}
	}
	for (int i=0;i<s.size();i++)
		a[i].lth.push_back(i);
	odd=0;
	memset(cnt,0,sizeof(cnt));
	for (int c=s.size()-1;c>=2;c--) {
		cnt[s[c]-'a']++;
		if (cnt[s[c]-'a']%2==1)
			odd++;
		else
			odd--;
		int pp=0;
		dodd=0;
		memset(dcnt,0,sizeof(dcnt));
		for (int i=0;i<a[c-1].lth.size();i++) {
			while (pp<=a[c-1].lth[i]) {
				dcnt[s[pp]-'a']++;
				if (dcnt[s[pp]-'a']%2==1)
					dodd++;
				else
					dodd--;
				if (dodd<=odd)
					ans+=(a[c-1].lth.size()-i);
				if (dodd<=odd && pp==a[c-1].lth[i])
					ans--;
				pp++;
			}
		}
	}
	cout<<ans<<endl;
}
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while (T--) {
		cin>>s;
		ans=0;
		if (s.size()<3) {
			cout<<0<<endl;
			continue;
		}
		else if (s.size()==3) {
			cout<<1<<endl;
			continue;
		}
		Subtask1();
	}
	return 0;
}
