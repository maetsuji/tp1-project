using namespace std;


//codigo de pagamento

void codigoDePagamento::validar(string codigoDePagamento){
     int tamanho = codigoPagamentoTeste.size();
            if(tamanho != 9){
                    throw invalid_argument("Codigo de Pagamento Fornecido Invalido (nao tem 9 caracteres)");} //checa se tem 9 digitos
            if(codigoPagamentoTeste[0] == '0') {
                throw invalid_argument( "Codigo de Pagamento Fornecido Invalido (o primeiro digito e 0)"); } //checa se o primeiro digito !=0
            for(int i = 0; i < tamanho; i++){
                if(!isdigit(codigoPagamentoTeste[i])){
                    throw invalid_argument ( "Codigo de Pagamento Fornecido Invalido (nem todos os caracteres sao digitos)");}} // checa se os digitos sao digitos
};

void codigoDePagamento::set(string codigoDePagamento){
    validar(codigoDePagamento);
    this->codigoPagamento = codigoDePagamento;
}

string codigoDePagamento::get(){
    return codigoDePagamento;
}

//senha

void Senha::validar(string senha){
    int tamanho = senhaTeste.size();
        if(tamanho != 6){
            throw invalid_argument ("Senha Fornecida Invalida (nao tem 6 caracteres)");} //checa se tem 6 caracteres
        if(senhaTeste[0] == '0') {
            throw invalid_argument ("Senha Fornecida Invalida(o primeiro digito e 0)"); } // checa se o primeiro digito !=0
        bool sequenciacresc = true, sequenciadecresc =  true;
        for(int i = 0; i < tamanho; i++){
            if(!isdigit(senhaTeste[i])){
                throw invalid_argument ("Senha Fornecida Invalida (nem todos caracteres sao digitos)");}// checa se todos caracteres sao digitos
            if(i<tamanho-1){
                int atualc = senhaTeste[i] - '0';
                int proxc = senhaTeste[i+1] -'0';
                if(atualc != proxc-1){ sequenciacresc = false;}


            }
            if( i<tamanho-1){
                int atuald = senhaTeste[i]-'0';
                int proxd = senhaTeste[i+1]-'0';
                if(atuald != proxd+1){ sequenciadecresc = false;}
            }
        }
            if(sequenciacresc) {
                throw invalid_argument ("Senha Fornecida Invalida (sequencia crescente)");}// checa se senha é sequencia crescente
            if(sequenciadecresc) {
                throw invalid_argument ("Senha Fornecida Invalida (sequencia decrescente)");}



        };

void Senha::set(string senha){
    validar(senha);
    this->senha=senha;
}

string Senha::get(){
    return senha;
}



// codigo de titulo
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

// CPF
void CPF::set(string CPF){
    validar(CPF);
    this->CPF=CPF;
};

void CPF::validar(string CPF){
    // modelo: XXX.XXX.XXX-CC
    if (CPF.length() != 14) {
        // Validando o tamanho do CPF
        throw invalid_argument("Erro: Tamanho do CPF Inválido.");
    } else if (CPF[3] != '.' || CPF[7] != '.' || CPF[11] != '-') {
        // Validando o formato do CPF
        throw invalid_argument("Erro: Formato do CPF Inválido.");
    } else if ((CPF[0] == CPF[1])&&(CPF[1]==CPF[2])&&(CPF[2]==CPF[4])&&(CPF[4]==CPF[5])&&(CPF[5]==CPF[6])&&(CPF[6]==CPF[8])&&(CPF[8]==CPF[9])&&(CPF[9]==CPF[10])&&(CPF[10]==CPF[12])&&(CPF[12]==CPF[13])) {
        /*
            Checagem de CPFs notoriamente inválidos,
            como "000.000.000-00" ou "333.333.333-33"
        */
        throw invalid_argument("Erro: CPF Inválido conhecido.");
    } else {
        /*
            Removendo traços e pontos do CPF, agora
            ele possui o formato XXXXXXXXXCC
        */
        string cleanCPF = "";
        for (int i = 0; i<14; i++) {
            if (i != 3 && i != 7 && i != 11) {
                string s(1, CPF[i]);
                cleanCPF += s;
            };
        };
        // Validação com primeiro dígito

        // definindo o dígito de validação
        int validDigit_1 = cleanCPF[9] - '0';

        // n = número iterado que vai multiplicar cada dígito do CPF
        // i = cada dígito do CPF
        int digitSum_1 = 0; // stoi(CPF[i])*n
        int n = 10;
        for (int i = 0; i < 9; i++) {
            digitSum_1 += (cleanCPF[i] - '0')*n;
            n--;
        };
           int testModulo_1 = (digitSum_1*10)%11;
        if (testModulo_1 == 10 && validDigit_1 != 0) {
            throw invalid_argument("Erro: CPF Inválido, erro na primeira validação.");
        } else if (testModulo_1 != validDigit_1) {
            throw invalid_argument("Erro: CPF Inválido, erro na primeira validação.");
        } else {
            // Validação com segundo dígito
            // definindo o dígito de validação
            int validDigit_2 = cleanCPF[10] - '0';
            // n = número iterado que vai multiplicar cada dígito do CPF
            // i = cada dígito do CPF
            int digitSum_2 = 0;
            int n = 11  ;
            for (int i = 0; i < 10; i++) {
                digitSum_2 += (cleanCPF[i] - '0')*n;
                n--;
            };

            int testModulo_2 = (digitSum_2*10)%11;
            if (testModulo_2 == 10 && validDigit_2 != 0) {
                throw invalid_argument("Erro: CPF Inválido, erro na segunda validação.");
            } else if (testModulo_2 != validDigit_2) {
                throw invalid_argument("Erro: CPF Inválido, erro na segunda validação.");
            } else {
                // se chegar até aqui, a validação teve sucesso.
                cout << "CPF Válido!" << endl;
            };
        };
    };
};

string CPF::get(){
    return CPF;
};

void Dinheiro::set(float valor){
    validar(valor);
    this->valor=valor;
};

void Dinheiro::validar(float valor){
    //codar aqui
    if (valor < 0 || valor > 1000000){
      throw invalid_argument("Valor inválido!");
    };
};

float Dinheiro::get() {
    return valor;
};

// Construtor
Data::Data(int dia, int mes, int ano) : dia(dia), mes(mes), ano(ano) {
    if (!validarData()) {
        cerr << "Erro: Data inválida!\n";
        this->dia = 0;
        this->mes = 0;
        this->ano = 0;
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

void Data::setDia(int dia) {
    this->dia = dia;
    if (!validarData()) {
        cerr << "Erro: Data inválida!\n";
        this->dia = 0; // Reverte para um valor inválido
    }
}
void Data::setMes(int mes) {
    this->mes = mes;
    if (!validarData()) {
        cerr << "Erro: Data inválida!\n";
        this->mes = 0; // Reverte para um valor inválido
    }
}
void Data::setAno(int ano) {
    this->ano = ano;
    if (!validarData()) {
        cerr << "Erro: Data inválida!\n";
        this->ano = 0; // Reverte para um valor inválido
    }
}

// validar a data
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
//  imprimir a data
void Data::imprimirData() const {
    cout << dia << "-" << mes << "-" << ano << std::endl;
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
