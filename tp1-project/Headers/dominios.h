class codigoDePagamento{
private:

public:

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
    string CPF
    int validchar
public:
    void setCPF(string);
    void validarCPF(string);
    string getCPF();
};

class Data{
private:
    int dia;
    int mes;
    int ano;

public:
    Data(int dia, int mes, int ano);
    int getDia() const;
    int getMes() const;
    int getAno() const;
    void imprimirData() const;

};

class Dinheiro{
private:

public:

};

class Estado{
private:
    std::string estado;
    void validarEstado(const std::string& estado) const;
public:
    Estado(const std::string& novoEstado);
    std::string getEstado() const;
    void setEstado(const std::string& novoEstado);
};

class Nome{
private:
    std::string primeiroTermo;
    std::string segundoTermo;
    bool validarTermo(const std::string& termo) const;

public:
    Nome(const std::string& nomeCompleto);
    std::string getPrimeiroTermo() const;
    std::string getSegundoTermo() const;
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

public:

};

class Setor{
private:
    std::string nome;
    void validarNome(const std::string& nome) const;
public:
    Setor(const std::string& novoNome);
    std::string getNome() const;
    void setNome(const std::string& novoNome);
};
