using namespace std;

//Declaração Adiantada

class ISConta;
class ISAuth;
class ISInvestimento;

//Camada de Apresentação

//Interface apresentação Conta
class IAprConta{
public:
    virtual void criarConta() = 0;
    virtual int executar(CPF*) = 0;
    virtual void setCntrServConta(IServConta*) = 0;
    virtual ~IAprConta(){};
};

//Interface apresentação Autenticação
class IAprAuth{
public:
    virtual bool autenticar(CPF*) = 0;
    virtual void setCntrServAuth(IServAuth*) = 0;
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
