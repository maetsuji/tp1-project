using namespace std;


//Codigo de Pagamento

/**
* Padr&atilde;o para representa&ccedil;&atilde;o de c&oacute;digo de pagamento.
*
* Regras de formato:
*
* - C&oacute;digo de pagamento &eacute; v&aacute;lido se possui exatamente 9 caracteres sendo d&iacute;gitos num&eacute;ricos de 0 a 9.
* - O primeiro d&iacute;gito &eacute; diferente de '0'.
*/
class codigoDePagamento{            //IMPLEMENTADA POR 231019003
private:
    string codigoDePagamento;

public:
    void validar(string);
    void setCodigo(string);
    string getCodigo();
};
//Codigo de titulo

/**
* Padr&atilde;o para representa&ccedil;&atilde;o de c&oacute;digo de t&iacute;tulo.
*
* Regras de formato:
*
* - C&oacute;digo de t&iacute;tulo &eacute; v&aacute;lido se possui 11 caracteres alfanum&eacute;ricos, com as letras sendo mai&uacute;sculas.
* - O identificador de cada t&iacute;tulo (3 primeiras letras) deve pertencer a uma lista de identificadores v&aacute;lidos.
*/

class codigoDeTitulo{                   //IMPLEMENTADA POR 231028746
private:
    string codigoDeTitulo;
    string identificador;
public:
    void setCodigo(string);
    void validar(string);
    string getCodigo();
};

/**
* Padr&atilde;o para representa&ccedil;&atilde;o de CPF.
*
* Regras de formato:
*
* - CPF &eacute; v&aacute;lido se for uma string no formato "XXX.XXX.XXX-CC"
* - Os algarismos do CPF não podem ser todos iguais (CPFs notavelmente inv&aacute;lidos)
* - O CPF deve passar na valida&ccedil;&atilde;o dos dois d&iacute;gitos (conforme determinado pelo Minist&eacute;rio da Fazenda)
*/

class CPF{                     // Implementada por 232009502
private:
    string CPF;
public:
    void setCPF(string);
    void validar(string);
    string getCPF();
};

class Data {                   //IMPLEMENTADA POR 180077911
private:
    string data;
public:
    void setData(string);
    void validar(string);
    string getData();
}

/**
* Padr&atilde;o para representa&ccedil;&atilde;o do Dinheiro
*
* Regras de formato:
*
* - O valor deve ser um float maior-igual a zero e menor-igual a 1000000
*/


class Dinheiro{                 // Implementada por 232009502
private:
    float valor;
public:
    void setValor(float);
    void validar(float);
    float getValor();
};

//Estado

/**
* Padr&atilde;o para representa&ccedil;&atilde;o de Estado.
*
* Regras de formato:
*
* - Estado &eacute; v&aacute;lido se for "Previsto", "Liquidado" ou "Inadimplente".
*/

class Estado{                        //IMPLEMENTADA POR 231021360
private:
    string estado;
public:
    string getEstado();
    void validar(string);
    void setEstado(string);
};

class Nome {                        //IMPLEMENTADA POR 180077911
private:
    string nome;
public:
    void setNome(string);
    void validar(string);
    string getNome();
};


//Percentual

/**
* Padr&atilde;o para representa&ccedil;&atilde;o de Percentual.
*
* Regras de formato:
*
* - Percentual &eacute; v&aacute;lido se maior ou igual a 0 e menor ou igual a 100.
*/

class Percentual                        //IMPLEMENTADA POR 231028746
{
private:
    int valor;
public:
    void setValor(int);
    void validar(int);
    int getValor();
};


//Senha

/**
* Padr&atilde;o para representa&ccedil;&atilde;o de senha.
*
* Regras de formato:
*
* - Senha &eacute; v&aacute;lida se possui exatamente 6 caracteres sendo d&iacute;gitos num&eacute;ricos de 0 a 9 sem repeti&ccedil;&atilde;o de d&iacute;gitos.
* - O primeiro d&iacute;gito &eacute; diferente de '0'.
* - Sequ&ecirc;ncia de caracteres n&atilde;o pode ser sequ&ecirc;ncia de d&iacute;gitos em ordem crescente ou decrescente.
*/


class Senha{                //IMPLEMENTADA POR 231019003
private:
    string senha;
public:
    void validar(string);
    void setSenha(string);
    string getSenha();

};

//Setor

/**
* Padr&atilde;o para representa&ccedil;&atilde;o de Setor.
*
* Regras de formato:
*
* - Setor &eacute; v&aacute;lido se pertence a uma lista de setores v&aacute;lidos.
*/

class Setor{                        //IMPLEMENTADA POR 231021360
private:
    string setor;
public:
    string getSetor();
    void validar(string);
    void setSetor(string);
};
