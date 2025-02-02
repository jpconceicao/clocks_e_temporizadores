# Controle de LEDs RGB com Botão na Raspberry Pi Pico

Este projeto implementa o controle de um **LED RGB** utilizando um botão conectado à **Raspberry Pi Pico**. O LED acende em três cores diferentes e apaga progressivamente ao longo do tempo após o acionamento do botão.

## Funcionalidade
- O sistema aguarda o pressionamento do botão (GPIO **5**).
- Quando o botão é pressionado, os três LEDs do LED RGB acendem simultaneamente.
- A cada 3 segundos, um dos LEDs apaga até que todos estejam desligados.
- O ciclo só se repete quando o botão for pressionado novamente.

## Hardware Utilizado
- Placa **Raspberry Pi Pico**
- **LED RGB**
- **Botão** para acionamento

## Pinos Utilizados

### LED RGB
- **Vermelho:** GPIO **13**
- **Verde:** GPIO **11**
- **Azul:** GPIO **12**

### Botão
- **Entrada Digital:** GPIO **5**

## Funcionamento do Código
O código gerencia os estados do LED RGB utilizando um **botão** e um **timer**:
1. O botão é pressionado e **todos os LEDs acendem**.
2. Após **3 segundos**, um LED apaga.
3. A cada **3 segundos seguintes**, mais um LED apaga até que todos estejam desligados.
4. O sistema aguarda um novo acionamento do botão para reiniciar o ciclo.

## Como Compilar e Executar
1. Certifique-se de que o **SDK do Raspberry Pi Pico** está configurado corretamente.
2. Compile o código utilizando **CMake**:
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```
3. Faça o upload do binário gerado para a **Raspberry Pi Pico**.

## Link do vídeo
- https://drive.google.com/file/d/1EvVKY5dvnikKhRuBjCfVrDZ1H6dIZMnQ/view?usp=sharing

## Observações
- Foi implementado um **debounce** de 50ms para evitar leituras falsas do botão.
- Um **timer** gerencia o desligamento progressivo dos LEDs.

## Autor
Desenvolvido por Jorge Palma

