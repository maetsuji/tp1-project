using namespace std;

//TESTES DE DOMÍNIOS
void TUCodigoDePagamento::setUp(){
    codigo = new codigoDePagamento();
    estado = SUCESSO;
}

void TUCodigoDePagamento::tearDown(){
    delete codigo;
}

void TUCodigoDePagamento::testarCenarioSucesso(){
    try{
        codigo->setCodigo(VALOR_VALIDO);
        if (codigo->getCodigo() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUCodigoDePagamento::testarCenarioFalha(){
    try{
        codigo->setCodigo(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (codigo->getCodigo() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUCodigoDePagamento::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}

void TUSenha::setUp(){
    senha = new Senha();
    estado = SUCESSO;
}

void TUSenha::tearDown(){
    delete senha;
}

void TUSenha::testarCenarioSucesso(){
    try{
        senha->setSenha(VALOR_VALIDO);
        if (senha->getSenha() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao){
        estado = FALHA;
    }
}

void TUSenha::testarCenarioFalha(){
    try{
        senha->setSenha(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao){
        if (senha->getSenha() == VALOR_INVALIDO)
            estado = FALHA;
    }
}

int TUSenha::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}


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
    nome = new Nome();
    estado = SUCESSO;
}

void TUNome::tearDown() {
    delete nome;
}

void TUNome::testarCenarioSucesso() {
    try {
        nome->setNome(NOME_VALIDO);
        if (nome->getNome() != NOME_VALIDO) {
            estado = FALHA;
        }
    } catch (invalid_argument &e) {
        estado = FALHA;
    }
}

void TUNome::testarCenarioFalha() {
    try {
        nome->setNome(NOME_INVALIDO);
        estado = FALHA;  // Se não lançar exceção, falha o teste
    } catch (invalid_argument &e) {
        // Exceção esperada, o estado permanece SUCESSO
    }
}

int TUNome::run() {
    setUp();
    testarCenarioSucesso();
    if (estado == SUCESSO) {
        testarCenarioFalha();
    }
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
    codigoDeTitulo codigodetitulo
    codigodetitulo.setCodigo(CODIGO_VALIDO);
    titulo->setCodigo(codigodetitulo);
    if (titulo->getCodigo().getCodigo() != CODIGO_VALIDO)
        estado = FALHA;
    
    Nome emissor;
    emissor.setNome(NOME_VALIDO);
    titulo->setEmissor(emissor);
    if (titulo->getEmissor().getNome() != NOME_VALIDO)
        estado = FALHA;
    
    Setor setor;
    setor.setSetor(SETOR_VALIDO);
    titulo->setSetor(setor);
    if (titulo->getSetor().getSetor() != SETOR_VALIDO)
        estado = FALHA;
    
    Data emissao;
    emissao.setData(DATA_VALIDA);
    titulo->setEmissao(emissao);
    if (titulo->getEmissao().getData() != DATA_VALIDO)
        estado = FALHA;
    
    Data vencimento;
    vencimento.setData(DATA_VALIDA);
    titulo->setVencimento(vencimento);
    if (titulo->getVencimento().getData() != DATA_VALIDA)
        estado = FALHA;
    
    Dinheiro valor;
    valor.setValor(VALOR_VALIDO);
    titulo->setValor(valor);
    if (titulo->getValor().getValor() != VALOR_VALIDO)
        estado = FALHA;
}

int TUTitulo::run() {
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}

void TUPagamento::setUp(){
    pagamento = new Pagamento();
    estado = SUCESSO;
}

void TUPagamento::tearDown(){
    delete pagamento;
}

void TUPagamento::testarCenarioSucesso(){
    codigoDePagamento codigodepagamento;
    codigodepagamento.setCodigo(CODIGO_VALIDO);
    pagamento->setCodigo(codigodepagamento);
    if (pagamento->getCodigo().getCodigo() != CODIGO_VALIDO)
        estado = FALHA;
    
    Data data;
    data.setData(DATA_VALIDA);
    pagamento->setData(data);
    if (pagamento->getData().getData() != DATA_VALIDA)
        estado = FALHA;
    
    Percentual percentual;
    percentual.setPercentual(PERCENTUAL_VALIDO);
    pagamento->setPercentual(percentual);
    if (pagamento->getPercentual().getPercentual() != PERCENTUAL_VALIDO)
        estado = FALHA;

    Estado estado_obj;
    estado_obj.setEstado(ESTADO_VALIDO);
    pagamento->setEstado(estado_obj);
    if (pagamento->getEstado().getEstado() != ESTADO_VALIDO)
        estado = FALHA;
}

int TUPagamento::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}
