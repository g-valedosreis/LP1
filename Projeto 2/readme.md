## Descrição do Projeto: Sistema de Monitoramento e Estatísticas de Temperatura

Este é um programa desenvolvido em **C** que funciona como um sistema de gerenciamento de dados climáticos diários. Ele permite ao usuário cadastrar registros de datas específicas acompanhadas de suas respectivas temperaturas, gerando métricas estatísticas e análises detalhadas a partir dos dados fornecidos.

O sistema utiliza estruturas de dados (`structs`) para organizar datas e registros, contando com uma interface interativa via console (menu de opções) limitada a um período de até 31 registros (equivalente a um mês).

---

### Principais Funcionalidades

* **[1] Cadastrar Registros:** Permite definir a quantidade de dias a serem monitorados (entre 1 e 31) e realizar a leitura de cada data e sua respectiva temperatura.
* *Validação robusta de dados:* O programa valida se a data inserida é real (tratando corretamente os meses e anos bissextos) e restringe as temperaturas a uma faixa válida de $-50^\circ\text{C}$ a $60^\circ\text{C}$.


* **[2] Mostrar Estatísticas:** Processa os dados meteorológicos salvos e exibe um relatório estatístico completo contendo:
* A maior temperatura registrada.
* A média aritmética das temperaturas.
* A variância e o desvio padrão populacional do período.
* A moda das temperaturas (o valor inteiro que mais se repetiu).


* **[3] Listar Abaixo da Média:** Identifica e lista de forma isolada todos os dias em que a temperatura registrada ficou estritamente abaixo da média calculada para o período.
* **[4] Mostrar Dias da Semana:** Utiliza um algoritmo matemático para calcular e exibir dinamicamente qual era o dia da semana correspondente (ex: Domingo, Segunda-feira, etc.) para cada data cadastrada.

---

### Tecnologias e Conceitos Aplicados

* Linguagem C estruturada.
* Estruturas de Dados (`struct` compostas).
* Passagem de parâmetros por referência (Ponteiros).
* Modularização através de funções.
* Estatística descritiva computacional (Média, Variância, Desvio Padrão e Moda).
* Algoritmo matemático de determinação do dia da semana (Congruência de Zeller / Zeller's Congruence modificado).
