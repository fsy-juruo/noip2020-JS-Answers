#include<bits/stdc++.h>
using namespace std;
int k[26],k1[26],k2[26];
int number(string str,int begin,int end){
	int ans=0;
	memset(k,0,sizeof(k));
	for(int i=begin;i<=end;i++)k[str[i]-'a']++;
	for(int i=0;i<=25;i++)ans+=(k[i]%2==0?0:1);
	return ans;
}
bool OK(string str,int end,int len){
	for(int i=len;i<=end;i++){
		if(str[i]!=str[i%len])return false;
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	string str;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>str;
		string tmp_str="";
		memset(k1,0,sizeof(k1));
		int kc=0;
		for(int j=str.length()-1;j>=0;j--){
			tmp_str=str[j]+tmp_str;
			if(k1[str[j]-'a']==0){
				k1[str[j]-'a']=1;kc++;
			}else{
				k1[str[j]-'a']=0;kc--;
			}
//			kc=number(str,j,str.length()-1);
			int new_len=str.length()-tmp_str.length();
			for(int len=2;len<=new_len;len++){
				if(new_len%len==0&&OK(str,new_len-1,len)){
					int ka=0;
					memset(k2,0,sizeof(k2));
					for(int it=0;it<len-1;it++){
						if(k2[str[it]-'a']==0){
							k2[str[it]-'a']=1;ka++;
						}else{
							k2[str[it]-'a']=0;ka--;
						}
//						ka=number(str,0,it);
						if(ka<=kc)
						{
							ans++;
//							for(int k1=0;k1<=it;k1++)cout<<str[k1];
//							cout<<'+';
//							for(int k2=it+1;k2<len;k2++)cout<<str[k2];
//							cout<<'*'<<new_len/len;
//							for(int k3=j;k3<str.length();k3++)cout<<str[k3];
//							cout<<endl;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
