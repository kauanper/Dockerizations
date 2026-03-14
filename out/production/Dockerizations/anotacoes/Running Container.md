
`docker run --rm -p 3001:3000 api-nest` 
- docker run -> cria e executa conteiner
- --rm apaga o container (traz a ideia de o container ser efêmero, mas é um comando opcional)
- api-nest -> nome da imagem
- -p 3001:3000 -> mapeia a porta 3001 da minha maquina para ser a porta 3000 do container

essa é a primeira forma, porém fico preso no terminal e meu container sobe com nome aleatório

`docker run --rm -p 3001:3000 -d api-nest`
- -d para rodar em background e liberar terminal, caso queria ver os logs usamos: 
	`docker logs <id container>`

`docker run --name api-nest --rm -p 3001:3000 api-nest
- --name (nome do conteiner): é uma flag para dar nome


Não existe hierarquia de ordem entre as flags, a **única coisa que importa** é **onde fica o nome da imagem**.
docker run [OPÇÕES] IMAGEM [COMANDO]
