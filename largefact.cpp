#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[5000]={0};
		arr[0]=1;
		int len=1;
		for(int i=2;i<=n;i++)
		{	arr[0]=arr[0]*i;
			int temp=arr[0]/10;
			arr[0]=arr[0]%10;
//			cout<<"temp and arr0  "<<temp<<"  "<<arr[0]<<endl;
			int j=1;
			for(;j<len;)
			{	
				arr[j]=arr[j]*i+temp;
				temp=arr[j]/10;
				arr[j]=arr[j]%10;
				
//				cout<<"j   temp and arr0  "<<j<<"  "<<temp<<"  "<<arr[j]<<endl;
				j++;
			}
			while(temp)
			{	
				arr[j]=temp%10;
				j++;
				len++;
				temp=temp/10;
			}
		}
//		cout<<len<<endl;
		while(len--)
		{
			cout<<arr[len];
//			len--;
		}
		cout<<endl;
		
	}
}
