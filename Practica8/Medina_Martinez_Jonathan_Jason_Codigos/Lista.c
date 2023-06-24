/**
 * @file Lista.c
 * @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2023-06-03
 * 
 * @copyrigth GPlv3
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 50
#define MAX_CARRERA 50
#define MAX_ALUMNOS 100

typedef struct {
    char nombre[MAX_NOMBRE];
    int numeroBoleta;
    int anioIngreso;
    char carrera[MAX_CARRERA];
    char turno;
} Alumno;

typedef struct {
    char nombre[MAX_NOMBRE];
    int numeroEmpleado;
    char turno;
} Profesor;

typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct {
    Fecha fecha;
    char unidadAprendizaje[MAX_NOMBRE];
    char grupo;
    Profesor profesor;
    Alumno alumnos[MAX_ALUMNOS];
    int numAlumnos;
} Lista;

void registrarUnidadAprendizaje(Lista *lista);
void registrarGrupo(Lista *lista);
void registrarFecha(Lista *lista);
void registrarProfesor(Lista *lista);
void agregarAlumno(Lista *lista);
void editarAlumno(Lista *lista);
void mostrarLista(const Lista *lista);
void liberarMemoria(Lista *lista);

int main() {
    Lista lista;
    lista.numAlumnos = 0;

    int opcion;
    char opcionStr[10];

    do {
        printf("\n--- MENU ---\n");
        printf("1. Registrar Unidad de Aprendizaje\n");
        printf("2. Registrar Grupo\n");
        printf("3. Registrar Fecha\n");
        printf("4. Registrar Profesor\n");
        printf("5. Agregar Alumno\n");
        printf("6. Editar Alumno\n");
        printf("7. Mostrar Lista\n");
        printf("8. Salir\n");
        printf("Ingrese una opcion: ");
        fgets(opcionStr, sizeof(opcionStr), stdin);
        opcionStr[strcspn(opcionStr, "\n")] = '\0';
        opcion = atoi(opcionStr);

        switch (opcion) {
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
                editarAlumno(&lista);
                break;
            case 7:
                mostrarLista(&lista);
                break;
            case 8:
                liberarMemoria(&lista);
                printf("Hasta luego!\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 8);

    return 0;
}

void registrarUnidadAprendizaje(Lista *lista) {
    printf("\n--- Registrar Unidad de Aprendizaje ---\n");
    printf("Ingrese el nombre de la unidad de aprendizaje: ");
    fgets(lista->unidadAprendizaje, sizeof(lista->unidadAprendizaje), stdin);
    lista->unidadAprendizaje[strcspn(lista->unidadAprendizaje, "\n")] = '\0';
}

void registrarGrupo(Lista *lista) {
    printf("\n--- Registrar Grupo ---\n");
    printf("Ingrese el grupo: ");
    scanf(" %c", &(lista->grupo));
    getchar();
}

void registrarFecha(Lista *lista) {
    printf("\n--- Registrar Fecha ---\n");
    printf("Ingrese el dia: ");
    scanf("%d", &(lista->fecha.dia));
    printf("Ingrese el mes: ");
    scanf("%d", &(lista->fecha.mes));
    printf("Ingrese el anio: ");
    scanf("%d", &(lista->fecha.anio));
}

void registrarProfesor(Lista *lista) {
    printf("\n--- Registrar Profesor ---\n");
    printf("Ingrese el nombre del profesor: ");
    fgets(lista->profesor.nombre, sizeof(lista->profesor.nombre), stdin);
    lista->profesor.nombre[strcspn(lista->profesor.nombre, "\n")] = '\0';
    printf("Ingrese el numero de empleado: ");
    scanf("%d", &(lista->profesor.numeroEmpleado));
    printf("Ingrese el turno del profesor: ");
    scanf(" %c", &(lista->profesor.turno));
}

void agregarAlumno(Lista *lista) {
    printf("\n--- Agregar Alumno ---\n");
    if (lista->numAlumnos < MAX_ALUMNOS) {
        Alumno *nuevoAlumno = &(lista->alumnos[lista->numAlumnos]);

        printf("Ingrese el nombre del alumno: ");
        fgets(nuevoAlumno->nombre, sizeof(nuevoAlumno->nombre), stdin);
        nuevoAlumno->nombre[strcspn(nuevoAlumno->nombre, "\n")] = '\0';
        printf("Ingrese el numero de boleta: ");
        scanf("%d", &(nuevoAlumno->numeroBoleta));
        printf("Ingrese el anio de ingreso: ");
        scanf("%d", &(nuevoAlumno->anioIngreso));
        printf("Ingrese la carrera del alumno: ");
        fgets(nuevoAlumno->carrera, sizeof(nuevoAlumno->carrera), stdin);
        nuevoAlumno->carrera[strcspn(nuevoAlumno->carrera, "\n")] = '\0';
        printf("Ingrese el turno del alumno: ");
        scanf(" %c", &(nuevoAlumno->turno));

        lista->numAlumnos++;
    } else {
        printf("No se pueden agregar mas alumnos. Limite alcanzado.\n");
    }
}

void editarAlumno(Lista *lista) {
    printf("\n--- Editar Alumno ---\n");
    int indice;
    printf("Ingrese el indice del alumno a editar (1-%d): ", lista->numAlumnos);
    scanf("%d", &indice);

    if (indice >= 1 && indice <= lista->numAlumnos) {
        Alumno *alumno = &(lista->alumnos[indice - 1]);

        printf("Ingrese el nombre del alumno: ");
        fgets(alumno->nombre, sizeof(alumno->nombre), stdin);
        alumno->nombre[strcspn(alumno->nombre, "\n")] = '\0';
        printf("Ingrese el numero de boleta: ");
        scanf("%d", &(alumno->numeroBoleta));
        printf("Ingrese el anio de ingreso: ");
        scanf("%d", &(alumno->anioIngreso));
        printf("Ingrese la carrera del alumno: ");
        fgets(alumno->carrera, sizeof(alumno->carrera), stdin);
        alumno->carrera[strcspn(alumno->carrera, "\n")] = '\0';
        printf("Ingrese el turno del alumno: ");
        scanf(" %c", &(alumno->turno));

        printf("Alumno editado con exito.\n");
    } else {
        printf("Indice de alumno invalido.\n");
    }
}

void mostrarLista(const Lista *lista) {
    printf("\n--- Mostrar Lista ---\n");
    printf("Unidad de Aprendizaje: %s\n", lista->unidadAprendizaje);
    printf("Grupo: %c\n", lista->grupo);
    printf("Fecha: %02d/%02d/%d\n", lista->fecha.dia, lista->fecha.mes, lista->fecha.anio);
    printf("Profesor: %s\n", lista->profesor.nombre);
    printf("Numero de Empleado: %d\n", lista->profesor.numeroEmpleado);
    printf("Turno del Profesor: %c\n", lista->profesor.turno);

    printf("\nAlumnos:\n");
    for (int i = 0; i < lista->numAlumnos; i++) {
        const Alumno *alumno = &(lista->alumnos[i]);
        printf("%d. %s, Boleta: %d, Anio de Ingreso: %d, Carrera: %s, Turno: %c\n",
            i + 1, alumno->nombre, alumno->numeroBoleta, alumno->anioIngreso, alumno->carrera, alumno->turno);
    }
}

void liberarMemoria(Lista *lista) {
    if (lista->alumnos != NULL) {
        lista->numAlumnos = 0;
        memset(lista->alumnos, 0, sizeof(lista->alumnos));
    }
}