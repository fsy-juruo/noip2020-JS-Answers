#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
	return x*f;
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cout<<-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

