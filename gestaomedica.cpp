#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

struct Paciente
{
    int codpaciente;
    string cpf;
    char nomepaciente[20];
    int idade;
    char sexo[2];
    string telefone;
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
    string crm;
    char nomemedico[20];
    int idade;
    char sexomedico[2];
    string telefoneMedico;
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
    string cpf_paciente;
    string crm_medico;
    string data;
    string horario;
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
            cout << "\Nome Especializacao: ";
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

void inclusao_medico(struct Indice_medico idx[], struct Medico cli[], int &cont, int cod)
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
    cout << "CODIGO ESPECIALIZACAO";
    cin >> cli[cont].codigo_especializacao;

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

void buscaaleatoria_medico(struct Indice_medico idx[], struct Medico cli[], int &cont, int cod)
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

    if (cod == idx[m].codigoidxmedico)
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
        inclusao_medico(idx, cli, cont, cod);
    getch();
}

int main()
{

    struct Paciente paciente[20];
    struct Indice_paciente indicepaciente[20];

    struct Medico medico[20];
    struct Indice_medico indicemedico[20];

    int varleitura = 1;
    while (varleitura > 0)
    {

        cout << "\t\tMENU";
        cout << "\n-------------------\n";
        cout << "\t1- Cadastrar" << endl;
        cout << "\t2- Inserir" << endl;
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

                int contpaciente;

                cout << "\nDigite a quantidade a cadastrar: ";
                cin >> contpaciente;

                if (contpaciente > 0)
                {
                    leitura_paciente(paciente, contpaciente);
                    system("cls");
                    leitura_indice_paciente(indicepaciente, contpaciente);
                    getch();
                }
                else
                    cout << "\nNUMERO INVALIDO";
                getch();
                system("cls");
            }
            if (escolhacadastro == 2)
            {
                struct Especializacao especializacao[20];
                struct Indice_especializacao indice_especializacao[20];
                int contespecializacao;

                cout << "\nDigite a Quantidade a cadastrar:";
                cin >> contespecializacao;

                if (contespecializacao > 0)
                {
                    leitura_especializacao(especializacao, contespecializacao);
                    system("cls");
                    leitura_indicie_especializacao(indice_especializacao, contespecializacao);
                    getch();
                }
                else
                    cout << "\nNumero invalido!";
                getch();
                system("cls");
            }
            if (escolhacadastro == 3)
            {
                // struct Medico medico[20];
                // struct Indice_medico indice_medico[20];
                int contmedico;

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
        default:
        case 2:
            cout << "Selecione o desejado" << endl;
            cout << "\t1- Paciente" << endl;
            cout << "\t2- Especializacao" << endl;
            cout << "\t3- Medico" << endl;
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
                    buscaaleatoria_paciente(indicepaciente, paciente, contadorinserirpaciente, codleiturapaciente);
                }
                else
                    cout << "\nNUMERO INVALIDO";
                getch();
                system("cls");
            }
            if (escolhainserir == 3)
            {
                int codleituramedico;
                int contadorinserirmedico;
                cout << "\t INFORME O CODIGO DO MEDICO A SER INSERIDO" << endl;
                cin >> codleituramedico;

                if (codleituramedico > 0)
                {

                    buscaaleatoria_medico(indicemedico, medico, contadorinserirmedico, codleituramedico);
                }
                else
                    cout << "\nNUMERO INVALIDO";
                getch();
                system("cls");
            }
        }
    }
}
