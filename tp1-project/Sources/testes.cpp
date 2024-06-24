using namespace std;

//TESTES DE DOMÍNIOS

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
        cpf->setCPF(VALOR_VALIDO);
        if (cpf->getCPF() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUCPF::testarCenarioFalha(){
    try{
        cpf->setCPF(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (cpf->getCPF() == VALOR_INVALIDO)
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

void TUValor::setUp(){
    valor = new Valor();
    estado = SUCESSO;
}

void TUValor::tearDown(){
    delete valor;
}

void TUValor::testarCenarioSucesso(){
    try{
        valor->setValor(VALOR_VALIDO);
        if (valor->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUValor::testarCenarioFalha(){
    try{
        valor->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (valor->getCPF() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUValor::run(){
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

void TUEstado::setUp(){
    estad_o = new Setor();
    estado = SUCESSO;
}

void TUEstado::tearDown(){
    delete estad_o;
}

void TUEstado::testarCenarioSucesso(){
    try{
        estad_o->setEstado(VALOR_VALIDO);
        if (estad_o->getEstado() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUEstado::testarCenarioFalha(){
    try{
        estad_o->setEstado(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (estad_o->getEstado() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUEstado::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUSetor::setUp(){
    setor = new Setor();
    estado = SUCESSO;
}

void TUSetor::tearDown(){
    delete setor;
}

void TUSetor::testarCenarioSucesso(){
    try{
        setor->setSetor(VALOR_VALIDO);
        if (setor->getSetor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUSetor::testarCenarioFalha(){
    try{
        setor->setSetor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (setor->getSetor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUSetor::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

//TESTES DE ENTIDADE

void TUConta::setUp(){
    conta = new Conta();
    estado = SUCESSO;
}

void TUConta::tearDown(){
    delete codigo;
}

void TUConta::testarCenarioSucesso(){
    CPF cpf;
    cpf.setCpf(CPF_VALIDO);
    conta->setCpf(cpf);
    if (conta->getCpf().getCpf() != CPF_VALIDO)
        estado = FALHA;

    Nome nome;
    nome.setCpf(NOME_VALIDO);
    conta->setNome(nome);
    if (conta->getNome().getNome() != NOME_VALIDO)
        estado = FALHA;

    Senha senha;
    senha.setSenha(SENHA_VALIDA);
    conta->setSenha(senha);
    if (conta->getSenha().getSenha() != SENHA_VALIDA)
        estado = FALHA;
}

int TUConta::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}
