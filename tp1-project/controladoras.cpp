using namespace std;

void CntrAprConta::criarConta{

    //Instâncias de classes domínios
    Nome nome;
    CPF cpf;
    Senha senha;

    //Variável temporária para inserção de dados
    string temp;
    bool resultado;

    //Loop para inserção e definição dos dados

    while (true){
        try{
            cout << " Informar Nome:" << endl;
            cin >> temp;
            nome.setNome(temp);
            cout << " Informar CPF:" <<endl;
            cin >> temp;
            cpf.setCPF(temp);
            cout << " Informar Senha:"<<endl;
            cin >> temp;
            senha.setSenha(temp);
            break;
        }
        catch (invalid_argument &e) {
            cout << "Dado Inválido."
            return;
        }
    }

    //Instanciar classe de entidade

    Conta conta;
    conta.setCPF(cpf);
    conta.setNome(nome);
    conta.setSenha(senha);

    //Registrar no banco de dados e verificar lógica de negócio (Á fazer)

    resultado=CntrServConta::criarConta(conta);
    if !resultado
        return;

};
