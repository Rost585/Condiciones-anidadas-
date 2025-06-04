
// PROYECTO FINAL - PROGRAMACIÓN I
// NOMBRE: Natividad Pelicó Vicente
// CARNÉ: 202508072
// UNIVERSIDAD MESOAMERICANA - QUETZALTENANGO
// DESCRIPCIÓN: Juego estilo Crossy Road en consola usando C++
// VIDEO DE REFERENCIA: https://youtu.be/9kmCPaPVugI

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

const int MAX_COLUMNAS = 20;
char mapa[13][MAX_COLUMNAS];
int filas;
int jugadorX, jugadorY;
int contadorMonedas = 0;
int nivelesSuperados = 0;

enum TipoFila { VEHICULO, RIO, ARBOLES };
TipoFila tipos[13];

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ocultarCursor() {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 100;
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hCon, &cci);
}

void limpiarMapa() {
    for (int i = 0; i < filas; i++)
        for (int j = 0; j < MAX_COLUMNAS; j++)
            mapa[i][j] = ' ';
}

void mostrarMapa() {
    gotoxy(0, 0);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < MAX_COLUMNAS; j++) {
            if (j == 0) cout << "#";
            if (i == jugadorY && j == jugadorX) {
                setColor(14); cout << 'P';
            } else {
                char c = mapa[i][j];
                switch (c) {
                    case 'V': setColor(12); break;
                    case 'T': setColor(11); break;
                    case '~': setColor(9); break;
                    case 'A': setColor(10); break;
                    case 'M': setColor(6); break;
                    default: setColor(7); break;
                }
                cout << c;
            }
            if (j == MAX_COLUMNAS - 1) cout << "#";
        }
        cout << endl;
    }
    for (int i = 0; i < MAX_COLUMNAS + 2; i++) cout << "#";
    cout << "\n";
    setColor(7);
    cout << "Monedas: " << contadorMonedas << "  |  Niveles: " << nivelesSuperados << endl;
}

void leerCantidadFilas() {
    do {
        cout << "Ingrese la cantidad de filas (3 a 12): ";
        cin >> filas;
        if (filas < 3 || filas > 12) {
            cout << "Valor no válido. Intente nuevamente.\n";
        }
    } while (filas < 3 || filas > 12);
}

void generarTiposDeFilas() {
    for (int i = 0; i < filas; i++) {
        tipos[i] = static_cast<TipoFila>(rand() % 3);
    }
}

void generarMapaEstático() {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < MAX_COLUMNAS; j++) {
            if (tipos[i] == VEHICULO) {
                mapa[i][j] = (rand() % 5 == 0) ? 'V' : ' ';
            } else if (tipos[i] == RIO) {
                mapa[i][j] = (rand() % 4 == 0) ? 'T' : '~';
            } else if (tipos[i] == ARBOLES) {
                mapa[i][j] = (rand() % 3 == 0) ? 'A' : ' ';
            }
        }
    }
}

void generarMonedas(int cantidad = 5) {
    int colocadas = 0;
    while (colocadas < cantidad) {
        int fila = rand() % filas;
        int col = rand() % MAX_COLUMNAS;
        if (mapa[fila][col] == ' ') {
            mapa[fila][col] = 'M';
            colocadas++;
        }
    }
}

void moverJugador(char tecla) {
    int nuevaX = jugadorX;
    int nuevaY = jugadorY;

    switch(tecla) {
        case 'w': nuevaY--; break;
        case 's': nuevaY++; break;
        case 'a': nuevaX--; break;
        case 'd': nuevaX++; break;
    }

    if (nuevaY >= 0 && nuevaY < filas && nuevaX >= 0 && nuevaX < MAX_COLUMNAS) {
        if (mapa[nuevaY][nuevaX] == 'M') contadorMonedas++;
        jugadorX = nuevaX;
        jugadorY = nuevaY;
        mapa[jugadorY][jugadorX] = ' ';
    }
}

void moverFilaDerecha(int fila) {
    char ultimo = mapa[fila][MAX_COLUMNAS - 1];
    for (int j = MAX_COLUMNAS - 1; j > 0; j--) {
        mapa[fila][j] = mapa[fila][j - 1];
    }
    mapa[fila][0] = ultimo;
}

void moverFilaIzquierda(int fila) {
    char primero = mapa[fila][0];
    for (int j = 0; j < MAX_COLUMNAS - 1; j++) {
        mapa[fila][j] = mapa[fila][j + 1];
    }
    mapa[fila][MAX_COLUMNAS - 1] = primero;
}

void moverObstaculos() {
    for (int i = 0; i < filas; i++) {
        if (tipos[i] == VEHICULO || tipos[i] == RIO) {
            if (i % 2 == 0) {
                moverFilaDerecha(i);
                if (tipos[i] == RIO && jugadorY == i && jugadorX < MAX_COLUMNAS - 1)
                    jugadorX++;
            } else {
                moverFilaIzquierda(i);
                if (tipos[i] == RIO && jugadorY == i && jugadorX > 0)
                    jugadorX--;
            }
        }
    }
}

bool verificarColision() {
    char celda = mapa[jugadorY][jugadorX];
    if (tipos[jugadorY] == VEHICULO && celda == 'V') return true;
    if (tipos[jugadorY] == RIO && celda != 'T') return true;
    return false;
}

bool verificarMeta() {
    return jugadorY == 0;
}

bool preguntarContinuar() {
    char opcion;
    cout << "\n🎉 ¡Nivel superado! 🎉\n¿Deseas seguir jugando? (s/n): ";
    cin >> opcion;
    return (opcion == 's' || opcion == 'S');
}

void reiniciarNivel() {
    nivelesSuperados++;
    jugadorY = filas - 1;
    jugadorX = MAX_COLUMNAS / 2;
    limpiarMapa();
    generarTiposDeFilas();
    generarMapaEstático();
    generarMonedas();
}

int main() {
    srand(time(0));
    ocultarCursor();
    leerCantidadFilas();
    reiniciarNivel();

    while (true) {
        if (_kbhit()) {
            char tecla = _getch();
            moverJugador(tecla);
        }

        moverObstaculos();

        if (verificarColision()) {
            mostrarMapa();
            cout << "\n💥 GAME OVER 💥" << endl;
            cout << "Monedas recolectadas: " << contadorMonedas << endl;
            cout << "Niveles superados: " << nivelesSuperados << endl;
            break;
        }

        if (verificarMeta()) {
            mostrarMapa();
            if (preguntarContinuar()) {
                reiniciarNivel();
                continue;
            } else {
                cout << "\n🏁 Juego terminado. ¡Buen trabajo!" << endl;
                cout << "Monedas recolectadas: " << contadorMonedas << endl;
                cout << "Niveles superados: " << nivelesSuperados << endl;
                break;
            }
        }

        mostrarMapa();
        Sleep(300);
    }
    return 0;
}
