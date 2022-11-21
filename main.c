#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define JASIG 4
#define IALUM 12

void leeMatriz(int m[][JASIG]);
void imprimeMatriz(int m[][JASIG]);
void rellenaMatrizAleatorio(int m[][JASIG]);
int numAlumnosSuspensas(int m[][JASIG], int susp);
float mediaAsignatura(int m[][JASIG],int asig);

int main() {
    int notas[IALUM][JASIG];
    //leeMatriz(notas);
    rellenaMatrizAleatorio(notas);
    imprimeMatriz(notas);
    for (int i = 0; i <= JASIG; ++i) {
        printf("\nEl numero de alumnos con %d suspensos es: %d",i,numAlumnosSuspensas(notas,i));
    }
    printf("\n");
    for (int i = 0; i < JASIG; ++i) {
        printf("\nLa media de la asignatura %d es: %.2f",i+1, mediaAsignatura(notas,i));
    }

    return 0;
}

void leeMatriz(int m[][JASIG]){
    int num;
    for (int i = 0; i < JASIG; ++i) {
        printf("---| Asignatura %d\n",i);
        for (int j = 0; j < IALUM; ++j) {
            printf("Alumno %d = ",j);
            scanf("%d",&num);
            fflush(stdin);
            m[j][i]=num;
        }
    }
}

void rellenaMatrizAleatorio(int m[][JASIG]){
    srand(time(NULL));
    for (int i = 0; i < IALUM; ++i) {
        for (int j = 0; j < JASIG; ++j) {
            m[i][j]=rand()%10;
        }
    }
}

int numAlumnosSuspensas(int m[][JASIG], int susp){
    int suspensas, alumnos_sus=0;
    for (int i = 0; i < IALUM; ++i) {
        suspensas=0;
        for (int j = 0; j < JASIG; ++j) {
            if (m[i][j]<5)
                suspensas++;
        }
        if (suspensas==susp)
            alumnos_sus++;

    }
    return alumnos_sus;
}

void imprimeMatriz(int m[][JASIG]){
    printf("\n");
    for (int i = 0; i < IALUM; ++i) {
        printf("Alumno %2d: |",i);
        for (int j = 0; j < JASIG; ++j) {
            printf("% d |",m[i][j]);
        }
        printf("\n");
    }
}

float mediaAsignatura(int m[][JASIG],int asig){
    float media=0;
    for (int i = 0; i < IALUM; ++i) {
        media+=(float)m[i][asig];
    }
    return media/IALUM;
}

void imprimirOrdenado(m[][JASIG]){

}