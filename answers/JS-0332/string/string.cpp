#include<bits/stdc++.h>
using namespace std;
int n;
string a;
int cnt[100];
int ansx;
int check(int fir,int end){
	for(int i=fir;i<=end;i++){
		cnt[a[i]-'a'+1]++;
	}
	int ans=0;
	for(int i=1;i<=100;i++){
		if(cnt[i]%2!=0)
			ans++;
	}
	return ans;
}
void work(string a){
	int len=a.length();
	for(int i=0;i<len-2;i++){
		for(int j=i+1;j<len-1;j++){
			memset(cnt,0,sizeof(cnt));
			int suma=check(0,i);
			memset(cnt,0,sizeof(cnt));
			int sumb=check(i+1,j);
			memset(cnt,0,sizeof(cnt));
			int sumc=check(j+1,len-1);
			if(suma<=sumc){
				ansx++;
			}
		}
	}
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		ansx=0;
		work(a);
		cout<<ansx<<endl;
	}
	return 0;
}
