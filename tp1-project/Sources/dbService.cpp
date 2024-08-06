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

//CRIAR================================================================
ComandoCriarConta::ComandoCriarConta(Conta conta) {
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
//ATUALIZAR====================================================
ComandoAtualizarConta::ComandoAtualizarConta(Conta conta) {
    comandoSQL = "UPDATE Conta ";
    comandoSQL += "SET Nome = '" + conta.getNome().getNome();
    comandoSQL += "', Senha = '" + conta.getSenha().getSenha();
    comandoSQL += "' WHERE CPF = " + conta.getCPF().getCPF();
}

//EXCLUIR====================================================
ComandoExcluirConta::ComandoExcluirConta(CPF cpf) {
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

//CRIAR=======================================================
ComandoCriarTitulo::ComandoCriarTitulo(CPF cpf,Titulo titulo){
    comandoSQL = "INSERT INTO Titulo VALUE (";
    comandoSQL += "'" + titulo.getCodigo().getCodigo() + "', ";
    comandoSQL += "'" + cpf.getCPF() + "', ";
    comandoSQL += "'" + titulo.getEmissor().getNome() + "', ";
    comandoSQL += "'" + titulo.getSetor().getSetor() + "', ";
    comandoSQL += "'" + titulo.getEmissao().getData() + "', ";
    comandoSQL += "'" + titulo.getVencimento().getData() + "', ";
    comandoSQL += "'" + titulo.getDinheiro().getValor() + "')";
}
//FIND TITULO============================================================
ComandoFindTitulo::ComandoFindTitulo(codigoDeTitulo codigo){
    comandoSQL = "SELECT * FROM Titulo WHERE CodigoTitulo = ";
    comandoSQL += codigo.getValor();
}

Titulo ComandoFindTitulo::getResultado() {
    ElementoResultado resultado;
    Titulo titulo;
    CodigoDeTitulo codigodetitulo;
    Nome emissor;
    Setor setor;
    Data emissao;
    Data vencimento;
    Dinheiro valor;

    // Remover Codigo;
    if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    codigodetitulo.setCodigo(resultado.getValorColuna());
    titulo.setCodigo(codigodetitulo);

    // Remover emissor;
    if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    emissor.setNome(resultado.getValorColuna());
    titulo.setEmissor(emissor);
    
    // Remover setor;
    if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    setor.setSetor(resultado.getValorColuna());
    titulo.setSetor(setor);
    
    // Remover Emissao;
    if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    emissao.setData(resultado.getValorColuna());
    titulo.setEmissao(emissao);
    
    // Remover Vencimento;
    if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    vencimento.setData(resultado.getValorColuna());
    titulo.setVencimento(vencimento);

    // Remover Valor;
    if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    valor.setValor(resultado.getValorColuna());
    titulo.setValor(vencimento);
    
    return titulo;
}
//ATUALIZAR====================================================
ComandoAtualizarTitulo::ComandoAtualizarTitulo(Titulo titulo) {
    comandoSQL = "UPDATE Titulo ";
    comandoSQL += "SET Emissor = '" + titulo.getEmissor().getNome();
    comandoSQL += "', Setor = '" + titulo.getSetor().getSetor();
    comandoSQL += "', Emissao = '" + titulo.getEmissao().getData();
    comandoSQL += "', Vencimento = '" + titulo.getVencimento().getData();
    comandoSQL += "', Dinheiro = '" + titulo.getDinheiro().getValor();
    comandoSQL += "' WHERE CodigoTitulo = " + titulo.getCodigo().getCodigo();
}

//EXCLUIR====================================================
ComandoExcluirTitulo::ComandoExcluirTitulo(codigoDeTitulo codigo) {
    comandoSQL = "DELETE FROM Titulo WHERE CodigoTitulo = ";
    comandoSQL += codigo.getCodigo();
}

//Implementação de métodos relativos a Pagamento-----------------------------------------------------------

//CRIAR=======================================================
ComandoCriarPagamento::ComandoCriarPagamento(CodigoDeTitulo codigodetitulo, Pagamento pagamento){
    comandoSQL = "INSERT INTO Titulo VALUE (";
    comandoSQL += "'" + pagamento.getCodigo().getCodigo() + "', ";
    comandoSQL += "'" + codigodetitulo.getCodigo() + "', ";
    comandoSQL += "'" + pagamento.getData().getData() + "', ";
    comandoSQL += "'" + pagamento.getPercentual().getPercentual() + "', ";
    comandoSQL += "'" + pagamento.getEstado().getEstado() + "', ";
}

//FIND============================================================NÃO PRONTA, FALAR COM O CAUÊ
ComandoFindPagamento::ComandoFindPagamento(codigoDePagamento codigo){
    comandoSQL = "SELECT * FROM Pagamento WHERE CodigoPagamento = ";
    comandoSQL += codigo.getCodigo();
}

Pagamento ComandoFindPagamento::getResultado() {
    ElementoResultado resultado;
    Pagamento pagamento;
    CodigoDePagamento codigodepagamento;
    Data data;
    Percentual percentual;
    Estado estado;

    // Remover Código;
    if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    codigodepagamento.setCodigo(resultado.getValorColuna());
    pagamento.setCodigo(codigodepagamento);
   
    // Remover Data;
    if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    data.setData(resultado.getValorColuna());
    pagamento.setData(data);
    
    // Remover Percentual;
    if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    percentual.setValor(resultado.getValorColuna());
    pagamento.setPercentual(percentual);
    
    // Remover Estado;
    if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
    resultado = listaResultado.back();
    listaResultado.pop_back();
    estado.setEstado(resultado.getValorColuna());
    pagamento.setEstado(estado);

    return pagamento;
}

//ATUALIZAR====================================================
ComandoAtualizarPagamento::ComandoAtualizarPagamento(Pagamento pagamento) {
    comandoSQL = "UPDATE Pagamento ";
    comandoSQL += "SET Data = '" + pagamento.getData().getData();
    comandoSQL += "', Percentual = '" + pagamento.getPercentual().getPercentual();
    comandoSQL += "', Estado = '" + pagamento.getEstado().getEstado();
    comandoSQL += "' WHERE CodigoPagamento = " + pagamento.getCodigo().getCodigo();
}

//EXCLUIR====================================================
ComandoExcluirPagamento::ComandoExcluirPagamento (codigoDePagamento codigo) {
    comandoSQL = "DELETE FROM Pagamento WHERE CodigoPagamento = ";
    comandoSQL += codigo.getCodigo();
}
