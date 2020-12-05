#include<bits/stdc++.h>
using namespace std;
const int N=1048600;
int T;
int cnt[N],cntt[N],cnttt[N];
string s;
bool f[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>s;
		int ans=0;
		int len=s.size();
		for(int i=0;i<len;i++){
			int x=s[i]-'a'+1;
			//cout<<x<<endl;
		}
		for(int i=2;i<len;i++){
			string s3,s4;
			memset(cnt,0,sizeof(cnt));
			int c=0;
			for(int j=0;j<i;j++){
				s4+=s[j];
			}
			for(int j=i;j<len;j++){
				s3+=s[j];
				int x=s[j]-'a'+1;
				cnt[x]++;
			}
			for(int j=1;j<=26;j++){
				if(cnt[j]%2==1){
					c++;
				}
			}
			//cout<<s4<<endl;
			for(int j=1;j<i;j++){
				string s1,s2;
				memset(cntt,0,sizeof(cntt));
				int a=0;
				for(int l=j;l<i;l++){
					s2+=s4[l];
				}
				for(int l=0;l<j;l++){
					s1+=s4[l];
					int x=s4[l]-'a'+1;
					cntt[x]++;
				}
				
				int len1=s1.length();
				int len2=s2.length();
				int mi,ma;
				string s5,s6;
				if(len1>len2){
					s5=s2;s6=s1;
					mi=len2;ma=len1;
				}else{
					s5=s1;s6=s2;
					mi=len1;ma=len2;
				}
				
				if(ma%mi==0 && f[mi]==0){
					
					//cout<<1<<endl;
					int k=ma/mi;
					string s7=s5;
					while(k>1){
						s7+=s5;
						k--;
					}
					if(s7==s6){

						for(int q=1;q<mi;q++){
							string s8,s9;
							int a=0;
							memset(cnttt,0,sizeof(cnttt));
							for(int r=0;r<q;r++){
								s8+=s5[r];
								int x=s5[r]-'a'+1;
								cnttt[x]++;
							}
							for(int r=q;r<mi;r++){
								s9+=s5[r];
								int x=s5[r]-'a'+1;
								cnttt[x]++;
							}
							for(int r=1;r<=26;r++){
								if(cnttt[r]%2==1){
									a++;
								}
							}
//							if(s1=="a" and s2=="aaaaa"){
//								cout<<"AAA"<<endl;
//								cout<<ma<<" "<<mi<<" "<<f[mi]<<endl;
//							}
							if(a<=c){
								f[mi]=1;
								ans++;
								//cout<<"k"<<s1<<" "<<s2<<" "<<s3<<" "<<a<<" "<<c<<" "<<endl;

							}
						}
					}
				}
				for(int k=1;k<=26;k++){
					if(cntt[k]%2==1){
						a++;
					}
				}
				if(a<=c){
					//cout<<s1<<" "<<s2<<" "<<s3<<" "<<a<<" "<<c<<" "<<endl;
					ans++;
				}
				
				
			}
		}
		cout<<ans<<endl;
	}	
	
	return 0;
}
