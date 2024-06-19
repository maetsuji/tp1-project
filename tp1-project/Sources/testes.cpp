using namespace std;

void TUCodigoDeTitulo::setUp(){
    codigo = new codigoDeTitulo();
    estado = SUCESSO;
}

void TUCodigoDeTitulo::tearDown(){
    delete codigo;
}

void TUCodigoDeTitulo::testarCenarioSucesso(){
    try{
        codigo->setCodigo(VALOR_VALIDO);
        if (codigo->getCodigo() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUCodigoDeTitulo::testarCenarioFalha(){
    try{
        codigo->setCodigo(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (codigo->getCodigo() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

void TUPercentual::setUp(){
    percentual = new Percentual();
    estado = SUCESSO;
}

void TUPercentual::tearDown(){
    delete percentual;
}

void TUPercentual::testarCenarioSucesso(){
    try{
        percentual->setValor(VALOR_VALIDO);
        if (percentual->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUPercentual::testarCenarioFalha(){
    try{
        percentual->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (percentual->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUPercentual::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUCPF::setUp(){
    cpf = new CPF();
    estado = SUCESSO;
}

void TUCPF::tearDown(){
    delete cpf;
}

void TUCPF::testarCenarioSucesso(){
    try{
        cpf->set(VALOR_VALIDO);
        if (cpf->get() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUCPF::testarCenarioFalha(){
    try{
        codigo->set(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (codigo->get() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUCPF::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUNome::setUp() {
    nome = new Nome(NOME_VALIDO);
    estado = SUCESSO;
}

void TUNome::tearDown() {
    delete nome;
}

void TUNome::testarCenarioSucesso() {
    if (nome->getPrimeiroTermo() != "João" || nome->getSegundoTermo() != "Silva") {
        estado = FALHA;
    }
}

void TUNome::testarCenarioFalha() {
    Nome nomeInvalido(NOME_INVALIDO);
    if (!nomeInvalido.getPrimeiroTermo().empty() || !nomeInvalido.getSegundoTermo().empty()) {
        estado = FALHA;
    }
}

int TUNome::run() {
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUData::setUp() {
    data = new Data(DIA_VALIDO, MES_VALIDO, ANO_VALIDO);
    estado = SUCESSO;
}

void TUData::tearDown() {
    delete data;
}

void TUData::testarCenarioSucesso() {
    if (data->getDia() != DIA_VALIDO || data->getMes() != MES_VALIDO || data->getAno() != ANO_VALIDO) {
        estado = FALHA;
    }
}

void TUData::testarCenarioFalha() {
    Data dataInvalida(DIA_INVALIDO, MES_INVALIDO, ANO_INVALIDO);
    if (dataInvalida.getDia() != 0 || dataInvalida.getMes() != 0 || dataInvalida.getAno() != 0) {
        estado = FALHA;
    }
}

int TUData::run() {
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}