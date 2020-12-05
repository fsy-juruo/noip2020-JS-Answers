#include <fstream>
#include <string>
#include <cstring>
using namespace std;

ifstream cin("string.in");
ofstream cout("string.out");
int cnt[28],cnt2[28];
string str;
inline bool check(string& a,int l,int len){
	string b=str.substr(l,len);
	memset(cnt,0,sizeof(int)*27);
	memset(cnt2,0,sizeof(int)*27);
	for(int i=0;i<a.length();i++){
		cnt[a[i]-'a']++;
	}
	for(int i=0;i<b.length();i++){
		cnt2[b[i]-'a']++;
	}
	int aj=0,bj=0;
	for(int i=0;i<26;i++){
		if(cnt[i]%2)aj++;
		if(cnt2[i]%2)bj++;
	}
	//cout<<"check: "<<a<<" "<<b;
	//if(aj>bj)cout<<" is false\n"<<"aj="<<aj<<" bj="<<bj<<endl;
	//cout<<" is true\n"<<"aj="<<aj<<" bj="<<bj<<endl;
	if(aj>bj)return false;
	return true;
}
inline bool check2(int l1,int l2){
	if(((l1)%2==0)||(((l1)%2==1)&&(l2%2==1)))return true;
	return false;
}
void cheat(string str){
	long long ans=0;
	int n=str.length();
	for(int i=1;i<n;i++){
		for(int j=i;j<n-1;j++){
			//string a=str.substr(0,i),b=str.substr(i,j-i+1);
			if(check2(i,n-j)){
				ans++;
			}
			int sa=i,sb=j-i+1;
			
			//if(j+1+sa*2+sb*2<n)
			//	ans+=(n-sa*2-sb*2-(j+1)+1)/(sa+sb);
			for(int k=j+1;k+sa+sb+sa+sb<n;k+=sa+sb){
				if(check2(i,n-k-sb-sa+1)){
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
//	return 0;
}
int mainrun(){
	long long ans=0;
	cin>>str;
	int n=str.length();
	if(n>=(1<<14)){
		cheat(str);
		return 0;
	}
	for(int i=1;i<n;i++){
		for(int j=i;j<n-1;j++){
			string a=str.substr(0,i),b=str.substr(i,j-i+1);
			if(check(a,j+1,n-j)){
				ans++;
			}
			int sa=a.length(),sb=b.length();
			for(int k=j+1;k+sa+sb<n;k+=sa+sb){
				if(str.substr(k,sa)!=a||str.substr(k+sa,sb)!=b){
					break;
				}
				if(check(a,k+sa+sb,n-k-sb-sa+1)){
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		mainrun();
	}
	return 0;
}

