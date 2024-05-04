# Flight Astronaut System

## Como Rodar o Projeto
- Na pasta principal do projeto rode o comando:
  ```
  cmake -B build
  cmake --build build
  ```
  - Será criado um diretório chamado `build`.
- No diretório `build`, execute o comando `make` e, após isso, execute o programa:
  ```
  cd build
  make
  ./project
  ```

## Do que se Trata
Este projeto é um sistema de gerenciamento de voos espaciais da disciplina **Linguagens de programação I**, que permite o registro de astronautas e voos, a adição e remoção de astronautas de voos, o lançamento de voos, a finalização de voos e a listagem de voos e astronautas.

### Funcionalidades:
O sistema oferece as seguintes funcionalidades:

- Registro de astronautas e voos
- Adição e remoção de astronautas de voos
- Lançamento de voos
- Finalização de voos
- Listagem de voos e astronautas
- Listagem de astronautas mortos

## Estrutura de Diretórios do Projeto
- `src/`: Este diretório contém todos os arquivos de código-fonte do projeto.
- `includes/`: Contém os códigos dos arquivos .hpp, suas especificações.
- `includes/enums/`: Contém todos os arquivos que possuem enums.
- `impl/`: Contém as implmentações dos arquivos ` .hpp`.