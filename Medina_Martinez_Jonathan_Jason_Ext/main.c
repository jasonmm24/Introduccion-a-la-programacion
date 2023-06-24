/**
 * @file main.c
 * @author Medina Martinez Jonathan Jason (jmedinam1702@alumno.ipn.mx)
 * @brief 
 * @version 0.1
 * @date 2023-06-22
 * 
 * @copyrigth GPlv3
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_CUENTAS 100

typedef struct {
    char cuenta[7];
    char contrasena[5];
    char nombre[50];
    double saldo;
} Cuenta;

void cargarCuentas(Cuenta* cuentas, int* numCuentas) {
    FILE* archivo = fopen("../basededatos.txt", "r");
    if (archivo == NULL) {
        printf("\nError al abrir el archivo de base de datos.\n");
        exit(1);
    }

    char linea[100];
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        sscanf(linea, "%[^,],%[^,],%[^,],%lf",
                cuentas[*numCuentas].cuenta,
                cuentas[*numCuentas].contrasena,
                cuentas[*numCuentas].nombre,
                &cuentas[*numCuentas].saldo);

        (*numCuentas)++;
    }

    fclose(archivo);
}

void guardarCuentas(const Cuenta* cuentas, int numCuentas) {
    FILE* archivo = fopen("../basededatos.txt", "w");
    if (archivo == NULL) {
        printf("\nError al abrir el archivo de base de datos.\n");
        exit(1);
    }

    for (int i = 0; i < numCuentas; i++) {
        fprintf(archivo, "%s,%s,%s,%.2lf\n", cuentas[i].cuenta, cuentas[i].contrasena, cuentas[i].nombre, cuentas[i].saldo);
    }

    fclose(archivo);
}

int obtenerIndiceCuenta(const Cuenta* cuentas, int numCuentas, const char* cuenta) {
    for (int i = 0; i < numCuentas; i++) {
        if (strcmp(cuentas[i].cuenta, cuenta) == 0) {
            return i;
        }
    }
    return -1;
}

int verificarCuenta(const Cuenta* cuentas, int numCuentas, const char* cuenta, const char* contrasena) {
    for (int i = 0; i < numCuentas; i++) {
        if (strcmp(cuentas[i].cuenta, cuenta) == 0 && strcmp(cuentas[i].contrasena, contrasena) == 0) {
            return i;
        }
    }
    return -1;
}

void mostrarMenu() {
    printf("\n--- MENU ---\n");
    printf("1. Mostrar saldo\n");
    printf("2. Depositar\n");
    printf("3. Retirar\n");
    printf("4. Transferir\n");
    printf("5. Cambiar contrasena\n");
    printf("6. Salir\n");
    printf("Ingrese la opcion: ");
}

void imprimirTicket(const Cuenta* cuenta, int operacion, double cantidad, const Cuenta* cuentaDestino) {
    time_t tiempoActual = time(NULL);
    struct tm* tiempoLocal = localtime(&tiempoActual);

    char nombreArchivo[100];
    sprintf(nombreArchivo, "ticket %s %d-%02d-%02d %02d-%02d-%02d.txt",
            cuenta->nombre, tiempoLocal->tm_year + 1900, tiempoLocal->tm_mon + 1,
            tiempoLocal->tm_mday, tiempoLocal->tm_hour, tiempoLocal->tm_min,
            tiempoLocal->tm_sec);

    FILE* archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        printf("\nError al crear el archivo del ticket.\n");
        return;
    }

    fprintf(archivo, "---------------------------------\n");
    fprintf(archivo, "Fecha y hora: %d-%02d-%02d %02d:%02d:%02d\n",
            tiempoLocal->tm_year + 1900, tiempoLocal->tm_mon + 1,
            tiempoLocal->tm_mday, tiempoLocal->tm_hour, tiempoLocal->tm_min,
            tiempoLocal->tm_sec);
    fprintf(archivo, "Nombre: %s\n", cuenta->nombre);
    fprintf(archivo, "Cuenta: %s\n", cuenta->cuenta);
    fprintf(archivo, "Operacion: ");

    switch (operacion) {
        case 1:
            fprintf(archivo, "Mostrar saldo\n");
            fprintf(archivo, "Saldo actual: %.2lf\n", cuenta->saldo);
            break;
        case 2:
            fprintf(archivo, "Deposito\n");
            fprintf(archivo, "Cantidad depositada: %.2lf\n", cantidad);
            fprintf(archivo, "Saldo actual: %.2lf\n", cuenta->saldo);
            break;
        case 3:
            fprintf(archivo, "Retiro\n");
            fprintf(archivo, "Cantidad retirada: %.2lf\n", cantidad);
            fprintf(archivo, "Saldo actual: %.2lf\n", cuenta->saldo);
            break;
        case 4:
            fprintf(archivo, "Transferencia\n");
            fprintf(archivo, "Cuenta destino: %s\n", cuentaDestino->cuenta);
            fprintf(archivo, "Beneficiario: %s\n", cuentaDestino->nombre);
            fprintf(archivo, "Cantidad transferida: %.2lf\n", cantidad);
            fprintf(archivo, "Saldo actual: %.2lf\n", cuenta->saldo);
            break;
        case 5:
            fprintf(archivo, "Cambio de contrasena\n");
            break;
        default:
            fprintf(archivo, "Operacion desconocida\n");
    }

    fprintf(archivo, "---------------------------------\n");

    fclose(archivo);

    printf("\nSe ha generado el ticket: %s\n", nombreArchivo);
}

void mostrarSaldosiono(const Cuenta* cuenta) {
    char siono[3];
    printf("\nSaldo actual: %.2lf\n", cuenta->saldo);
    printf("\nImprimir comprobante: Si/No\n");
    scanf("%2s", siono);
    getc(stdin);
    if (strcmp(siono, "Si") == 0 || strcmp(siono, "S") == 0 || strcmp(siono, "s") == 0 || strcmp(siono, "si") == 0) {
        imprimirTicket(cuenta, 1, 0.0, NULL);
    }
}
void mostrarSaldo(const Cuenta* cuenta) {
    printf("\nSaldo actual: %.2lf\n", cuenta->saldo);
    imprimirTicket(cuenta, 1, 0.0, NULL);
}

void depositar(Cuenta* cuenta) {
    double cantidad;
    printf("\nIngrese la cantidad a depositar: ");
    scanf("%lf", &cantidad);

    cuenta->saldo += cantidad;

    printf("\nDeposito realizado con exito.\n");
    mostrarSaldo(cuenta);
    imprimirTicket(cuenta, 2, cantidad, NULL);
}

void retirar(Cuenta* cuenta) {
    double cantidad;
    printf("\nIngrese la cantidad a retirar: ");
    scanf("%lf", &cantidad);

    if (cantidad > cuenta->saldo) {
        printf("\nSaldo insuficiente.\n");
    } else {
        cuenta->saldo -= cantidad;
        printf("\nRetiro realizado con exito.\n");
        mostrarSaldo(cuenta);
        imprimirTicket(cuenta, 3, cantidad, NULL);
    }
}

void transferir(Cuenta* cuentas, int numCuentas, Cuenta* cuenta) {
    char cuentaDestino[7];
    printf("\nIngrese la cuenta destino: ");
    scanf("%s", cuentaDestino);

    int indiceCuentaDestino = obtenerIndiceCuenta(cuentas, numCuentas, cuentaDestino);
    if (indiceCuentaDestino == -1) {
        printf("\nLa cuenta destino no existe.\n");
        return;
    }

    double cantidad;
    printf("\nIngrese la cantidad a transferir: ");
    scanf("%lf", &cantidad);

    if (cantidad > cuenta->saldo) {
        printf("\nSaldo insuficiente.\n");
    } else {
        cuenta->saldo -= cantidad;
        cuentas[indiceCuentaDestino].saldo += cantidad;
        printf("\nTransferencia realizada con exito.\n");
        mostrarSaldo(cuenta);
        imprimirTicket(cuenta, 4, cantidad, &cuentas[indiceCuentaDestino]);
    }
}

void cambiarContrasena(Cuenta* cuenta) {
    char contrasenaActual[5];
    printf("\nIngrese la contrasena actual: ");
    scanf("%s", contrasenaActual);

    if (strcmp(cuenta->contrasena, contrasenaActual) == 0) {
        char nuevaContrasena[5];
        printf("\nIngrese la nueva contrasena (4 caracteres): ");
        scanf("%s", nuevaContrasena);

        strncpy(cuenta->contrasena, nuevaContrasena, sizeof(cuenta->contrasena) - 1);
        cuenta->contrasena[sizeof(cuenta->contrasena) - 1] = '\0';

        printf("\nContrasena cambiada con exito.\n");
        imprimirTicket(cuenta, 5, 0.0, NULL);
    } else {
        printf("\nContrasena incorrecta.\n");
    }
}

int main() {
    Cuenta cuentas[MAX_CUENTAS];
    int numCuentas = 0;

    cargarCuentas(cuentas, &numCuentas);

    char cuentaActual[7];
    char contrasenaActual[5];
    int indiceCuentaActual = -1;

    printf("--- BIENVENIDO ---\n");

    while (indiceCuentaActual == -1) {
        printf("\nIngrese su cuenta (o ingrese '0' para salir): ");
        scanf("%s", cuentaActual);

        if (strcmp(cuentaActual, "0") == 0) {
            printf("\nGracias por utilizar nuestro servicio. Hasta luego.\n");
            return 0;
        }

        printf("Ingrese su contrasena: ");
        scanf("%s", contrasenaActual);

        indiceCuentaActual = verificarCuenta(cuentas, numCuentas, cuentaActual, contrasenaActual);

        if (indiceCuentaActual == -1) {
            printf("\nCuenta o contrasena incorrecta. Intente nuevamente.\n");
        }
    }

    printf("\nBienvenido, %s.\n", cuentas[indiceCuentaActual].nombre);

    int opcion;

    do {
        mostrarMenu();
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                mostrarSaldosiono(&cuentas[indiceCuentaActual]);
                break;
            case 2:
                depositar(&cuentas[indiceCuentaActual]);
                break;
            case 3:
                retirar(&cuentas[indiceCuentaActual]);
                break;
            case 4:
                transferir(cuentas, numCuentas, &cuentas[indiceCuentaActual]);
                break;
            case 5:
                cambiarContrasena(&cuentas[indiceCuentaActual]);
                break;
            case 6:
                printf("\nGracias por utilizar nuestro servicio. Hasta luego.\n");
                break;
            default:
                printf("\nOpcion invalida. Intente nuevamente.\n");
        }
    } while (opcion != 6);

    guardarCuentas(cuentas, numCuentas);

    return 0;
}