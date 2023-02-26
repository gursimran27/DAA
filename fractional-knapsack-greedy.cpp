#include<bits/stdc++.h>
using namespace std;
# define rep(i,a,b) for(i=a;i<b;i++)
 

 bool comparator(pair<int,int>p1,pair<int,int>p2)
 {
    double a=(double)p1.first/p1.second;
    double b=(double)p2.first/p2.second;
    // p1.first/p1.second might be 0 so we are converting p1.first to double by doing (double)p1.second
    
    return a>b;
 }

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>a(n);

    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }

    int w;
    // knapsnack capacity
    cin>>w;

    // sort according to value/weight

    sort(a.begin(),a.end(),comparator);

    double ans=0;

    for(int i=0;i<n;i++)
    {
        if(w>=a[i].second)
        {
            ans+=a[i].first;
            w-=a[i].second;

            continue;
       }

    ans+=((double)w/a[i].second)*a[i].first;

            //or 
    // double vw=((double)w/a[i].second);
    // ans+=(double)(vw*(a[i].first));
       w=0;
       break;
    }

    cout<<ans;
return 0;
}