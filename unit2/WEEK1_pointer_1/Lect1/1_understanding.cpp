#include<iostream>
using namespace std;
int main(){
    int i = 10;
    int*p =&i;
     cout << "size of the pointer p :  "<< sizeof(p) << endl;
     cout << "value stored in i :" << i << endl;
     cout << "Address of i :" << &i << endl;
     cout <<"value stored in p :" <<  *p << endl;
     cout << "Address of p :" << &p << endl;//address of the pointer p

     i++;
     cout << "After increment :: " <<endl;
     cout <<"value stored in i :"   << i << endl;
     cout << "value stored in i :" << *p << endl;

    /*SEMENT 2//ABOVE CONTINUTION....*/

    int a=i;
    a++;
    cout << "a= " << a;
    cout << " new i= " << i <<endl;// wwill remain unaffected by any change made by the i bcz we'r not plaing with the store of i
    cout <<"NOTe :: a=*p and a=i are both the same things..points to same location";  


//  NOTE: HUM a=*p; likh shakte hain...YAH BHI WHI COPY KR REHE THO KOI FARK NHI HOGA...US ADDRESS PE JAAKE WHA KI VALUE COPY KRI JAATI HAIN AUR EK NEW LOCAION FOR A MEIN PUT KIYA JAATA H...CPOY-CAT KA KOI FAIDA NHI HOTA.....REAL EXAMPLE -VIKASH LOOK AT URSEFF   
}