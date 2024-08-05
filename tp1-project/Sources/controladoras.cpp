#include "common.h"
using namespace std;

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Conta

void CntrAprConta::criarConta{

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
    if(cntrServConta->cadastrar(conta))
        //IMPLEMENTAR
        CLR_SCR;
        cout << "Cadastro realizado com sucesso. Digite algo.";
        getch();
        return;
    else
        //IMPLEMENTAR
        CLR_SCR;
        cout << "Falha no cadastro. Retornando para tela inicial. Digite algo."
        getch();
        return;
}

void CntrAprConta::executar(CPF *cpf){
    bool apresentar = true;

    while (apresentar){
        CLR_SCR;
        cout << "Selecione uma opção :" << endl;
        cout << "1. Alterar dados cadastrais." << endl;
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
}

void CntrAprConta::lerConta(CPF cpf){
    //IDENTIFICAR NO BANCO DE DADOS A INSTANCIA DE CONTA
    //IMPLEMENTAR
    nome=CntrServConta::getNome()
    cpf=CntrServConta::getCPF()
    senha=CntrServConta::getSenha()
    CLR_SCR;
    cout << "O Nome cadastrado é: " << nome.getNome() << endl;
    cout << "O CPF cadastrado é: " << cpf.getCPF() << endl;
    cout << "A Senha cadastrada é: " << senha.getSenha() << endl;
    cout << "Digite algo para retornar.";
    getch();
    return;
}

void CntrAprConta::atualizarConta(CPF *cpf){
    //IDENTIFICAR NO BANCO DE DADOS A INSTANCIA DE CONTA
    string tempNome;
    Nome nome;
    string tempSenha;
    Senha senha;
    try{
        CLR_SCR;
        cout << "Digite um novo Nome: " << " ";
        cin >> tempNome;
        nome.setNome(tempNome);
        cout << "Digite uma nova Senha: " << " ";
        cin >> tempSenha;
        senha.setSenha(tempSenha);
        //atualizar no banco de dados
        cout << "Dados atualizados com sucesso. Digite algo."
        getch();
        return;
    }
    catch(invalid_argument &e)
        CLR_SCR;
        cout << "Dado informado no formato inválido. Digite algo."
        getch();
        return;
}

void CntrAprConta::excluirConta(CPF *cpf){
    //IDENTIFICAR NO BANCO DE DADOS A INSTANCIA DE CONTA
    //IMPLEMENTAR
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Auth

int CntrAprAuth::executar(CPF *cpf){
    Senha senha;
    string tempCPF;
    string tempSenha;
    bool resultado;

    while (true){
        try{
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

    resultado=CntrServAuth::autenticar(cpf,senha);
    if !resultado
        return 0;
    return 1;
};

//tentativa de implementação de controladoras serviço. (não testado)
void CntrServConta::create(Conta conta){
    CPF cpf;
    cpf = conta.getCPF;
    ComandoExisteConta existeConta(cpf.getValor());
    try{
        existeConta.executar();
    }catch(EErroPersistencia exp){
        //erro no banco 
    }
    if(existeConta.getResultado()){
        throw EErroPersistencia("Já existe conta associada a esse CPF.");
    }
    ComandoCreateConta createConta(conta);

    try{
        createConta.executar();
    }catch(EErroPersistencia exp){
        //erro no banco
    }
    cout << "Conta no CPF "<<cpf.getValor()<<" criada com sucesso" << endl;
    return;
}

void CntrServConta::findConta(CPF cpf) {
    ComandoFindConta pesquisarConta(cpf);
    Conta conta;
    try {
        pesquisarConta.executar()
    }
    catch{
    //erro no banco
    }
    try {
        conta = pesquisarConta.getResultado();
    }catch(EErroPersistencia exp) {
        //erro doido, nao sei qual
                cout << endl << exp.what();
                cout << endl << endl << "Digite algo para continuar.";
                getch();
        }
    //tudo certo
    return;
}

void CntrServConta::deleteConta(CPF cpf){
    ComandoDeleteConta deletarConta(cpf);
    try {
        deletarConta.executar();
    }
    catch(EErroPersistencia exp){
        //erro no banco
    }

    //tudo certo
    return;

}

void CntrServConta::updateConta(Conta conta){
    ComandoUpdateConta atualizarConta(conta);
    try{
        atualizarConta.executar();
    }
    catch {
        //erro no banco
    }

    //tudo certo
    return;

}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Investimento

class CntrAprInvestimento::executar(CPF *cpf) {

void mostrarMenu() {
    cout << "0. Criar" << endl;
    cout << "1. Altear" << endl;
    cout << "2. Ler" << endl;
    cout << "3. Excluir" << endl;
    cout << "4. Voltar" << endl;
    cout << "Digite sua opção (0-4): ";
}
 
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

 }

//IMPLEMENTAR AS CLASSES DE MANUTENÇÃO NO BANCO DE DADOS 

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
//Instâncias de classes domínios para tabela de TITULO
    CPF cpf;

//Variáveis temporárias para inserções de dados na tabela de TITULO
    string codigo_titulo;   // CHAVE PRIMÁRIA ex.: CDBxxxxxxxx, x letra maiúscula de A-Z ou dígito 1-9
    string nome_emissor;
    string setor;           // Agricultura, construção civil, energia, finanças, imobiliário
                            // papel e celulose, pecuária, química e petroquímica, metalurgia e siderurgia
                            // mineração
    string data_emissao;    // DD-MM-AAAA
    string data_vencimento; // DD-MM-AAAA
    float  valor;

class CntrAprInvestimento::criarTitulo(CPF *cpf) {
    
}
class CntrAprInvestimento::alterarTitulo(CPF *cpf) {
    
}
class CntrAprInvestimento::lerTitulo(CPF *cpf) {
    
}
class CntrAprInvestimento::excluirTitulo(CPF *cpf) {
    
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//Variáveis temporárias para inserções de dados na tabela de PAGAMENTO

string codigo_pagamento;  // CHAVE PRIMÁRIA, formato XXXXXXXX, X é digito 0-9 e primeiro dígito é diferente de zero 1-9
string data_pagamento;    // DD-MM-AAAA
float  percentual;
string estado;            // PREVISTO, LIQUIDADO OU INADIMPLENTE


class CntrAprInvestimento::criarPagamento(CPF *cpf) {
        
}
class CntrAprInvestimento::alterarPagamento(CPF *cpf) {

}
class CntrAprInvestimento::lerPagamento(CPF *cpf) {
    
}
class CntrAprInvestimento::excluirPagamento(CPF *cpf) {
} 
