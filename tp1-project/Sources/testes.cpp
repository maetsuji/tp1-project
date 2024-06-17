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
