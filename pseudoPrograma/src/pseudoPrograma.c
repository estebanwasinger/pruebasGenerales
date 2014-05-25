/*
 ============================================================================
 Name        : pseudoPrograma.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "socket.h"
#include "package.h"
#include "estructurasPackage.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>


int main(void) {
	int socketKernel;
	socketKernel = socket_crearCliente();
	socket_conectarCliente(socketKernel, "127.0.0.1", 5555);
	t_struct_handshake_umv * estructura = malloc(sizeof(t_struct_handshake_umv));
	estructura->tipoProceso = 32;

	socket_enviar(socketKernel,D_STRUCT_HANDSHAKE_UMV,estructura);
	return EXIT_SUCCESS;
}
