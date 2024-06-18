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


//Class Pagamento
