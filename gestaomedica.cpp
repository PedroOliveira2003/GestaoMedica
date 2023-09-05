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
    cont = i - 1;
}

void leitura_indice_paciente(struct Indice_paciente idx[], int cont)
{

    for (int i = 0; i < cont; i++)
    {
        cout << "\n\nCodigo do Indice " << (i + 1) << ": ";
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
    cont = i - 1;
}

void leitura_indicie_especializacao(struct Indice_especializacao idx[], int cont)
{

    for (int i = 0; i < cont; i++)
    {
        cout << "\n\nCodigo do Indice " << (i + 1) << ": ";
        cin >> idx[i].codigoidxespecializacao;
        cout << "Endereco Fisico na Area de Dados: ";
        cin >> idx[i].enderidxespecializacao;
    }
}

void leitura_medico(struct Medico cli[], int &cont)
{
    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++)
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
    cont = i - 1;
}

int main()
{
    struct Paciente paciente[20];
    int cont;
    struct Indice_paciente indice[20];
    struct Indice_especializacao indiceespecial[20];
    struct Especializacao especializacao[20];
    struct Medico medico[20];

    // leitura_paciente(paciente,cont);
    // leitura_indice_paciente(indice,cont);
    // leitura_especializacao(especializacao,cont);
    // leitura_indicie_especializacao(indiceespecial,cont);
    // leitura_medico(medico,cont);

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

        if (varleitura == 1)
        {

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
                struct Paciente paciente[20];
                int contpaciente;

                cout << "\nDigite a quantidade a cadastrar: ";
                cin >> contpaciente;

                if (contpaciente > 0)
                {
                    leitura_paciente(paciente, contpaciente);
                }
                else
                    cout << "\nNUMERO INVALIDO";
                getch();
                system("cls");
            }
            if (escolhacadastro == 2)
            {
                struct Especializacao especializacao[20];
                int contespecializacao;

                cout << "\nDigite a Quantidade a cadastrar:";
                cin >> contespecializacao;

                if (contespecializacao > 0)
                {
                    leitura_especializacao(especializacao, contespecializacao);
                }
                else
                    cout << "\nNumero invalido!";
                getch();
                system("cls");
            }
        }
    }
}
