#ifndef MATRIZ_H
#define MATRIZ_H

class matriz{

    public:
        matriz();
        matriz(int,int);
        void llenar_matriz();
        int getfila();
        int getcolumna();
        int getComp_mat(int,int);
        void setComp_mat(int,int,int);
        void imprimir();
        matriz & operator*( matriz & );
        matriz & operator+( matriz & );

        


    private:
       int fila;
       int columna;
       int**ptrMat;
       void establecer(int,int);
       
       

};

#endif