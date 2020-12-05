#include<bits/stdc++.h>
using namespace std;
string c;
unsigned long long a[2000007];
int num[37],k,n;
int ans;
int pan(int x,int g){
	unsigned long long p=a[g],l=1;
	for(int i=1;i<=g;i++) l*=131;
	for(int i=g+1;i<=x;i+=g){
		unsigned long long q=a[i+g-1]-a[i-1];
		p*=l;
		if(p!=q) return 0; 
	}
	return 1;
}
int he(int x){
	int sum=0;
	int f[37],h=0;memset(f,0,sizeof(f));
	for(int i=2;i<=x;i++){
		if(x%i==0&&pan(x,i)){
			memset(f,0,sizeof(f));h=0;
			for(int j=1;j<i;j++){
				f[c[j-1]-'a']++;
				if(f[c[j-1]-'a']%2==1) h++;
				else h--;
				if(h<=k) sum++;
			}
		}
	}
	return sum;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>c;
		memset(a,0,sizeof(a));ans=0;
		memset(num,0,sizeof(num));k=0;
		n=c.size();
		for(int i=1;i<=n;i++) 
			a[i]=a[i-1]*131+c[i-1]-'a';
		for(int i=n;i>=3;i--){
			num[c[i-1]-'a']++;
			if((num[c[i-1]-'a']%2)==1) k++;
			else k--;
			ans+=he(i-1);
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
