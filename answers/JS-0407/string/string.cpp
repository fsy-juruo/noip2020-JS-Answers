#include <bits/stdc++.h>
#define maxn 100007
using namespace std;

string s;
int cntf[maxn],cntr[maxn];

bool check(string s,int a,int b) {
	string cp = s.substr(0,a);
	for (int i=a; i<b; i+=a)
		if (s.substr(i,a) != cp)return false;
		
	return true;
}

int main() {
	//cout<<check("acacacab",2,6)<<endl;
	//i: C length,j: chunks,k:A length
	ios_base::sync_with_stdio(false);
	freopen("string.in","r",stdin);
	freopen("string.out","e",stdout);
	
	int T;
	cin>>T;
	while (T--) {
		cin>>s;
		int len = s.length();
		map<char,int> m1,m2;
		memset(cntf,0,sizeof(cntf));
		memset(cntr,0,sizeof(cntr));
		
		for (int i=1; i<=len; i++) {
			m1[s[i-1]]++;
			if (m1[s[i-1]] %2 == 0) cntf[i] = cntf[i-1] -1;
			else cntf[i] = cntf[i-1] +1;
			//cout<<cntf[i]<<' ';
		}//cout<<endl;
		for (int i=1; i<=len; i++) {
			m2[s[len-i]]++;
			if (m2[s[len-i]] %2 == 0) cntr[i] = cntr[i-1] -1;
			else cntr[i] = cntr[i-1] +1;
			//cout<<cntr[i];
		}//cout<<endl;

		long long ans = 0;
		for (int i=0; i<len; i++)
			for (int j=i; j>=2; j--)
				if (i % j == 0 && check(s,j,i)){
					for (int k=1; k<j; k++)
						if (cntf[k] <= cntr[len - i]) {
							//cout<<k<<' '<<cntf[k]<<' '<<len-i<<' '<<cntr[len-i]<<endl;
							//cout<<"A="<<s.substr(0,k)<<" B="<<s.substr(k,j-k)<<" C="<<s.substr(i)<<endl;
							ans++;
						}
				}
		cout<<ans<<endl;
	}
	return 0;
}
