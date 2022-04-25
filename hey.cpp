#include <bits/stdc++.h>
#include <string>
#define ll  long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define base 1000000007
#define rep(i,a,n)    for(ll  i=a;i<n;i++)
#define inf LLONG_MAX
 
using namespace std;
 
void fast()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

ll  ceiling(ll  a,ll  b){
    if(a%b==0)
    return a/b;
    else
    return a/b+1;
}

struct runner{
    vector<ll>v;
};

struct page{
    vector<ll>v2;
};






int main(){
     fast();
     ll buff;
     cin>>buff;
     ll cap;
     cin>>cap;
     ll n;
     cin>>n;
     ll ar[n],arr[n];
     for(int x=0;x<n;x++){
         cin>>ar[x];
     }

     vector<struct page*>pages;
     for(int x=0;x<n;x++){
         struct page* new_page=new page;
         ll p=x;
         for(int y=p;y<min(n,p+cap);y++){
             new_page->v2.pb(ar[y]);
             x++;
         }
         pages.pb(new_page);
         x--;
     }
     
     vector<struct runner*>runners;
     ll i=0;

     for(int x=0;x<n;x++){
         struct runner* new_run=new runner;
         ll p=x;
         for(int y=p;y<min(n,p+buff*cap);y++){
              new_run->v.pb(ar[y]);
              x++;
         }
         sort(new_run->v.begin(),new_run->v.end());
         runners.pb(new_run);
         ll a=ceiling(new_run->v.size(),cap);
         ll j=0;
         while(a--){
             struct page* new_page=new page;
             for(int y=0;y<cap;y++){
                new_page->v2.pb(new_run->v[j]);
                j++;
             }
             pages[i]=new_page;
             i++;
         }
         x--;
     }

     i=0;

     while(runners.size()>1){
         vector<struct runner*>new_array;
         for(int x=0;x<runners.size();x++){
             struct runner* midd=new runner;
             ll a=runners.size();
             ll p=x;
             for(int y=p;y<min(a,p+buff-1);y++){
                     for(auto it:runners[y]->v){
                        midd->v.pb(it);
                     }
                     x++;
             }
             sort(midd->v.begin(),midd->v.end());
             a=ceiling(midd->v.size(),cap);
            ll j=0;
            while(a--){
                struct page* new_page=new page;
                for(int y=0;y<cap;y++){
                    new_page->v2.pb(midd->v[j]);
                    j++;
                }
                pages[i]=new_page;
                i++;
            }

            new_array.pb(midd);
            x--;

         }
         runners.clear();
         runners=new_array;

     }


     for(auto it:runners[0]->v){
        cout<<it<<endl;
     }

     


     

     









}