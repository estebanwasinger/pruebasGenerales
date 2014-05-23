/*
 ============================================================================
 Name        : pseudoKernel.c
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
	printf("Hola soy el PLP\n\n");
	int socketPLP;
	int socketPLPEscucha;
//	t_struct_handshakeUMV soyKernel;
	void *laEstructura;

	t_tipoEstructura tipoNumero;



	socketPLP = socket_crearServidor("127.0.0.1", 5000);
	socketPLPEscucha = socket_aceptarCliente(socketPLP);
	int ret = socket_recibir(socketPLPEscucha,&tipoNumero,&laEstructura);
	printf("RETT %d", ret);


	printf("\n Recibido: %d\n", (*((t_struct_numero*)laEstructura)->numero));
	close(socketPLP);
	close(socketPLPEscucha);
	return 0;
}
