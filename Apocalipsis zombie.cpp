#include <iostream>
using namespace std;
int main()
{
    cout << "//Escoge el numeral de la opcion que deseas escoger//" << endl;
    cout << " " << endl;
    cout << "Estas viendo noticias y te enteras de un virus zombie y te percatas que ya llego a tu ciudad" << endl;
    cout << " " << endl;
    cout << "Que harias? " << endl;
    int opcion;
    
    cout << "1. Buscas un refugio" << endl;
    cout << "2. Te robas toda la comida de un super mercado" << endl;
    cout << "3. Vas a buscar a tu familia" << endl;
    cout << "4. Buscas a los primeros zombies para matarlos" << endl;
    cout << "5. LLoras en tu cuarto" << endl;
    cin >> opcion;
    if (opcion == 1){
        cout << "Sales y despues de mucha busqueda te quedas sin gasolina... y llega una horda de zombies" << endl;
        cout << " " << endl;
        cout << "Te moriste, no pudiste escapar de nadie";
    }
    else if (opcion == 2){
        cout << "LLegas al supermercado y cuando llegas ya no hay nada, todo se lo llevaron" << endl;
        cout << " " << endl;
        cout << "Has fallado y te mueres de hambre" << endl;
    }
    else if (opcion == 3){
        cout << "LLegas con tu familia y tienen comida hasta para 5 años de supervivencia" << endl;
        cout << " " << endl;
        cout << "Te salvaste y pasas el apocalipsis luego de que encuentren la cura." << endl;
    }
    else if (opcion == 4){
        cout << "Para que buscaste a los zombies??? Te comen vivo" << endl;
        cout << " " << endl;
        cout << "Te conviertes en zombie y te rechaza la que te gustaba" << endl;
    }
    else if (opcion == 5){
        cout << "Te quedas llorando hasta el amanecer..." << endl;
        cout << " " << endl;
        cout << "Sales con vida, todo era parte de un experimento social." << endl;
    }
    else {
        cout << "no es una opcion valida bro";
    }
}