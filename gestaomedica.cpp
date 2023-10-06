#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

struct Paciente
{
    int codpaciente;
    int cpf;
    char nomepaciente[20];
    int idade;
    char sexo[2];
    int telefone;
    char endereco[20];
    char cidade[20];
    char uf[2];
    int status;
};

struct Indice_paciente
{

    int codigoidxpaciente;
    int enderidxpaciente;
};

struct Especializacao
{
    int codigo;
    char nomeespecializacao[20];
};

struct Indice_especializacao
{
    int codigoidxespecializacao;
    int enderidxespecializacao;
};

struct Medico
{
    int codigomedico;
    int crm;
    char nomemedico[20];
    int idade;
    char sexomedico[2];
    int telefoneMedico;
    int codigo_especializacao;
    float valorconsulta;
    int statusmed;
};

struct Indice_medico
{
    int codigoidxmedico;
    int enderidxmedico;
};

struct ConsultaMarcada
{
    int cpf_paciente;
    int crm_medico;
    int  data;
    int horario;
};

struct Indice_consulta
{
    int codigoidxconsulta;
    int enderidxconsulta;
};

void leitura_paciente(struct Paciente cli[], int &cont)
{
    int i = 0;
    for (int saida = 1; i < cont && saida != 0; i++)
    {
        cout << "\n\nCodigo Paciente " << (i + 1) << ": ";
        cin >> cli[i].codpaciente;
        if (cli[i].codpaciente > 0)
        {
            cout << "Nome: ";
            cin >> cli[i].nomepaciente;
            cout << "CPF: ";
            cin >> cli[i].cpf;
            cout << "Idade: ";
            cin >> cli[i].idade;
            cout << "Sexo [M/F]";
            cin >> cli[i].sexo;
            cout << "Telefone: ";
            cin >> cli[i].telefone;
            cout << "Cidade: ";
            cin >> cli[i].cidade;
            cout << "Uf: ";
            cin >> cli[i].uf;
            cout << "Endereco: ";
            cin >> cli[i].endereco;
            cli[i].status = 0;
        }
        else
            saida = 0;
    }
    cont = i;
}

void leitura_indice_paciente(struct Indice_paciente idx[], int cont)
{

    for (int i = 0; i < cont; i++)
    {
        cout << "\n\nCodigo do Indice " << (i) << ": ";
        cin >> idx[i].codigoidxpaciente;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idx[i].enderidxpaciente;
    }
}

void leitura_especializacao(struct Especializacao cli[], int &cont)
{
    int i = 0;
    for (int saida = 1; i < cont && saida != 0; i++)
    {
        cout << "\n\nCodigo Especializacao " << (i + 1) << ":";
        cin >> cli[i].codigo;
        if (cli[i].codigo > 0)
        {
            cout << "\nNome Especializacao: ";
            cin >> cli[i].nomeespecializacao;
        }
        else
            saida = 0;
    }
    cont = i;
}

void leitura_indicie_especializacao(struct Indice_especializacao idx[], int cont)
{

    for (int i = 0; i < cont; i++)
    {
        cout << "\n\nCodigo do Indice " << (i) << ": ";
        cin >> idx[i].codigoidxespecializacao;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idx[i].enderidxespecializacao;
    }
}

void leitura_medico(struct Medico cli[], int &cont)
{
    int i = 0;
    for (int saida = 1; i < cont && saida != 0; i++)
    {
        cout << "\n\nCodigo do Medico: " << (i + 1) << ": ";
        cin >> cli[i].codigomedico;
        if (cli[i].codigomedico > 0)
        {
            cout << "Nome Medico: ";
            cin >> cli[i].nomemedico;
            cout << "CRM: ";
            cin >> cli[i].crm;
            cout << "IDADE: ";
            cin >> cli[i].idade;
            cout << "SEXO: ";
            cin >> cli[i].sexomedico;
            cout << "Telefone: ";
            cin >> cli[i].telefoneMedico;
            cout << "Codigo Especializacao: ";
            cin >> cli[i].codigo_especializacao;
            cout << "Valor Consulta: ";
            cin >> cli[i].valorconsulta;
            cli[i].statusmed = 0;
        }
        else
            saida = 0;
    }
    cont = i;
}

