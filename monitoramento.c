# Projeto: Estruturas de Repetição - Monitoramento de Temperatura

## 1. Identificação
* **Nome do Aluno:** Caio Oliveira Guimarães
* **Disciplina:** Algoritmos e Programação / Estruturas de Dados
* **Professora:** Profa. Karla Sartin
* **Título do Projeto:** Sistema de Monitoramento de Temperatura com Alerta Crítico

## 2. Objetivo
O programa visa monitorar leituras contínuas de temperatura em tempo real, validando as entradas do utilizador e emitindo alertas caso a temperatura exceda um limite pré-determinado. O objetivo principal é interromper a operação automaticamente assim que forem identificadas três medições consecutivas acima do limite de segurança.

## 3. Funcionamento do Programa
* **Definição do Limite:** O utilizador define a temperatura máxima permitida no início da execução.
* **Leitura Contínua:** As leituras são inseridas uma a uma através do terminal.
* **Tratamento de Entradas Inválidas:** Entradas não numéricas ou valores incoerentes são capturados por validação de `scanf`, limpando o buffer de entrada e solicitando um novo valor sem interromper o programa.
* **Identificação de Alerta:** Cada medição é comparada com a temperatura limite definida.
* **Contagem Consecutiva:** Uma variável de contagem é incrementada quando a leitura ultrapassa o limite. Se uma medição válida estiver dentro do limite normal, o contador é reiniciado para 0.
* **Encerramento:** O loop principal encerra imediatamente assim que o contador atinge 3 leituras consecutivas acima do limite.

## 4. Estruturas de Repetição Utilizadas
* **`do...while`:** Utilizado na fase inicial de configuração para garantir que o utilizador insira um limite de temperatura válido (positivo) antes de avançar para o monitoramento.
* **`while`:** Utilizado no ciclo principal do monitoramento, mantendo a leitura contínua de dados enquanto o número de leituras críticas consecutivas for inferior a 3 (`acimaDoLimiteConsecutivos < 3`).
* **Justificativa:** A combinação garante a execução obrigatória de pelo menos uma validação inicial de parâmetros (`do...while`) e o controlo orientado a condição de paragem dinâmica (`while`).

## 5. Como Executar
Para compilar e executar o código C, utilize os seguintes comandos no terminal (ex: GCC):

\`\`\`bash
# Compilar o código-fonte
gcc monitoramento.c -o monitoramento

# Executar o programa
./monitoramento
\`\`\`

## 6. Testes Realizados

### Teste 1: Validação de Entradas Inválidas
* **Entrada:** `abc`, `-10` (no limite inicial).
* **Resultado:** O programa rejeitou o texto não numérico e o valor negativo, solicitando novamente uma entrada válida sem falhar.

### Teste 2: Temperaturas Acima do Limite, Porém Não Consecutivas
* **Configuração:** Limite = 30.0 °C.
* **Entradas:** `35.0` (Alerta 1/3) -> `25.0` (Reset para 0) -> `32.0` (Alerta 1/3) -> `28.0` (Reset para 0).
* **Resultado:** O contador foi reiniciado sempre que uma leitura normal ocorreu, mantendo o programa em execução contínua.

### Teste 3: Três Temperaturas Consecutivas Acima do Limite
* **Configuração:** Limite = 30.0 °C.
* **Entradas:** `31.0` (Alerta 1/3) -> `34.0` (Alerta 2/3) -> `36.0` (Alerta 3/3).
* **Resultado:** O programa identificou o 3º alerta seguido e encerrou a execução exibindo a mensagem de alerta crítico de segurança.
