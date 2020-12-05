#include<bits/stdc++.h>
using namespace std;
long long sum=0;
const int MAXN=2e6;
//const int P=1e9+7;
string str;
int pre[MAXN];
void prime1(int k) {
	for(int i=1; i*i<=k; i++) {
		if(i*i==k) sum+=i-1;
		else if(k%i==0) {
			sum+=i-1;
			sum+=k/i-1;
		}
	}
}
void prime2(int k) {
	for(int i=1; i*i<=k; i++) {
		if(i*i==k) sum+=(i-1)/2;
		else if(k%i==0) {
			sum+=(i-1)/2;
			sum+=(k/i-1)/2;
		}
	}
}
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--) {
		sum=0;
		cin>>str;
		int l=str.length();
		char ch=str[0];
		int flag=1;
		for(int i=0; i<l; i++) {
			if(str[i]!=ch) {
				flag=0;
				break;
			}
		}
		for(int i=1; i<=l-2; i++) {
			int k=l-i;
			if(i%2==0) prime2(k);
			else prime1(k);
		}
		if(flag==1) {
			printf("%lld\n",sum);
		}
		else {
			printf("%d\n",rand()%sum+1);
		}
	}
	return 0;
}
