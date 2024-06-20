using namespace std;

//Codigo de pagamento
void codigoDePagamento::validar(string codigoDePagamento){
     int tamanho = codigoDePagamento.size();
            if(tamanho != 9){
                    throw invalid_argument("Codigo de Pagamento Fornecido Invalido (nao tem 9 caracteres)");} //checa se tem 9 digitos
            if(codigoDePagamento[0] == '0') {
                throw invalid_argument( "Codigo de Pagamento Fornecido Invalido (o primeiro digito e 0)"); } //checa se o primeiro digito !=0
            for(int i = 0; i < tamanho; i++){
                if(!isdigit(codigoDePagamento[i])){
                    throw invalid_argument ( "Codigo de Pagamento Fornecido Invalido (nem todos os caracteres sao digitos)");}} // checa se os digitos sao digitos
};

void codigoDePagamento::setCodigo(string codigoDePagamento){
    validar(codigoDePagamento);
    this->codigoDePagamento = codigoDePagamento;
};

string codigoDePagamento::getCodigo(){
    return codigoDePagamento;
};

//Codigo de titulo

/**
* Armazena o c&oacute;digo informado caso o mesmo seja v&aacute;lido.
*
* Lan&ccedil;a exce&ccedil;&atilde;o caso o c&oacute;digo informado seja inv&aacute;lido.
*
* @param valor C&oacute;digo.
*
* @throw invalid_argument
*/

void codigoDeTitulo::setCodigo(string codigoDeTitulo){
    validar(codigoDeTitulo);
    this->codigoDeTitulo=codigoDeTitulo;
};

/**
* Verifica se o c&oacute;digo possui exatamente 11 caracteres, com as letras sendo mai&uacute;sculas.
*
* Depois, verifica se o identificador (3 primeiros caracteres) faz parte da lista de c&oacute;digos v&aacute;lidos: -CDB -CRA -CRI -LCA -LCI -DEB
*
* Lan&ccedil;a exce&ccedil;&atilde;o caso o c&oacute;digo seja inv&aacute;lido.
*
* @param codigoDeTitulo C&oacute;digo.
*
* @throw invalid_argument
*/

void codigoDeTitulo::validar(string codigoDeTitulo){
    identificador.assign(codigoDeTitulo,0,3);
    static const string codigosConhecidos[]={
        "CDB",
        "CRA",
        "CRI",
        "LCA",
        "LCI",
        "DEB"
    };
    if (codigoDeTitulo.length()!=11)
        throw invalid_argument("Codigo de Titulo Invalido (Tamanho invalido).");
    for (int i=3;i<11;i++){
        if (!(isdigit(codigoDeTitulo[i])) && !(isupper(codigoDeTitulo[i])))
            throw invalid_argument("Codigo de Titulo Invalido.");
        };
    for (string codigoValido : codigosConhecidos){
        if (identificador == codigoValido)
            return;
    }
    throw invalid_argument("Codigo de Titulo Invalido. (Identificador desconhecido)");
};

/**
* Retorna c&oacute;digo de t&iacute;tulo
*
* @return C&oacute;digo
*/

string codigoDeTitulo::getCodigo(){
    return codigoDeTitulo;
};

// CPF
void CPF::setCpf(string CPF){
    validar(CPF);
    this->CPF=CPF;
};

void CPF::validar(string CPF){
    // modelo: XXX.XXX.XXX-CC
    if (CPF.length() != 14) {  /// Validando o tamanho do CPF
        throw invalid_argument("Erro: Tamanho do CPF Invalido.");
    } else if (CPF[3] != '.' || CPF[7] != '.' || CPF[11] != '-') {   /// Validando o formato do CPF
        throw invalid_argument("Erro: Formato do CPF Invalido.");
    } else if ((CPF[0] == CPF[1])&&(CPF[1]==CPF[2])&&(CPF[2]==CPF[4])&&(CPF[4]==CPF[5])&&(CPF[5]==CPF[6])&&(CPF[6]==CPF[8])&&(CPF[8]==CPF[9])&&(CPF[9]==CPF[10])&&(CPF[10]==CPF[12])&&(CPF[12]==CPF[13])) {
        /*
            Checagem de CPFs notoriamente inválidos,
            como "000.000.000-00" ou "333.333.333-33"
        */
        throw invalid_argument("Erro: CPF Invalido conhecido.");
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
            throw invalid_argument("Erro: CPF Invalido, erro na primeira validacao.");
        } else if (testModulo_1 != validDigit_1) {
            throw invalid_argument("Erro: CPF Invalido, erro na primeira validacao.");
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
                throw invalid_argument("Erro: CPF Invalido, erro na segunda validacao.");
            } else if (testModulo_2 != validDigit_2) {
                throw invalid_argument("Erro: CPF Invalido, erro na segunda validacao.");
            } else {
                // se chegar até aqui, a validação teve sucesso.
                cout << "CPF Valido!" << endl;
            };
        };
    };
};

