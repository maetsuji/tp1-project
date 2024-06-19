using namespace std;

class codigoDePagamento{
private:
    string codigoDePagamento;

public:
    void validar(string);
    void setCodigo(string);
    string getCodigo();
};

class codigoDeTitulo{
private:
    string codigoDeTitulo;
    string identificador;
public:
    void setCodigo(string);
    void validar(string);
    string getCodigo();
};

class CPF{
private:
    string CPF;
public:
    void set(string);
    void validar(string);
    string get();
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
    void set(float);
    void validar(float);
    float get();
};

class Estado{
private:
    string estado;
    void validarEstado(const string& estado) const;
public:
    Estado(const string& novoEstado);
    string getEstado() const;
    void setEstado(const string& novoEstado);
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

class Percentual{
private:
    int valor;
    static const int valorMinimo = 0;
    static const int valorMaximo = 100;
public:
    void setValor(int);
    void validar(int);
    int getValor();
};

class Senha{
private:
    string senha;
public:
    void validar(string);
    void set(string);
    string get();

};

class Setor{
private:
    string nome;
    void validarNome(const string& nome) const;
public:
    Setor(const string& novoNome);
    string getNome() const;
    void setNome(const string& novoNome);
};
