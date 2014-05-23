/*
 ============================================================================
 Name        : cliente.c
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

t_stream * paquetizar(int tipoEstructura, void * estructuraOrigen){
	t_stream * paquete;

	switch (tipoEstructura){
			case D_STRUCT_POSXPOSY:
				paquete = paquetizarStruct_posxposy((t_struct_posxposy *) estructuraOrigen);
				break;
		}


	return paquete;
}

t_stream * paquetizarStruct_posxposy(t_struct_posxposy * estructuraOrigen){

	t_stream * paquete = malloc(sizeof(t_stream));		//creo el paquete

	paquete->length = sizeof(t_header) + sizeof(t_struct_posxposy);

	char * data = crearDataConHeader(D_STRUCT_POSXPOSY, paquete->length); //creo el data

	memcpy(data + sizeof(t_header), estructuraOrigen, sizeof(t_struct_posxposy));	//copio a data la estructura.

	paquete->data = data;

	return paquete;
}

int socket_enviar(int socketReceptor, t_tipoEstructura tipoEstructura, void* estructura){
	int cantBytesEnviados;

	t_stream * paquete = paquetizar(tipoEstructura, estructura);

	cantBytesEnviados = send(socketReceptor, paquete->data, paquete->length, 0);
	free(paquete->data);
	free(paquete);
	if( cantBytesEnviados == -1){
		perror("Server no encontrado\n");
		return 0;
	}
	else {
		return 1;
	}
}

int main(void) {
	int socketEscucha;
	socketEscucha = socket_crearCliente();
	socket_conectarCliente(socketEscucha, "127.0.0.1", 5555);
	t_struct_posxposy * stringNombreNivel = malloc(sizeof(t_struct_posxposy));
	stringNombreNivel->posX = 1;
	stringNombreNivel->posY = 2;
	printf("%d", stringNombreNivel->posX);
	socket_enviar(socketEscucha, D_STRUCT_NOMBRENIVEL, stringNombreNivel);

	return EXIT_SUCCESS;
}
