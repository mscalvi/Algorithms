#include <stdio.h>
#include <string.h>

#define MAX_PATIENTS 100
#define MAX_NAME_LEN 50

typedef struct {
    char nome[MAX_NAME_LEN];
    int estado;  
} Paciente;

Paciente listaPacientes[MAX_PATIENTS];
int totalPacientes = 0;

void adicionarPaciente(const char *nome, int estado) {
    if (totalPacientes < MAX_PATIENTS) {
        strcpy(listaPacientes[totalPacientes].nome, nome);
        listaPacientes[totalPacientes].estado = estado;
        totalPacientes++;
    } else {
        printf("Lista de pacientes esta cheia!\n");
    }
}

int prioridade(int estado) {
    return estado; 
}

const char* nomeEstado(int estado) {
    if (estado == 3) {
        return "pessimo";
    } else if (estado == 2) {
        return "ruim";
    } else if (estado == 1) {
        return "regular";
    }
    return "desconhecido";
}

void atenderPaciente() {
    if (totalPacientes == 0) {
        printf("Nenhum paciente a espera.\n");
        return;
    }

    int indicePrioritario = 0;
    int maiorPrioridade = prioridade(listaPacientes[0].estado);

    for (int i = 1; i < totalPacientes; i++) {
        int prioridadeAtual = prioridade(listaPacientes[i].estado);
        if (prioridadeAtual > maiorPrioridade) {
            indicePrioritario = i;
            maiorPrioridade = prioridadeAtual;
        }
    }

    printf("Atendendo paciente: %s (estado: %s)\n", listaPacientes[indicePrioritario].nome, nomeEstado(listaPacientes[indicePrioritario].estado));

    for (int i = indicePrioritario; i < totalPacientes - 1; i++) {
        listaPacientes[i] = listaPacientes[i + 1];
    }
    totalPacientes--;
}

void exibirPacientes() {
    if (totalPacientes == 0) {
        printf("Nenhum paciente a espera.\n");
        return;
    }

    printf("\nPacientes aguardando:\n");
    for (int i = 0; i < totalPacientes; i++) {
        printf("  %s (estado: %s)\n", listaPacientes[i].nome, nomeEstado(listaPacientes[i].estado));
    }
}

int main() {
    int opcao;
    char nome[MAX_NAME_LEN];
    int estado;

    do {
        printf("\nSistema de Atendimento do Pronto-Socorro\n");
        printf("1. Adicionar paciente\n");
        printf("2. Atender proximo paciente\n");
        printf("3. Exibir pacientes aguardando\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("Nome do paciente: ");
                fgets(nome, MAX_NAME_LEN, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf("Estado do paciente (1-regular, 2-ruim, 3-pessimo): ");
                scanf("%d", &estado);

                if (estado >= 1 && estado <= 3) {
                    adicionarPaciente(nome, estado);
                } else {
                    printf("Estado invalido! Escolha entre 1 (regular), 2 (ruim), 3 (pessimo).\n");
                }
                break;

            case 2:
                atenderPaciente();
                break;

            case 3:
                exibirPacientes();
                break;

            case 4:
                printf("Encerrando o sistema...\n");
                break;

            default:
                printf("Opção invalida!\n");
                break;
        }

    } while (opcao != 4);

    return 0;
}
