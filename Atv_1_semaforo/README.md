# Semáforo com LED RGB e LEDs Individuais na Placa BitDog Lab

Este projeto implementa um sistema de semáforo utilizando a placa **BitDog Lab**. O sistema utiliza um **LED RGB** e três LEDs individuais para simular a troca de estados do semáforo.

## Funcionalidade
O programa alterna entre os estados **Vermelho**, **Amarelo** e **Verde** a cada 3 segundos. A mudança de estado é indicada tanto pelos LEDs individuais quanto pelo LED RGB.

## Hardware Utilizado
- Placa **BitDog Lab**
- **LED RGB**
- **Três LEDs individuais com seus respectivos resistores** (Vermelho, Amarelo e Verde)

## Pinos Utilizados
Os seguintes pinos são utilizados para controle dos LEDs:

### LEDs Individuais (para simulação no protoboard)
- **Vermelho:** GPIO **18**
- **Amarelo:** GPIO **19**
- **Verde:** GPIO **20**

### LED RGB
- **Vermelho:** GPIO **13**
- **Verde:** GPIO **11**
- **Azul:** GPIO **12**

## Funcionamento do Código
O código segue a lógica de funcionamento de um semáforo:
1. **Estado Vermelho:** Ativa o LED vermelho e o LED RGB na cor vermelha.
2. **Estado Amarelo:** Ativa o LED amarelo e o LED RGB na cor amarela.
3. **Estado Verde:** Ativa o LED verde e o LED RGB na cor verde.
4. O ciclo se repete a cada 3 segundos.

## Como Compilar e Executar
1. Certifique-se de que o **SDK do Raspberry Pi Pico** está configurado corretamente.
2. Compile o código utilizando **CMake**:
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```
3. Faça o upload do binário gerado para a **BitDog Lab**.

## Observações
- Os pinos **18, 19 e 20** são utilizados para simular o comportamento do semáforo em um **protoboard** com LEDs individuais, caso o LED RGB não esteja disponível.
- O código utiliza um **timer repetitivo** para alterar os estados automaticamente.

## Autor
Desenvolvido por Jorge Palma Conceição

