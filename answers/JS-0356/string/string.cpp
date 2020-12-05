#include<bits/stdc++.h>
using namespace std;
int n,a[100],ans;
string s;
int main(){
//	freopen();
	cin>>n;
	for (int zz=0;zz<n;zz++){
		cin>>s;
		int o=s.size();
		for (int i=0;i<o;i++)
			for (int j=0;j<o;j++)
				for (int k=0;k<o;k++)
					if ((o-k)%(i+j)!=0||i+j+k>o||(i+j)*(o-k)/(i+j)+k!=o)
						continue;
					else{
						int x=(o-k)/(i+j),f=0;
						for (int l=0;l<x;l++){
							for (int m=0;m<x;m++)
								if (s[l*(i+j)+i]!=s[m*(i+j)+i]){
									f=1;
									break;
								}
							if (f==1) break;
						}
						if (f==0){
							int l=0,z=0,y=0;
							for (;l<=i;l++) a[s[l]-'a']++;
							for (int m=0;m<26;m++) if (a[m]%2==1) y++;
							memset(a,0,sizeof(a));
							for (l=o-k;l<o;l++) a[s[l]-'a']++;
							for (int m=0;m<26;m++) if (a[m]%2==1) z++;
							memset(a,0,sizeof(a));
							if (y<=z) ans++;
						}
					}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
