#include "common.h"
#include "controladoras.h"


using namespace std;

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Conta

void CntrAprConta::criarConta(){

    //Instâncias de classes domínios
    Nome nome;
    CPF cpf;
    Senha senha;

    //Variável temporária para inserção de dados
    string tempNome;
    string tempCPF;
    string tempSenha;
    bool resultado;

    //Loop para inserção e definição dos dados
    while (true){
        try{
            CLR_SCR;
            cout << " Informar Nome:" << " ";
            cin >> tempNome;
            nome.setNome(tempNome);
            CLR_SCR;
            cout << " Informar CPF:" <<" ";
            cin >> tempCPF;
            cpf.setCPF(tempCPF);
            CLR_SCR;
            cout << " Informar Senha:"<<" ";
            cin >> tempSenha;
            senha.setSenha(tempSenha);
            break;
        }
        catch (invalid_argument &e) {
            CLR_SCR;
            cout << "Dado Inválido.";
            return;
        }
    }

    //Instanciar e inicializar a classe de entidade
    Conta conta;
    conta.setNome(nome);
    conta.setCPF(cpf);
    conta.setSenha(senha);

    //Registrar no banco de dados e verificar lógica de negócio (Á fazer)
    if(cntrServConta->criarConta(conta)){
        CLR_SCR;
        cout << "Cadastro realizado com sucesso. Digite algo.";
        getch();
        return;
    }
    else{
        CLR_SCR;
        cout << "Falha no cadastro. Retornando para tela inicial. Digite algo.";
        getch();
        return;
    }
};

void CntrAprConta::executar(CPF *cpf){
    bool apresentar = true;

    while (apresentar){
        CLR_SCR;
        cout << "Selecione uma opção :" << endl;
        cout << "1. Atualizar dados cadastrais." << endl;
        cout << "2. Ler dados cadastrados." << endl;
        cout << "3. Excluir conta." << endl;
        cout << "4. Voltar." << endl;

        opcao = getch() - 48;

        switch (opcao){
            case 1: lerConta(cpf)
                break;
            case 2: atualizarConta(cpf)
                break;
            case 3: excluirConta(cpf)
                break;
            case 4:
                apresentar=false;
                break;
        }
    }
};

void CntrAprConta::lerConta(CPF cpf){
    Conta conta;

    try{
        conta=cntrServConta->lerConta(cpf);
    }
    catch(EErroPersistencia exp){
        CLR_SCR;
        cout << "Não foi possível ler a conta";
    }

    Nome  nome=conta.getNome();
    CPF   cpf=conta.getCPF();
    Senha senha=conta.getSenha();

    CLR_SCR;
    cout << "O Nome cadastrado é: " << nome.getNome() << endl;
    cout << "O CPF cadastrado é: " << cpf.getCPF() << endl;
    cout << "A Senha cadastrada é: " << senha.getSenha() << endl;
    cout << "Digite algo para retornar.";
    getch();
    return;
};

void CntrAprConta::atualizarConta(CPF *cpf){
    string tempNome;
    Nome nome;
    string tempSenha;
    Senha senha;
    Conta conta;
    conta.setCPF(cpf);
    try{
        CLR_SCR;
        cout << "Digite um novo nome: " << " ";
        cin >> tempNome;
        nome.setNome(tempNome);
        conta.setNome(nome);
        cout << "Digite uma nova senha: " << " ";
        cin >> tempSenha;
        senha.setSenha(tempSenha);
        conta.setSenha(senha);
    }
    catch(invalid_argument &e)
        CLR_SCR;
        cout << "Dado informado no formato inválido. Digite algo.";
        getch();
        return;
    if (cntrServConta->atualizarConta(conta))
        cout << "Dados atualizados com sucesso. Digite algo.";
        getch();
        return;
    else
        CLR_SCR;
        cout << "Não foi possível atualizar conta. Digite algo.";
        getch();
        return;
};

void CntrAprConta::excluirConta(CPF *cpf){
    if (cntrservconta.excluirConta(cpf))
        CLR_SCR;
        cout << "Conta excluída com sucesso. Digite algo.";
        cpf=0;
    else
        CLR_SCR;
        cout << "Não foi possível excluir a conta. Digite algo.";
};

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Auth

