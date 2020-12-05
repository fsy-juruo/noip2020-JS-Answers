#include <bits/stdc++.h>
using namespace std;
int read(){
	int x=0;char w=0,ch=0;
	while(!isdigit(ch))w|=ch=='-',ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return w?-x:x;
}int w[20];int zuobiao[6],z[6];

int n,k,xx;int mm=0,nn=1,ans=0,c[100010],d[100010];


bool hefa()
{
	for(int i=1;i<=k;i++)if(zuobiao[i]>w[i]||zuobiao[i]<=0)return false;return true;
}

int tongji(){int as=0;
	for(int i=1;1;i++){
		as++;
		zuobiao[c[i]]+=d[i];
		if(!hefa())break;
		if(i==n){
			i=0;
			if(z[1]==zuobiao[1]&&z[2]==zuobiao[2]&&z[3]==zuobiao[3]&&z[4]==zuobiao[4]&&z[5]==zuobiao[5])return -1;
		}
		
		
	}
	
	return as;
	
}


int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(),k=read();
	if(n<=100000){for(int i=1;i<=k;i++)w[i]=read(),mm=max(mm,w[i]),nn*=w[i];
	for(int i=1;i<=n;i++)c[i]=read(),d[i]=read();	
	
	
	if(mm<=3){
		for(int i=1;i<=nn;i++){
			
			zuobiao[1]=i%3+1;z[1]=zuobiao[1];
			zuobiao[2]=i/3%3+1;z[2]=zuobiao[2];
			zuobiao[3]=i/9%3+1;z[3]=zuobiao[3];
			zuobiao[4]=i/27%3+1;z[4]=zuobiao[4];
			zuobiao[5]=i/81%3+1;z[5]=zuobiao[5];
			//for(int i=1;i<=5;i++)cout<<z[i]<<" ";cout<<endl;
			if(hefa())
			{
				
				xx=tongji();
				//cout<<xx<<endl;
				if(xx==-1)
				{
				cout<<-1;return 0;
				}
				else ans+=xx;
			}
			
		}
		if(ans!=0)cout<<ans%(10000007);
	    else cout<<-1;
		return 0;
	}
	if(mm<=10){
		for(int i=1;i<=nn;i++){
			
			zuobiao[1]=i%10+1;z[1]=zuobiao[1];
			zuobiao[2]=i/10%10+1;z[2]=zuobiao[2];
			zuobiao[3]=i/100%10+1;z[3]=zuobiao[3];
			//for(int i=1;i<=5;i++)cout<<z[i]<<" ";cout<<endl;
			if(hefa())
			{
				
				xx=tongji();
				//cout<<xx<<endl;
				if(xx==-1)
				{
				cout<<-1;return 0;
				}
				else ans+=xx;
			}
			
		}
		if(ans!=0)cout<<ans%(10000007);
	    else cout<<-1;
		return 0;
		
	}
	if(k==1){
		int lef=0,rig=0,jishu=0;
		for(int i=1;i<=n;i++){
			jishu+=d[i];
			if(jishu>rig)rig=jishu;
			if(jishu<lef)lef=jishu;
	    } 
		
		for(int i=1;i<=nn;i++){
			if(jishu==0)
				{
				cout<<-1;return 0;
				}
			zuobiao[1]=i;z[1]=zuobiao[1];
			while(zuobiao[1]+rig<=w[1]&&zuobiao[1]+lef>=1)
			{
				zuobiao[1]+=jishu;
				ans+=n;
			}
			//for(int i=1;i<=5;i++)cout<<z[i]<<" ";cout<<endl;
			if(hefa())
			{
				
				xx=tongji();
				//cout<<xx<<endl;
				if(xx==-1)
				{
				cout<<-1;return 0;
				}
				else ans+=xx,ans%=(10000007);
			}
			
		}
		//cout<<lef<<" "<<rig<<endl;
		if(ans!=0)cout<<ans%(10000007);
	    else cout<<-1;
		return 0;
	}
	
	}
	
	
	
	if(ans!=0)cout<<ans%(10000007);
	    else cout<<-1;
		return 0;
	
}

/*
3 2
3 3
1 1
2 -1
1 1

2 3
10 10 10
1 1
1 -1

10 1
100
1 1
1 2
1 3
1 4
1 5
1 -2
1 -4
1 -6
1 -8
1 -10
*/




