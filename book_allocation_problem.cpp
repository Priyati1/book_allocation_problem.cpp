//given n-->books
//each book contain some no of pages
//m-->students read
//ho do we get to know binary search lgega
//jha maximize ya minimize ya search kuch aaya waha
//given array sorted
//problem state:assign books in such a way that 
//the max number of pages assigned to a student is minimum
//continuous manner mein assign krni hain
#include<iostream>
using namespace std;
bool is_valid(int *arr,int book,int stu,int capacity){
	int s=1;
	int current_pages=0;
	for(int i=0;i<book;i++){
		if(current_pages+arr[i]>capacity){
			s++;
			current_pages=arr[i];
			if(s>stu){
				return false;
			}
		}
		else{
			current_pages+=arr[i];
		}
	}
	return true;
}
int book_allocation(int *arr,int book,int stu){
	int total_page=0;
	int s=0,e=0;
	for(int i=0;i<book;i++){
		total_page+=arr[i];
		s = max(s,arr[i]);
	}
	// s=arr[book-1];
	e=total_page;
	int ans;
	while(s<=e){
		int mid=(s+e)/2;
		if(is_valid(arr,book,stu,mid)){
			ans=mid;
			e=mid-1;
		}
		else{
			s=mid+1;
		}
	}
	return ans;
}
int main(){
	int t;
	int arr[1000000];
	cin>>t;
	while(t--){
		int book,stu;
		cin>>stu>>book;
		for(int i=0;i<book;i++){
			cin>>arr[i];
		}
		int x=book_allocation(arr,book,stu);
		cout<<x<<endl;
	}
	return 0;
}