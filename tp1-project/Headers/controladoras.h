using namespace std;

class CntrAprConta:public IAprConta{
private:
    IServConta *cntrservconta;
public:
    void criarConta();
    int executar(CPF*);
    void setCntrServConta(IServConta*);
};

class CntrAprAuth:public IAprAuth{
private:
    IServAuth *cntrservauth;
public:
    inline void setCntrServAuth(IServAuth*);
    int executar(CPF*);
};

class CntrAprInvestimento:public IAprInvestimento{
private:
    IServInvestimento *cntrservinvestimento;
public:
    void setCntrServInvestimento(IServInvestimento*);
    int executar(CPF*);
};

criar{

try
cin CPF
cpf.setValor
cin Nome
nome.setValor
cin Senha
senha.setValor
catch

Conta conta;
setCPF
setNome
setSenha

resultado=CntrServConta::LN/escreverNoBD(Conta conta)
}
