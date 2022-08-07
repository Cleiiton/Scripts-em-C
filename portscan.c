#include <stdio.h>
#include<sys/socket.h>
#include<netdb.h>


int main(int argc, char *argv[]){

	int conexao;
	int conecta;
	
	int porta;
	int inicio;
	int final = 65535;
	int *destino;
	destino = argv[1];
	
	struct sockaddr_in alvo;
	
	for(porta=inicio;porta<final;porta++){
	
	
	conexao = socket(AF_INET,SOCK_STREAM,0);
	alvo.sin_family = AF_INET;
	alvo.sin_port = htons(porta);
	alvo.sin_addr.s_addr = inet_addr(destino);
	
	conecta = connect(conexao, (struct sockaddr *)&alvo,sizeof alvo);
	if(conecta == 0){
	printf("Porta Aberta %d - status [ABERTA]\n",porta);
	close(conexao);
	close(conecta);
	} else {
	close(conexao);
	close(conecta);
	}
	}
}
