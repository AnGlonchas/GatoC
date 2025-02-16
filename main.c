#include <stdio.h>
#include <stdbool.h>

#define TAMANO 3  // Tamaño del tablero (3x3)

// Declaración de funciones
void mostrarTablero(char tablero[TAMANO][TAMANO]);  // Muestra el tablero
bool hacerMovimiento(char tablero[TAMANO][TAMANO], int fila, int columna, char jugador);  // Realiza un movimiento
bool verificarGanador(char tablero[TAMANO][TAMANO], char jugador);  // Verifica si hay un ganador
bool verificarEmpate(char tablero[TAMANO][TAMANO]);  // Verifica si hay un empate

int main() {
    // Inicialización del tablero con espacios en blanco
    char tablero[TAMANO][TAMANO] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int fila, columna;  // Variables para almacenar la fila y columna del movimiento
    char jugadorActual = 'X';  // Jugador actual (comienza con 'X')
    bool juegoTerminado = false;  // Controla si el juego ha terminado

    printf("Bienvenido al juego del Gato (Tic-Tac-Toe)!\n");

    // Bucle principal del juego
    while (!juegoTerminado) {
        // Mostrar el tablero actual
        mostrarTablero(tablero);

        // Pedir al jugador actual que ingrese su movimiento
        printf("Jugador %c, primero ingrese la fila (0-2) y luego la columna (0-2): ", jugadorActual);
        scanf("%d %d", &fila, &columna);

        // Verificar si el movimiento es válido
        if (fila >= 0 && fila < TAMANO && columna >= 0 && columna < TAMANO && tablero[fila][columna] == ' ') {
            // Realizar el movimiento en el tablero
            hacerMovimiento(tablero, fila, columna, jugadorActual);

            // Verificar si el jugador actual ha ganado
            if (verificarGanador(tablero, jugadorActual)) {
                mostrarTablero(tablero);  // Mostrar el tablero final
                printf("¡Felicidades! El jugador %c ha ganado.\n", jugadorActual);
                juegoTerminado = true;  // Terminar el juego
            }
            // Verificar si hay un empate
            else if (verificarEmpate(tablero)) {
                mostrarTablero(tablero);  // Mostrar el tablero final
                printf("¡Es un empate!\n");
                juegoTerminado = true;  // Terminar el juego
            }
            // Cambiar al siguiente jugador
            jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
        } else {
            // Si el movimiento no es válido, mostrar un mensaje de error
            printf("Movimiento inválido. Intente de nuevo.\n");
        }
    }

    return 0;  // Fin del programa
}

// Función para mostrar el tablero
void mostrarTablero(char tablero[TAMANO][TAMANO]) {
    printf("\n");
    // Recorrer cada fila del tablero
    for (int i = 0; i < TAMANO; i++) {
        // Recorrer cada columna de la fila actual
        for (int j = 0; j < TAMANO; j++) {
            printf(" %c ", tablero[i][j]);  // Mostrar el contenido de la casilla
            if (j < TAMANO - 1) printf("|");  // Agregar separador entre columnas
        }
        printf("\n");
        // Agregar línea divisoria entre filas (excepto después de la última fila)
        if (i < TAMANO - 1) printf("-----------\n");
    }
    printf("\n");
}

// Función para realizar un movimiento
bool hacerMovimiento(char tablero[TAMANO][TAMANO], int fila, int columna, char jugador) {
    // Verificar si la casilla está vacía
    if (tablero[fila][columna] == ' ') {
        tablero[fila][columna] = jugador;  // Colocar el símbolo del jugador en la casilla
        return true;  // Movimiento válido
    }
    return false;  // Movimiento inválido (casilla ocupada)
}

// Función para verificar si hay un ganador
bool verificarGanador(char tablero[TAMANO][TAMANO], char jugador) {
    // Verificar filas y columnas
    for (int i = 0; i < TAMANO; i++) {
        // Verificar si todas las casillas de una fila son iguales al jugador actual
        if (tablero[i][0] == jugador && tablero[i][1] == jugador && tablero[i][2] == jugador) return true;
        // Verificar si todas las casillas de una columna son iguales al jugador actual
        if (tablero[0][i] == jugador && tablero[1][i] == jugador && tablero[2][i] == jugador) return true;
    }
    // Verificar diagonales
    // Diagonal principal (de arriba-izquierda a abajo-derecha)
    if (tablero[0][0] == jugador && tablero[1][1] == jugador && tablero[2][2] == jugador) return true;
    // Diagonal secundaria (de arriba-derecha a abajo-izquierda)
    if (tablero[0][2] == jugador && tablero[1][1] == jugador && tablero[2][0] == jugador) return true;

    return false;  // No hay ganador
}

// Función para verificar si hay un empate
bool verificarEmpate(char tablero[TAMANO][TAMANO]) {
    // Recorrer todas las casillas del tablero
    for (int i = 0; i < TAMANO; i++) {
        for (int j = 0; j < TAMANO; j++) {
            // Si hay al menos una casilla vacía, no es empate
            if (tablero[i][j] == ' ') return false;
        }
    }
    // Si no hay casillas vacías, es empate
    return true;
}