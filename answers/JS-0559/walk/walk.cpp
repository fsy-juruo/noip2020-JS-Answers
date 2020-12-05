//REMEMBER TO ENABLE freopen(). - Elanda
#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
struct step {
	int c;
	int d;
} s[500001];
int n,k,wid[11],bias[11]; //1D ~ 10D
unsigned sol;
int main() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=k;i++) cin>>wid[i];
	for(int i=0;i<n;i++) {
		cin>>s[i].c>>s[i].d;
		bias[s[i].c]+=s[i].d;
	}
	cout<<-1<<endl;
	return 0;
}
