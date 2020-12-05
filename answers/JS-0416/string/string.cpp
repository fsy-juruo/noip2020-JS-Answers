#include<bits/stdc++.h>
using namespace std;
struct q
{
	long long v,mul,add;
};
q s[4200010];
string b;
int a;
long long sss[210],t[210],w[210],ww,pos,ss,ts,ans,l;
bool ff;
template <typename T> void read(T &x)
{
	 x=0;char c=getchar();bool flg=0;
	 for (;!isdigit(c);c=getchar()) if (c=='-') flg=1;
	 for (;isdigit(c);c=getchar()) x=x*10+c-'0';
	 if (flg) x=-x;
}
void write(long long x)
{
	if (x<0)
	{
		x=-x;
		putchar('-');
	}
	if (x>=10) write(x/10);
	putchar(x%10+48);
}
void writeln(long long x)
{
	write(x);
	puts("");
}
void pushdown(int k,int l,int r)
{
	int mid=(l+r)>>1;
	s[(k<<1)].v=(s[(k<<1)].v*s[k].mul+s[k].add*(mid-l+1));
	s[(k<<1)+1].v=(s[(k<<1)+1].v*s[k].mul+s[k].add*(r-mid));	
	s[(k<<1)].add=(s[(k<<1)].add*s[k].mul+s[k].add);
	s[(k<<1)+1].add=(s[(k<<1)+1].add*s[k].mul+s[k].add);	
	s[(k<<1)].mul=(s[(k<<1)].mul*s[k].mul);
	s[(k<<1)+1].mul=(s[(k<<1)+1].mul*s[k].mul);	
	s[k].mul=1;
	s[k].add=0;
}
void modify2(int k,int l,int r,int x,int y,int z)
{
	if ((l>=x)&&(r<=y)) 
	{
		s[k].v=(s[k].v+z*(r-l+1));
		s[k].add=(s[k].add+z);
		return;
	}
	int mid=(l+r)>>1;
	pushdown(k,l,r);
	if (x<=mid) modify2((k<<1),l,mid,x,y,z);
	if (y>mid) modify2((k<<1)+1,mid+1,r,x,y,z);
	s[k].v=(s[(k<<1)].v+s[(k<<1)+1].v);
}
long long query(int k,int l,int r,int x,int y)
{
	if ((l>=x)&&(r<=y)) return s[k].v;
	int mid=(l+r)>>1;
	pushdown(k,l,r);
	long long ss=0;
	if (x<=mid) ss=(ss+query((k<<1),l,mid,x,y));
	if (y>mid) ss=(ss+query((k<<1)+1,mid+1,r,x,y));
	return ss;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for (int i=1;i<=a;i++)
	{
		cin>>b;
		if (b.size()<=2)
		{
			writeln(0);
			continue;
		}
		for (int j=0;j<=b.size()*4;j++)
		{
			s[j].mul=1;
			s[j].add=0;
			s[j].v=0;
		}
		memset(sss,0,sizeof(sss));memset(t,0,sizeof(t));ss=0;ts=0;ans=0;
		for (int j=2;j<b.size();j++) sss[b[j]]++;
		for (int j=97;j<=122;j++) if (sss[j]&1) ss++;
		t[b[0]]++;ts=1;modify2(1,0,b.size(),ts,ts,1);
		ans+=query(1,0,b.size(),0,ss);
		for (int k=97;k<=122;k++) w[k]=sss[k];
		ww=ss;pos=1;
		while (pos+2<b.size()-1)
		{
			ff=0;
			for (int k=pos+1;k<=pos+2;k++)
			if (b[k]!=b[k-pos-1])
			{
				ff=1;
				break;
			}
			if (ff) break;
			for (int k=pos+1;k<=pos+2;k++)
			{
				w[b[k]]--;
				if (w[b[k]]&1) ww++; else ww--;
			}
			ans+=query(1,0,b.size(),0,ww);
			pos+=2;
		}		
		for (int j=1;j<b.size()-2;j++)
		{
			t[b[j]]++;sss[b[j+1]]--;
			if (sss[b[j+1]]&1) ss++; else ss--;
			if (t[b[j]]&1) ts++; else ts--;
			modify2(1,0,b.size(),ts,ts,1);
			ans+=query(1,0,b.size(),0,ss);			
			for (int k=97;k<=122;k++) w[k]=sss[k];
			ww=ss;pos=j+1;l=0;
			while (pos+j+2<b.size()-1)
			{
				ff=0;l++;
				for (int k=pos+1;k<=pos+j+2;k++)
				if (b[k]!=b[k-pos-1])
				{
					ff=1;
					break;
				}
				if (ff) break;
				if (l==1)
				for (int k=pos+1;k<=pos+j+2;k++)
				{
					w[b[k]]--;
					if (w[b[k]]&1) ww++; else ww--;
				}
				if (l&1) ans+=query(1,0,b.size(),0,ww); else ans+=query(1,0,b.size(),0,ss);
				pos+=j+2;
			}
		}
		writeln(ans);
	}
	return 0;
}

