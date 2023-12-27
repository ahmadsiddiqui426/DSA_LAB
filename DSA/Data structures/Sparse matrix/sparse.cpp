#include<iostream>

using namespace std;

class Sparse_term{
	public:
	int row;
	int col;
	int term;
	public:
		Sparse_term(int r , int c, int t){
			row = r;
			col = c;
			term = t;
		}
};
class Sparse_matrix{
	Sparse_term *sparse[50];
	int rows;
	int cols;
	int terms;
	public:
		Sparse_matrix(int rows, int cols, int terms, int *r, int *c, int *values){
			this->rows = rows;
			this->cols = cols;
			this->terms = terms;
			for(int i=0; i<terms; i++)
				sparse[i] = new Sparse_term(r[i], c[i] , values[i]);
		}
		void printMatrix(){
			int k=0;
			for(int i=0; i<rows; i++){
				for(int j=0; j<cols; j++){
					if(i == sparse[k]->row && j == sparse[k]->col){
						cout<<sparse[k]->term<<'\t';
						k++;
					}
					else cout<<"0"<<'\t';
				}
				cout<<'\n';
			}
		}
		void transpose(){
			for(int i=0; i<terms; i++){
				int temp=sparse[i]->row;
				sparse[i]->row=sparse[i]->col;
				sparse[i]->col=temp;
			}
		}
};
int main(){
	int row1[]={1,2,4}, col1[]={0,1,3};
	int term1[]={3,4,5};
	Sparse_matrix s1(5,5,3,row1,col1,term1);
	s1.printMatrix();
	cout<<"-------------------------------------\n";
	s1.transpose();
	s1.printMatrix();
	return 0;
}