void leitura_indicie_medico(struct Indice_medico idx[], int cont)
{
    for (int i = 0; i < cont; i++)
    {
        cout << "\n\nCodigo do Indice " << (i) << ": ";
        cin >> idx[i].codigoidxmedico;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idx[i].enderidxmedico;
    }
}

void inclusao_paciente(struct Indice_paciente idx[], struct Paciente cli[], int &cont, int cod)
{

    cont++;
    cli[cont].codpaciente = cod;
    cout << "\nNome: ";
    cin >> cli[cont].nomepaciente;
    cout << "CPF: ";
    cin >> cli[cont].cpf;
    cout << "Idade: ";
    cin >> cli[cont].idade;
    cout << "Sexo [M/F]: ";
    cin >> cli[cont].sexo;
    cout << "Telefone: ";
    cin >> cli[cont].telefone;
    cout << "Endereco: ";
    cin >> cli[cont].endereco;
    cout << "Cidade: ";
    cin >> cli[cont].cidade;
    cout << "UF: ";
    cin >> cli[cont].uf;
    cli[cont].status = 1;
    int i;
    for (i = cont - 1; idx[i].codigoidxpaciente > cod; i--)
    {
        idx[i + 1].codigoidxpaciente = idx[i].codigoidxpaciente;
        idx[i + 1].enderidxpaciente = idx[i].enderidxpaciente;
    }
    idx[i + 1].codigoidxpaciente = cod;
    idx[i + 1].enderidxpaciente = cont;
}

int buscaaleatoria_especializacao(struct Indice_especializacao idx[], struct Especializacao cli[], int &cont, int cod);

void inclusao_medico(struct Indice_medico idx[], struct Medico cli[], int &cont, int cod, struct Indice_especializacao idxespec[], struct Especializacao cliespec[])
{
    cont++;

    cli[cont].codigomedico = cod;
    cout << "\nNOME: ";
    cin >> cli[cont].nomemedico;
    cout << "CRM: ";
    cin >> cli[cont].crm;
    cout << "IDADE: ";
    cin >> cli[cont].idade;
    cout << "SEXO: ";
    cin >> cli[cont].sexomedico;
    cout << "TELEFONE: ";
    cin >> cli[cont].telefoneMedico;
    cout << "CODIGO ESPECIALIZACAO: ";
    cin >> cli[cont].codigo_especializacao;
    int codteste = cli[cont].codigo_especializacao;
    codteste = buscaaleatoria_especializacao(idxespec, cliespec, cont, codteste);
    if (codteste > -2)
    {
        cout << cliespec[codteste-1].nomeespecializacao << endl;
    }
    cout << "VALOR CONSULTA: ";
    cin >> cli[cont].valorconsulta;

    int i;
    for (i = cont - 1; idx[i].codigoidxmedico > cod; i--)
    {
        idx[i + 1].codigoidxmedico = idx[i].codigoidxmedico;
        idx[i + 1].enderidxmedico = idx[i].enderidxmedico;
    }
    idx[i + 1].codigoidxmedico = cod;
    idx[i + 1].enderidxmedico = cont;
}

int buscaaleatoria_especializacao(struct Indice_especializacao idx[], struct Especializacao cli[], int &cont, int cod)
{
    int i = 0, f = cont;
    int m = (i + f) / 2;
    ;
    for (; f >= i && cod != idx[m].codigoidxespecializacao; m = (i + f) / 2)
    {
        if (cod > idx[m].codigoidxespecializacao)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == idx[m].codigoidxespecializacao)
    {
        cod = idx[m].codigoidxespecializacao;
        return cod;
    }
    else
        cout << "\n ESPECIALIZACAO NAO ENCONTRADA";
}

