void codigoDeTitulo::setCodigo(string codigoDeTitulo){
    validar(codigoDeTitulo);
    this->codigoDeTitulo=codigoDeTitulo;
};

void codigoDeTitulo::validar(string codigoDeTitulo){
    identificador.assign(codigoDeTitulo,0,3);
    if (codigoDeTitulo.length()!=11)
        throw invalid_argument("Codigo de Titulo Invalido.");
    if (identificador!="CDB" && identificador!="CRA" && identificador!="CRI" && identificador!="LCA" && identificador!="LCI" && identificador!="DEB" )
        throw invalid_argument("Codigo de Titulo Invalido.");
    else
        for (int i=3;i<11;i++){
            if (!(isdigit(codigoDeTitulo[i])) && !(isupper(codigoDeTitulo[i])))
                throw invalid_argument("Codigo de Titulo Invalido.");
        };
};

string codigoDeTitulo::getCodigo(){
    return codigoDeTitulo;
};


void Percentual::setValor(int valor){
    validar(valor);
    this->valor=valor;
};
void Percentual::validar(int valor){
    if (valor < 0 || valor > 100)
        throw invalid_argument("Percentual Invalido.");
};
int Percentual::getValor(){
    return valor;
};
