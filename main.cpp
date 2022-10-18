#include"matriz.hpp"

#include<iostream>
using namespace std;

int main(){
  

    matriz m1;
    
    matriz m2;

    //matriz producto(m1*m2);
   // cout<<"\nEl producto de la matriz es :\n"<<endl;
   // producto.imprimir();

    cout<<"\nLa suma de las matrices es :\n"<<endl;
    matriz sum(m1+m2);
   
    sum.imprimir();

    

 
   
   
  
   

    return 0;
}