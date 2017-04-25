#include <stdio.h>

// Rafael Sartori Martins dos Santos (RA: 186154)
int main() {
    int numDias;
    // Recebendo o input do número de dias que será usado (numDias <= 15)
    scanf("%d", &numDias);

    float valorAcoes[5][numDias];
    float diferencaAcoes[5][numDias - 1];
    // Recebendo o input dos valores das ações
    for(int empresa = 1; empresa < 5; empresa++) {
        for(int dia = 0; dia < numDias; dia++) {
            float valor;
            scanf("%f", &valor);
            valorAcoes[empresa][dia] = valor;

            // Preencher, também, a 'empresa zero': que seria a empresa sem lucro
            // nem prejuízo
            if(empresa == 1)
                valorAcoes[0][dia] = 0.0f;

            // Calcular as diferenças das ações entre o dia atual e anterior:
            // Isso nos ajudará a calcular o lucro diretamente, pois
            // diferencaAcoes[empresa][dia] será o lucro/prejuízo entre os dias
            // 'dia' e 'dia - 1'
            // Note que 'dia' é o índice e não representa o "dia real".
            if(dia > 0) {
                diferencaAcoes[empresa][dia - 1] = valorAcoes[empresa][dia] - valorAcoes[empresa][dia - 1];
                // Preencher para a 'empresa zero'
                if(empresa == 1)
                    diferencaAcoes[0][dia - 1] = 0.0f;
            }
        }
    }

    // Debugging input (usando como teste o arq03, pois o lucro máximo não é a
    // soma dos maiores lucros)
    /*for(int empresa = 0; empresa < 5; empresa++) {
        printf("-- Empresa %d\n", empresa);
        for(int dia = 0; dia < (numDias - 1); dia++) {
            printf("dia %d -> %d: variação de %f\n", dia + 1, dia + 2, diferencaAcoes[empresa][dia]);
        }
    }*/

    {
        // Variável do loop
        int finished = 0;

        // Esse vetor será o que representa o número da empresa entre os dias,
        // para contar a diferencaAcoes
        int empresaIntervalo[numDias - 1];
        // Inicializamos ela com zero (o lucro da empresa 0)
        for(int intervalo = 0; intervalo < (numDias - 1); intervalo++) {
            empresaIntervalo[intervalo] = 0;
        }
        /*
         * O loop terminará quando todas as possibilidades forem percorridas:
         * isso ocorrerá quando empresaIntervalo[interalo] for 4 para todos os,
         * dias, pois faremos o loop de 0 -> 4 para todos os dias começando do
         * índice do último dia (empresaIntervalo[numDias - 2])
         */

        // Informações para lucro máximo
        float lucroMaximo = 0.0f;
        char mensagensOutputLucroMaximo[5][50];
        for(int i = 0; i < 5; i++) {
            // Inicializando com '\0' para não imprimirmos nada
            mensagensOutputLucroMaximo[i][0] = '\0';
        }
        // Definindo o output para quando todas as ações tem prejuízo
        sprintf(mensagensOutputLucroMaximo[4], "Lucro: %.2f\n", lucroMaximo);

        while(!finished) {
            /*for(int i = 0; i < numDias - 1; i++)
                printf("empresa[%d] = %d, ", i, empresaIntervalo[i]);
            printf("\n");*/

            int iteracaoValida = 1;
            float lucro = 0.0f;

            char mensagensOutput[5][50];
            for(int i = 0; i < 5; i++) {
                // Inicializando com '\0' para não imprimirmos nada
                mensagensOutput[i][0] = '\0';
            }

            int empresasUsadas[] = {0, 0, 0, 0};

            // O invervalo de compra é o primeiro intervalo da empresa cuja ação
            // teve efeito, e o intervalo de venda é o último intervalo da empre-
            // sa cuja ação teve efeito.
            int intervaloCompra = -1, intervaloVenda = -1;


            // Fazemos o loop de dias de diferença, isto é, os dias em que houve
            // lucro/prejuízo (os intervalos), e não os dias reais
            for(int intervalo = 0; intervalo < (numDias - 1); intervalo++) {
                int empresa = empresaIntervalo[intervalo];

                // Se estamos em uma empresa, vamos marcar o primeiro intervalo
                // em que compramos a ação
                if(empresa > 0 && intervaloCompra < 0) {
                    if(!empresasUsadas[empresa - 1]) {
                        // Se a empresa nunca foi usada anteriormente, compramos
                        // a ação, já que atualmente estávamos sem nenhuma pois
                        // vendemos
                        intervaloCompra = intervalo;
                    } else {
                        // Quebrou a regra de não voltar à mesma empresa depois
                        // de venda
                        iteracaoValida = 0;
                        break;
                    }
                }

                // Vendemos a ação quando havíamos comprado uma ação e:
                // (i) o próximo intervalo não existe (fim)
                // (ii) a empresa do próximo intervalo é diferente
                if(intervaloCompra >= 0 && ((intervalo + 1) == (numDias - 1)
                    || empresaIntervalo[intervalo] != empresaIntervalo[intervalo + 1])) {
                    intervaloVenda = intervalo;
                    //printf("Empresa = %d, intervaloCompra = %d, intervaloVenda = %d\n", empresaIntervalo[intervalo], intervaloCompra, intervaloVenda);

                    float lucroAcao = 0.0f;
                    int empresaCompra = empresaIntervalo[intervaloCompra];

                    // Calculando o lucro da ação
                    for(int i = intervaloCompra; i <= intervaloVenda; i++) {
                        lucroAcao += diferencaAcoes[empresaCompra][i];
                    }

                    // Somando ao lucro total calculado
                    lucro += lucroAcao;
                    sprintf(mensagensOutput[empresaCompra - 1], "acao %d: compra %d, venda %d, lucro %.2f\n", empresaCompra, intervaloCompra + 1, intervaloVenda + 2, lucroAcao);
                    //printf("acao %d: compra %d, venda %d, lucro %.2f\n", empresaCompra, intervaloCompra, intervaloVenda + 1, lucroAcao);

                    // Redefinindo dia de compra e venda
                    intervaloCompra = -1;
                    intervaloVenda = -1;

                    // Adicionando como empresa usada
                    empresasUsadas[empresaCompra - 1] = 1;
                }
            }

            if(iteracaoValida) {
                // Função não ensinada: formata a string e guarda em mensagensOutput
                // da mesma forma que printf, porém sem imprimir, justamente o que pre-
                // cisamos.
                sprintf(mensagensOutput[4], "Lucro: %.2f\n", lucro);
                //printf("Lucro: %.2f\n\n\n", lucro);

                if(lucro > lucroMaximo) {
                    // Substituindo valores máximos
                    lucroMaximo = lucro;
                    for(int i = 0; i < 5; i++) {
                        for(int j = 0; j < 50; j++) {
                            // Copiando a string
                            mensagensOutputLucroMaximo[i][j] = mensagensOutput[i][j];
                            if(mensagensOutput[i][j] == '\0')
                                break;
                        }
                    }
                }
            }

            {
                int incrementacaoValida = 0;
                int i = 0;
                while(!incrementacaoValida) {
                    // Trabalharemos com o index (numDias - 2) - i, pois começa-
                    // remos do último índice e subiremos até o índice 0
                    int index = (numDias - 2) - i;
                    int valorAtual = empresaIntervalo[index];

                    // Se extrapolamos o limite, devemos definir como zero e
                    // alterar o próximo índice
                    if((valorAtual + 1) > 4) {
                        // Se extrapolamos o limite do index zero, terminamos
                        if(index == 0) {
                                finished = 1;
                                break;
                        }
                        empresaIntervalo[index] = 0;
                        // Na próxima iteração, o programa irá tentar incrementar
                        // o próximo índice, até chegar no índice zero
                        i++;
                    } else {
                        // Já que não extrapolamos o limite, tudo ocorrerá normal-
                        // mente ;)
                        empresaIntervalo[index]++;
                        incrementacaoValida = 1;
                    }

                    if(incrementacaoValida) {
                        // Para economizar tempo (entradas 13, 14 e 15 estão
                        // extrapolando o tempo limite), vamos pular combina-
                        // ções que envolvam uma empresa mais de um intervalo
                        int previewEmpresasUsadas[] = {0, 0, 0, 0};
                        int intervaloCompra, empresa;
                        for(int intervalo = 0; intervalo < (numDias - 1); intervalo++) {
                            intervaloCompra = -1;
                            empresa = empresaIntervalo[intervalo];

                            // Se compramos de uma empresa, registramos
                            if(empresa != 0 && intervaloCompra < 0) {
                                // Se podemos prever que a combinação não segue
                                // a regra, pulamos todos os calculos pesados
                                if(previewEmpresasUsadas[empresa - 1]) {
                                    incrementacaoValida = 0;
                                    //puladas++;
                                    break;
                                }
                                intervaloCompra = intervalo;
                            }

                            // Se compramos e vendemos, vamos marcar a venda
                            if(intervaloCompra >= 0 && empresa != empresaIntervalo[intervalo + 1]) {
                                previewEmpresasUsadas[empresa - 1] = 1;
                                intervaloCompra = -1;
                            }
                        }
                    }
                }
            }
        }

        // Imprimindo lucro máximo
        for(int i = 0; i < 5; i++) {
            printf("%s", mensagensOutputLucroMaximo[i]);
        }
        //printf("pulamos %d\n", puladas); // Meu deus.. no arquivo 15 foram 603 mil combinações ignoradas
    }
}
