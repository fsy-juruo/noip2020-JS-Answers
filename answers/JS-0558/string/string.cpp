#include<bits/stdc++.h>
using namespace std;
int T,ans;
int numa[130],numc[130];
string s,A,B,C;
string all(string ss,int a,int b){
	string s1;
	for(int i=a;i<=b;i++){
		s1+=ss[i];
	}
	return s1;
}
void f(int a,int b){
	string tem=A+B;
	int i=0,temp=0;
	for(;i<s.size();i+=(a+b)){
		if(all(s,i,i+a+b-1)!=tem) break;
		else temp++;
	}
	ans+=temp-1;
	C=all(s,i,s.size()-1);
//	if(C==""){
//		C=A+B;
//		i-=(a+b);
//	}
	memset(numa,0,sizeof(numa));
	memset(numc,0,sizeof(numc));
	for(int j=0;j<C.size();j++) numc[C[j]]++;
	for(int j=0;j<A.size();j++) numa[A[j]]++;
	for(int j=96;j<=123;j++){
		if(numc[j]%2==1) numc[0]++;
		if(numa[j]%2==1) numa[0]++;
	}
//	cout<<"A:"<<A<<" B:"<<B<<" C:"<<C;
	if(numa[0]<=numc[0]&&C!=""){
		ans++;
//		cout<<"   yes"<<endl;	
	}
//	else cout<<"   no"<<endl;
	return ;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	for(int k=1;k<=T;k++){
		ans=0;
		cin>>s;
		int len=s.size();
		for(int i=1;i<=len-2;i++){
			for(int j=1;j<=len-i-1;j++){
				A=all(s,0,i-1);
				B=all(s,i,i+j-1);
				f(i,j);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

