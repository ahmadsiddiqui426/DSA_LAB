#include <iostream>
using namespace std;

int* sort(int *arr, int len)
{
	for(int j = 0;j<len-1; j++){
		if(arr[j]>arr[j+1]){
			int temp = arr[j];
			arr[j] = arr[j+1];
			arr[j+1] = temp;
			j=-1;
		}
	}
	return arr;
}
int* squaring(int *arr , int len)
{
	int k=0;
	for (int i =0;arr[i]<0;i++)
		k++;
	int i=k-1 , j=k ,ind=0 , res[len];
	while(i>=0 && j<len){
		if(arr[i]*arr[i]<arr[j]*arr[j]){
			res[ind++]=arr[i]*arr[i];
			i--;
		}
		else{
			res[ind++]=arr[j]*arr[j];
			j++;
		}
	}
	while(i>=0){
			res[ind++]=arr[i]*arr[i];
			i--;
		}
	while(j<len){
		res[ind++]=arr[j]*arr[j];
		j++;
	}
	for (int i =0;i<len;i++)
		arr[i]=res[i];
	return arr;
}
void index(int *arr, int num,int len)
{
	int low = 0, high = len-1;
	int mid;
	if (arr[high] < num){
	cout<<"Your number should be at index "<<high+1<<" !";
	return;
	}
	while (low <= high){
		mid = (low+high)/2;
		if(arr[mid] == num){
			cout<<"Your number is at index "<<mid<<" !";
			return;
		}
		else if(arr[mid] > num)
			high = mid-1;
		else low = mid+1;
	}
	cout<<"Your number should be at index "<<mid<<" !";
}
void rotate(int *arr, int times , int len)
{
	int k = len- times%len;
	int res[len] ,i,j=0;
	for(i=k ; i<=len-1 ; i++){
		res[j++]=arr[i];
	}
	for(i=0 ; i<k ; i++)
		res[j++]=arr[i];
	for(int i =0;i<len;i++)
    	cout<<res[i]<<' ';
}
void reverse(string s)
{
	string r;
	int j=0;
	for(int i = s.length()-1;i>=0;i--)
		r[j++]=s[i];
	for(int i =0;i<s.length();i++)
    	cout<<r[i];
}
float median(int *a, int len1,int *b, int len2){
	int len = len1+len2;
	int res[len];
	for(int i=0;i<len1;i++)
		res[i]=a[i];
	int j=0;
	for(int i=len1;i<len;i++)
		res[i]=b[j++];
	for(int i=0;i<len-1;i++)
		if(res[i]>res[i+1]){
			int temp = res[i];
			res[i] = res[i+1];
			res[i+1] = temp;
			i=-1;
		}
	cout<<"\nMerged Array: ";
	for(int i=0;i<len;i++)
		cout<<res[i]<<' ';
	cout<<'\n';
	if(len%2 == 0){
		float num1= res[len/2];
		float num2= res[(len/2)-1];
		cout<<"\nMedian: ";
		return (num1+num2)/2;
	}
	else{
		cout<<"\nMedian: ";
		return res[len]/2;
	}
}
int MissingNo(int *a,int len){
	int sum = 0, total=0;
	int small = a[0],large = a[0];
	for(int i=1;i<len;i++){
		if(a[i]<small)	small = a[i];
		if(a[i]>large)	large = a[i];
	}
	for(int i=0;i<len;i++){
		sum+=a[i];
	}
	for(int i=small;i<=large;i++){
		total+=i;
	}
	return total-sum;
}
struct Node {
	int val;
	Node *next;
	Node(int x = 0, Node *Nnext = nullptr) {
		val = x;
		next = Nnext;
	}
};
class list{
	public:
	Node *head;
	Node *tail;
	list(){
		head = tail = 0;
	}
	bool isEmpty(){
		if(head == 0)	return true;
		return false;
	}
	void addToHead(int e){
		head = new Node(e,head);
		if(tail == 0)	tail = head;
	}
	void addToTail(int e){
		if(tail != 0){
			tail->next = new Node(e);
			tail = tail->next;
		}
		else head = tail = new Node(e);
	}
	int middle(){
		Node *p1,*p2;
		for(p1 = head,p2 = head; p1->next!=tail->next;p1 = p1->next->next,p2=p2->next){
			continue;
		}
		return p2->val;
	}
	void deleteFromEnd(int num){
//		list *temp = this;
//		temp->show();
//
		Node *temp,*t;
		int len=0,i;
		for(temp = head; temp!=tail->next;temp = temp->next)
			len++;
		for(i=1,t=head;i<=len-num;i++,t = t->next)
			if(i==len-num){
				temp= t->next;
				t->next=t->next->next;
				delete temp;
			}
	}
	list* reverseList(){
		Node *temp;
		list *t;
		for(temp=head;temp!=tail->next;temp=temp->next){
			t->addToHead(temp->val);
		}
		return t;
	}
	list mergeLists(list l){
		Node *t1=head,*t2=l.head;
		list res;
		while(t1!=tail->next && t2!=l.tail->next){
			if(t1->val < t2->val){
				res.addToTail(t1->val);
				t1=t1->next;
			}
			else{
				res.addToTail(t2->val);
				t2=t2->next;
			}
		}
		while(t1!=tail->next){
			res.addToTail(t1->val);
			t1=t1->next;
		}
		while(t2!=l.tail->next){
			res.addToTail(t2->val);
			t2=t2->next;
		}
		return res;
	}
	void show(){
		Node *temp , *a;
		for(temp = head; temp!=tail->next;temp = temp->next)
			cout<<temp->val<<' ';
	}
};

