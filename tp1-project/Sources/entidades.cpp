#include "entidades.h"

using namespace std;

//Class Conta

/**
* Armazena, como atributo da classe de entidade Conta, um objeto da classe CPF chamado cpf, caso contenha um cpf v&aacute;lido
* 
* @param CPF cpf
*
* @throw invalid_argument
*/

void Conta::setCPF(const CPF& cpf){
    this->cpf = cpf;
}

/**
* Armazena, como atributo da classe de entidade Conta, um objeto da classe Nome chamado nome, caso contenha um nome v&aacute;lido
* 
* @param Nome nome
*
* @throw invalid_argument
*/

void Conta::setNome(const Nome& nome){
    this->nome = nome;
}

/**
* Armazena, como atributo da classe de entidade Conta, um objeto da classe Senha chamado senha, caso contenha uma senha v&aacute;lida
* 
* @param Senha senha
*
* @throw invalid_argument
*/

void Conta::setSenha(const Senha& senha){
    this->senha = senha;
}

/**
* Retorna um objeto da classe CPF.
*
* @return cpf
*/

CPF Conta::getCPF() const{
    return cpf;
}

/**
* Retorna um objeto da classe Nome.
*
* @return nome
*/

Nome Conta::getNome() const{
    return nome;
}

/**
* Retorna um objeto da classe Senha.
*
* @return senha
*/


Senha Conta::getSenha() const{
    return senha;
}

//Class Titulo

/**
* Armazena, como atributo da classe de entidade Titulo, um objeto da classe codigoDeTitulo chamado codigo, caso contenha um c&oacute;digo de t&iacute;tulo v&aacute;lido
* 
* @param codigoDeTitulo codigo
*
* @throw invalid_argument
*/

void Titulo::setCodigo(const codigoDeTitulo& codigo){
    this->codigo = codigo;
}

/**
* Armazena, como atributo da classe de entidade Titulo, um objeto da classe Nome chamado emissor, caso contenha um nome v&aacute;lido
* 
* @param Nome emissor
*
* @throw invalid_argument
*/

void Titulo::setEmissor(const Nome& emissor){
    this->emissor = emissor;
}

/**
* Armazena, como atributo da classe de entidade Titulo, um objeto da classe Setor chamado setor, caso contenha um setor v&aacute;lido
* 
* @param Setor setor
*
* @throw invalid_argument
*/

void Titulo::setSetor(const Setor& setor){
    this->setor = setor;
}

/**
* Armazena, como atributo da classe de entidade Titulo, um objeto da classe Data chamado emissao, caso contenha uma data v&aacute;lida
* 
* @param Data emissao
*
* @throw invalid_argument
*/

void Titulo::setEmissao(const Data& emissao){
    this->emissao = emissao;
}

/**
* Armazena, como atributo da classe de entidade Titulo, um objeto da classe Data chamado vencimento, caso contenha uma data v&aacute;lida
* 
* @param Data vencimento
*
* @throw invalid_argument
*/

void Titulo::setVencimento(const Data& vencimento){
    this->vencimento = vencimento;
}

/**
* Armazena, como atributo da classe de entidade Titulo, um objeto da classe Dinheiro chamado valor, caso contenha um valor v&aacute;lido
* 
* @param Dinheiro valor
*
* @throw invalid_argument
*/

void Titulo::setValor(const Dinheiro& valor){
    this->valor = valor;
}

/**
* Retorna um objeto da classe codigoDeTitulo.
*
* @return codigo
*/

codigoDeTitulo Titulo::getCodigo() const{
    return codigo;
}

/**
* Retorna um objeto da classe Nome.
*
* @return nome
*/

Nome Titulo::getEmissor() const{
    return emissor;
}

/**
* Retorna um objeto da classe Setor.
*
* @return setor
*/

Setor Titulo::getSetor() const{
    return setor;
}

/**
* Retorna um objeto da classe Data.
*
* @return emissao
*/

Data Titulo::getEmissao() const{
    return emissao;
}

/**
* Retorna um objeto da classe Data.
*
* @return vencimento
*/

Data Titulo::getVencimento() const{
    return vencimento;
}

/**
* Retorna um objeto da classe Dinheiro.
*
* @return valor
*/

Dinheiro Titulo::getValor() const{
    return valor;
}

//Class Pagamento

/**
* Armazena, como atributo da classe de entidade Pagamento, um objeto da classe codigoDePagamento chamado codigo, caso contenha um c&oacute;digo v&aacute;lido
* 
* @param codigoDePagamento codigo
*
* @throw invalid_argument
*/

void Pagamento::setCodigo(const codigoDePagamento& codigo){
    this->codigo = codigo;
}

/**
* Armazena, como atributo da classe de entidade Pagamento, um objeto da classe Data chamado data, caso contenha uma data v&aacute;lida
* 
* @param Data data
*
* @throw invalid_argument
*/

void Pagamento::setData(const Data& data){
    this->data = data;
}

/**
* Armazena, como atributo da classe de entidade Pagamento, um objeto da classe Percentual chamado percentual, caso contenha um percentual v&aacute;lido
* 
* @param Percentual percentual
*
* @throw invalid_argument
*/

void Pagamento::setPercentual(const Percentual& percentual){
    this->percentual = percentual;
}

/**
* Armazena, como atributo da classe de entidade Pagamento, um objeto da classe Estado chamado estado, caso contenha um estado v&aacute;lido
* 
* @param Estado estado
*
* @throw invalid_argument
*/

void Pagamento::setEstado(const Estado& estado){
    this->estado = estado;
}

/**
* Retorna um objeto da classe codigoDePagamento.
*
* @return codigo
*/

codigoDePagamento Pagamento::getCodigo() const{
    return codigo;
}

/**
* Retorna um objeto da classe Data.
*
* @return data
*/

Data Pagamento::getData() const{
    return data;
}

/**
* Retorna um objeto da classe Percentual.
*
* @return percentual
*/

Percentual Pagamento::getPercentual() const{
    return percentual;
}

/**
* Retorna um objeto da classe Estado.
*
* @return estado
*/

Estado Pagamento::getEstado() const{
    return estado;
}
