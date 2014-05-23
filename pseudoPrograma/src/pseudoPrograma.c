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
#include <commons/socket.h>
#include <commons/estructurasPackage.h>
#include <commons/package.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

int main(void) {
	int socketKernel;
	socketKernel = socket_crearCliente();
	socket_conectarCliente(socketKernel, "127.0.0.1", 5000);

	t_struct_numero soyKernel;
	soyKernel.numero = 3;
	//void*estructura = &soyKernel;
	//t_tipoEstructura tipo = 1;

	int cantBytesEnviados;

	t_stream * paquete = malloc(sizeof(t_stream));		//creo el paquete

	paquete->length = sizeof(t_header) + sizeof(unsigned int);

	char * data = crearDataConHeader(D_STRUCT_NUMERO, paquete->length); //creo el data

	memcpy(data + sizeof(t_header), &soyKernel, sizeof(t_struct_numero));		//copio a data el numero.

	paquete->data = data;

	cantBytesEnviados = send(socketKernel, paquete->data, paquete->length, 0);

	free(paquete->data);
	free(paquete);

	return EXIT_SUCCESS;
}
