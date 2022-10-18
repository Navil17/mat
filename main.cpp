#include"matriz.hpp"

#include<iostream>
using namespace std;

int main(){
  

    matriz m1;
    
    //matriz m2;

    //matriz producto(m1*m2);
   // cout<<"\nEl producto de la matriz es :\n"<<endl;
   // producto.imprimir();

    
    //matriz sum(m1+m2);
   // cout<<"\nLa suma de las matrices es :\n"<<endl;
   // sum.imprimir();
    double esc;
    cout<<"\nIngrese el escalar:\n";
    cin>>esc;
    matriz escalar(m1*esc);
    escalar.imprimir();

    

 
   
   
  
   

    return 0;
}