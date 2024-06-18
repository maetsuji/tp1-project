//Class Conta
void Conta::setCpf(const Cpf& cpf){
    this->cpf = cpf;
}

void Conta::setNome(const Nome& nome){
    this->nome = nome;
}

void Conta::setSenha(const Senha& senha){
    this->senha = senha;
}

Cpf Conta::getCpf() const{
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
void Titulo::void setVencimento(const Data& vencimento){
    this->vencimento = vencimento;
}
void Titulo::setDinheiro(const Valor& valor){
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
