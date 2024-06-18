#include <iostream>
using namespace std;

class Conta{
private:
    Cpf cpf;
    Nome nome;
    Senha senha;
public:
    void setCpf(const Cpf&);
    void setNome(const Nome&);
    void setSenha(const Senha&);
    Cpf getCpf() const;
    Nome getNome() const;
    Senha getSenha() const;
};
