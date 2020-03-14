#include<iostream>
#define n 3
using namespace std;

void display(int arr[3][3])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    int a[9]={20,21,22,12,02,01,0,10,11};
    int curr1=a[0];
    int curr2=a[0];
    int value1=1,value2=1,temp1,temp2;
    int arr[n][n],flag=1,num,temp=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            arr[i][j]=0;
    }
    arr[2][0]=12;
    arr[1][1]=9;
    display(arr);
    while(flag)
    {
        temp=temp%2;
        cout<<"Enter the value for player "<<temp+1<<"\n";
        cin>>num;
        if(num<1 || num>3)
        {
            cout<<"Enter correct value\n";
            continue;
        }
        if(temp+1==1)
        {
            if(value1+num<10)
                value1+=num;
            if(value1==9)
            {
                cout<<"Player1 wins\n";
                arr[curr1/10][curr1%10]=0;
                arr[1][1]=1;
                flag=0;
                display(arr);
                break;
            } 
            else if(value1<10)
            {
                if(curr2==a[0])
                    arr[curr1/10][curr1%10]=2;
                else
                    arr[curr1/10][curr1%10]=0;
                curr1=a[value1-1];
                if(curr1==curr2)
                {
                    value2=1;
                    arr[2][0]=2;
                    curr2=a[0];
                }     
                arr[curr1/10][curr1%10]=1;
                
            }
            display(arr); 
        }
        
        else
        {
            if(value2+num<10)
                value2+=num;
            if(value2==9)
            {
                cout<<"Player2 wins\n";
                arr[curr2/10][curr2%10]=0;
                arr[1][1]=2;
                flag=0;
                display(arr);
                break;
            }
            else if(value2<10)
            {
                if(curr1==a[0])
                    arr[curr2/10][curr2%10]=2;
                else
                    arr[curr2/10][curr2%10]=0;
                curr2=a[value2-1];
                if(curr1==curr2)
                {
                    arr[2][0]=1;
                    value1=1;
                    curr1=a[0];
                }   
                arr[curr2/10][curr2%10]=2;
            }
            display(arr);
        }
        
        temp++;
        
    }

    return 0;
}
