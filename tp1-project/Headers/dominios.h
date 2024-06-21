using namespace std;

class codigoDePagamento{
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

//CPF
class CPF{
private:
    string CPF;
public:
    void setCpf(string);
    void validar(string);
    string getCpf();
};

class Data {
private:
    int dia;
    int mes;
    int ano;
public:
    Data(int dia, int mes, int ano);
    int getDia() const;
    int getMes() const;
    int getAno() const;
    void setDia(int dia);
    void setMes(int mes);
    void setAno(int ano);
    void imprimirData() const;
private:
    bool validarData() const;
};

class Dinheiro{
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

class Nome {
private:
    string primeiroTermo;
    string segundoTermo;
    bool validarTermo(const string& termo) const;

public:
    Nome(const string& nomeCompleto);
    string getPrimeiroTermo() const;
    string getSegundoTermo() const;
    void setPrimeiroTermo(const string& primeiroTermo);
    void setSegundoTermo(const string& segundoTermo);
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
class Senha{
private:
    string senha;
public:
    void validar(string);
    void set(string);
    string get();

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
