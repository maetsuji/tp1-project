using namespace std;

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

void Data::Data(int dia, int mes, int ano) : dia(dia), mes(mes), ano(ano) {
    if (!validarData()) {
        cerr << "Erro: Data inválida!\n";
        this->dia = 0;
        this->mes = 0;
        this->ano = 0;
    }
}

bool Data::validarData() const {
    if (ano < 2000 || ano > 2100 || mes < 1 || mes > 12)
        return false;
    if (dia < 1)
        return false;
    switch (mes) {
        case 2: // Fevereiro
            if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
                return dia <= 29;
            else
                return dia <= 28;
        case 4: case 6: case 9: case 11: // Meses com 30 dias
            return dia <= 30;
        default: // Meses com 31 dias
            return dia <= 31;
    }
}
int Data::getDia() const {
    return dia;
}
int Data::getMes() const {
    return mes;
}
int Data::getAno() const {
    return ano;
}
void Data::imprimirData() const {
    cout << dia << "-" << mes << "-" << ano << endl;
}

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

Estado::Estado(const string& novoEstado) {
    validarEstado(novoEstado);
    estado = novoEstado;
}

string Estado::getEstado() const {
    return estado;
}

void estado::setEstado(const string& novoEstado) {
    validarEstado(novoEstado);
    estado = novoEstado;
}

void Estado::validarEstado(const  string& estado) const {
    if (estado != "Previsto" && estado != "Liquidado" && estado != "Inadimplente") {
        throw invalid_argument("Estado inválido");
    }
}

Setor::Setor(const string& novoNome) {
    validarNome(novoNome);
    nome = novoNome;
}

string Setor::getNome() const {
    return nome;
}

void Setor::setNome(const string& novoNome) {
    validarNome(novoNome);
    nome = novoNome;
}

void Setor::validarNome(const string& nome) const {
    static const string setoresValidos[] = {
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
        throw invalid_argument("Setor inválido");
    }
}

void Nome::Nome(const string& nomeCompleto) {
    size_t pos = nomeCompleto.find(' ');

    primeiroTermo = nomeCompleto.substr(0, pos);

    if (pos != string::npos) {
        segundoTermo = nomeCompleto.substr(pos + 1);
    }

    if (!validarTermo(primeiroTermo) || !validarTermo(segundoTermo)) {
        cerr << "Erro: Termo(s) inválido(s)!\n";
        primeiroTermo.clear();
        segundoTermo.clear();
    }
}

bool Nome::validarTermo(const string& termo) const {
    if (termo.empty() || !isupper(termo[0])) // maiúscula
        return false;
    for (char c : termo) {
        if (!isalpha(c))
            return false; 
    }
    return true;
}

string Nome::getPrimeiroTermo() const {
    return primeiroTermo;
}

string Nome::getSegundoTermo() const {
    return segundoTermo;
}
