/**
 * @file Programa.c
 * @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2023-06-23
 * 
 * @copyrigth GPlv3
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct {
    char nombre[50];
    int numeroBoleta;
    int anioIngreso;
    char carrera[50];
    char turno;
} Alumno;

typedef struct {
    char nombre[50];
    int numeroEmpleado;
    char turno;
} Profesor;

typedef struct {
    Fecha fecha;
    char unidadAprendizaje[50];
    char grupo[10];
    Profesor profesor;
    Alumno *alumnos;
    int cantidadAlumnos;
} Lista;

void registrarUnidadAprendizaje(Lista *lista);
void registrarGrupo(Lista *lista);
void registrarFecha(Lista *lista);
void registrarProfesor(Lista *lista);
void agregarAlumno(Lista *lista);
void modificarAlumno(Lista *lista);
void mostrarLista(Lista lista);
void guardarDatos(Lista lista);
void cargarDatos(Lista *lista);

int main() {
    Lista lista;
    lista.alumnos = NULL;
    lista.cantidadAlumnos = 0;
    
    int opcion;
    
    cargarDatos(&lista);
    
    do {
        printf("\n==== MENU ====\n");
        printf("1. Registrar Unidad de Aprendizaje\n");
        printf("2. Registrar Grupo\n");
        printf("3. Registrar Fecha\n");
        printf("4. Registrar Profesor\n");
        printf("5. Agregar Alumno\n");
        printf("6. Modificar Alumno\n");
        printf("7. Mostrar Lista\n");
        printf("8. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                registrarUnidadAprendizaje(&lista);
                break;
            case 2:
                registrarGrupo(&lista);
                break;
            case 3:
                registrarFecha(&lista);
                break;
            case 4:
                registrarProfesor(&lista);
                break;
            case 5:
                agregarAlumno(&lista);
                break;
            case 6:
                modificarAlumno(&lista);
                break;
            case 7:
                mostrarLista(lista);
                break;
            case 8:
                guardarDatos(lista);
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
    } while(opcion != 8);
    
    free(lista.alumnos);
    
    return 0;
}

void registrarUnidadAprendizaje(Lista *lista) {
    printf("\n==== REGISTRAR UNIDAD DE APRENDIZAJE ====\n");
    printf("Ingrese el nombre de la unidad de aprendizaje: ");
    scanf("%s", lista->unidadAprendizaje);
}

void registrarGrupo(Lista *lista) {
    printf("\n==== REGISTRAR GRUPO ====\n");
    printf("Ingrese el nombre del grupo: ");
    scanf("%s", lista->grupo);
}

void registrarFecha(Lista *lista) {
    printf("\n==== REGISTRAR FECHA ====\n");
    printf("Ingrese el dia: ");
    scanf("%d", &lista->fecha.dia);
    printf("Ingrese el mes: ");
    scanf("%d", &lista->fecha.mes);
    printf("Ingrese el anio: ");
    scanf("%d", &lista->fecha.anio);
}

void registrarProfesor(Lista *lista) {
    printf("\n==== REGISTRAR PROFESOR ====\n");
    printf("Ingrese el nombre del profesor: ");
    scanf("%s", lista->profesor.nombre);
    printf("Ingrese el numero de empleado: ");
    scanf("%d", &lista->profesor.numeroEmpleado);
    printf("Ingrese el turno (M-maniana, T-tarde, N-noche): ");
    scanf(" %c", &lista->profesor.turno);
}

void agregarAlumno(Lista *lista) {
    printf("\n==== AGREGAR ALUMNO ====\n");
    
    lista->cantidadAlumnos++;
    lista->alumnos = (Alumno*)realloc(lista->alumnos, lista->cantidadAlumnos * sizeof(Alumno));
    
    Alumno *alumno = &lista->alumnos[lista->cantidadAlumnos - 1];
    
    printf("Ingrese el nombre del alumno: ");
    scanf("%s", alumno->nombre);
    printf("Ingrese el numero de boleta: ");
    scanf("%d", &alumno->numeroBoleta);
    printf("Ingrese el anio de ingreso: ");
    scanf("%d", &alumno->anioIngreso);
    printf("Ingrese la carrera: ");
    scanf("%s", alumno->carrera);
    printf("Ingrese el turno (M-maniana, T-tarde, N-noche): ");
    scanf(" %c", &alumno->turno);
}

void modificarAlumno(Lista *lista) {
    printf("\n==== MODIFICAR ALUMNO ====\n");
    
    int numeroBoleta;
    printf("Ingrese el numero de boleta del alumno a modificar: ");
    scanf("%d", &numeroBoleta);
    
    int encontrado = 0;
    
    for (int i = 0; i < lista->cantidadAlumnos; i++) {
        if (lista->alumnos[i].numeroBoleta == numeroBoleta) {
            printf("Ingrese el nuevo nombre del alumno: ");
            scanf("%s", lista->alumnos[i].nombre);
            printf("Ingrese el nuevo anio de ingreso: ");
            scanf("%d", &lista->alumnos[i].anioIngreso);
            printf("Ingrese la nueva carrera: ");
            scanf("%s", lista->alumnos[i].carrera);
            printf("Ingrese el nuevo turno (M-maniana, T-tarde, N-noche): ");
            scanf(" %c", &lista->alumnos[i].turno);
            
            encontrado = 1;
            break;
        }
    }
    
    if (!encontrado) {
        printf("Alumno no encontrado.\n");
    }
}

void mostrarLista(Lista lista) {
    printf("\n==== LISTA DE ASISTENCIA ====\n");
    
    printf("Fecha: %02d/%02d/%04d\n", lista.fecha.dia, lista.fecha.mes, lista.fecha.anio);
    printf("Unidad de Aprendizaje: %s\n", lista.unidadAprendizaje);
    printf("Grupo: %s\n", lista.grupo);
    printf("Profesor: %s\n", lista.profesor.nombre);
    printf("Numero de empleado del profesor: %d\n", lista.profesor.numeroEmpleado);
    printf("Turno del profesor: %c\n", lista.profesor.turno);
    
    printf("\nAlumnos:\n");
    printf("%-20s %-15s %-10s %-10s\n", "Nombre", "Num. Boleta", "Anio Ingreso", "Carrera");
    
    for (int i = 0; i < lista.cantidadAlumnos; i++) {
        Alumno alumno = lista.alumnos[i];
        printf("%-20s %-15d %-10d %-10s\n", alumno.nombre, alumno.numeroBoleta, alumno.anioIngreso, alumno.carrera);
    }
}

void guardarDatos(Lista lista) {
    FILE *archivo = fopen("lista_alumnos.bin", "wb");
    
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }
    
    fwrite(&lista.fecha, sizeof(Fecha), 1, archivo);
    fwrite(lista.unidadAprendizaje, sizeof(char), sizeof(lista.unidadAprendizaje), archivo);
    fwrite(lista.grupo, sizeof(char), sizeof(lista.grupo), archivo);
    fwrite(&lista.profesor, sizeof(Profesor), 1, archivo);
    fwrite(&lista.cantidadAlumnos, sizeof(int), 1, archivo);
    fwrite(lista.alumnos, sizeof(Alumno), lista.cantidadAlumnos, archivo);
    
    fclose(archivo);
}

void cargarDatos(Lista *lista) {
    FILE *archivo = fopen("lista_alumnos.bin", "rb");
    
    if (archivo == NULL) {
        printf("No se encontro el archivo. Se creara uno nuevo.\n");
        return;
    }
    
    fread(&lista->fecha, sizeof(Fecha), 1, archivo);
    fread(lista->unidadAprendizaje, sizeof(char), sizeof(lista->unidadAprendizaje), archivo);
    fread(lista->grupo, sizeof(char), sizeof(lista->grupo), archivo);
    fread(&lista->profesor, sizeof(Profesor), 1, archivo);
    fread(&lista->cantidadAlumnos, sizeof(int), 1, archivo);
    
    lista->alumnos = (Alumno*)malloc(lista->cantidadAlumnos * sizeof(Alumno));
    fread(lista->alumnos, sizeof(Alumno), lista->cantidadAlumnos, archivo);
    
    fclose(archivo);
}
