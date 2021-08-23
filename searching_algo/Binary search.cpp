//Binary search:

#include<bits/stdc++.h>
using namespace std;
int main()
{
int a[50],n;
cout<<"Enter the number: ";
cin>>n;
for(int i=0; i<n; i++)
{
cin>>a[i];
}
for(int i=0; i<n; i++)
{
cout<<a[i]<<" ";
}
int lo=0,hi=n-1,mid,t;
cout<<"searching number:";
cin>>t;
while(lo<=hi)
{
mid=(hi+lo)/2;
if(a[mid]==t)
{
cout<<"Found"<<" "<<"Number is at"<<" "<<mid<<" "<<"index"<<endl;break;
}
else if(t>a[mid])
{
lo=mid+1;
}
else if(t<a[mid])
{
hi=mid-1;
}
}
if(lo>hi)
{
cout<<"searching index: "<<" "<<"not found";
}
return 0;
}