string CPF::getCpf(){
    return CPF;
};

//Dinheiro
void Dinheiro::setValor(float valor){
    validar(valor);
    this->valor=valor;
};

void Dinheiro::validar(float valor){
    //codar aqui
    if (valor < 0 || valor > 1000000){
      throw invalid_argument("Valor invalido!");
    };
};

float Dinheiro::getValor() {
    return valor;
};

//Data
void Data::Data(int dia, int mes, int ano) : dia(dia), mes(mes), ano(ano) {
    if (!validarData()) {
        cerr << "Erro: Data inválida!\n";
        this->dia = 0;
        this->mes = 0;
        this->ano = 0;
    }
};

int Data::getDia() const {
    return dia;
};

int Data::getMes() const {
    return mes;
};

int Data::getAno() const {
    return ano;
};

void Data::setDia(int dia) {
    this->dia = dia;
    if (!validarData()) {
        cerr << "Erro: Data inválida!\n";
        this->dia = 0; 
    }
};

void Data::setMes(int mes) {
    this->mes = mes;
    if (!validarData()) {
        cerr << "Erro: Data inválida!\n";
        this->mes = 0; 
    }
};

void Data::setAno(int ano) {
    this->ano = ano;
    if (!validarData()) {
        cerr << "Erro: Data inválida!\n";
        this->ano = 0; 
    }
};

bool Data::validarData() const {      // validar a data
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
};

void Data::imprimirData() const {    //  imprimir a data
    cout << dia << "-" << mes << "-" << ano << endl;
};

//Estado
string Estado::getEstado(){
    return estado;
};

void Estado::setEstado(string novoEstado){
    validar(novoEstado);
    estado = novoEstado;
};

void Estado::validar(string estado){
    if (estado != "Previsto" && estado != "Liquidado" && estado != "Inadimplente") {
        throw invalid_argument("Estado invalido");
    }
};

//Nome
void Nome::Nome(const std::string& nomeCompleto) {
    size_t pos = nomeCompleto.find(' ');
    primeiroTermo = nomeCompleto.substr(0, pos);
    if (pos != std::string::npos) {
        segundoTermo = nomeCompleto.substr(pos + 1);
    }
    if (!validarTermo(primeiroTermo) || !validarTermo(segundoTermo)) {
        std::cerr << "Erro: Termo(s) inválido(s)!\n";
        primeiroTermo.clear();
        segundoTermo.clear();
    }
}

bool Nome::validarTermo(const std::string& termo) const {
    if (termo.empty() || !isupper(termo[0])) // Primeiro caractere deve ser maiúscula
        return false;
    for (char c : termo) {
        if (!isalpha(c))
            return false; // Caractere não é uma letra
    }
    return true;
}
string Nome::getPrimeiroTermo() const {
    return primeiroTermo;
}
string Nome::getSegundoTermo() const {
    return segundoTermo;
};

void Nome::setPrimeiroTermo(const string& primeiroTermo) {
    if (validarTermo(primeiroTermo)) {
        this->primeiroTermo = primeiroTermo;
    } else {
        cerr << "Erro: Primeiro termo inválido!\n";
    }
};

void Nome::setSegundoTermo(const string& segundoTermo) {
    if (validarTermo(segundoTermo)) {
        this->segundoTermo = segundoTermo;
    } else {
        cerr << "Erro: Segundo termo inválido!\n";
    }
};

//Percentual

/**
* Armazena o percentual informado caso o mesmo seja v&aacute;lido.
*
* Lan&ccedil;a exce&ccedil;&atilde;o caso o percentual informado seja inv&aacute;lido.
*
* @param valor Percentual.
*
* @throw invalid_argument
*/

void Percentual::setValor(int valor)
{
    validar(valor);
    this->valor=valor;
};

/**
* Verifica se o percentual a ser validado vai de 0 a 100.
*
* Lan&ccedil;a exce&ccedil;&atilde;o caso o percentual seja inv&aacute;lido.
*
* @param valor Percentual.
*
* @throw invalid_argument
*/

void Percentual::validar(int valor)
{
    if (valor < 0 || valor > 100)
        throw invalid_argument("Percentual Invalido.");
};

/**
* Retorna Percentual
*
* @return Percentual
*/

int Percentual::getValor()
{
    return valor;
};

//Senha
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
};

string Senha::get(){
    return senha;
};

//Setor
string Setor::getSetor(){
    return setor;
};

void Setor::setSetor(string novoSetor) {
    validar(novoSetor);
    setor = novoSetor;
};

void Setor::validar(string setor){
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
    for (const string setorValido : setoresValidos) {
        if (setor == setorValido) {
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        throw invalid_argument("Setor invalido");
    }
};
