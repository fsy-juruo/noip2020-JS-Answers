#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int read() {
	int f=1,x=0;
	char ch;
	do {
		ch=getchar();
		if(ch=='-')f=-1;
	} while(ch<'0'||ch>'9');
	do {
		x=x*10+ch-'0';
		ch=getchar();
	} while(ch>='0'&&ch<='9');
	return f*x;
}
const int p=1e9+7;
int n,m[100005],k;
int mp[105][105][105];
int num;
int main() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=k; i++) {
		m[i]=read();
	}
	if(k==1) {
		int c[100005],d[100005];
		for(int i=1; i<=n; i++) {
			c[i]=read(),d[i]=read();
			num+=d[i];
		}
		int sum;
		for(int i=1; i<=m[i]; i++) {
			int site=m[i];
			if(num==0) {
				cout<<"-1";
				return 0;
			}
			int nn=0;
			for(int i=1;i<=n;i=(n%i)+1){
				if(site>=1&&site<=m[1]) {
					site+=d[i];
					sum=(sum+1)%p;
				} 
				else {
					sum=(sum+1)%p;
					break;
				}
			}
		}

		cout<<sum<<endl;
		return 0;
	}
	else {
		cout<<"-1";
	}
	return 0;
}
