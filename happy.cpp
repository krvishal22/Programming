#include <bits/stdc++.h>
using namespace std;
int findSumDigit(int n)
{
    int sum=0,rem;
    while(n)
    {
        rem=n%10;
        n=n/10;
        sum+=(rem*rem);
    }
    return sum;
}
int main()
{
    int flag=0,n,temp;
    unordered_set <int> s;
    cout<<"Enter the number\n";
    cin>>n;
    temp=findSumDigit(n);
    if(temp==1)
        cout<<"Yes\n";
    else
    {
        s.insert(temp);
        while(true)
        {
            temp=findSumDigit(temp);
            if(temp==1)
            {
                flag=1;
                break;
            }
            if(s.find(temp)==s.end())
                s.insert(temp);
            else
            {
                flag=2;
                break;
            }  
        }
        if(flag==1)
            cout<<"yes\n";
        if(flag==2)
            cout<<"Not possible\n";
    }
}
