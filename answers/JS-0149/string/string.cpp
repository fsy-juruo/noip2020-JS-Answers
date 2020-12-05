#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
string s;
int that(string s1){
	int f[30]={0};
	for(int i=0;i<s1.size();i++){
		f[s1[i]-'a']++;
	}
	int sum=0;
	for(int i=0;i<=25;i++){
		if(f[i]%2==1)sum++;
	}
	return sum;
}
string su(string s1,int t,int m){
	string sss="";
	if(m==1001){
		for(int i=t;i<s1.size();i++)sss+=s1[i];
	}
	else{
		for(int i=t;i<=t+m-1;i++)sss+=s1[i];
	}
	return sss;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int xxx=1;xxx<=n;xxx++){
		cin>>s;
		ans=0;
		for(int i=1;i<s.size()-1;i++){
			int z=0;
			do{
				string s11=su(s,z+i+1,1001);
				int x=that(s11);
				int f1=0;
				for(int j=0;j<i;j++){
					string s12=su(s,0,j+1);
					f1=that(s12);
					if(f1<=x){
						ans++;
					}
				}
				z+=i+1;
			}while(s.substr(z,i+1)==s.substr(0,i+1)&&z+i<s.size()-1);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
