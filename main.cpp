#include <iostream>
#include "estado.h"
#include "nodo.h"
bool Recursive_Best_First_Search(nodo *);
bool RBFS(nodo *);

using namespace std;

int main()
{
    //int fichitas[FILAS * FILAS] = {1, 0, 2, 3, 6, 5, 7, 4, 8};
    int fichitas[FILAS * FILAS] = {7, 2, 4, 5, 0, 6, 8, 3, 1};
    nodo nr;
    nodo *pnr;
    nr.e.setFichas(fichitas);
    pnr=nr.autoApuntador();
    Recursive_Best_First_Search(pnr);

    /*
    //Pruebas de la función sucesor. Borren antes de crear el programa.
    n.funcionSucesor();
    n.hijos[0] -> funcionSucesor();
    n.hijos[0]->hijos[2]->funcionSucesor();

    n.hijos[0]->hijos[2]->hijos[0] -> imprimirRecorrido();
    n.hijos[0]->hijos[2]->hijos[1] -> imprimirRecorrido();
    */
    return 0;
}

bool Recursive_Best_First_Search(nodo *na){
    if (RBFS(na)==false){
        cout<<"No tiene solucion\n";
        return false;
    }else{
        return true;
    }
};

bool RBFS(nodo *n){
    //CREACIÓN DE LA FRONTERA Y UN APUNTADOR A LA FRONTERA
    frontera fronter;
    frontera *pfrontera=NULL;
    pfrontera=fronter.autoApuntadorFront();
    pfrontera->nuevoElemento(n);
    nodo *na;
        do{
            cout<<"-----------------------------------------------------"<<endl;
            //cout<<"\n\t\tNIVEL DEL ARBOL: "<<nivel++<<endl;
            //int num_Nodo_Frontera=pfrontera->nEf;
            //cout<<"NUMERO DE ELEMENTOS EN FRONTERA: "<<num_Nodo_Frontera<<endl;
            //for(int i = 0; i<num_Nodo_Frontera;i++){                                      //PARA CADA ELEMENTO DE LA FRONTERA
                int num_Nodo_Frontera=pfrontera->nEf;
                cout<<"NUMERO DE ELEMETOS EN FRONTERA: "<<num_Nodo_Frontera<<endl;
                cout<<"EXTRAYENDO EL NODO CON MEJOR FUNCION EVALUACION DE LA FRONTERA"<<endl;
                na=pfrontera->extraerMejorF();                                                   // EXTRAER EL PRIMER ELEMENTO DE LA FRONTERA
                na->e.imprimirEstado();
                if((na->e.testObjetivo()) ){                                 //TEST OBJETIVO DEL ESTADO DEL NODO ESTRAIDO
                        cout<<"\n\nEXISTE UNA SOLUCION: \nSE DESCRIBE LOS PASOS A REALIZAR: "<<endl;
                        na->imprimirRecorrido();                                          //SI HALLA LA SOLUCION IMPRIME
                        //pfrontera->~Frontera();                                       //DESTRUYE LOS OBJETOS DE TIPO FRONTERA
                        return true;                                                    //RETORNA 1 SI HALLA LA SOLUCIÓN
                        break;
                }else{                                                      //SI EL ESTADO NO ES EL OBJETIVO HACER ...
                    //punterobmc=na->e.apuntadorEstado();                         //CREAMOS UN PUNTERO AL ESTADO DEL NODO EXTRAIDO DE LA FRONTERA
                    //cout<<"ESTADO VISITADO: "<<endl;
                    //punterobmc->print();
                    //explorad->addEstadoVisitado(punterobmc);                    //AÑADIMOS EL ESTADO EXTRAIDO A LA LISTA DE ESTADOS VISITADOS
                    int num_Hijos_Creados=na->funcionSucesor();
                    cout<<"EL NUMERO DE HIJOS POSIBLES QUE TIENE ES: "<<num_Hijos_Creados<<endl;
                    //cout<<"HIJOS DEL NODO "<<i<<" EN FRONTERA: "<<na->fR<<endl;
                    for(int i=0; i<na->factorRamificacion;i++){
                        cout<<"Intenta ingresar el hijo: "<<i<<" en frontera\n";
                        na->hijos[i]->e.imprimirEstado();
                        cout<<"Fn()= "<<na->hijos[i]->funcionEvaluacion()<<endl;
                        pfrontera->nuevoElemento(na->hijos[i]);                                //PARA CADA HIJO DEL NODO EXTRAIDO HACER
                    }
                    pfrontera->eliminarElemento(na);             //COMO EL NODO FUE EXTRAIDO DE LA FRONTERA, LO ELIMINAMOS
                }
                //cout<<"INGRESARON EN FRONTERA"<<endl;
            //}
            //break;
        }while(pfrontera->fronteraVacia()==false);
        if(pfrontera->fronteraVacia()){
            return false;
        }

    //CREACIÓN DEL ARRAY DE ESTADOS VISITADOS Y UN PUNTERO AL ARRAY
    //Explorado expl;
    //Explorado *explorad;
    //explorad=expl.autoApuntExpl();

    //CREACION DE UN PUNTERO DE TIPO ESTADO
    //Estado *punterobmc;

    //CICLO PARA QUE EXPLORE EL NODO ACORDE A LOS ELEMENTOS DE LA FRONTERA

    return 0;
};

