João Vitor S. Amorim

# Projeto de Controle de Servomotor e LED RGB com Raspberry Pi Pico

# VIDEO EXPLICATIVO:

https://drive.google.com/file/d/1dm6LTfGR-ewUh1jjmiFQ-EAArM-M67MN/view?usp=sharing

# PROJETO NO WOKWI: 

https://wokwi.com/projects/422263353142645761

# Descrição do projeto:

- Este projeto demonstra como controlar um servomotor e um LED RGB usando o microcontrolador Raspberry Pi Pico e a ferramenta educacional BitDogLab. O código foi escrito em C e utiliza o Pico SDK para configurar o módulo PWM (Pulse Width Modulation).

# Funcionalidades

1. Controle do Servomotor:

- Configura o PWM para controlar o ângulo do servomotor.

- Ajusta o servomotor para posições específicas (0, 90 e 180 graus) e aguarda 5 segundos em cada posição.

- Movimenta o servomotor suavemente entre os ângulos de 0 e 180 graus periodicamente.

2. Controle do LED RGB:

- Configura o PWM para controlar as cores do LED RGB.

- Muda a cor do LED RGB conforme o servomotor se movimenta (vermelho, verde e azul).


# Requisitos de Hardware:

- Para implementar o projeto de controle do servomotor e LED RGB com o Raspberry Pi Pico, você precisará dos seguintes componentes de hardware:

1. Raspberry Pi Pico:

- Microcontrolador RP2040 com suporte a programação em C/C++ utilizando o Pico SDK.

2. Servomotor:

- Um servomotor padrão que pode ser controlado via PWM.

3. LED RGB:

- Um LED RGB com pinos separados para cada cor (vermelho, verde, azul).

4. Protoboard e Jumpers:

- Uma protoboard para montar o circuito.

- Jumpers para conectar os componentes ao Raspberry Pi Pico.

5. Fonte de Alimentação:

- Cabo USB para alimentação do Raspberry Pi Pico e programação.

6. Resistores (opcional):

- Resistores podem ser necessários para limitar a corrente que passa pelo LED RGB.


7. Conexões do Servomotor:

- Pino de Sinal do Servomotor: Conectar ao GPIO 22 do Raspberry Pi Pico.

- Pino de Alimentação (VCC) do Servomotor: Conectar ao VCC (3.3V ou 5V) do Raspberry Pi Pico.

- Pino de Terra (GND) do Servomotor: Conectar ao GND do Raspberry Pi Pico.

8. Conexões do LED RGB:

- Pino da Cor Vermelha (R) do LED RGB: Conectar ao GPIO 12 do Raspberry Pi Pico.

- Pino da Cor Verde (G) do LED RGB: Conectar ao GPIO 13 do Raspberry Pi Pico.

- Pino da Cor Azul (B) do LED RGB: Conectar ao GPIO 14 do Raspberry Pi Pico.

- Pino de Terra (GND) do LED RGB: Conectar ao GND do Raspberry Pi Pico.


# Instalação do Pico SDK:

- Siga as instruções no Guia de Configuração do Pico SDK.

1. Configuração do CMakeLists.txt:

2. Certifique-se de que o arquivo CMakeLists.txt esteja configurado corretamente para incluir as bibliotecas necessárias:

*{ cmake
cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake) 

project(pwm_project)

pico_sdk_init()

add_executable(pwm
    pwm.c
) }*


# Funções

1. setup_pwm:

- Configura o pino para a função PWM, define o divisor de clock e o valor máximo do contador (período do PWM).

2. set_servo_position:

- Ajusta o ângulo do servomotor com base na largura do pulso em microsegundos.

3. smooth_servo_movement:

- Move o servomotor suavemente entre duas posições, incrementando ou decrementando o ciclo ativo de ±5µs com um atraso de 10ms.

- Código Principal (main)
- Inicializa o sistema padrão de entrada e saída.

- Configura o PWM para o servomotor e o LED RGB.

- Ajusta o servomotor para posições específicas e aguarda 5 segundos em cada posição.

- Executa a movimentação periódica suave do servomotor e muda a cor do LED RGB conforme o servomotor se movimenta.

#Executando o Projeto: 

- Conecte o Raspberry Pi Pico ao computador usando um cabo USB.

- Compile e carregue o código no Raspberry Pi Pico.

- Observe o servomotor se movendo suavemente entre os ângulos de 0 e 180 graus e o LED RGB piscando conforme o movimento do servomotor.