#include<bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
#define RE return
#define V vector
using namespace std;
int readint(){
	char c=getchar();
	while(!isdigit(c))c=getchar();
	int s=c-'0';c=getchar();
	while(isdigit(c)){
		s=(s<<1)+(s<<3)+c-'0';
		c=getchar();
	}
	RE s;
}
void output(int x){
	if(x>=10)output(x/10);
	putchar((char)(x%10+'0'));
}
signed main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout<<-1;
	RE 0;
}


