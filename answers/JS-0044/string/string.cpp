#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;

long long T;
string s;
long long ans;
long long res(long long len){
	long long i = len;
	for(i = len;i<s.size();i++){
		if(s[i%len] != s[i])break;
	}
	return (i)/len*len-1;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>s;
		for(long long i = 2;i<s.size();i++){
			long long t = res(i);		
			long long r = (t+1)/i;
			for(long long j = 0;j<i;j++){
				for(long long k = 0;k<r;k++){
					long long cccnt[100] = {0};
					long long cacnt[100] = {0};
					long long ccnt = 0,acnt = 0;
					string a,b,c;
					for(long long l = 0;l<j;l++){
						cacnt[s[l]-'a']++;
						if(cacnt[s[l]-'a']%2 == 1)acnt++;
						else acnt--;
						a = a + s[l];
					}
					for(long long l = j;l<i;l++){
						b = b + s[l];
					}
					for(long long l = t - k*i+1;l<s.size();l++){
						cccnt[s[l]-'a']++;
						if(cccnt[s[l]-'a']%2 == 1)ccnt++;
						else ccnt--;
						c = c + s[l];
					}
					if(acnt<=ccnt&&a.size()!=0&&b.size()!=0&&c.size()!=0){
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
		ans = 0;
	}
	return 0;
}
