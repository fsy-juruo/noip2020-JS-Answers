#include<bits/stdc++.h>
using namespace std;
#define ll long long 
inline int read(){
	int f=1,x=0;
	char ch;
	do{
		ch=getchar();
		if(ch=='-')f=-1;
	}while(ch<'0'||ch>'9');
	do{
		x=x*10+ch-'0';
		ch=getchar();
	}while(ch>='0'&&ch<=9);
	return f*x;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	
	return 0;
}
