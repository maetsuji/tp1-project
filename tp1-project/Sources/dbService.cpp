#include "dbService.h"

list<ElementoResultado> ComandoSQL::listaResultado;

//---------------------------------------------------------

EErroPersistencia::EErroPersistencia(string mensagem){
    this->what= mensagem;
}

string EErroPersistencia::what(){
    return mensagem;
    }

//Implementação de métodos ElementoResultado

void ElementoResultado::setNomeColuna(const string& nomeColuna ) {
    this->nomeColuna = nomeColuna;
}

void ElementoResultado::setValorColuna(const string& valorColuna) {
    this->valorColuna = valorColuna;
}


//Implementação de métodos ComandoSQL
void ComandoSQL::conectar() {
      rc = sqlite3_open(nomeBancoDados, &bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na conexao ao banco de dados");
}

void ComandoSQL::desconectar() {
      rc =  sqlite3_close(bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na desconexao ao banco de dados");
}

void ComandoSQL::executar() {
        conectar();
        rc = sqlite3_exec(bd, comandoSQL.c_str(), callback, 0, &mensagem);
        if(rc != SQLITE_OK){
                sqlite3_free(mensagem);
                desconectar();
                throw EErroPersistencia("Erro na execucao do comando SQL");
        }
        desconectar();
}

int ComandoSQL::callback(void *NotUsed, int argc, char **valorColuna, char **nomeColuna){
      NotUsed=0;
      ElementoResultado elemento;
      int i;
      for(i=0; i<argc; i++){
        elemento.setNomeColuna(nomeColuna[i]);
        elemento.setValorColuna(valorColuna[i] ? valorColuna[i]: "NULL");
        listaResultado.push_front(elemento);
      }
      return 0;
}


//Implementação de métodos relativos a Conta -------------------------------------------

//CREATE================================================================
ComandoCreateConta::ComandoCreateConta(Conta conta) {
    comandoSQL = "INSERT INTO Conta VALUE (";
    comandoSQL += "'" + conta.getCPF().getValor() + "', ";
    comandoSQL += "'" + conta.getNome().getValor() + "', ";
    comandoSQL += "'" + conta.getSenha().getValor() + "')";
}

//FIND CONTA============================================================
ComandoFindConta::ComandoFindConta(CPF cpf){
    comandoSQL = "SELECT * FROM Conta WHERE CPF = ";
    comandoSQL += cpf.getValor();
}

Conta ComandoFindConta::getResultado() {
    ElementoResultado resultado;
    Conta conta;

    // Remover nome;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        conta.setNome(Nome(resultado.getValorColuna()));

        // Remover cpf;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        conta.setCPF(CPF(resultado.getValorColuna()));

        // Remover senha;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        conta.setSenha(Senha(resultado.getValorColuna()));

        return conta;
}

//FIND SENHA=============================================================
ComandoFindSenhaConta::ComandoFindSenhaConta(CPF cpf){
    comandoSQL = "SELECT Senha FROM Conta WHERE CPF = ";
    comandoSQL += cpf.getValor();
}
string ComandoFindSenhaConta::getResultado() {
    ElementoResultado resultado;
    string senha;
    if(listaResultado.empty()){
        throw EErroPersistencia("Lista de resultados vazia.");
    }
    resultado = listaResultado.back();
    listaResultado.pop_back();

    senha = resultado.getValorColuna();
    return senha;
}
//UPDATE====================================================
ComandoUpdateConta::ComandoUpdateConta(Conta conta) {
    comandoSQL = "UPDATE Conta ";
    comandoSQL += "SET Nome = '" + conta.getNome().getValor();
    comandoSQL += "', Senha = '" + conta.getSenha().getValor();
    comandoSQL += "' WHERE CPF = " + conta.getCPF().getValor();
}

//DELETE====================================================
ComandoDeleteConta::ComandoDeleteConta(CPF cpf) {
    comandoSQL = "DELETE FROM Conta WHERE CPF = ";
    comandoSQL += cpf.getValor();
}

//EXISTE====================================================
ComandoExisteConta::ComandoExisteConta(CPF cpf){
    comandoSQL = "SELECT * FROM Conta WHERE CPF = ";
    comandoSQL += cpf.getValor();
}

bool ComandoExisteConta::getResultado() {
    if(listaResultado.empty()){
        return false;
    }
    else{
        return true;
    }
}
//Implementação de métodos relativos a Titulo-----------------------------------------------------------

//CREATE=======================================================
ComandoCreateTitulo::ComandoCreateTitulo(Titulo titulo){
    comandoSQL = "INSERT INTO Titulo VALUE (";
    comandoSQL += "'" + titulo.getCodigo().getValor() + "', ";
    comandoSQL += "'" + titulo.getConta().getValor() + "', ";
    comandoSQL += "'" + titulo.getEmissor().getValor() + "', ";
    comandoSQL += "'" + titulo.getSetor().getValor() + "', ";
    comandoSQL += "'" + titulo.getEmissao().getValor() + "', ";
    comandoSQL += "'" + titulo.getVencimento().getValor() + "', ";
    comandoSQL += "'" + titulo.getDinheiro().getValor() + "')";
}
//FIND TITULO============================================================
ComandoFindTitulo::ComandoFindTitulo(codigoDeTitulo codigo){
    comandoSQL = "SELECT * FROM Titulo WHERE CodigoTitulo = ";
    comandoSQL += codigo.getValor();
}

Conta ComandoFindTitulo::getResultado() {
    ElementoResultado resultado;
    Titulo titulo;

    // Remover nome;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        titulo.setCodigo(Codigo(resultado.getValorColuna()));

        // Remover cpf;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        conta.setCPF(CPF(resultado.getValorColuna()));

        // Remover senha;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        conta.setSenha(Senha(resultado.getValorColuna()));

        return conta;
}
//UPDATE====================================================
ComandoUpdateTitulo::ComandoUpdateTitulo(Titulo titulo) {
    comandoSQL = "UPDATE Titulo ";
    comandoSQL += "SET Emissor = '" + conta.getNome().getValor();
    comandoSQL += "', Setor = '" + conta.getSenha().getValor();
    comandoSQL += "', Emissao = '" + conta.getSenha().getValor
    comandoSQL += "', Vencimento = '" + conta.getSenha().getValor();
    comandoSQL += "', Dinheiro = '" + conta.getSenha().getValor();
    comandoSQL += "' WHERE CodigoTitulo = " + conta.getCPF().getValor();
}

//DELETE====================================================
ComandoDeleteTitulo::ComandoDeleteTitulo(codigoDeTitulo codigo) {
    comandoSQL = "DELETE FROM Titulo WHERE CodigoTitulo = ";
    comandoSQL += codigo.getValor();
}

//Implementação de métodos relativos a Pagamento-----------------------------------------------------------

//CREATE=======================================================
ComandoCreatePagamento::ComandoCreatePagamento(Pagamento pagamento){
    comandoSQL = "INSERT INTO Titulo VALUE (";
    comandoSQL += "'" + titulo.getCodigo().getValor() + "', ";
    comandoSQL += "'" + titulo.getConta().getValor() + "', ";
    comandoSQL += "'" + titulo.getEmissor().getValor() + "', ";
    comandoSQL += "'" + titulo.getSetor().getValor() + "', ";
    comandoSQL += "'" + titulo.getEmissao().getValor() + "', ";
    comandoSQL += "'" + titulo.getVencimento().getValor() + "', ";
    comandoSQL += "'" + titulo.getDinheiro().getValor() + "')";
}

//FIND============================================================
ComandoFindPagamento::ComandoFindPagamento(codigoDePagamento codigo){
    comandoSQL = "SELECT * FROM Pagamento WHERE CodigoPagamento = ";
    comandoSQL += codigo.getValor();
}

Conta ComandoFindPagamento::getResultado() {
    ElementoResultado resultado;
    Pagamento pagamento;

    // Remover nome;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        titulo.setCodigo(Codigo(resultado.getValorColuna()));

        // Remover cpf;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        conta.setCPF(CPF(resultado.getValorColuna()));

        // Remover senha;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        conta.setSenha(Senha(resultado.getValorColuna()));

        return conta;
}
//UPDATE====================================================
ComandoUpdatePagamento::ComandoUpdatePagamento(Pagamento pagamento) {
    comandoSQL = "UPDATE Pagamento ";
    comandoSQL += "SET Data = '" + conta.getNome().getValor();
    comandoSQL += "', Percentual = '" + conta.getSenha().getValor();
    comandoSQL += "', Estado = '" + conta.getSenha().getValor;
    comandoSQL += "' WHERE CodigoPagamento = " + conta.getCPF().getValor();
}

//DELETE====================================================
ComandoDeletePagamento::ComandoDeletePagamento (codigoDePagamento codigo) {
    comandoSQL = "DELETE FROM Pagamento WHERE CodigoPagamento = ";
    comandoSQL += codigo.getValor();
}
