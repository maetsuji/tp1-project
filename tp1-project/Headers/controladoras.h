using namespace std;

class CntrAprConta:public IAprConta{
private:
    IServConta *cntrservconta;
    void lerConta(CPF);
    void atualizarConta(CPF*);
    void excluirConta(CPF*)
public:
    void criarConta();
    int executar(CPF*);
    void setCntrServConta(IServConta*);
};

inline void CntrAprConta::setCntrServConta(IServConta *cntrservconta){
    this->cntrservconta=cntrservconta
};


class CntrAprAuth:public IAprAuth{
private:
    IServAuth *cntrservauth;
public:
    void setCntrServAuth(IServAuth*);
    int executar(CPF*);
};

inline void CntrAprAuth::setCntrServAuth(IServAuth *cntrservauth){
    this->cntrservauth=cntrservauth
};


class CntrAprInvestimento:public IAprInvestimento{
private:
    IServInvestimento *cntrservinvestimento;
public:
    void setCntrServInvestimento(IServInvestimento*);
    int executar(CPF*);
};

inline void CntrAprInvestimento::setCntrServInvestimento(IServInvestimento *cntrservinvestimento){
    this->cntrservinvestimento=cntrservinvestimento
};


//EXEMPLO PARA AJUDAR NA LÓGICA
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
