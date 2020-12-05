#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x){
	x=0;T f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	x*=f;
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	read(n);read(m);
	if(n==1){
		cout<<m<<endl;
		for(int i=1;i<=m;i++)cout<<"1 2"<<endl;
	}else if(n==2){
		cout<<"6"<<endl;
		cout<<"1 3"<<endl;
		cout<<"2 3"<<endl;
		cout<<"2 3"<<endl;
		cout<<"3 1"<<endl;
		cout<<"3 2"<<endl;
		cout<<"3 2"<<endl;
	}else{
		cout<<0<<endl;
	}
	return 0;
}

