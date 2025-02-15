#include <stdio.h>


void printGame(char points[], int table[3][3]){
    printf("------- 1 ------------- 2 ------------- 3 -------\n");
    for(int i = 0; i < 3; i++){
        printf("|\t \t|\t \t|\t \t|\n");
        printf("%d\t%c\t|\t%c\t|\t%c\t|\n",i+1,points[table[i][0]],points[table[i][1]],points[table[i][2]]);
        printf("|\t \t|\t \t|\t \t|\n");
        printf("-------------------------------------------------\n");
    }
}

void setZero(int table[3][3]){
    for(int i = 0; i < 3; i++){
        for(int ii = 0; ii < 3; ii++){
            table[i][ii] = 132;
        }
    }
}

int validatePos(int num){
    if(num > 3){
        num = 3;
    }else if (num < 1){
        num = 1;
    }
    return num;
}

void getValues(int table[3][3]){
    int x, y;
    puts("Escribe la primera coordenada: ");
    scanf("%d",&x);
    puts("Escribe la segunda coordenada: ");
    scanf("%d",&y);
    x = validatePos(x);
    y = validatePos(y);
    table[y-1][x-1] = 1;
    
}


int main(){
    /*
    Array de caracteres 
    points[0] es un espacio
    points[1] es O
    points[2] es X
    */
    char points[] = " OX";
    int table[3][3];
    int run = 1;

    setZero(table);

	printGame(points, table);
    while(run){
        getValues(table);
        printGame(points, table);
    }
	return 0;
}