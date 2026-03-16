#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h> // Necessário para gethostbyname

#define PORT 7896
#define BUFFER_SIZE 1024

int main() {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *server; // Estrutura para o host resolvido
    char buffer[BUFFER_SIZE];
    char *mensagem = "sistemas_distribuidos";

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Erro ao criar socket");
        exit(1);
    }

    // Resolve o nome "servidor" para um IP
    server = gethostbyname("servidor");
    if (server == NULL) {
        fprintf(stderr, "Erro: Host não encontrado\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    
    // Copia o endereço IP resolvido para a estrutura da conexão
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("Erro na conexão");
        exit(1);
    }

    printf("Enviado: %s\n", mensagem);
    write(sock, mensagem, strlen(mensagem));

    memset(buffer, 0, BUFFER_SIZE);
    read(sock, buffer, BUFFER_SIZE);
    printf("Recebido: %s\n", buffer);

    close(sock);
    return 0;
}