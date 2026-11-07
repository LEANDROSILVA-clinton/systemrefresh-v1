# Sumario
# 1 Conceito
# 2 Dependências
# 3 Finalidade
# 4 Execução




# Conceito
Projeto para fins educativos e aprendizado voltado a sistemas embarcados.
O conceito envolve uma aplicação de controle de temperatura onde pode ser usado para diversos dispositivos e para o setor de Hardware.
Tendo como inspiração o dispositivo de medição de temperatura observado em garrafas termicas,mas utilizando engenharia reversa ,foi possível adicionar um comando de ativamento um jato de resfriamento no momento que o dispositivo identificar uma temperatura acima do normal/permitido.

Para facilitar esse monitoramento , a integração do serviço de API gratuito api.weatherapi.com para justamente ter uma estatistica em tempo real do clima.
Com o intuito de evitar o uso indevido de memória da maquina, foi utilzado bibliotecas de gerenciamento de memória em C++ e funções, smart pointer com conexão ao algoritmo pool e alocação direta, o que dessa forma evita memory leak.

# Dependências
CMake - configuração padrão da linguagem C++, criação da build(recomendado instalação)
Linguagem de Programação C++ V26(também recomendo o uso dessa versão para o uso do memory.cpp)
google-test - realização e execução de testes unitarios.
MinGw - instalação e execução de sistemas pelo IDE ou terminal local
MSVC - Compiler e sua configuração




# Finalidade
Sistema de Resfriamento para dispositivos com contato constante ao calor,ativando o sistema após a identificação da temperatura acima do normal.

# Execução

O Requisito para a execução do sistema, é necessário a inclusão das dependêcias citadas anteriormente, após feito a instalação, execute os comandos no terminal
build\Debug\nomeapi - executar a API.
g++ filename.cpp -o filename.exe - compilar o programa
filename.exe - executar o programa

seguindo tais passos ,o programa já estará funcionando


# Observação 
O sistema obtém uma certa limitação de uso caso seja necessário interrompe-ló em uma situação emergencial, você pode conferir no main.cpp! 
Não se trata da versão final do sistema e sim como a 1 versão , futuramente pretendo desenvolver uma versão para linux e outros sistemas operacionais.



# Autor
Desenvolvido por Leandro Bruno para fins educativos e aplicação de conceitos de embedded systems e memory management!
