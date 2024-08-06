#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

using namespace std;

//Declaração Adiantada

class ISConta;
class ISAuth;
class ISInvestimento;

//Camada de Apresentação

/**
 * Interface para apresenta&ccedil;&atilde;o de Conta.
 *
 * Fun&ccedil;&otilde;es principais:
 *
 * - Cria uma nova conta.
 * - Executa opera&ccedil;&otilde;es com base no CPF.
 * - Define o controlador de servi&ccedil;os de conta.
 */
class IAprConta {
public:
    /**
     * Cria uma nova conta.
     */
    virtual void criarConta() = 0;

    /**
     * Executa uma opera&ccedil;&atilde;o com base no CPF fornecido.
     * 
     * @param cpf Ponteiro para o CPF.
     * @return Um inteiro representando o resultado da opera&ccedil;&atilde;o.
     */
    virtual int executar(CPF*) = 0;

    /**
     * Define o controlador de servi&ccedil;os de conta.
     * 
     * @param servConta Ponteiro para o controlador de servi&ccedil;os de conta.
     */
    virtual void setCntrServConta(IServConta*) = 0;

    /**
     * Destrutor virtual para garantir a libera&ccedil;&atilde;o correta dos recursos.
     */
    virtual ~IAprConta(){};
};

/**
 * Interface para apresenta&ccedil;&atilde;o de Autentica&ccedil;&atilde;o.
 *
 * Fun&ccedil;&otilde;es principais:
 *
 * - Autentica um usu&aacute;rio com base no CPF.
 * - Define o controlador de servi&ccedil;os de autentica&ccedil;&atilde;o.
 */
class IAprAuth {
public:
    /**
     * Autentica um usu&aacute;rio com base no CPF fornecido.
     * 
     * @param cpf Ponteiro para o CPF.
     * @return Verdadeiro se a autentica&ccedil;&atilde;o for bem-sucedida, falso caso contr&aacute;rio.
     */
    virtual bool autenticar(CPF*) = 0;

    /**
     * Define o controlador de serviços de autentica&ccedil;&atilde;o.
     * 
     * @param servAuth Ponteiro para o controlador de servi&ccedil;os de autentica&ccedil;&atilde;o.
     */
    virtual void setCntrServAuth(IServAuth*) = 0;

    /**
     * Destrutor virtual para garantir a libera&ccedil;&atilde;o correta dos recursos.
     */
    virtual ~IAprAuth(){};
};

//Interface apresentação Investimento
class IAprInvestimento{
public:
    virtual bool executar(CPF) = 0;
    virtual void setCntrServInvestimento(IServInvestimento*) = 0;
    virtual ~IAprInvestimento(){};
};

//Camada de Serviço


class IServConta{
public:
    virtual bool criarConta() = 0;
    virtual bool lerConta(CPF*) = 0;
    virtual bool atualizarConta(CPF*) = 0;
    virtual bool excluirConta(CPF) = 0;
    virtual ~IServConta(){};
};

class IServAuth{
public:
    virtual bool autenticarConta(CPF) = 0;
    virtual ~IServAuth(){};
};

class IServInvestimento{
public:
    virtual bool criarTitulo(CPF) = 0;
    virtual bool lerTitulo(CPF) = 0;
    virtual bool atualizarTitulo(Titulo) = 0;
    virtual bool excluirTitulo(codigoDeTitulo) = 0;
    
    virtual bool criarPagamaento(codigoDeTitulo) = 0;
    virtual bool lerPagamento(codigoDeTitulo) = 0;
    virtual bool atualizarPagamento(Pagamento) = 0;
    virtual bool excluirPagamento(codigoDePagamento) = 0;
    virtual ~IServInvestimento(){};
};
#endif //INTERFACE_H_INCLUDED
