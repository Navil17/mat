#include"matriz.hpp"

#include<iostream>
using namespace std;


void matriz::establecer(int f,int c){
    if(f>0 && c>0){
        this->fila = f;
        this->columna= c;
       

       
        
    }else{
        this->fila= 0;
        this->columna= 0;
        this->ptrMat= NULL;
    }
}

//______________________________________________________________________________________________________
matriz::matriz(){
     llenar_matriz();
}
//_______________________________________________________________________________________________________
matriz::matriz(int f,int c){
    this->establecer(f , c);

}
//_______________________________________________________________________________________________________
int matriz::getComp_mat(int i,int j){
    return this->ptrMat[i][j];

}
//_______________________________________________________________________________________________________
void matriz::setComp_mat(int i,int j,int val){
    this->ptrMat[i][j]=val;

}

void matriz::llenar_matriz(){
    srand(time(NULL));
    cout<<"Ingrese el numero de filas: "<<endl;
    cin>>this->fila;
    cout<<"Ingrese el numero de columnas: "<<endl;
    cin>>this->columna;

    ptrMat=new  int*[this->fila];
    for(int i=0;i<this->fila;i++){
        ptrMat[i]=new int[this->columna];
    }

    for(int i=0;i<this->fila;i++){
        for(int j=0;j<this->columna;j++){
            ptrMat[i][j]=rand ()% 11;

        }
    }

    for(int i=0;i<this->fila;i++){
        for(int j=0;j<this->columna;j++){
           cout<<"\t"<< ptrMat[i][j];

        }
        cout<<"\n";
       
    }
}

//_________________________________________________________________________________________________________
void matriz::imprimir(){
    for(int i=0; i <this->fila; i++){
        for(int j=0; j < this->columna; j++){
            cout<<"\t"<<this->ptrMat[i][j];
        }
        cout<< endl;
    }
    cout<< "___________________________________________________________" <<endl;
}

//_________________________________________________________________________________________________________

int matriz::getfila(){
    return this->fila;
}
//_________________________________________________________________________________________________________
int matriz::getcolumna(){
    return this->columna;
}
//___________________________________________________________________________________________________________

matriz & matriz::operator*(matriz& M){ 
    if( this->columna == M.getcolumna() ){
         matriz *temp= new matriz(this->fila,M.getcolumna());
         int val;
         for (int i = 0; i < this->fila;  i++) {
           for (int j = 0; j < this->columna ; ++j) {
            val=0;
            for (int k = 0; k < columna ; ++k) {
                val += this->getComp_mat(i, k) * M.getComp_mat(k, j);
            }
            temp->setComp_mat(i,j,val);
          }
        }

        return *temp;
     }else{
        cout<< "ERROR: las matrices no se pueden multiplicar." <<endl;
        exit(EXIT_FAILURE);
    }

}
//________________________________________________________________________________________
matriz & matriz::operator+(matriz& M){
    if(this->fila==M.getfila() && this->columna==M.getcolumna()){
        matriz *temp=new matriz(this->fila,this->columna);
        int val;
        for(int i = 0;i< this->fila ; i++){
            for(int j = 0;j < this->columna; j++){
                val = this->getComp_mat(i,j)+ M.getComp_mat(i,j);
                temp->setComp_mat(i,j,val);
            }
        }
        return *temp;


    }else{
        cout<< "ERROR: las matrices no se pueden sumar." <<endl;
        exit(EXIT_FAILURE);

    }


}
//________________________________________________________________________________________________________________
matriz & matriz::operator*(double escalar){
    
    matriz *temp=new matriz(this->fila,this->columna);
    int val;
    for(int i=0 ;i<this->fila; i++){
        for(int j=0;j< this->columna;j++){
            val=escalar*this->getComp_mat(i,j);
            temp->setComp_mat(i,j,val);
        }
    }
    return *temp;


}