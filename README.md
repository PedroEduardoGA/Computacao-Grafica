# Computacao-Grafica
Repositório destinado para disciplina de Computação Gráfica

A pasta Base contém os exercícios feitos utilizando Python para aprendizado de conceitos iniciais de computação gráfica, ja a pasta OpenGL contém programas implementados em C++ utilizando o Glut.

## Passo a passo para execução de um "projeto" Glut com VsCode
  Instação e configuração:
  -  Instale o MinGW e configure o MinGW Installer para instalar o MinGWbase, compilador com g++ e g++ obj
  -  Adicione na variável ambiente do PATH o caminho para o bin do MinGW, por padrão será: C:\MinGW\bin
  -  Instale VsCode e as extensões para C/C++
  
  Agora para criar e executar um projeto:
  - Para todo "projeto" que for fazer, crie uma pasta e copie todos arquivos contidos na pasta OpenGL/libs para a pasta do seu "projeto"
  - Quando criado o arquivo .cpp, inclua as seguintes bibliotecas:
  ```c++
	#include <Windows.h> //Caso esteja utilizando windows
	#include "glut.h"
  ```
  - Para compilar o código, utilize o comando (sem chaves e trocando os nomes pro seu cenário): `g++ -o <NOME_DESEJADO> -Wall <NOME_ARQUIVO>.cpp -mwindows glut32.lib -lopengl32 -lglu32`
  - Para executar o projeto e abrir a tela de display, utilize o comando: `.\<NOME_DO_EXECUTAVEL>.exe`
