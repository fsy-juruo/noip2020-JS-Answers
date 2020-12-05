#include<bits/stdc++.h>
using namespace std;
inline int R(){
	int x=0,f=1;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
	for(;isdigit(ch);ch=getchar())x=x*10+ch-48;
	return x*f;
}
int fl[1050000],fr[1050000];
int f1[300],f2[300];
int T;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	T=R();
	while(T--){
		string st;
		cin>>st;
		fl[0]=0;
		for(int i=1;i<=st.size();i++){
			fl[i]=fl[i-1];
			f1[st[i-1]]++;
			if(f1[st[i-1]]%2==1)fl[i]++;
			else fl[i]--;
		}
		fr[st.size()+1]=0;
		for(int i=st.size();i>0;i--){
			fr[i]=fr[i+1];
			f2[st[i-1]]++;
			if(f2[st[i-1]]%2==1)fr[i]++;
			else fr[i]--;
		}
		long long sum=0;
		for(int i=1;i<=st.size()-1;i++){
			long long s=0;
			for(int j=1;j<=i-1;j++){
				if(fl[j]<=fr[i+1]){
					s++;
				}
			}
			sum+=s;
			for(int j=i*2;j<=st.size()-1;j+=i){
				bool f=false;
				for(int k=j-i+1;k<=j;k++){
					if(st[(k-(j-i))-1]!=st[k-1]){
						f=true;
						break;
					}
				}
				if(f)break;
				sum+=s;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}

