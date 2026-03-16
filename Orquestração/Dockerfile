# Estágio de Compilação (Builder)
FROM alpine:latest AS builder
RUN apk add --no-cache gcc musl-dev
WORKDIR /build
COPY TCPServer.c TCPClient.c ./
RUN gcc TCPServer.c -o servidor -lpthread
RUN gcc TCPClient.c -o cliente

# Estágio Final para o Servidor
FROM alpine:latest AS server
WORKDIR /app
COPY --from=builder /build/servidor ./
EXPOSE 7896
CMD ["./servidor"]

# Estágio Final para o Cliente
FROM alpine:latest AS client
WORKDIR /app
COPY --from=builder /build/cliente ./
CMD ["./cliente"]