#include<bits/stdc++.h>
#define ll long long
#define ri register int
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define rep(i,a,b) for(ri i=(a);i<=(b);++i)
#define REP(i,a,b) for(ri i=(a);i>=(b);--i)
using namespace std;

inline int read(){
	ri x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}

const int p=900000011,q=900000041,N=(1<<17)+10;
bool issub1=0;
ll ans;
int po[N],qo[N],hp[N],hq[N],n,num[1000],al[N],ar[N];
char s[N];
inline int add2(ri x,ri y,ri pq){x+=y;return x>=pq?x-pq:x;}
inline int sub2(ri x,ri y,ri pq){x-=y;return x<0?x+pq:x;}
void prework(){
	po[0]=1;rep(i,1,n)po[i]=po[i-1]*41ll%p;
	qo[0]=1;rep(i,1,n)qo[i]=qo[i-1]*41ll%q;
	rep(i,1,n)hp[i]=add2(hp[i-1]*41ll%p,s[i],p);
	rep(i,1,n)hq[i]=add2(hq[i-1]*41ll%q,s[i],q);
	rep(i,'a','z')num[i]=0;ri tot=0;
	rep(i,1,n){
		++num[s[i]];
		if(num[s[i]]&1)++tot;
		else --tot;
		al[i]=tot;
	}
	rep(i,'a','z')num[i]=0;tot=0;
	REP(i,n,1){
		++num[s[i]];
		if(num[s[i]]&1)++tot;
		else --tot;
		ar[i]=tot;
	}
}
bool chk(ri j,ri i){
	if(i==j) return 1;
	ri vp1=hp[i-j];
	ri vp2=sub2(hp[i],(ll)hp[j]*po[i-j]%p,p);
	//cout<<"chk "<<j<<' '<<i<<"      "<<vp1<<' '<<vp2<<endl;
	if(vp1!=vp2)return 0;
	ri vq1=hq[i-j];
	ri vq2=sub2(hq[i],(ll)hq[j]*qo[i-j]%q,q);
	return vq1==vq2;
}
namespace subtask1{
void work(ri x,ri y){
	ri val=ar[x+1];
	rep(i,1,y-1)if(al[i]<=val)++ans;
}
}
namespace subtask2{
int rt[N],cnt;
struct zxs{
	int l,r,sz;
}T[N*25];
void upd(ri p,ri l,ri r,ri x,ri &y){
	T[y=++cnt]=T[x];++T[y].sz;
	if(l==r)return;ri mid=(l+r)>>1;
	if(p<=mid)upd(p,l,mid,T[x].l,T[y].l);
	else upd(p,mid+1,r,T[x].r,T[y].r);
}
int qry(ri p,ri l,ri r,ri x,ri y){
	if(p>=r)return T[y].sz-T[x].sz;
	if(p<l)return 0;
	ri mid=(l+r)>>1;
	return qry(p,l,mid,T[x].l,T[y].l)+qry(p,mid+1,r,T[x].r,T[y].r);
}
void pre(){
	rep(i,1,n)upd(al[i],0,n,rt[i-1],rt[i]);
}
void work(ri x,ri y){
	ans+=qry(ar[x+1],0,n,rt[0],rt[y-1]);
}
void qingkong(){
	rep(i,1,cnt)T[i].l=T[i].r=T[i].sz=0;
	cnt=0;
	rep(i,1,n)rt[i]=0;
}
}

int main()
{
	//¶à²â
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	ri T=read();
	while(T--){
		scanf("%s",s+1);n=strlen(s+1);
		issub1=(n<=1000);
		prework();ans=0;
		if(!issub1)subtask2::pre();
		REP(i,n-1,2){//ababab... -> 1~i
			ri tot=0;bool ok;//if(T==0)cout<<i<<"::::"<<endl;
			for(ri j=1;j*j<=i;++j)if(i%j==0){
				if(j*j==i){
					ok=chk(j,i);
					if(ok){
						//if(T==0)cout<<j<<endl;
						if(issub1)subtask1::work(i,j);
						else subtask2::work(i,j);
					}
				}else{
					ok=chk(j,i);
					if(ok){
						//if(T==0)cout<<j<<endl;
						if(issub1)subtask1::work(i,j);
						else subtask2::work(i,j);
					}
					ok=chk(i/j,i);
					if(ok){
						//if(T==0)cout<<i/j<<endl;
						if(issub1)subtask1::work(i,i/j);
						else subtask2::work(i,i/j);
					}
				}
			}
			//if(T==0)cout<<i<<":"<<ans<<endl;
		}
		if(!issub1)subtask2::qingkong();
		printf("%lld\n",ans);
	}
	return 0;
}
