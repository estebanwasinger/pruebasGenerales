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
#include <commons/socket.h>
#include <commons/package.h>
#include <commons/estructurasPackage.h>
int main(void) {

int socketEscuchaGeneral;
int socketEscuchaNueva;

socketEscuchaGeneral = socket_crearServidor("127.0.0.1",5555);
socketEscuchaNueva = socket_aceptarCliente(socketEscuchaGeneral);

void * estructuraRecibida;
t_tipoEstructura tipoRecibido;


socket_recibir(socketEscuchaNueva, &tipoRecibido, &estructuraRecibida);
printf("%d",((t_struct_posxposy*) estructuraRecibida)->posX);

return 0;

}
