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

/**
 * Interface para apresenta&ccedil;&atilde;o de Investimento.
 *
 * Fun&ccedil;&otilde;es principais:
 *
 * - Executa opera&ccedil;&otilde;es de investimento com base no CPF.
 * - Define o controlador de servi&ccedil;os de investimento.
 */
class IAprInvestimento {
public:
    /**
     * Executa uma opera&ccedil;&atilde;o de investimento com base no CPF fornecido.
     * 
     * @param cpf CPF a ser utilizado na opera&ccedil;&atilde;o.
     * @return Verdadeiro se a opera&ccedil;&atilde;o for bem-sucedida, falso caso contr&aacute;rio.
     */
    virtual bool executar(CPF) = 0;

    /**
     * Define o controlador de servi&ccedil;os de investimento.
     * 
     * @param servInvestimento Ponteiro para o controlador de servi&ccedil;os de investimento.
     */
    virtual void setCntrServInvestimento(IServInvestimento*) = 0;

    /**
     * Destrutor virtual para garantir a libera&ccedil;&atilde;o correta dos recursos.
     */
    virtual ~IAprInvestimento(){};
};


//Camada de Serviço

/**
 * Interface para servi&ccedil;os relacionados a contas.
 *
 * Fun&ccedil;&otilde;es principais:
 *
 * - Cria, l&ecirc;, atualiza e exclui contas.
 */
class IServConta {
public:
    /**
     * Cria uma nova conta.
     * 
     * @return Verdadeiro se a conta for criada com sucesso, falso caso contr&aacute;rio.
     */
    virtual bool criarConta() = 0;

    /**
     * L&ecirc; os dados de uma conta com base no CPF fornecido.
     * 
     * @param cpf Ponteiro para o CPF da conta a ser lida.
     * @return Verdadeiro se a leitura for bem-sucedida, falso caso contr&aacute;rio.
     */
    virtual bool lerConta(CPF*) = 0;

    /**
     * Atualiza os dados de uma conta com base no CPF fornecido.
     * 
     * @param cpf Ponteiro para o CPF da conta a ser atualizada.
     * @return Verdadeiro se a atualização for bem-sucedida, falso caso contr&aacute;rio.
     */
    virtual bool atualizarConta(CPF*) = 0;

    /**
     * Exclui uma conta com base no CPF fornecido.
     * 
     * @param cpf CPF da conta a ser exclu&iacute;da.
     * @return Verdadeiro se a exclus&atilde;o for bem-sucedida, falso caso contr&aacute;rio.
     */
    virtual bool excluirConta(CPF) = 0;

    /**
     * Destrutor virtual para garantir a libera&ccedil;&atilde;o correta dos recursos.
     */
    virtual ~IServConta(){};
};


/**
 * Interface para servi&ccedil;os relacionados a autentica&ccedil;&atilde;o.
 *
 * Fun&ccedil;&atilde;o principal:
 *
 * - Autentica uma conta com base no CPF.
 */
class IServAuth {
public:
    /**
     * Autentica uma conta com base no CPF fornecido.
     * 
     * @param cpf CPF da conta a ser autenticada.
     * @return Verdadeiro se a autenticação for bem-sucedida, falso caso contr&aacute;rio.
     */
    virtual bool autenticarConta(CPF) = 0;

    /**
     * Destrutor virtual para garantir a libera&ccedil;&atilde;o correta dos recursos.
     */
    virtual ~IServAuth(){};
};

/**
 * Interface para servi&ccedil;os relacionados a investimentos.
 *
 * Fun&ccedil;&otilde;es principais:
 *
 * - Cria, l&ecirc;, atualiza e exclui t&iacute;tulos e pagamentos.
 */
class IServInvestimento {
public:
    /**
     * Cria um t&iacute;tulo de investimento com base no CPF fornecido.
     * 
     * @param cpf CPF para o qual o t&iacute;tulo ser&aacute; criado.
     * @return Verdadeiro se o t&iacute;tulo for criado com sucesso, falso caso contr&aacute;rio.
     */
    virtual bool criarTitulo(CPF) = 0;

    /**
     * L&ecirc; os dados de um t&iacute;tulo de investimento com base no CPF fornecido.
     * 
     * @param cpf CPF do t&iacute;tulo a ser lido.
     * @return Verdadeiro se a leitura for bem-sucedida, falso caso contr&aacute;rio.
     */
    virtual bool lerTitulo(CPF) = 0;

    /**
     * Atualiza os dados de um t&iacute;tulo de investimento.
     * 
     * @param titulo Dados do t&iacute;tulo a ser atualizado.
     * @return Verdadeiro se a atualiza&ccedil;&atilde;o for bem-sucedida, falso caso contr&aacute;rio.
     */
    virtual bool atualizarTitulo(Titulo) = 0;

    /**
     * Exclui um t&aacute;tulo de investimento com base no c&oacute;digo fornecido.
     * 
     * @param codigoDeTitulo C&oacute;digo do t&iacute;tulo a ser exclu&iacute;do.
     * @return Verdadeiro se a exclus&atilde;o for bem-sucedida, falso caso contr&aacute;rio.
     */
    virtual bool excluirTitulo(codigoDeTitulo) = 0;

    /**
     * Cria um pagamento associado a um t&iacute;tulo com base no c&oacute;digo fornecido.
     * 
     * @param codigoDeTitulo C&oacute;digo do t&iacute;tulo para o qual o pagamento ser&aacute; criado.
     * @return Verdadeiro se o pagamento for criado com sucesso, falso caso contr&aacute;rio.
     */
    virtual bool criarPagamento(codigoDeTitulo) = 0;

    /**
     * L&ecirc; os dados de um pagamento associado a um t&iacute;tulo com base no c&iacute;digo fornecido.
     * 
     * @param codigoDeTitulo C&iacute;digo do t&iacute;tulo para o qual o pagamento ser&aacute; lido.
     * @return Verdadeiro se a leitura for bem-sucedida, falso caso contr&aacute;rio.
     */
    virtual bool lerPagamento(codigoDeTitulo) = 0;

    /**
     * Atualiza os dados de um pagamento.
     * 
     * @param pagamento Dados do pagamento a ser atualizado.
     * @return Verdadeiro se a atualiza&ccedil;&atilde;o for bem-sucedida, falso caso contr&aacute;rio.
     */
    virtual bool atualizarPagamento(Pagamento) = 0;

    /**
     * Exclui um pagamento com base no c&oacute;digo fornecido.
     * 
     * @param codigoDePagamento C&oacute;digo do pagamento a ser exclu&iacute;do.
     * @return Verdadeiro se a exclus&atilde;o for bem-sucedida, falso caso contr&aacute;rio.
     */
    virtual bool excluirPagamento(codigoDePagamento) = 0;

    /**
     * Destrutor virtual para garantir a libera&ccedil;&atilde;o correta dos recursos.
     */
    virtual ~IServInvestimento(){};
};
#endif //INTERFACE_H_INCLUDED
