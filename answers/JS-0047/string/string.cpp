#include<bits/stdc++.h>
#define maxn 1048600
using namespace std;
template<typename TP>
inline void read(TP &num7){
	long long val7=0;int w7=1;
	char ch7=getchar();
	while(ch7<'0'||ch7>'9'){if(ch7=='-')w7=-1;ch7=getchar();}
	while(ch7>='0'&&ch7<='9'){val7=(val7<<3)+(val7<<1)+ch7-'0';ch7=getchar();}
	num7=val7*w7;
}
int T,n;
char str[maxn];
namespace subtask1{
long long ans;
int cnt1[28],cnt2[28][maxn],num1,num2;
void work(){
	ans=0;
	int i,j,ltt,kkk;
	for(i=1;i<=n;i++){
		for(j=1;j<=26;j++)
		cnt2[j][i]=cnt2[j][i-1];
		cnt2[str[i]-'a'+1][i]++;
	}
	for(i=n;i>=3;i--){
		memset(cnt1,0,sizeof(cnt1));
		num1=0;
		for(ltt=i;ltt<=n;ltt++)cnt1[str[ltt]-'a'+1]++;
		for(ltt=1;ltt<=26;ltt++)if(cnt1[ltt]&1)num1++;
		for(j=2;j<=(i-1)/2;j++){
			bool flag=1;if((i-1)%j!=0)continue;
			for(ltt=j+1;ltt<=i-1;ltt++){
				if(str[ltt]!=str[ltt-j]){
					flag=0;
					break;
				}
			}
			if(flag==0)continue;
			for(ltt=1;ltt<=j-1;ltt++){
				num2=0;
				for(kkk=1;kkk<=26;kkk++)
				if(cnt2[kkk][ltt]&1){
					num2++;
					if(num2>num1)break;
				}
				if(num2<=num1)ans++;
			}
		}
		j=i-1;bool flag=1;
		for(ltt=j+1;ltt<=i-1;ltt++){
			if(str[ltt]!=str[ltt-j]){
				flag=0;
				break;
			}
		}
		if(flag==0)continue;
		for(ltt=1;ltt<=j-1;ltt++){
			num2=0;
			for(kkk=1;kkk<=26;kkk++)
			if(cnt2[kkk][ltt]&1){
				num2++;
				if(num2>num1)break;
			}
			if(num2<=num1)ans++;
		}
	}
	cout<<ans<<endl;
}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	read(T);
	while(T--){
		memset(str,0,sizeof(str));
		scanf("%s",str+1);
		n=strlen(str+1);
		subtask1::work();
		continue;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
