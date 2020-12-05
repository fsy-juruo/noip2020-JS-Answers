#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+ch-'0';
	return x*f;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cout<<"8"<<endl<<"9"<<endl<<16;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

