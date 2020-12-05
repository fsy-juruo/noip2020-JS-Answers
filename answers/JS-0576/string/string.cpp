#include<bits/stdc++.h>
#define gc getchar()
#define ll long long
using namespace std;
int t;
inline int r(){
	int x=0;
	char c=gc;
	while(!isdigit(c))c=gc;
	while(isdigit(c))x=(x<<1)+(x<<3)+c-48,c=gc;
	return x;
}
void work(string s){
	ll ans=0;
	ll lens=s.length();
	for(int i=1;i<=lens;i+=2){
		for(int j=1;(lens-i)/j>1;j++){
			if((lens-i)%j)continue;
			ans+=(lens-i)/j-1;
		}
	}
	for(int i=2;i<=lens;i+=2){
		for(int j=1;(lens-i)/j>1;j++){
			if((lens-i)%j)continue;
			ans+=((lens-i)/j-1)/2;
		}
	}
	cout<<ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	t=r();
	while(t--){
		string s;
		cin>>s;
		work(s);
	}
	return 0;
}

