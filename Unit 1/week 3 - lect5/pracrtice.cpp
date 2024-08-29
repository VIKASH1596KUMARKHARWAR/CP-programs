#include<iostream>
using namespace std;


int main(){

       /*  Read input as specified in the question.
	* Print output as specified in the question.
	*/
		int n;
		cin >> n;
		int row =1;
		while (row <=n ){
			 int space=1;
			 while( space <= n-row ){
				 cout << " ";
				 space++;
			 }
			 int j = 1;
			 while(j <= row){
				 cout <<  "*";
				 j++;
			 }
            j = row - 1;
        while(j >=1){
            cout << "*";
            j = j - 1;}
			 row++;
			 cout << endl; 
		}
        return 0;
}


