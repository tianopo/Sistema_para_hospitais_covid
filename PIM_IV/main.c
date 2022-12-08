#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct endereco{
    char rua[50];
    int numero;
    char bairro[50];
    char cidade[50];
    char estado[3];
    char cep[20];
} residencia;

typedef struct comorbidades{
    char diabetes;
    char obesidade;
    char hipertensao;
    char tuberculose;
}doenca;

struct dadosPaciente{
    int id;
    char nome[50];
    char cpf[20];
    char telefone[20];
    residencia moradia;
    char diagnostico[100];
    char dataDiagnostico[50];
    int anoNascimento;
    doenca patologia;
};

struct dadosPaciente paciente;

void main(){
    FILE *arquivo;
    int i = 0,idade;
    char sn,principal,login[15] = "hospitalAlvo",login1[15],senha[15] = "saude",senha1[15];

    while(i==0){
        printf("Digite o Login do hospital: ");
        scanf("%s", login1);
        fflush(stdin);

        printf("Digite a Senha: ");
        scanf("%s", senha1);
        fflush(stdin);

        if (strcmp(login, login1) == 0 && strcmp(senha, senha1) == 0){
            printf("LOGADO!\n");
            i++;
        }else{
            printf("Login ou senha nao conferem\n");
        }
    }

    printf("O paciente foi diagnosticado com Covid-19 e carece de acompanhamento e monitoramento? s/n \n");
    scanf("%c",&principal);
    fflush(stdin);
    while(principal == 's'){

        printf("Vamos cadastrar o paciente\n");
        printf("Qual o nome do paciente?\n");
        fgets(paciente.nome,99,stdin);

        printf("Qual o cpf do paciente?\n");
        fgets(paciente.cpf,19,stdin);

        printf("Qual o telefone?\n");
        fgets(paciente.telefone,19,stdin);

        printf("Qual o ano do nascimento do paciente?\n");
        scanf("%d",&paciente.anoNascimento);
        fflush(stdin);

        printf("Gostaria de preencher o endereco agora? s/n \n");
        scanf("%c",&sn);
        fflush(stdin);

        if(sn == 's'){
            printf("Qual o cep?\n");
            fgets(paciente.moradia.cep,19,stdin);

            printf("Qual o nome da rua?\n");
            fgets(paciente.moradia.rua,19,stdin);

            printf("Qual o numero?\n");
            scanf("%d",&paciente.moradia.numero);
            fflush(stdin);

            printf("Qual o nome do bairro?\n");
            fgets(paciente.moradia.bairro,49,stdin);

            printf("Qual a sigla do estado?\n");
            fgets(paciente.moradia.estado,2,stdin);

            printf("Qual o nome da cidade?\n");
            fgets(paciente.moradia.cidade,49,stdin);

        }

        printf("Qual foi o diagnostico?\n");
        fgets(paciente.diagnostico,99,stdin);

        printf("Qual foi a data do diagnostico? dia/mes/ano\n");
        fgets(paciente.dataDiagnostico,49,stdin);

        printf("Precisa preencher as comorbidades? s/n \n");
        scanf("%c",&sn);
        fflush(stdin);

        if(sn == 's'){
            printf("O paciente e...\n");
            printf("diabetico? s/n \n");
            scanf("%c",&paciente.patologia.diabetes);
            fflush(stdin);

            printf("obeso? s/n \n");
            scanf("%c",&paciente.patologia.obesidade);
            fflush(stdin);

            printf("hipertenso? s/n \n");
            scanf("%c",&paciente.patologia.hipertensao);
            fflush(stdin);

            printf("tuberculoso? s/n \n");
            scanf("%c",&paciente.patologia.tuberculose);
            fflush(stdin);
        }
        idade = 2022 - paciente.anoNascimento;
        if(idade > 65){
            printf("O paciente pertence ao grupo de risco\n");
            arquivo = fopen("grupo_de_risco3.txt","a");
            fprintf(arquivo,"Cep: %s\nIdade: %d\n",paciente.moradia.cep,idade);
            fclose(arquivo);
            printf("CEP e idade gravados para a Central da Secretaria de Saude\n");
        }
        principal = 'n';
    }

    paciente.id++;
    printf("Paciente Cadastrado! \n");

    printf("nome: %s\ncpf: %s\ntelefone:%s\nano de nascimento: %d\n"
           ,paciente.nome, paciente.cpf, paciente.telefone,paciente.anoNascimento);
    printf("cep: %s\nrua: %s\nn: %d\nbairro: %sestado: %s\ncidade: %s\n",
            paciente.moradia.cep,paciente.moradia.rua,paciente.moradia.numero,
            paciente.moradia.bairro,paciente.moradia.estado,paciente.moradia.cidade);
    printf("Diabetes: %c\nObesidade: %c\nHipertensao: %c\nTuberculose: %c\n",
           paciente.patologia.diabetes,paciente.patologia.obesidade,
           paciente.patologia.hipertensao,paciente.patologia.tuberculose);
    getch();
}
