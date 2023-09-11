#include <stdio.h>
#include <stdlib.h>

//PROTOTIPADO
int factorizador (int num);
int potenciador (int num, int potencia);
int cargarArreglo(int arreglo[],int dim);
void mostrarArregloINT (int arreglo[], int validos);
void cargaArchivo(FILE *archi);
int leerArchi(FILE* archi);

int main()
{

    int num;
    int factorizado;
    int opc;
    int potencia;
    int potenciado;
    int dim = 30;
    int validos;
    int arreglo[dim];
    int suma;
    int menor;
    char archivo[] = {"miArchivo.bin"};
    FILE* archi;


    printf("================MENU================\n");
    printf(" -Punto 1             -Punto 7\n");
    printf(" -Punto 2             -Punto 8\n");
    printf(" -Punto 3             -Punto 9\n");
    printf(" -Punto 4             -Punto 10\n");
    printf(" -Punto 5             -Punto 11\n");
    printf(" -Punto 6             -Punto 12\n");
    printf("====================================");
    fflush(stdin);
    printf("\nIngrese una opcion: \n");
    scanf("%i", &opc);



    switch(opc)
    {

    case 1: //Calcular el factorial de un número en forma recursiva.

        printf("\nINGRESE UN NUMERO QUE QUIERA FACTORIZAR: \n");
        fflush(stdin);
        scanf("%i", &num);

        factorizado = factorizador(num);
        printf("Factorizado = %d", factorizado);

        break;


    case 2: //Calcular la potencia de un número en forma recursiva.
        printf("\nINGRESE NUMERO: \n");
        fflush(stdin);
        scanf("%i", &num);

        printf("INGRESE POTENCIA: \n");
        fflush(stdin);
        scanf("%i", &potencia);

        potenciado = potenciador (num, potencia);
        printf("\nPotenciado= %d\n", potenciado);

        break;

    case 3://Recorrer un arreglo y mostrar sus elementos en forma recursiva.
        validos = cargarArreglo(arreglo, dim);

        printf("\nARREGLO ORDENADO: \n");
        mostrarArregloRECU(arreglo, validos, 0);

        break;

    case 4: //Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos en forma invertida (recursivo).

        validos = cargarArreglo(arreglo, dim);
        printf("\nARREGLO ORDENADO: \n");
        mostrarArregloRECU(arreglo, validos, 0);
        printf("\nARREGLO INVERTIDO: \n");
        mostrarArregloINVERTIDO(arreglo, validos);

        break;

    case 5: //Determinar en forma recursiva si un arreglo es capicúa.

        validos = cargarArreglo(arreglo, dim);

        if (chequeaCapicua(arreglo, validos, 0)==0)
        {
            printf("\nEL ARREGLO ES CAPICUA\n");
        }
        else
        {
            printf("\nEL ARREGLO NO ES CAPICUA \n");
        }

        break;

    case 6: //Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el total de la suma.

        validos= cargarArreglo(arreglo, dim);
        mostrarArregloINT(arreglo, validos);
        suma = sumador(arreglo, validos);
        printf("\nLA SUMA ES: %i", suma);

        break;

    case 7: //Buscar el menor elemento de un arreglo en forma recursiva.
        validos= cargarArreglo(arreglo, dim);

        menor = buscarMenor(arreglo, validos);
        printf("\nEL MENOR ES: %i", menor);
        break;

    case 8: //Buscar el menor elemento de un archivo de números enteros de forma recursiva. (desde el mismo archivo)

        archi = fopen(archivo, "ab");
        cargaArchivo(archi);
        fclose (archi);

        archi = fopen(archivo, "rb");
        menor = leerArchi(archi);
        fclose (archi);
        printf("MENOR: %i", menor);




        break;

    case 9:

        break;

    case 10:

        break;

    case 11:
        break;

    case 12:
        break;


    }




    return 0;
}

int factorizador (int num)
{
    int sumaFacto;
    if (num > 1)
    {
        sumaFacto = (num*(num-1));
        sumaFacto = sumaFacto * factorizador(num-2);
    }
    else
    {
        sumaFacto = 1;
    }
    return sumaFacto;
}


int potenciador (int num, int potencia)
{
    int valor=1;
    int sumapotencia;

    if(potencia > 1)
    {

        valor = potenciador(num, potencia-1);

    }


    valor = (valor * num);

    return valor;

}

int cargarArreglo(int arreglo[],int dim)
{
    int i=0;
    char op = 's';
    while (op=='s')
    {
        printf("Ingrese el valor que quiera en el arreglo\n");
        fflush(stdin);
        scanf("%i",&arreglo[i]);

        i++;

        printf("Si desea continuar ingrese s\n");
        fflush(stdin);
        scanf("%c",&op);
    }


    return i;
}

void mostrarArregloINT (int arreglo[], int validos)
{

    for(int i = 0; i < validos; i++)
    {

        printf("| %d |", arreglo[i]);

    }
}

void mostrarArregloRECU(int arreglo[], int validos, int i)
{
    if (i<validos)
    {
        printf("|%i|", arreglo[i]);
        i++;
        mostrarArregloRECU(arreglo, validos, i);
    }

}


void mostrarArregloINVERTIDO(int arreglo[], int validos)
{
    if (validos!=0)
    {
        printf("|%i|", arreglo[validos-1]);
        mostrarArregloINVERTIDO(arreglo, validos-1);
    }
}

int chequeaCapicua (int arreglo[], int validos, int i)
{
    int flag = 0;

    if (flag==0 && i < validos)
    {
        if(arreglo[i]==arreglo[validos-1])
        {
            flag = chequeaCapicua(arreglo, validos-1, i+1);
        }
        else
        {
            flag = 1;
        }
    }

    return flag;
}

int sumador (int arreglo[], int validos)
{
    int suma=0;

    if (validos >0)
    {

        suma = sumador(arreglo, validos-1);
        suma = suma + arreglo[validos-1];

    }

    return suma;
}

int buscarMenor(int arreglo[], int validos)
{

    int menor;
    if (validos != 0)
    {
        menor = buscarMenor(arreglo, validos-1);
        if(menor > arreglo[validos-1])
        {
            menor = arreglo[validos-1];
        }
    }
    else
    {
        menor = arreglo[validos];
    }

    return menor;
}

void cargaArchivo(FILE *archi)
{
    char opt = 's';
    int num;
    if (archi != NULL)
    {
        while (opt == 's')
        {
            printf("Ingrese un numero: \n");
            fflush(stdin);
            scanf("%i", &num);
            fwrite(&num, sizeof(int), 1, archi);

            printf("Si desea continuar ingrese s\n");
            fflush(stdin);
            scanf("%c", &opt);

        }

    }
    else
    {
        printf("EL ARCHIVO NO EXISTE");
    }
}

int leerArchi(FILE* archi)
{
    int num;
    int menor;
    if(archi != NULL)
    {
        if (fread(&num, sizeof(int),1, archi)== 0)
        {
            fseek(archi, sizeof(int)*-1, SEEK_CUR);
            fread(&menor, sizeof(int),1, archi);


        }
        else
        {
            menor = leerArchi(archi);
            if(num<menor)
            {
                menor = num;
            }


        }

    }
    return menor;
}


