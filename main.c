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
float mediaAlumno(int m[][JASIG],int alumno);
void ordenaInsercion(float v[][2], int prim, int ultm);
void imprimirOrdenado(int m[][JASIG]);

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
    imprimirOrdenado(notas);
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

void imprimirOrdenado(int m[][JASIG]){
    float media=0;
    float orden[IALUM][2];
    for (int i = 0; i < IALUM; ++i) {
        orden[i][0]=(float)i;
        orden[i][1]= mediaAlumno(m,i);
    }
    ordenaInsercion(orden,0,IALUM-1);
    printf("\n");
    for (int i = 0; i < IALUM; ++i) {
        printf("\nNota media: %.2f. Alumno: %.f",orden[i][1],orden[i][0]);
    }
    printf("\n");
}

float mediaAlumno(int m[][JASIG],int alumno){
    float media=0;
    for (int i = 0; i < JASIG; ++i) {
        media+=(float)m[alumno][i];
    }
    return media/JASIG;
}

void ordenaInsercion(float v[][2], int prim, int ultm){
    int i,j;
    float x,pos;
    for(i=prim+1; i<=ultm; i++)
    {
        x=v[i][1];
        pos=v[i][0];
        j=i-1;
        while(j>=prim && x<v[j][1]) {
            v[j+1][1]=v[j][1];
            v[j+1][0]=v[j][0];
            j--; }
        v[j+1][0]=pos;
        v[j+1][1]=x; }
}