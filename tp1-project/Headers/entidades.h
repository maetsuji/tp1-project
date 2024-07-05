#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"

using namespace std;

class Conta{
private:
    CPF cpf;
    Nome nome;
    Senha senha;
public:
    void setCPF(const CPF&);
    void setNome(const Nome&);
    void setSenha(const Senha&);
    CPF getCPF() const;
    Nome getNome() const;
    Senha getSenha() const;
};

class Titulo{                     //IMPLEMENTADA POR 231021360
private:
    codigoDeTitulo codigo;
    Nome emissor;
    Setor setor;
    Data emissao;
    Data vencimento;
    Dinheiro valor;
public:
    void setCodigo(const codigoDeTitulo&);
    void setEmissor(const Nome&);
    void setSetor(const Setor&);
    void setEmissao(const Data&);
    void setVencimento(const Data&);
    void setValor(const Dinheiro&);
    codigoDeTitulo getCodigo() const;
    Nome getEmissor() const;
    Setor getSetor() const;
    Data getEmissao() const;
    Data getVencimento() const;
    Dinheiro getValor() const;
};

class Pagamento{
private:
    codigoDePagamento codigo;
    Data data;
    Percentual percentual;
    Estado estado;
public:
    void setCodigo(const codigoDePagamento&);
    void setData(const Data&);
    void setPercentual(const Percentual&);
    void setEstado(const Estado&);
    codigoDePagamento getCodigo() const;
    Data getData() const;
    Percentual getPercentual() const;
    Estado getEstado() const;
};

#endif // ENTIDADES_H_INCLUDED
