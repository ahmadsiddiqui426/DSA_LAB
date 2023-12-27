#include <iostream>

using namespace std;


class Tree {
    int *array;
    int size;
    int noofnodes;
public:
	Tree(){	}
	Tree(int size)
	{
		this->size = 1;
		for(int i=0;i<size; i++)
			this->size*=2;
		this->size--;
        noofnodes=0;
		//this->size = size;
        array = new int[this->size];
        for(int i =0 ;i< this->size ;i++)
   		   array[i] = -99999;
	}
   
   void insert( int value)
   {
   	if(noofnodes < size)
   		array[noofnodes++] = value;
   	else cout<<"Cannot add node. Binary tree is full.\n";
   }
   
   
   int deletion( int index)
   {
   	if(! noofnodes == 0){
	    int temp = array[index];
	    for(int i=index; i<size-1; i++)
	   		array[i] = array[i+1];
	    noofnodes--;
	   	return temp;
	   }
	else{
		cout<<"Cannot delete node.\n";
		return 0;
	}
   }
   
   void print()
   {
   	for(int i=0 ; i<noofnodes ; i++)
   	{
   		cout << array[i] << ' ';
	 }
   }
    
    
   void convert(int *a , int s)
   {
    	int i;
   	    for(i=0 ; i< s ; i++)
      {
   	       insert(a[i]);
      }
   }
//   void parent(Tree *t, int val){
//   	int j;
//   	if(val == array[0]){
//   		cout<<"It is root node\n";
//   		return;
//	   }
//		for(int i=0; i<t->noofnodes; i++){
//			if(array[i] == val){
//				temp = i;
//			}
//		}
//		while(i != 0){
//			cout<<arr[]
//		}
//   }
   void preorderTraverse(int node=1){
		if(node>size) 	return;
		if (array[node]==0) return;
		cout << array[node] << ' ';
		preorderTraverse(node*2);
		preorderTraverse(node*2+1);

		return ;
	}
	void postorderTraverse(int node=1){
		if(node>size) 	return;
		if (array[node]==0) return;
		postorderTraverse(node*2);
		postorderTraverse(node*2+1);
		cout << array[node] << ' ';

		return ;
	}
};
int main()
{
	int size;
	cout<<"Enter size of Tree: ";
	cin>>size;
    Tree t(size);
    t.insert(2);
    t.insert(3);
    t.insert(4);
    t.insert(6);
    t.insert(7);
    t.insert(8);
    t.insert(9);
    t.print();
    cout << endl;
    t.insert(67);
    t.print();
    cout << endl;
    cout<<"After deletion:\n";
    cout << t.deletion(5);
    cout<<endl;
    t.print();
    int b[] = {3 ,6 ,8 ,9 ,4};
    size = sizeof(b)/sizeof(b[0]);
    Tree t2(size);
    t2.convert(b ,size);
    cout << endl;
    t2.print();
    cout<<endl;
    t.preorderTraverse();
    return 0;
}