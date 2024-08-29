#include<iostream>
using namespace std;
int main(){
  /* 
            //POINTER ARITHMETIC
    double d  = 102.45;
    double* dp =&d;
    cout<<"old dp: "<<dp<<endl;
    dp++;
    cout <<"new dp: "<<dp<<endl;
    */

   /*         //ARRAY AND POINTER
    //  NOTE::  a[i] == i[a] == *(a+i)

//last way in (above) can be used to iterate over the array elements     
    //differences btw  'a' and norma pointer p
      
        int a[10];
        cout << a <<endl;//array_name ' a 'give the address of a[0]==&a[0]
        cout << &a[0] <<endl;

        a[0]=5;
        a[1]=10;
        cout << *a<< endl;
        cout << *(a+1)<< endl;//can be used to iterate the elements

        int *p=&a[0];//a
        cout << a <<endl;
        cout << p <<endl;

        cout << sizeof(p)<<endl;
        cout << sizeof(a)<<endl;


*/


      /*      //CHARACTER ARRAY AND  HARACTER POINTER::- behaves different and we are not going the print the address any how here...
                                        // THE THING IS THAT ...CALLING EVEN  like cout << b; will give the character until it encour the null character
        int a[] ={1,2,3,4};
        char b[]="abc";
        cout << a << endl;//calling int array name will give the address of a[0] 
        cout << b<< endl;//but here as regular it will print all character unless encounter the null character

        char *c = &b[0];
        cout << c << endl; //here, we have store the address of b[0] in pointer c ... but this also give the element unless \0 encounter

        char c1= 'a';
        char *pc = &c1;
        cout << pc; 
        
*/


        // FUNCTION AND POINTERS

        //exampl- swap 
       /* void swap(int *a,int *b){
            int t;
            t=*a;
            *a=*b;
            *b=t;
        }  
        int main()
        {
            int t;
            cin>>t;
            for(int i=0;i<t;i++)
            {
                int a,b;
                cin>>a>>b;
                swap(&a , &b);
                cout<<a<<" "<<b;
                cout<<endl;
            }
        }
        }
        */

       //DOUBLE POINTER

       int i =410;
       int *p = &i;
       int **p2=&p;

       cout <<"<call p2> p2 storing addres of p: "<< p2<<endl;
       cout <<"address of p(by &p): " << &p<<endl;
        cout << endl;
       cout <<"calling  p(add. of i): " <<p <<endl;
       cout << "address of i by &i: "<< &i <<endl;
       cout<<"derefrencing the p2..(gives the sotred value in  p): "<< *p2<< endl;

       cout << i<<endl;
       cout << *p<<endl;
       cout << **p2 <<endl;
}