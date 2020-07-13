#include "iostream"
#include "string"
#include "string.h"

using namespace std;

const int longCad=20;

struct costoPorAticulo{
    char nombreArticul[longCad + 1];
    int cantidad;
    float precio;
    float costoPorArticulos;
};

void datos(int n,costoPorAticulo cuenta[]);
void calculo(int n,costoPorAticulo cuenta []);
void mostrardatos(int n,costoPorAticulo cuenta[]);
float total(int n,costoPorAticulo cuenta[]);

int main(){
    int n;  
    cout<<"Bienvenido, ingrese el numero de productos que desea ingresar"<<endl;
    cin>>n;
    cin.ignore(100,'\n');
    costoPorAticulo cuenta[n];
    datos(n,cuenta);
    calculo (n,cuenta); 
    mostrardatos(n,cuenta);
    cout<<"El total a pagar es: "<<total(n,cuenta)<<" dolares";
    
}

void datos(int n,costoPorAticulo cuenta[]){
    string cad;    
    cout<<"Ingrese el nombre del atriculo, cantidad de dicho articulo y precio unitario de este"<<endl;
    for(int i=0; i<n; i++){ 
      cout<<"Ingrese el nombre del producto"<<endl;
      getline(cin,cad,'\n');
      strncpy(cuenta[i].nombreArticul, cad.c_str(),longCad);
      cuenta[i].nombreArticul[longCad]='\0'; 
      cout<<"Ingrese la cantidad de articulos"<<endl;
      cin>>cuenta[i].cantidad;
      cout<<"Ingrese el precio del producto"<<endl;
      cin>>cuenta[i].precio;
      cin.ignore(100,'\n');
    }
}

void calculo(int n,costoPorAticulo cuenta[]){
    for(int i=0;i<n;i++)
    {
        cuenta[i].costoPorArticulos=cuenta[i].precio*cuenta[i].cantidad;   

    }


}

void mostrardatos(int n,costoPorAticulo cuenta[]){
    for(int i=0;i<n;i++){
        cout<<endl;
        cout<<"El nombre del producto es: "<<cuenta[i].nombreArticul<<endl;
        cout<<"La cantidad del producto es: "<<cuenta[i].cantidad<<endl;
        cout<<"El precio unitario del producto es :"<<cuenta[i].precio<<" dolares"<<endl;
        cout<<"El costo total del articulo es: "<< cuenta[i].costoPorArticulos<<" dolares"<<endl<<endl;;
    }
}

float total(int n,costoPorAticulo cuenta[]){
    int i;
    float tot=0;
    for( i=0;i<n;i++){
        tot=tot+cuenta[i].costoPorArticulos;
    }

    return tot;
}

