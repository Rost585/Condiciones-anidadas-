#include <iostream>
using namespace std;
int main(){
    int opcion;

cout<<"¿Que haces si te quedas sin gasolina en plena carretera?"<<endl;
cout<<"1. Llamar al seguro"<<endl;
cout<<"2. Llamar a tus padres"<<endl;
cout<<"3. Buscar ayuda con personas cercanas"<<endl;
cout<<"4. Dejar el auto y buscar gasolina "<<endl;
cout<<"5. Llamar a un amigo"<<endl;
cout<<"Que opcion eliges?"<<endl;
cin>>opcion;

if(opcion==1){
    cout<<"Esperar a que lleguen y tratar de no estra dentro del auto para evitar accidentes"<<endl;
}
if (opcion==2){
    cout<<"Esperar a que lleguen con gasolina"<<endl;    
}
if(opcion==3){
    cout<<"Buscar personas que se vea que pueden ayudar o preguntar en lugares cercanos donde hay una gasolinera"<<endl;

}
if(opcion==4){
    cout<<"Buscar un recipiente e ir a la gasolinera cercana"<<endl;
}
if(opcion==5){
    cout<<"Esperar la respuesta del amigo y decirle que llegue con una cierta cantidad de gasolina segun se necesite"<<endl;

}
}
