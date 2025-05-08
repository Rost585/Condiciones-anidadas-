#include <iostream>
using namespace std;
int main()
{
    cout << "//Escoge el numeral de la opcion que deseas escoger//" << endl;
    cout << " " << endl;
    cout << "Estas copiando en un examen de mate... y derepente aparece la ingeniera detras tuyo, Que harias?" << endl;
    int opcion;
    
    cout << "1. Escondes el chivo" << endl;
    cout << "2. Te haces el loco" << endl;
    cout << "3. Tiras el chivo" << endl;
    cout << "4. Le pegas a la ingeniera" << endl;
    cout << "5. Admites tu error" << endl;
    cin >> opcion;
    if (opcion == 1){
        cout << "Has escondido el chivo... la ingeniera no nota nada raro y se va" << endl;
        cout << " " << endl;
        cout << "Ganaste, sacas 10/10 en el parcial.";
    }
    else if (opcion == 2){
        cout << "Te has hecho el loco, la ingeniera lo nota y te revisa ante todos" << endl;
        cout << " " << endl;
        cout << "Has fallado y la que te gusta te rechaza." << endl;
    }
    else if (opcion == 3){
        cout << "Tiraste el chivo... LE CAYO A TU AMIGO EN EL ESCRITORIO!!" << endl;
        cout << " " << endl;
        cout << "Pasaste el parcial bien, pero a tu amigo le anulan el examen." << endl;
    }
    else if (opcion == 4){
        cout << "LE PEGASTE A LA INGE???" << endl;
        cout << " " << endl;
        cout << "Has fallado y ademas te has ido a la carcel de gratis." << endl;
    }
    else if (opcion == 5){
        cout << "Has admitido tu error y la inge se apiada de ti" << endl;
        cout << " " << endl;
        cout << "Sacaste 2/10 porque por algo estabas copiando, nuv." << endl;
    }
    else {
        cout << "no es una opcion valida bro";
    }
}