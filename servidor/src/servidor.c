/*
 ============================================================================
 Name        : servidor.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <socket.h>
#include <package.h>
#include <estructurasPackage.h>


int main(void) {

int socketEscuchaGeneral;
int socketEscuchaNueva;

void * estructuraRecibida;
t_tipoEstructura tipoRecibido;

socketEscuchaGeneral = socket_crearServidor("127.0.0.1",5555);
socketEscuchaNueva = socket_aceptarCliente(socketEscuchaGeneral);

socket_recibir(socketEscuchaNueva, &tipoRecibido, &estructuraRecibida);
printf("\nID: %d \n",((t_struct_handshake_umv*) estructuraRecibida)->tipoProceso);

return 0;

}