void CntrAprAuth::executar(CPF *cpf){
    //O QUE AUTENTICAR RETORNA?
    Senha senha;
    string tempCPF;
    string tempSenha;
    bool resultado;

    while (true){
        try{
            CLR_SCR;
            cout << " Informar CPF:" <<endl;
            cin >> tempCPF;
            cpf->setCPF(tempCPF);

            cout << " Informar Senha:"<<endl;
            cin >> tempSenha;
            senha.setSenha(tempSenha);
            break;
        }
        catch (invalid_argument &e) {
            cout << "Dado Inválido." << endl;
            return 0;
        }
    }
    if (cntrservauth.autenticarConta(cpf,senha))
        CLR_SCR;
        cout << "Conta autenticada com sucesso." << endl;
        cout << "Seja bem-vindo(a). Digite algo.";
    else
        CLR_SCR;
        cout << "Não foi possível autenticar sua conta. Digite algo.";
};

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Investimento

void CntrAprInvestimento::executar(CPF *cpf) {

void mostrarMenu() {
    cout << "0. Criar" << endl;
    cout << "1. Altear" << endl;
    cout << "2. Ler" << endl;
    cout << "3. Excluir" << endl;
    cout << "4. Voltar" << endl;
    cout << "Digite sua opção (0-4): ";
};

    do {
        int opcao = 0;
// Exibe o menu de opções
        cout << "Selecione a opção desejada:" << endl;
        cout << "1. Pagamentos" << endl;
        cout << "2. Títulos" << endl;
        cout << "3. Voltar" << endl;
        cout << "Digite sua opção (1-3): ";
        cin >> opcao;

        opcao = getch() - 48;

// Processa a opção selecionada
        switch (opcao) {
            case 1:
                do {
                    int opcao_pagamento = -1;
                    cout << "Você selecionou PAGAMENTO" << endl;
                    mostrarMenu();
                    cin >> opcao_pagamento;
                    opcao_pagamento = getch() - 48;

                    switch (opcao_pagamento) {
                        case 0;
                                criarPagamento(cpf);
                                break
                        case 1:
                                alterarPagamento(cpf);
                                break;
                        case 2:
                                lerPagamento(cpf);
                                break;
                        case 3:
                                excluirPagamento(cpf);
                                break;

                        default:
                            cout << "Opção inválida. Tente novamente." << endl;
                    }
                } while (opcao_pagamento != 4 );
                break;

            case 2:
                do {
                    int opcao_titulo = -1;
                    cout << "Você selecionou TÍTULOS" << endl;
                    mostrarMenu();
                    cin >> opcao_titulo;
                    opcao_titulo = getch() - 48;
                    switch (opcao_titulo) {
                        case 0;
                                criarTitulo(cpf);
                                break;
                        case 1:
                                alterarTitulo(cpf);
                                break;
                        case 2:
                                lerTitulo(cpf);
                                break;
                        case 3:
                                excluirTitulo(cpf);
                                break;
                        default:
                            cout << "Opção inválida. Tente novamente." << endl;

                    }
                } while (opcao_titulo != 4 );
                break;

            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
// Linha em branco para melhor visualização
        cout << endl;

    } while (opcao != 3 );

 };

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Título

void CntrAprInvestimento::criarTitulo(CPF *cpf) {

    //Domínios
    string tempCodigo;
    codigoDeTitulo codigo;
    string tempEmissor;
    Nome emissor;
    string tempSetor;
    Setor setor;
    string tempEmissao;
    Data emissao;
    string tempVencimento;
    Data vencimento;
    float tempValor;
    Dinheiro valor;
    Titulo titulo;

    //Inserção de dados
    while (true){
        try{
        CLR_SCR;
        cout << "Informar código de título:" << " ";
        cin >> tempCodigo;
        codigo.setCodigo(tempCodigo);
        cout << "Informar emissor:" << " ";
        cin >> tempEmissor;
        nome.setNome(tempEmissor);
        cout << "Informar setor:" << " ";
        cin >> tempSetor;
        setor.setSetor(tempSetor);
        cout << "Informar data de emissão:" << " ";
        cin >> tempEmissao;
        emissao.setData(tempEmissao);
        cout << "Informar data de vencimento:" << " ";
        cin >> tempVencimento;
        vencimento.setData(tempVencimento);
        cout << "Informar valor:" << " ";
        cin >> tempValor;
        valor.setValor(tempValor);
        break;
        }

        catch(invalid_argument &e){
            cout << "Valor inválido. Digite algo"
            getch();
            return;
        }
    }

    //Entidade
    titulo.setCodigo(codigo);
    titulo.setEmissor(emissor);
    titulo.setSetor(setor);
    titulo.setEmissao(emissao);
    titulo.setVencimento(vencimento);
    titulo.setValor(valor);

    if (cntrservinvestimento.criarTitulo(titulo,cpf))
        cout << "Título criado com sucesso. Digite algo.";
        getch();
        return;
    else
        cout << "Título não foi criado. Digite algo."
        getch();
        return;
};

void CntrAprInvestimento::atualizarTitulo(CPF *cpf) {
    //Domínios
    string tempCodigo;
    codigoDeTitulo codigo;
    string tempEmissor;
    Nome emissor;
    string tempSetor;
    Setor setor;
    string tempEmissao;
    Data emissao;
    string tempVencimento;
    Data vencimento;
    float tempValor;
    Dinheiro valor;
    Titulo titulo;

    //Inserção de dados
    while (true){
        try{
        CLR_SCR;
        cout << "Informar código de título que será alterado:" << " ";
        cin >> tempCodigo;
        codigo.setCodigo(tempCodigo);
        cout << "Informar emissor:" << " ";
        cin >> tempEmissor;
        nome.setNome(tempEmissor);
        cout << "Informar setor:" << " ";
        cin >> tempSetor;
        setor.setSetor(tempSetor);
        cout << "Informar data de emissão:" << " ";
        cin >> tempEmissao;
        emissao.setData(tempEmissao);
        cout << "Informar data de vencimento:" << " ";
        cin >> tempVencimento;
        vencimento.setData(tempVencimento);
        cout << "Informar valor:" << " ";
        cin >> tempValor;
        valor.setValor(tempValor);
        break;
        }

        catch(invalid_argument &e){
            cout << "Valor inválido. Digite algo"
            getch();
            return;
        }
    }

    //Entidade
    titulo.setCodigo(codigo);
    titulo.setEmissor(emissor);
    titulo.setSetor(setor);
    titulo.setEmissao(emissao);
    titulo.setVencimento(vencimento);
    titulo.setValor(valor);

    if (cntrservinvestimento.atualizarTitulo(titulo)){
        cout << "Título atualizado com sucesso. Digite algo.";
        getch();
        return;
    }
    else{
        cout << "Título não foi atualizado. Digite algo."
        getch();
        return;
    }
};

void CntrAprInvestimento::lerTitulo(CPF *cpf) {
    CLR_SCR;
    Titulo lista_titulo[]=cntrservainvestimento.lerTitulo(cpf);
    if (lista_titulo.size()==0){
        cout << "Não existem títulos cadastrados. Digite algo.";
        getch();
        return;
    }
    cout << "Título(s) associado(s) ao seu CPF:";
    for (Titulo titulo : lista_titulo){
        cout << "Código de título: " << titulo.getCodigo().getCodigo();
        cout << "Emissor: " << titulo.getCodigo().getCodigo();
        cout << "Setor: " << titulo.getCodigo().getCodigo();
        cout << "Data de emissão: " << titulo.getCodigo().getCodigo();
        cout << "Data de vencimento: " << titulo.getCodigo().getCodigo();
        cout << "Valor: " << titulo.getCodigo().getCodigo();
        cout << endl;
    };
    cout << "Digite algo.";
    getch();
    return;
};

void CntrAprInvestimento::excluirTitulo(CPF *cpf) {
    codigoDeTitulo codigodetitulo;
    string tempCodigo;
    try{
        cout << "Informe o código do título que será excluído: ";
        cin << tempCodigo;
        codigodetitulo.setCodigo(tempCodigo);
    }
    catch(invalid_argument &e){
        cout << "Código inválido. Digite algo.";
        getch();
        return;
    }

    if (cntrservinvestimento.excluirTitulo(codigodetitulo)){
        cout << "Título excluído com sucesso. Digite algo."
        getch();
        return;
    else
        cout << "Título não foi excluído. Digite algo."
        getch();
        return;
    }
};

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Pagamento

void CntrAprInvestimento::criarPagamento(CPF *cpf) {
    //Domínios
    string tempCodigo;
    codigoDePagamento codigo;
    string tempData;
    Data data;
    int tempPercentual;
    Percentual percentual;
    string tempEstado;
    Estado estado;
    Pagamento pagamento;

    while (true){
        try{
            CLR_SCR;
            cout << "Informar código de pagamento:" << " ";
            cin >> tempCodigo;
            codigo.setCodigo(tempCodigo);
            cout << "Informar data de pagamento:" << " ";
            cin >> tempData;
            data.setData(tempData);
            cout << "Informar percentual:" << " ";
            cin >> tempPercentual;
            setor.setPercentual(tempPercentual);
            cout << "Informar estado:" << " ";
            cin >> tempEstado;
            estado.setEstado(tempEstado);
            break;
            }

        catch(invalid_argument &e){
            CLR_SCR;
            cout << "Valor inválido. Digite algo"
            getch();
            return;
            }
    }
    pagamento.setCodigo(codigo);
    pagamento.setData(data);
    pagamento.setPercentual(percentual);
    pagamento.setEstado(estado);

    if (cntrservinvestimento.criarPagamento(pagamento,cpf))
        CLR_SCR;
        cout << "Pagamento criado com sucesso. Digite algo.";
        getch();
        return;
    else
        CLR_SCR;
        cout << "Pagamento não foi criado."
        getch();
        return;
};

void CntrAprInvestimento::atualizarPagamento(CPF *cpf) {


    //Domínios
    string tempCodigo;
    codigoDePagamento codigo;
    string tempData;
    Data data;
    int tempPercentual;
    Percentual percentual;
    string TempEstado;
    Estado estado;
    Pagamento pagamento;

    while (true){
        try{
            CLR_SCR;
            cout << "Informar código do pagamento que será alterado:" << " ";
            cin >> tempCodigo;
            codigo.setCodigo(tempCodigo);
            cout << "Informar data de pagamento:" << " ";
            cin >> tempData;
            data.setData(tempData);
            cout << "Informar percentual:" << " ";
            cin >> tempPercentual;
            setor.setPercentual(percentual);
            cout << "Informar estado:" << " ";
            cin >> TempEstado;
            estado.setEstado(estado);
            break;
            }

        catch(invalid_argument &e){
            CLR_SCR;
            cout << "Valor inválido. Digite algo"
            getch();
            return;
            }
    }
    pagamento.setCodigo(codigo);
    pagamento.setData(data);
    pagamento.setPercentual(percentual);
    pagamento.setEstado(estado);

    if (cntrservinvestimento.atualizarPagamento(pagamento))
        CLR_SCR;
        cout << "Pagamento atualizado com sucesso.";
        getch();
        return;
    else
        CLR_SCR;
        cout << "Pagamento não atualizado.";
        getch();
        return;

};

void CntrAprInvestimento::lerPagamento(CPF *cpf) {
    CLR_SCR;
    codigoDeTitulo codigodetitulo;
    string temp_titulo;
    cout << "Informe o código do título ao qual o pagamento é associado:";
    cin << temp_titulo;
    codigodetitulo.setCodigo(temp_titulo);
    Pagamento lista_pagamento[]=cntrservinvestimento.lerPagamento(codigodetitulo);
    if (lista_pagamento.size()==0){
        cout << "Não existem títulos cadastrados. Digite algo.";
        getch();
        return;
    }
    cout << "Pagamento(s) associado(s) ao título informado:"
    for (Pagamento pagamento : lista_pagamento){
        cout << "Código de pagamento: " << pagamento.getCodigo().getCodigo();
        cout << "Data de pagamento: " << pagamento.getData().getData();
        cout << "Percentual: " << pagamento.getPercentual().getValor();
        cout << "Estado de pagamento: " << pagamento.getEstado().getEstado();
        cout << "Digite algo."
    };
    getch();
    return;
};

void CntrAprInvestimento::excluirPagamento(CPF *cpf) {
    codigoDePagamento codigodepagamento;
    string tempCodigo;
    try{
        cout << "Informe o código do pagamento que será excluído: ";
        cin << tempCodigo;
        codigodepagamento.setCodigo(tempCodigo);
    }
    catch(invalid_argument &e){
        cout << "Código inválido. Digite algo.";
        getch();
        return;
    }
    if (cntrservinvestimento.excluirPagamento(codigodepagamento)){
        cout << "Pagamento Excluído com sucesso. Digite algo."
        getch();
        return;
    }
    else
        cout << "Pagamento não foi excluído. Digite algo."
        getch();
        return;
};

//Serviço de conta---------------------------
bool CntrServConta::criarConta(Conta conta){
    CPF cpf;
    cpf = conta.getCPF;
    ComandoExisteConta existeConta(cpf.getValor());
    try{
        existeConta.executar();
    }catch(EErroPersistencia exp){
        //logica de erro
    }
    if(existeConta.getResultado()){
        return false;
    }
    ComandoCreateConta createConta(conta);

    try{
        createConta.executar();
    }catch(EErroPersistencia exp){
        return false;
    }
    return true;
}


Conta CntrServConta::lerConta(CPF cpf) {
    ComandoFindConta pesquisarConta(cpf);
    Conta conta;
    pesquisarConta.executar();
    conta = pesquisarConta.getResultado();
    return conta;
}

bool CntrServConta::excluirConta(CPF cpf){
    ComandoDeleteConta deletarConta(cpf);
    try {
        deletarConta.executar();
    }
    catch(EErroPersistencia exp){
        throw
    }

    //tudo certo
    return true;

}

bool CntrServConta::atualizarConta(Conta conta){
    ComandoUpdateConta updateConta(conta);
    try{
        updateConta.executar();
    }
    catch {
        //erro no
        return false;
    }
    return true;


}


bool CntrServAuth::autenticarConta(CPF cpf, Senha senha) {
 ComandoLerSenhaConta lerSenha(cpf);

 try {
    lerSenha.executar();
 } catch {
  return false;
 }
    if(senha.getSenha() == lerSenha.getResultado()){
        return true;
    }
    return false;
}
bool CntrServInvestimento::criarTitulo(CPF cpf, Titulo titulo){
    ComandoCriarTitulo createTitulo(cpf,titulo);

    try{
        criarTitulo.executar();
    }
    catch(EErroPersistencia exp){
        return false;
    }
    return true;
}

list<Titulo> CntrServInvestimento::lerTitulo(CPF cpf) {
    return 0;

}

bool CntrServInvestimento::atualizarTitulo(codigoDeTitulo codigo) {
    ComandoAtualizarTitulo updateTitulo(codigo);
    try
    {
        updateTitulo.executar()
    }
    catch(EErroPersistencia exp)
    {
        return false;
    }
    return true;
    

}


bool CntrServInvestimento::excluirTitulo(codigoDeTitulo codigo) {
    ComandoExcluirTitulo deletarTitulo(codigo);
    try
    {
        deletarTitulo.executar();
    }
    catch(EErroPersistencia exp)
    {
        return false;
    }
    return true;
    
}

bool CntrServInvestimento::criarPagamento(codigoDeTitulo codigo, Pagamento pagamento){
    ComandoCriarPagamento createPagamento(codigo, pagamento);

    try{createPagamento.executar()}
    catch(EErroPersistencia exp){
        return false;
    }
    return true;

}


bool CntrServInvestimento::atualizarPagamento(codigoDePagamento codigo) {
    ComandoAtualizarPagamento updatePagamento(codigo);
    try
    {
        updatePagamento.executar()
    }
    catch(EErroPersistencia exp)
    {
        return false;
    }
    return true;
    

}


bool CntrServInvestimento::excluirPagamento(codigoDePagamento codigo) {
    ComandoExcluirPagamento deletarPagamento(codigo);
    try
    {
        deletarPagamento.executar();
    }
    catch(EErroPersistencia exp)
    {
        return false;
    }
    return true;
    
}

list<Pagamento> CntrServInvestimento::lerPagamento(codigoDeTitulo codigo) {
    ComandoFindPagamentosPorTitulo findPagamentosPorTitulo(codigo);
    
    findPagamentosPorTitulo.executar();
    return findPagamentosPorTitulo.getResultado();
}
