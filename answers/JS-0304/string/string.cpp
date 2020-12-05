#include<bits/stdc++.h>
using namespace std;
int T,no,cnt;
int tot;
int x[27];
string s;
void solve(string s,int len){
	for(int i=1;i<=len-2;i++){
		for(int j=1;j<len-i;j++){
			int cnta=0,cntc=0;
			string a=s.substr(0,i);
			string b=s.substr(i,len-i-j);
			string c=s.substr(len-j,j);
//			cout<<a<<" "<<b<<" "<<c<<'\n';
			if(a==b){
				int l=a.length();
				while(l%2==0){
					l/=2;
					cnt++;
				}
			}
			for(int k=0;k<a.length();k++){
				x[(int)(a[k]-'a')+1]+=1;
			}
			for(int k=1;k<=26;k++){
				if(x[(int)(a[k]-'a')+1]%2!=0)
					cnta++;
			}
			memset(x,0,sizeof(x));
//			cout<<'\n'<<c<<'\n';
			for(int k=0;k<c.length();k++){
				x[(int)(c[k]-'a')+1]++;
//				cout<<c[k]<<" ";
			}
			for(int k=1;k<=26;k++){
				if(x[(int)(c[k]-'a')+1]%2!=0)
					cntc++;
			}
			if(cnta>cntc){
				no++;
//				cout<<cnta<<" "<<cntc<<'\n';
//				cout<<a<<" "<<c<<'\n';
			}
		}
	}
}
int main(){
  	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>s;
		int len=s.length();
		tot=(len-2)*(len-1)/2;
		no=0,cnt=0;
		solve(s,len);
//		cout<<tot<<" "<<no<<" "<<cnt<<'\n';
		cout<<tot-no+cnt<<'\n';
	}
	return 0;
}
/*
1
aabaab
*/
