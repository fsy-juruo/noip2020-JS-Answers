#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &cn){
	cn=0;int sig=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')sig=-1;c=getchar();}
	while(isdigit(c)){cn=cn*10+c-48;c=getchar();}
	cn*=sig;
}
template<typename T>inline void write(T cn){
	int wei=0;
	int cx=cn%10;cn/=10;
	if(cx<0||cn<0){
		putchar('-');
		cx=0-cx;cn=0-cn;
	}
	T cm=0;
	while(cn){
		cm=cm*10+cn%10;cn/=10;
		wei++;
	}
	while(wei--){
		putchar(cm%10+48);
		cm/=10;
	}
	putchar(cx+48);
	putchar('\n');
}
int a[26];
inline int count(string st){
	for(int i=0;i<26;i++)a[i]=0;
	int s=0;
	for(int i=0;i<st.size();i++){
		int y=st[i]-97;
		a[y]++;
	}
	for(int i=0;i<26;i++){
		if(a[i]%2){
			s++;
		}
	}
	return s;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	read(T);
	for(int i=0;i<26;i++){
		a[i]=char(i+97);
	}
	while(T--){
		string st;
		cin>>st;
		string A,B,C;
		long long ans=0;
		for(int i=0;i<=st.size()-3;i++){
			A=st.substr(0,i+1);
			for(int j=i+1;j<=st.size()-2;j++){
				B=st.substr(i+1,j-i);
				for(int k=j+1;k<st.size();k++){
					C=st.substr(j+1,k-j);
					if((st.size()-C.size())%(A.size()+B.size()))continue;
					int ac=count(A),bc=count(B),cc=count(C);
					if(ac>cc)continue;
					int y=0;
					y=(st.size()-C.size())/(A.size()+B.size());
					string e="";
					for(int u=1;u<=y;u++){
						e=e+A;
						e=e+B;
						string h=e;
						h=h+C;
						if(h==st)ans++;
					}
				}
			}
		}
		write(ans);
	}
	return 0;
}

