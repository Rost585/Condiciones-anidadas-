#include <iostream>
using namespace std;
int main(){
    int opcion;
    cout<<"¿Que haces si te ganas la loteria?"<<endl;
    cout<<"1. Me compro una casa"<<endl;
    cout<<"2. Divido el dinero para darle cierta parte a mis padres"<<endl;
    cout<<"3. Me voy de viaje"<<endl;
    cout<<"4. Compro un carro"<<endl;
    cout<<"5. Abro una cuenta que me genere intereses por la cantidad de dinero"<<endl;
    cin>>opcion;
    if(opcion==1){
        cout<<"Cotizar una buena opcion que cuente con los espacios necesarios segun mis necesidades"<<endl;
        cout<<"Despues de la busqueda comprar la casa"<<endl;
    } else if(opcion==2){
        cout<<"Hacer un calculo de cual ser la cantidad que les compartiras a tus padres"<<endl;
        cout<<"Seguidamente entregarle la cantidad a tus papas"<<endl;
    }
    else if(opcion==3){
        cout<<"Cotizar posibles lugares que sean de tu interes"<<endl;
        cout<<"Adquirir boletos, rentar hospedaje y verificar demas costospara cubrir gastos basicos"<<endl;
    }else if(opcion==4){
    cout<<"Cotizar en distintas sucursales los diferentes tipos de auto"<<endl;
    cout<<"Comprar el auto que mas te convence"<<endl;
    }else if(opcion==5){
    cout<<"Buscar coperativas y bancos"<<endl;
    cout<<"Hacer las gestiones correspondientes para obtener la cuenta "<<endl;
    }
}