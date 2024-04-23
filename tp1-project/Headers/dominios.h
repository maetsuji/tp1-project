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

public:

};

class Data{
private:

public:

};

class Dinheiro{
private:

public:

};

class Estado{
private:

public:

};

class Nome{
private:

public:

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

public:

};