int main(){
//	int a[6]={1,5,3,2,9,7};
//	int len = sizeof(a)/sizeof(a[0]);
//	sort(a,len);
//    index(a,4,6);
//    cout<<"\nSquaring: ";
//    int b[]={-5,-3,-1,0,2,4,7};
//	int len2=sizeof(b)/sizeof(b[0]);
//	int *c=squaring(b,len2);
//	for (int i =0;i<len2;i++)
//		cout<<c[i]<<' ';
//    cout<<"\nRotating: ";
//    int d[]= {1,2,3,4,5,6,7};
//    rotate(d,9,7);
//    cout<<"\nReverse String: ";
//    string s="Maedah Nazar";
//    reverse(s);
//    cout<<"\nList:\n";
//    list l;
//    l.addToHead(10);
//    l.addToTail(20);
//    l.addToTail(30);
//    l.addToTail(40);
//    l.addToTail(50);
//    l.addToTail(60);
//    l.addToTail(70);
//    l.show();
//    cout<<"\nMiddle node: "<<l.middle();
//    cout<<"\nReverse List: ";
//    l.reverseList()->show();
//    list l1;
//    l1.addToHead(3);
//    l1.addToTail(5);
//    l1.addToTail(8);
//    cout<<"\nList 1: ";
//    l1.show();
//    list l2;
//    l2.addToHead(2);
//    l2.addToTail(7);
//    l2.addToTail(8);
//    l2.addToTail(9);
//    cout<<"\nList 2: ";
//    l2.show();
//    cout<<"\nAfter Merging: ";
//    l1.mergeLists(l2).show();
//	int e[]={1,4};
//	int l1 = sizeof(e)/sizeof(e[0]);
//	cout<<"\nFirst Array: ";
//	for (int i =0;i<l1;i++)
//		cout<<e[i]<<' ';
//	cout<<'\n';
//	int f[]={2,3};
//	int l2 = sizeof(f)/sizeof(f[0]);
//	cout<<"\nSecond Array: ";
//	for (int i =0;i<l2;i++)
//		cout<<f[i]<<' ';
//	cout<<'\n';
//	cout<<median(e,l1,f,l2);
	int g[]={1,3,0};
	cout<<MissingNo(g,3);
	return 0;
}
