#include <iostream>
#include <algorithm>
#include "estado.h"
#include "nodo.h"
void Recursive_Best_First_Search(nodo *);
int RBFS(nodo *,int);

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
    return 0;
}

void Recursive_Best_First_Search(nodo *na){
    if (RBFS(na,50)==-1){
        cout<<"No tiene solucion\n";
    }
};

int RBFS(nodo *n, int limite){
    cout<<"------------------------------------------\n";
    cout<<"Valor limite es: "<<limite<<endl;
    //bool bandera=false;
    //CREACIÓN DE LA FRONTERA Y UN APUNTADOR A LA FRONTERA
    if(n->e.testObjetivo()){
        cout<<"\n\nEXISTE UNA SOLUCION: \nSE DESCRIBE LOS PASOS A REALIZAR: \n"<<endl;
        n->imprimirRecorrido();
        return 0;
    }else{
        frontera succesor;
        frontera *psuccesor=succesor.autoApuntadorFront();
        n->funcionSucesor();
        cout<<"EL NUMERO DE HIJOS POSIBLES QUE TIENE ES: "<<n->factorRamificacion<<endl;
        for(int i=0; i<n->factorRamificacion;i++){
            cout<<"Intenta ingresar el hijo: "<<i<<" en frontera\n";
            n->hijos[i]->e.imprimirEstado();
            cout<<"Fn()= "<<n->hijos[i]->funcionEvaluacion()<<endl;
            psuccesor->nuevoElemento(n->hijos[i]);                                //PARA CADA HIJO DEL NODO EXTRAIDO HACER
        }
        do{
            nodo* nodoBest=psuccesor->extraerMejorF();
            cout<<"EL MEJOR NODO SIGUIENTE ES: \n";
            nodoBest->e.imprimirEstado();
            cout<<"Fn()= "<<nodoBest->funcionEvaluacion()<<endl;
            psuccesor->eliminarElemento(nodoBest);
            if(nodoBest->funcionEvaluacion()>limite){
                return nodoBest->funcionEvaluacion();
            }else{
                int alternative=psuccesor->extraerSegundoMejorF()->funcionEvaluacion();
                int best = nodoBest->funcionEvaluacion();
                int result=RBFS(nodoBest,std::min(best,alternative));
                if(result==0){
                    return 0;
                }else if(result==-1){
                    return -1;
                }else{
                    limite=result;
                }
            }
        }while(psuccesor->fronteraVacia()==false);

        if(psuccesor->fronteraVacia()){
            return -1;
        }
    }
    return -1;
};

