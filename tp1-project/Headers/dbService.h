#ifndef DBSERVICE_H_INCLUDED
#define DBSERVICE_H_INCLUDED

#include <iostream>
#include "sqlite3.h"

using namespace std;
//-----------------------------------------

//Declaração de erro

class EErroPersistencia {
private:
        string mensagem;
public:
        EErroPersistencia(string);
        string what();
};

//Declaração elemento Resultado

class ElementoResultado {
private:
        string nomeColuna;
        string valorColuna;
public:
        void setNomeColuna(const string&);
        string getNomeColuna() const;
        void setValorColuna(const string&);
        string getValorColuna() const;
};

//Declaração comando Sql

class ComandoSQL {
private:
        const char *nomeBancoDados;
        sqlite3 *bd;
        char *mensagem;
        int rc;
        void conectar();
        void desconectar();
        static int callback(void *, int, char **, char **);

protected:
        static list<ElementoResultado> listaResultado;
        string comandoSQL;
public:
        ComandoSQL() {
             nomeBancoDados = "tp1-project.db";                             // Nome do banco de dados.
        }
        void executar();
};

//-----------------------------------------------------------
//Declaração de classes específicas de comando sql



//Relativo a Conta -----------------------------------------------
class ComandoCriarConta:public ComandoSQL {
public:
    ComandoCreateConta(Conta);
};

class ComandoFindConta:public ComandoSQL {
public:
    ComandoFindConta(CPF);
    Conta getResultado();
};

class ComandoFindSenhaConta:public ComandoSQL {
public:
    ComandoFindSenhaConta(CPF);
    string getResultado();
};

class ComandoAtualizarConta:public ComandoSQL {
public:
    ComandoUpdateConta(Conta);
};

class ComandoExcluirConta:public ComandoSQL {
public:
    ComandoDeleteConta(CPF);
};

class ComandoExisteConta:public ComandoSQL {
public:
    ComandoExisteConta(CPF);
    bool getResultado();

};
// Relativo a titulo

class ComandoCreateTitulo:public ComandoSQL {
public:
    ComandoCreateTitulo(Titulo);
};

class ComandoFindTitulo:public ComandoSQL {
public:
    ComandoFindTitulo(CodigoTitulo);
    Titulo getResultado();
};

class ComandoUpdateTitulo:public ComandoSQL {
public:
    ComandoUpdateTitulo(Titulo);
};
class ComandoDeleteTitulo:public ComandoSQL {
public:
    ComandoDeleteTitulo(CodigoTitulo);
};

// Relativo a Pagamento

class ComandoCreatePagamento:public ComandoSQL {
public:
    ComandoCreatePagamento(Pagamento);
};

class ComandoFindPagamento:public ComandoSQL {
public:
    ComandoFindPagamento(CodigoPagamento);
    Pagamento getResultado();
};

class ComandoUpdatePagamento:public ComandoSQL {
public:
    ComandoUpdatePagamento(Pagamento);
};
class ComandoDeletePagamento:public ComandoSQL {
public:
    ComandoDeletePagamento(CodigoPagamento);
};












#endif // DBSERVICE_H_INCLUDED
