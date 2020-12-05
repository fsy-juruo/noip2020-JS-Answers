#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define isnum(c) (c>='0'&&c<='9')
#define re register
const int MAXN=1e5+10;
int water1[MAXN],water2[MAXN],n,m,outt,T,size;
std::vector<int> pipe[MAXN];
bool flag[MAXN]; 
inline int gcd(int a,int b)
{
	if(!b) return a;
	return(gcd(b,a%b));
}
inline int read()
{
	bool flag1=0;char c=0;int A=0;
	c=getchar();
	while(!isnum(c))
	{
		flag1=(c=='-');
		c=getchar();
	}
	while(isnum(c))
	{
		A=(A<<3)+(A<<1)+c-'0';
		c=getchar();
	}
	return A;
}
inline void input()
{
	n=read();m=read();//排水结点数，接收口数量
	//printf("%d %d",n,m); 
	for(int i=1;i<=n;++i)
	{
		outt=read();//有几个排出管道 
		if(!outt) flag[i]=1;
		else
		{
			while(outt--)
			{
				T=read();
				pipe[i].push_back(T);//存进去 
			}
			//printf("%d ",pipe[i][0]);
		}
		
	}
	return;
	
}
inline void work()
{
	for(int i=1;i<=n;++i)
	{
		int now_w1,now_w2;
		if(!flag[i])
		{
			size=pipe[i].size();
			if(i<=m) {
				now_w1=1,now_w2=size;}
			else {
				now_w1=water1[i],now_w2=water2[i]*size;}
			//printf("%d ",size);
			for(int j=0;j<size;++j)
			{
				int pos=pipe[i][j];
				//printf("%d|",pos);
				if((!water1[pos])&&(!water2[pos])) {water1[pos]+=now_w1;water2[pos]+=now_w2;}
				else if(water2[pos]==now_w2) water1[pos]+=now_w1;
				else 
				{
					int gong=(ll)now_w2*water2[pos]/gcd(now_w2,water2[pos]);//?
					water1[pos]=water1[pos]*(gong/water2[pos])+gong/now_w2*now_w1;
					water2[pos]=gong;
				}
			}
		}
	}
	
}
inline void print()
{
	for(int i=1;i<=n;++i)
	{
		if(flag[i]){
			int fenzi=water1[i],fenmu=water2[i];
			if(fenzi==1||fenmu==1){
				printf("%d %d\n",fenzi,fenmu);
				continue;
			}
			int G=gcd(fenmu,fenzi);
			printf("%d %d\n",fenzi/G,fenmu/G);
		}
	}
}
int main()
{
	freopen("water3.in","r",stdin);
	freopen("mywater.out","w",stdout);
	input();
	work();
	print();
	return 0;
}