void buscaaleatoria_especializacao2(struct Indice_especializacao idx[], struct Especializacao test[], int &cont, int cod, struct Medico cli[], struct Indice_medico idxmed[])
{

    int i = 0, f = cont;
    int m = (i + f) / 2;

    for (; f >= i && cod != cli[m].codigo_especializacao; m = (i + f) / 2)
    {
        if (cod > cli[m].codigo_especializacao)
            i = m + 1;
        else
            f = m - 1;
    }

    if (cod == cli[m].codigo_especializacao && cli[m].statusmed ==0)
    {
        cout << "NOME: " << cli[m].nomemedico << endl;
        cout << "CRM: " << cli[m].crm << endl;
        cout << "VALOR: " << cli[m].valorconsulta << endl;
    }
    else
        cout << "\n MEDICO NAO ENCONTRADO";
}

void buscaaleatoria_paciente(struct Indice_paciente idx[], struct Paciente cli[], int &cont, int cod)
{

    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].codigoidxpaciente; m = (i + f) / 2)
    {
        if (cod > idx[m].codigoidxpaciente)
            i = m + 1;
        else
            f = m - 1;
    }

    if (cod == idx[m].codigoidxpaciente)
    {
        system("cls");
        cout << "\n\nPACIENTE JA CADASTRADO - NAO PODE SER INCLUIDO";
        i = idx[m].enderidxpaciente;
        cout << "\nCodigo Paciente:" << cli[i].codpaciente << endl;
        cout << "\tNome: " << cli[i].nomepaciente << endl;
        cout << "\tCPF: " << cli[i].cpf << endl;
        cout << "\tIdade: " << cli[i].idade << endl;
        cout << "\tSexo: " << cli[i].sexo << endl;
        cout << "\tTelefone: " << cli[i].telefone << endl;
        cout << "\tEndereco: " << cli[i].endereco << endl;
        cout << "\tCidade: " << cli[i].cidade << endl;
        cout << "\tUf: " << cli[i].uf << endl;
    }
    else
        inclusao_paciente(idx, cli, cont, cod);
    getch();
}

void mostrar_espec(struct Especializacao cli[], int &cont)
{
    int i = 0;
    for (i = 0; i < cont; i++)
    {

        cout << cli[i].codigo << cli[i].nomeespecializacao << endl;
    }
}

void buscaaleatoria_medico(struct Indice_medico idx[], struct Medico cli[], int &cont, int cod, struct Indice_especializacao idxespec[], struct Especializacao cliespec[])
{

    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != idx[m].codigoidxmedico; m = (i + f) / 2)
    {
        if (cod > idx[m].codigoidxmedico)
            i = m + 1;
        else
            f = m - 1;
    }

    if (cod == idx[m].codigoidxmedico && cli[m].statusmed ==0)
    {
        system("cls");
        cout << "\n\nMEDICO JA CADASTRADO - NAO PODE SER INCLUIDO";
        i = idx[m].enderidxmedico;
        cout << "\nCODIGO MEDICO: " << cli[i].codigomedico << endl;
        cout << "\tNOME: " << cli[i].nomemedico << endl;
        cout << "\tCRM: " << cli[i].crm << endl;
        cout << "\tIDADE: " << cli[i].idade << endl;
        cout << "\tSEXO: " << cli[i].sexomedico << endl;
        cout << "\tTELEFONE: " << cli[i].telefoneMedico << endl;
        cout << "\tVALOR CONSULTA: " << cli[i].valorconsulta;
    }
    else
              inclusao_medico(idx, cli, cont, cod, idxespec, cliespec);
    getch();
}

int buscaaleatoria_medico2(struct Indice_medico idx[], struct Medico cli[], int &cont, int cod, struct Indice_especializacao idxespec[], struct Especializacao cliespec[])
{

    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != cli[m].crm; m = (i + f) / 2)
    {
        if (cod > cli[m].crm)
            i = m + 1;
        else
            f = m - 1;
    }

    if (cod == cli[m].crm && cli[m].statusmed ==0)
    {

        cout << "\tNOME: " << cli[i].nomemedico << endl;
        cout << "\tCRM: " << cli[i].crm << endl;
        return 1;

    }
}

void inserir_consulta(struct ConsultaMarcada cli[], struct Indice_consulta idx[], int crm, int cpf, int data, int horario, int &cont)
{

    cont++;
    cli[cont].cpf_paciente = cpf;
    cli[cont].crm_medico = crm;
    cli[cont].data = data;
    cli[cont].horario = horario;
    system("cls");
    cout << "CONSULTA MARCADA!!! ";
}

