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

void TUDinheiro::setUp(){
    valor = new Valor();
    estado = SUCESSO;
}

void TUDinheiro::tearDown(){
    delete valor;
}

void TUDinheiror::testarCenarioSucesso(){
    try{
        valor->setValor(VALOR_VALIDO);
        if (valor->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUDinheiro::testarCenarioFalha(){
    try{
        valor->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (valor->getCPF() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUDinheiro::run(){
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

void TUData::setUp(){
    data = new Data();
    estado = SUCESSO;
}

void TUData::tearDown(){
    delete data;
}

void TUData::testarCenarioSucesso(){
    try{
        data->setData(VALOR_VALIDO);
        if (data->getData() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(std::invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUData::testarCenarioFalha(){
    try{
        data->setData(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(std::invalid_argument &excecao){
        if (data->getData() == VALOR_INVALIDO)
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

void TuTitulo::setUp() {
    titulo = new Titulo();
    estado = SUCESSO;
}

void TUtitulo::tearDown() {
    delete titulo;
}

void TUTitulo::testarCenarioSucesso(){
    codigodeTitulo TITULO_VALIDO = "CDB";
    Nome NOME_VALIDO;
    NOME_VALIDO.setNome("Nome Emissor");
    Setor SETOR_VALIDO;
    SETOR_VALIDO.setSetor("Setor Válido");
    Data DATA_VALIDA;
    DATA_VALIDA.setData("01/01/2023");
    Dinheiro VALOR_VALIDO;
    VALOR_VALIDO.setValor(1000.00);

    titulo->setCodigo(CODIGO_VALIDO);
    if (titulo->getCodigo() != CODIGO_VALIDO)
        estado = FALHA;
    titulo->setEmissor(NOME_VALIDO);
    if (titulo->getEmissor().getNome() != "Nome Emissor")
        estado = FALHA;
    titulo->setSetor(SETOR_VALIDO);
    if (titulo->getSetor().getSetor() != "Setor Válido")
        estado = FALHA;
    titulo->setEmissao(DATA_VALIDA);
    if (titulo->getEmissao().getData() != "01/01/2023")
        estado = FALHA;
    titulo->setVencimento(DATA_VALIDA);
    if (titulo->getVencimento().getData() != "01/01/2023")
        estado = FALHA;
    titulo->setValor(VALOR_VALIDO);
    if (titulo->getValor().getValor() != 1000.00)
        estado = FALHA;
}

int TUTitulo::run() {
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}
