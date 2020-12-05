#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	x=0;char ch=0;short fh=1;
	while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch=='-'){
		fh=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
	x*=fh;
}
long long t,ans;
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>s;
		long long len=s.length();
		ans=(len-1)*(len-2);
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