void buscaaleatoria_medico4(struct Indice_medico idx[], struct Medico cli[], int &cont, int cod, struct Indice_especializacao idxespec[], struct Especializacao cliespec[])
{

    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != cli[m].crm; m = (i + f) / 2)
    {
        if (cod > cli[m].crm)
            i = m + 1;
        else
            f = m - 1;
    }

    if (cod == cli[m].crm && cli[m].statusmed==0)
    {
        cout << "\tNOME: " << cli[i].nomemedico << endl;
        cout << "\tCRM: " << cli[i].crm << endl;
        cli[i].statusmed =1 ;
        cout<<"MEDICO EXCLUIDO";

    }
    else
        cout << "\nMEDICO NAO ENCONTRADO";
    getch();
}

void faturamento(struct ConsultaMarcada consul[],int &contConsulta,struct Medico cli[],int &contMedico){

     cout << "Faturamento Clinica!\n\n\n";
    int soma = 0, total;
    int j;
    for (int i = 0; i < contConsulta; i++)
    {
        j = consul[i].crm_medico;
        for (int k = 0; k <= contMedico; k++)
        {
            if (j == cli[k].crm)
            {
                soma += cli[k].valorconsulta;
            }
        }
    }

    total = soma * 0.05;

    cout << "Faturamento Da clinica: R$ " << total << endl;

}

void maiorMenor(struct ConsultaMarcada consultas[], int &contConsulta, struct Medico cli[], int &contMedico)
{
    cout << "Menor valor e maior Valor faturado"<<endl;
    int maior = cli[0].valorconsulta;
    int menor = cli[0].valorconsulta;
    int crm_aux;

    for (int i = 0; i <= contConsulta; i++)
    {
        crm_aux = consultas[i].crm_medico;
        for (int k = 0; k <= contMedico; k++)
        {
            if (crm_aux == cli[k].crm)
            {
                if (cli[k].valorconsulta > maior) {
                    maior = cli[k].valorconsulta;
                } else if (cli[k].valorconsulta < menor) {
                    menor = cli[k].valorconsulta;
                }
            }
        }
    }
    cout << "menor Valor: " << menor << endl;
    cout << "maior Valor: " << maior << endl;
}


