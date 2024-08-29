#include<iostream> 
using namespace std;
int main(){
    int  i = 65;
    char c = i;//typecasting the variables
    cout << "value of i is: "<< i <<endl;
    cout << " char_typecasted value of i is: "<< c <<endl;

    int* p = &i;
    //char* pc = p;// tryng pointer conversion --w rarning as implict conversion hain 

    char* pc  =(char*)p;//explit conversion
    cout <<"explit conversion"<<endl;

    cout << "derefrencing p: "<<*p<< endl;
    cout<< "derefrencing pc: "<< *pc<< endl;
    cout<<"derefrencing pc+1: "<<*(pc+1)<< endl;
    cout<<"derefrencing pc+1: "<< *(pc+2)<< endl;
    cout<<"derefrencing pc+1: "<< *(pc+3)<< endl;



    cout <<"int pointer ko cout kra(cout p): "<< p << endl;
    cout <<"char  pointer ko cout kra(cout pc): "<< pc << endl;
    
}