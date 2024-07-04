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
/**
 * Armazena o CPF informado caso este seja v&aacute;lido
 *
 * Lança a exce&ccedil;&atilde;o caso o CPF informado seja inv&aacute;lido.
 *
 * @param CPF cpf.
 *
 * @throw invalid_argument
 */

void CPF::setCPF(string CPF){
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

string CPF::getCPF(){
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
void Data::setData(string data) {
    validar(data);
    this->data = data;
}

void Data::validar(string data) {
    if (data.length() != 10 || data[2] != '-' || data[5] != '-') {
        throw invalid_argument("Formato de data inválido. Use DD-MM-AAAA.");
    }

    int dia, mes, ano;
    char hifen1, hifen2;
    istringstream iss(data);
    iss >> setw(2) >> dia >> hifen1 >> setw(2) >> mes >> hifen2 >> setw(4) >> ano;

    if (hifen1 != '-' || hifen2 != '-') {
        throw invalid_argument("Formato de data inválido. Use DD-MM-AAAA.");
    }

    if (mes < 1 || mes > 12) {
        throw invalid_argument("Mês inválido. Deve ser entre 01 e 12.");
    }

    if (ano < 2000 || ano > 2100) {
        throw invalid_argument("Ano inválido. Deve ser entre 2000 e 2100.");
    }

    bool bissexto = (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));

    int diasPorMes[] = { 31, (bissexto ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (dia < 1 || dia > diasPorMes[mes - 1]) {
        throw invalid_argument("Dia inválido para o mês especificado.");
    }
}

string Data::getData() {
    return data;
}

//Estado
/**
* Obtém o estado atual.
*
* @return o estado atual.
*/
string Estado::getEstado(){
    return estado;
};

/**
* Define o estado após validar a entrada.
*
* Lan&ccedil;a exce&ccedil;&atilde;o caso o estado seja inv&aacute;lido.
*
* @param novoEstado O novo estado.
*
* @throw invalid_argument
*/

void Estado::setEstado(string novoEstado){
    validar(novoEstado);
    estado = novoEstado;
};

/**
* Valida se o estado fornecido é um dos estados válidos.
*
* Lan&ccedil;a exce&ccedil;&atilde;o caso o estado seja inv&aacute;lido.
*
* @param estado O estado a ser validado.
*
* @throw invalid_argument
*/

void Estado::validar(string estado){
    if (estado != "Previsto" && estado != "Liquidado" && estado != "Inadimplente") {
        throw invalid_argument("Estado invalido");
    }
};

//Nome

// Função para definir o valor do nome
void Nome::setNome(string nome) { 
    validar(nome);
    this->nome = nome;
}

// Função de validação
void Nome::validar(string nome) {
    size_t len = nome.length();
    if (len < 3 || len > 21) {
        throw invalid_argument("Nome deve ter entre 3 e 21 caracteres.");
    }

    int termo_count = count(nome.begin(), nome.end(), ' ') + 1;
    if (termo_count > 2) {
        throw invalid_argument("Nome deve ser composto por um ou dois termos.");
    }

    string::size_type pos = 0;
    for (int i = 0; i < termo_count; ++i) {
        string::size_type next_space = nome.find(' ', pos);
        size_t term_len = (next_space == string::npos) ? len - pos : next_space - pos;
        if (term_len < 3 || term_len > 10) {
            throw invalid_argument("Cada termo deve ter entre 3 e 10 caracteres.");
        }
        for (size_t j = pos; j < pos + term_len; ++j) {
            if (!isalpha(nome[j])) {
                throw invalid_argument("Cada caractere deve ser uma letra.");
            }
        }
        if (!isupper(nome[pos])) {
            throw invalid_argument("Primeiro caractere de cada termo deve ser letra maiúscula.");
        }
        pos = next_space + 1;
    }
}

// Função para obter o valor do nome
string Nome::getNome() {
    return nome;
}

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

void Senha::setSenha(string senha){
    validar(senha);
    this->senha=senha;
};

string Senha::getSenha(){
    return senha;
};

//Setor
/**
* Obtém o nome do setor.
*
* @return O nome do setor.
*/
string Setor::getSetor(){
    return setor;
};
/**
* Define o nome do setor após validar a entrada.
*
* Lan&ccedil;a exce&ccedil;&atilde;o caso o setor seja inv&aacute;lido.
*
* @param novoSetor O novo nome do setor.
*
* @throw invalid_argument
*/
void Setor::setSetor(string novoSetor) {
    validar(novoSetor);
    setor = novoSetor;
};

/**
* Valida se o setor fornecido está entre os setores válidos.
*
* Lan&ccedil;a exce&ccedil;&atilde;o caso o setor seja inv&aacute;lido.
*
* @param setor O nome do setor a ser validado.
*
* @throw invalid_argument
*/
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
