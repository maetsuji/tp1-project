using namespace std;

class CntrAprConta:public IAprConta{
private:
    IServConta *cntrservconta;
    void lerConta(CPF);
    void atualizarConta(CPF*);
    void excluirConta(CPF*)
public:
    void criarConta();
    void executar(CPF*);
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
    void executar(CPF*);
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


class CntrServConta {
    void createConta(Conta);
    void deleteConta(CPF);
    void findConta(CPF);
    void updateConta(Conta);
};





