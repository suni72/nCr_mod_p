#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define vl vector<ll>
#define vi vector<int>
#define pi pair<int,int>
#define pl pair<ll,ll>
#define vpl vector<pl>
#define vpi vector<pi>
#define ml map<ll,ll>
#define mi map<int,int>
#define m(a,b) map<a,b>
#define YesNo(f) if(f){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;continue;}
#define setval(a,val) memset(a,val,sizeof(a)) 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define mxn 1000005
ll fact[mxn];
ll invfact[mxn];
ll inv[mxn];
void factCal(ll md){
	fact[0]=1;
	for(int i=1;i<mxn;i++){
		fact[i]=fact[i-1]*i;
		fact[i]%=md;
	}
}
void invCal(ll md){
	inv[0]=inv[1]=1;
	for(int i=2;i<mxn;i++){
		inv[i]=(-(md/i)*inv[md%i])%md;
		inv[i]+=md;
		inv[i]%=md;
	}
}
void invfactCal(ll md){
	invfact[0]=invfact[1]=inv[1];
	for(int i=2;i<mxn;i++){
		invfact[i]=invfact[i-1]*inv[i];
		invfact[i]%=md;
	}
}
void Callfunction(ll mod){
	factCal(mod);
	invCal(mod);
	invfactCal(mod);
}
ll nCrCalculate(ll n,ll r,ll mod){
	ll x=fact[n];
	x*=invfact[r];
	x%=mod;
	x*=invfact[n-r];
	return x%mod;
}
int main()
{
	fastIO;
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int t=1;
	// cin>>t;
	while(t--){
		int n,r,md;
		cin>>n>>r>>md;
		Callfunction(md);
		ll ncr=nCrCalculate(n,r,md);
		cout<<ncr<<endl;
	}

return 0;
}