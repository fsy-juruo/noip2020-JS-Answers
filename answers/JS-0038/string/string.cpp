#include<bits/stdc++.h>
using namespace std;
int sum[26][1048600],T;
bool a[26][1048600];
long long d[1048600];//��iλ��������C���ķ����� 
int js(int l,int r){//���ر�����[l,r]֮����������ε��ַ�����
 int i,an=0;
 for(i=0;i<26;i++){
 	if((sum[i][r]-sum[i][l-1])%2==1)an++;
	}
	return an;
}
long long ans;
void solve(int t,int len,string s)
{
	int x=js(t,len-1),i,j,k;
	for(i=1;i<=t/2;i++)//i�ǻ��ֵ�AB������
	{
		if(t%i!=0)continue;
		if(i!=1){
			int j;
			for(j=t-1;j>=t/i;j--){
				int x=j%(t/i);
				if(s[j]!=s[x]){
					break;
				}
			}
			if(j>=t/i)continue;
		}//���ܻ��־͹�
		if(d[t/i]!=0)d[t]+=d[t/i];//���ֵ��Ӵ������������
		else{
			for(j=1;j<=t/i-1;j++)//j������B���� 
			{
				if(js(0,j-1)>x)continue;
				if(((t/i)-j)==j)
				{
				for(k=0;k<j;k++){
					if(s[k]!=s[k+j])break;
				}
				if(k>=j)continue;
				}
				d[t]++;
			} 
		} 
	 }
	 ans+=d[t]; 
}
int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>T;
	while(T--){
		memset(sum,0,sizeof(sum));
		memset(a,0,sizeof(a));
		memset(d,0,sizeof(d));
		ans=0;
		string s;
		cin>>s;
		int i;
		for(i=0;i<s.size();i++){
			a[s[i]-'a'][i+1]=1;
		}
		for(i=0;i<26;i++)
		for(int j=0;j<s.size();j++)
		sum[i][j]=sum[i][j-1]+a[i][j];
		for(i=2;i<s.size();i++){
			solve(i,s.size(),s);
		}
		cout<<ans<<endl;
	}
	return 0;
}
