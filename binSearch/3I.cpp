#include <iostream> 
using namespace std; 

int under(int arr[], int x, int n) 
{ 
	int left=0, right=n-1, ans=-1; 
	while (left <= right) { 
		int middle=(left+right) / 2; 
		if (arr[middle] > x) 
			right=middle-1; 
		else if (arr[middle] < x) 
			left=middle+1;  
		else { 
			ans=middle; 
			right=middle-1; 
		} 
	} 
	return ans; 
} 


int upper(int arr[], int x, int n) 
{ 
	int left=0, right=n-1, ans=-1; 
	while (left <= right) { 
		
		int middle=(left+right) / 2; 
		if (arr[middle] > x) 
			right=middle-1; 
		else if (arr[middle] < x) 
			left=middle+1; 
		else { 
			ans=middle; 
			left=middle+1; 
		} 
	} 
	return ans; 
} 

int main() 
{ 
	int n,m;
	cin>>n>>m;
	int a[n], b[m];	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int j=0;j<m;j++){
		cin>>b[j];
	}
	for( int j=0;j<m;j++){
		if(under(a,b[j],n)+upper(a,b[j],n)!=-2 )
		cout<<under(a,b[j],n)+1 <<" "<<upper(a,b[j],n)+1<<endl;
		else cout<<0;
		
	}
	return 0; 
} 
