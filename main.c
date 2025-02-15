#include <stdio.h>

// Imprime el gato
void printGame(char points[], int table[3][3]){
    printf("\t%c------ 1 ------+------ 2 ------+------ 3 ------%c\n",254,254);

    // Todo el for es un renglon, se imprime 3 veces porque son 3 renglones

    for(int i = 0; i < 3; i++){
        // Imprime un renglon sin caracteres (el \t sirve para tabular valores, los pone bonitos)
        printf("\t|\t \t|\t \t|\t \t|\n");
        
        // Imprime el renglon con caracteres
        printf("\t%d\t%c\t|\t%c\t|\t%c\t|\n",
            //del 1 al 3
            i+1,
            points[table[i][0]],
            points[table[i][1]],
            points[table[i][2]]);
        
        // Imprime otro renglon sin caracteres
        printf("\t|\t \t|\t \t|\t \t|\n");
        printf("\t%c---------------+---------------+---------------%c\n",254,254);
    }
}

//Rellena la tabla del gato con ceros
void setZero(int table[3][3]){
    for(int i = 0; i < 3; i++){
        for(int ii = 0; ii < 3; ii++){
            table[i][ii] = 132;
        }
    }
}

// Revisa que el valor este dentro de los limites, si se sale, poner el minimo o el maximo
int validatePos(int num){
    if(num > 3){
        num = 3;
    }else if (num < 1){
        num = 1;
    }
    return num;
}

//Obtiene los valores ingresados por el usuario y los asigna al array bidimensional
void getValues(int table[3][3]){
    int x, y;
    printf("Escribe la primera coordenada: ");
    scanf("%d",&x);
    printf("Escribe la segunda coordenada: ");
    scanf("%d",&y);
    x = validatePos(x);
    y = validatePos(y);

    /* 
    Empieza con la y porque en internamente las columnas van primero
    El usuario ingresa coordenadas y se muestran como en el plano cartesiano
    */
    table[y-1][x-1] = 1;
    
}


int main(){
    /*
    Array de caracteres 
    points[0] es un espacio
    points[1] es O
    points[2] es X
    */
    char points[] = {' ', 'O', 'X'};
    int table[3][3];
    int run = 1;

    setZero(table);

	printGame(points, table);

    // Bucle infinito, esto se va a cambiar
    while(run){
        getValues(table);
        printGame(points, table);
    }
	return 0;
}