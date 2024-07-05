#include "entidades.h"

using namespace std;

//Class Conta
void Conta::setCPF(const CPF& cpf){
    this->cpf = cpf;
}

void Conta::setNome(const Nome& nome){
    this->nome = nome;
}

void Conta::setSenha(const Senha& senha){
    this->senha = senha;
}

CPF Conta::getCPF() const{
    return cpf;
}

Nome Conta::getNome() const{
    return nome;
}

Senha Conta::getSenha() const{
    return senha;
}

//Class Titulo
void Titulo::setCodigo(const codigoDeTitulo& codigo){
    this->codigo = codigo;
}

void Titulo::setEmissor(const Nome& emissor){
    this->emissor = emissor;
}

void Titulo::setSetor(const Setor& setor){
    this->setor = setor;
}

void Titulo::setEmissao(const Data& emissao){
    this->emissao = emissao;
}

void Titulo::setVencimento(const Data& vencimento){
    this->vencimento = vencimento;
}

void Titulo::setValor(const Dinheiro& valor){
    this->valor = valor;
}

codigoDeTitulo Titulo::getCodigo() const{
    return codigo;
}

Nome Titulo::getEmissor() const{
    return emissor;
}

Setor Titulo::getSetor() const{
    return setor;
}

Data Titulo::getEmissao() const{
    return emissao;
}

Data Titulo::getVencimento() const{
    return vencimento;
}

Dinheiro Titulo::getValor() const{
    return valor;
}

//Class Pagamento
void Pagamento::setCodigo(const codigoDePagamento& codigo){
    this->codigo = codigo;
}

void Pagamento::setData(const Data& data){
    this->data = data;
}

void Pagamento::setPercentual(const Percentual& percentual){
    this->percentual = percentual;
}

void Pagamento::setEstado(const Estado& estado){
    this->estado = estado;
}

codigoDePagamento Pagamento::getCodigo() const{
    return codigo;
}

Data Pagamento::getData() const{
    return data;
}

Percentual Pagamento::getPercentual() const{
    return percentual;
}

Estado Pagamento::getEstado() const{
    return estado;
}
