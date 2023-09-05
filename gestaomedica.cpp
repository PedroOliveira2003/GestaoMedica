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

    for (int saida = 1; i < 20 && saida != 0; i++)
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
    for (int saida = 1; i < 20 && saida != 0; i++)
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

int main()
{
    struct Paciente paciente[20];
    int cont;
    struct Indice_paciente indice[20];
    struct Indice_especializacao indiceespecial[20];
    struct Especializacao especializacao[20];

    // leitura_paciente(paciente,cont);
    // leitura_indice_paciente(indice,cont);
    // leitura_especializacao(especializacao,cont);
    // leitura_indicie_especializacao(indiceespecial,cont);
}
