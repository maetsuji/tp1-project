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


/*class ISConta{
public:
    virtual bool lerConta(CPF*) = 0;
    virtual bool atualizarConta(CPF*) = 0;
    virtual bool excluirConta(CPF) = 0;
    virtual ~ISConta(){};
};
*/
