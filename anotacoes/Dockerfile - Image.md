O **Dockerfile** é um **manifesto declarativo** que descreve tudo o que a aplicação precisa para ser executada dentro de um container.
Nele, definimos:
- a **imagem base**
- o **ambiente de execução**
- as **dependências**
- e o **comando de inicialização** da aplicação
#### Comandos com explicação

`FROM node:24-slim

`FROM` define onde buscar **imagem base** do container.
- `node` → imagem oficial do Node.js
- `24` → versão do Node.js
- `slim` → variante mais enxuta que a imagem padrão, com menos pacotes do sistema

O dockerfile por padrão sempre vai apontar para o DockerHub. Caso tenha imagem base dentro da própria infraestrutura, basta configurar a rede para apontar local.

`WORKDIR /usr/src/app
- `/usr` → diretório padrão de softwares do sistema
- `/src` → geralmente usado para código-fonte
- `/app` → sua aplicação

`WORKDIR` -> define **qual diretório será o “diretório atual” dentro do container** a partir daquele ponto do Dockerfile. Sem ele os arquivos iriam para a raiz do container, fazendo assim uma bagunça.


`COPY package.json ./

Copia o arquivo package.json do host para o diretório de trabalho do container.
Essa abordagem permite aproveitar o cache de camadas do Docker, evitando reinstalar dependências quando o package.json não muda.

`COPY . .` -> copia tudo do diretório que estamos inseridos para o container


`RUN yarn

No Dockerfile, `RUN` executa **um comando durante o build da imagem**, não quando o container está rodando.

#### Building
`docker build -t api-nest .` -> Docker, construa uma imagem, dê o nome `api-nest` pra ela, usando **a pasta atual** como base.

`docker build -f Dockerfile.dev -t api-nest .` -> Docker, construa a imagem `api-nest`, usando **esse Dockerfile aqui** (`Dockerfile.dev`), e a pasta atual como contexto.

`cd api
`docker build -f docker/Dockerfile.dev -t api-nest .` -> Docker, construa a imagem `api-nest`, usando **esse Dockerfile aqui** (`Dockerfile.dev`) que está na pasta docker, e a pasta atual como contexto.

O `.` pega **a pasta onde o comando é executado**, não a pasta onde está o Dockerfile.


`docker build -f api/docker/Dockerfile.dev -t api-nest api` -> caso não queria usar o ponto, declaro onde o contexto será passado para o `COPY` funcionar