int main()
{

    struct Paciente paciente[20];
    struct Indice_paciente indicepaciente[20];
    int contpaciente = 0;

    struct Medico medico[20];
    struct Indice_medico indicemedico[20];
    int contmedico = 0;

    struct Especializacao especializacao[20];
    struct Indice_especializacao indice_espec[20];
    int contespecializacao = 0;

    struct ConsultaMarcada consulta[20];
    struct Indice_consulta indice_consulta[20];
    int contconsulta = 0;

    int data;
    int horario;
    int cpfpaciente;
    int crmmedico;
    int codexcluir;

    int varleitura = 1;
    while (varleitura > 0 && varleitura < 10)
    {

        cout << "\t\tMENU";
        cout << "\n-------------------\n";
        cout << "\t1- Cadastrar" << endl;
        cout << "\t2- Inserir" << endl;
        cout << "\t3- Busca por Especializacao" << endl;
        cout << "\t4- Agendar Consulta" << endl;
        cout << "\t5- Excluir Medico" << endl;
        cout << "\t6- Faturamento" <<endl;
        cout << "\t7- Maior e Menor Faturamento"<<endl;
        cout << "-------------------\n";
        cout << "\tEscolha Opcao: ";
        cin >> varleitura;
        system("cls");

        switch (varleitura)
        {
        case 1:
            cout << "Selecione o desejado" << endl;
            cout << "\t1- Paciente" << endl;
            cout << "\t2- Especializacao" << endl;
            cout << "\t3- Medico" << endl;
            cout << "\tDigite a opcao: ";
            int escolhacadastro;
            cin >> escolhacadastro;
            system("cls");

            if (escolhacadastro == 1)
            {

                cout << "\nDigite a quantidade a cadastrar: ";
                cin >> contpaciente;

                    leitura_paciente(paciente, contpaciente);
                    system("cls");
                    leitura_indice_paciente(indicepaciente, contpaciente);
                    getch();


                getch();
                system("cls");
            }
            else if (escolhacadastro == 2)
            {

                cout << "\nDigite a Quantidade a cadastrar:";
                cin >> contespecializacao;

                if (contespecializacao > 0)
                {
                    leitura_especializacao(especializacao, contespecializacao);
                    system("cls");
                    leitura_indicie_especializacao(indice_espec, contespecializacao);
                    getch();
                }
                else
                    cout << "\nNumero invalido!";
                getch();
                system("cls");
            }
            else if (escolhacadastro == 3)
            {

                cout << "\nDigite a Quantidade a cadastrar:";
                cin >> contmedico;

                if (contmedico > 0)
                {
                    leitura_medico(medico, contmedico);
                    system("cls");
                    leitura_indicie_medico(indicemedico, contmedico);
                }
                else
                    cout << "\nNumero Invalido!";
                getch();
                system("cls");
            }
            break;

        case 2:
            cout << "Selecione o desejado" << endl;
            cout << "\t1- Paciente" << endl;
            cout << "\t2- Medico" << endl;
            cout << "\tDigite a opcao: ";
            int escolhainserir;
            cin >> escolhainserir;
            system("cls");

            if (escolhainserir == 1)
            {
                int codleiturapaciente;
                int contadorinserirpaciente;
                cout << "\tINFORME O CODIGO DO PACIENTE A SER INSERIDO" << endl;
                cin >> codleiturapaciente;

                if (codleiturapaciente > 0)
                {
                    buscaaleatoria_paciente(indicepaciente, paciente, contpaciente, codleiturapaciente);
                }
                else
                    cout << "\nNUMERO INVALIDO";
                getch();
                system("cls");
            }
            else if (escolhainserir == 2)
            {
                int codleituramedico;

                cout << "\t INFORME O CODIGO DO MEDICO A SER INSERIDO" << endl;
                cin >> codleituramedico;

                if (codleituramedico > 0)
                {

                    buscaaleatoria_medico(indicemedico, medico, contmedico, codleituramedico, indice_espec, especializacao);
                }
                else
                    cout << "\nNUMERO INVALIDO";
                getch();
                system("cls");
            }
            break;

        case 3:
            int codespec;
            cout << "\t ESPECIALIZACOES CADASTRADAS" << endl;
            mostrar_espec(especializacao, contespecializacao);
            cout << "\t ESCOLHA UM OPCAO: ";
            cin >> codespec;

            buscaaleatoria_especializacao2(indice_espec, especializacao, contespecializacao, codespec, medico, indicemedico);

            getch();
            system("CLS");

            break;

        case 4:


            cout << "\t AGENDAMENTO DE CONSULTA" << endl;
            cout << "\nDIGITE O CPF DO PACIENTE:" << endl;
            cin >> cpfpaciente;
            cout << "\nDIGITE O CRM DO MEDICO: " << endl;
            cin >> crmmedico;
             int teste;
            teste = buscaaleatoria_medico2(indicemedico, medico, contmedico, crmmedico, indice_espec, especializacao);

            if(teste ==1){

            cout << "\nDIGITE UMA DATA PARA AGENDAR: " << endl;
            cin >> data;
            cout << "DIGITE UM HORARIO PARA AGENDAR " << endl;
            cin >> horario;

            inserir_consulta(consulta, indice_consulta, crmmedico, cpfpaciente, data, horario, contconsulta);

            }
            else cout<<"\nMEDICO NAO ENCONTRADO CONSULTA CANCELADA"<<endl;

            getch();
            system("CLS");

        break;

        case 5:

            cout<<"\tDIGITE O CRM A SER EXCLUIDO:"<<endl;
            cin>>codexcluir;

                buscaaleatoria_medico4(indicemedico, medico, contmedico, codexcluir, indice_espec, especializacao);

            getch();
            system("cls");

            break;

        case 6:

        faturamento(consulta,contconsulta,medico,contmedico);
        getch();
        system("cls");


        break;

        case 7:
            maiorMenor(consulta,contconsulta,medico,contmedico);
            getch();
        system("cls");

        break;


        }
    }
}
