🎬 AcervoFilmes
Sistema de gerenciamento de coleção de filmes desenvolvido em C.
📋 Descrição
AcervoFilmes é uma aplicação em linha de comando para organizar e gerenciar sua coleção pessoal de filmes. O sistema permite adicionar, listar, buscar e organizar informações sobre filmes de forma simples e eficiente.
🗂️ Estrutura do Projeto
AcervoFilmes/
├── src/
│   ├── main.c          # Arquivo principal do programa
│   ├── colecao.c       # Implementação das funções de coleção
│   ├── colecao.h       # Interface e definições da coleção
│   └── output/         # Diretório para arquivos compilados
├── data/
│   └── acervo.txt      # Arquivo de dados da coleção
├── Makefile            # Arquivo de compilação
└── .gitignore          # Arquivos ignorados pelo Git
🚀 Como Usar
Pré-requisitos

Compilador GCC instalado
Sistema operacional Unix/Linux ou Windows com MinGW

Compilação
Para compilar o projeto, execute:
bashmake
Ou compile manualmente:
bashgcc -o acervo src/main.c src/colecao.c -I src/
Execução
Após compilar, execute o programa:
bash./acervo
🛠️ Funcionalidades

✅ Adicionar filmes à coleção
✅ Listar todos os filmes
✅ Buscar filmes por diferentes critérios
✅ Remover filmes da coleção
✅ Salvar e carregar dados automaticamente

📝 Formato de Dados
Os dados são armazenados no arquivo data/acervo.txt em formato texto simples.
