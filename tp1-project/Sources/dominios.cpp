void codigoDeTitulo::setCodigo(string codigoDeTitulo){
    validar(codigoDeTitulo);
    this->codigoDeTitulo=codigoDeTitulo;
};

void codigoDeTitulo::validar(string codigoDeTitulo){
    identificador.assign(codigoDeTitulo,0,3);
    if (codigoDeTitulo.length()!=11)
        throw invalid_argument("Codigo de Titulo Invalido.");
    if (identificador!="CDB" && identificador!="CRA" && identificador!="CRI" && identificador!="LCA" && identificador!="LCI" && identificador!="DEB" )
        throw invalid_argument("Codigo de Titulo Invalido.");
    else
        for (int i=3;i<11;i++){
            if (!(isdigit(codigoDeTitulo[i])) && !(isupper(codigoDeTitulo[i])))
                throw invalid_argument("Codigo de Titulo Invalido.");
        };
};

string codigoDeTitulo::getCodigo(){
    return codigoDeTitulo;
};

void CPF::setCPF(string CPF){
    validarCPF(CPF);
    this->CPF=CPF;
};

void CPF::validarCPF(string CPF){
    // codar aqui rs
    // modelo: XXX.XXX.XXX-CC
    int validChar_1 = stoi(CPF[-2]);
    int validChar_2 = stoi(CPF[-1]);
    // Validação com primeiro dígito
    int minusCount = 10;
    for (char i = 0; i)

};

string CPF::getCPF(){
    return CPF;
};

void Percentual::setValor(int valor){
    validar(valor);
    this->valor=valor;
};
void Percentual::validar(int valor){
    if (valor < 0 || valor > 100)
        throw invalid_argument("Percentual Invalido.");
};
int Percentual::getValor(){
    return valor;
};

Estado::Estado(const std::string& novoEstado) {
    validarEstado(novoEstado);
    estado = novoEstado;
}

std::string Estado::getEstado() const {
    return estado;
}

void estado::setEstado(const std::string& novoEstado) {
    validarEstado(novoEstado);
    estado = novoEstado;
}

void Estado::validarEstado(const std:: string& estado) const {
    if (estado != "Previsto" && estado != "Liquidado" && estado != "Inadimplente") {
        throw std::invalid_argument("Estado inválido");
    }
}

Setor::Setor(const std::string& novoNome) {
    validarNome(novoNome);
    nome = novoNome;
}

std::string Setor::getNome() const {
    return nome;
}

void Setor::setNome(const std::string& novoNome) {
    validarNome(novoNome);
    nome = novoNome;
}

void Setor::validarNome(const std::string& nome) const {
    static const std::string setoresValidos[] = {
        "Agricultura",
        "Construção civil",
        "Energia", 
        "Finanças",
        "Imobiliário",
        "Papel e celulose",
        "Pecuária",
        "Química e petroquímica",
        "Metalurgia e siderurgia",
        "Mineração"
    };

    bool encontrado = false;
    for (const auto& setor : setoresValidos) {
        if (nome == setor) {
            encontrado = true; 
            break;
        }
    }
    if (!encontrado) {
        throw std::invalid_argument("Setor inválido");
    }
}
