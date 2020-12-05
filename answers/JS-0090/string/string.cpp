#include <bits/stdc++.h>
using namespace std;

long long T,f[30],cou[30],num,sum,ans,c;
string s;

bool check1(long long len,long long k){
	for(long long i=0;i<len;++i)
		for(long long j=1;j<k;++j)
			if(s[i+len*j]!=s[i])
				return false;
	return true;
}

void check(long long r){
	memset(cou,0,sizeof(cou));
	sum=0;
	for(long long i=0;i<r;++i){
		if(++cou[s[i]-'a']&1)
			sum++;
		else
			sum--;
		if(sum>num)
			continue;
		for(long long j=2;j<=r+1&&(r+1)/j>i+1;++j)
			if((r+1)%j==0&&check1((r+1)/j,j))
				ans++;
		ans++;
	}
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while(T>0){
		T--;
		memset(f,0,sizeof(f));
		num=ans=0;
		cin>>s;
		long long len=s.size();
		for(long long i=len-1;i>1;--i){
			if(++f[s[i]-'a']&1)
				num++;
			else
				num--;
			check(i-1);
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
