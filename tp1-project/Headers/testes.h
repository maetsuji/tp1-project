#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

using namespace std;

//TESTES DE DOMÍNIO

class TUCodigoDePagamento {                     //IMPLEMENTADA POR 231019003
private:
    const string VALOR_VALIDO = "901765432";    // Definição de constante para evitar valores mágicos.
    const string VALOR_INVALIDO = "098887777";  // Definição de constante para evitar valores mágicos.
    codigoDePagamento * codigo;                 // Referência para unidade em teste.
    int estado;                                 // Estado do teste.
    void setUp();                               // Método para criar unidade em teste.
    void tearDown();                            // Método para destruir unidade em teste.
    void testarCenarioSucesso();                // Cenário de teste.
    void testarCenarioFalha();                  // Cenário de teste.

public:
    const static int SUCESSO = 0;               // Definição de constante para reportar resultado de teste.
    const static int FALHA = -1;                // Definição de constante para reportar resultado de teste.
    int run();                                  // Método para executar teste.

};

class TUSenha {                                 // IMPLEMENTADA POR 231019003
private:
    const string VALOR_VALIDO = "290805";
    const string VALOR_INVALIDO = "123456";
    Senha * senha;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();

};

class TUCodigoDeTitulo {                        //IMPLEMENTADA POR 231028746
private:
    const string VALOR_VALIDO   = "CRA1913576A";
    const string VALOR_INVALIDO = "GWM12345678";
    codigoDeTitulo *codigo;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};

class TUCPF {                                   // Implementada por 232009502
private:
    const string VALOR_VALIDO    = "761.776.634-35";
    const string VALOR_INVALIDO  = "099.000.999-88";
    CPF *cpf;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};

class TUDinheiro {                              // Implementada por 232009502
private:
    const float VALOR_VALIDO    = 7343.57;
    const float VALOR_INVALIDO  = 4000999.69;
    Dinheiro *valor;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();
public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};

class TUData {                                  //Implementada por 180077911
private:
    const string VALOR_VALIDO   = "29-02-2020";
    const string VALOR_INVALIDO = "31-02-2021";
    Data *data;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();

};

class TUEstado {                     //IMPLEMENTADA POR 231021360
private:
    const string VALOR_VALIDO    = "Previsto";
    const string VALOR_INVALIDO  = "Imprevisto";
    Estado *estado_obj;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};

class TUNome {                                  //Implementada por 180077911
private:
    const string NOME_VALIDO  = "João Silva";
    const string NOME_INVALIDO = "123456";
    Nome *nome;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};

class TUPercentual {                           //IMPLEMENTADA POR 231028746
private:
    const int VALOR_VALIDO   = 97;
    const int VALOR_INVALIDO = 107;
    Percentual *percentual;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};

class TUSetor {                     //IMPLEMENTADA POR 231021360
private:
    const string VALOR_VALIDO    = "Agricultura";
    const string VALOR_INVALIDO  = "Agronomia";
    Setor *setor;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
    void testarCenarioFalha();

public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};

//TESTES DE ENTIDADE

class TUConta{                                 //IMPLEMENTADA POR 231028746
private:
    const string CPF_VALIDO="063.179.831-51";  // Definição de constante para evitar número mágico.
    const string NOME_VALIDO="Caio Rafik";     // Definição de constante para evitar número mágico.
    const string SENHA_VALIDA="163179";        // Definição de constante para evitar número mágico.
    Conta *conta;                              // Referência para unidade em teste.
    int estado;                                // Estado do teste.
    void setUp();                              // Método para criar unidade em teste.
    void tearDown();                           // Método para destruir unidade em teste.
    void testarCenarioSucesso();
public:
    const static int SUCESSO =  0;             // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;             // Definição de constante para reportar resultado de teste.
    int run();                                 // Método para executar teste.
};

class TUTitulo {
private:
    const string CODIGO_VALIDO = "CDB12345678";
    const string NOME_VALIDO = "Caio Rafik";
    const string SETOR_VALIDO = "Agricultura";
    const string DATA_VALIDA = "01-01-2023";
    const double VALOR_VALIDO = 1000.00;
    Titulo *titulo;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int run();
};

class TUPagamento{                              //IMPLEMENTADA POR 231028746
private:
    const string CODIGO_VALIDO="789456123";
    const string DATA_VALIDA = "01-01-2023";
    const int PERCENTUAL_VALIDO=92;
    const string ESTADO_VALIDO="Previsto";
    Pagamento *pagamento;
    int estado;
    void setUp();
    void tearDown();
    void testarCenarioSucesso();
public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};

#endif // TESTES_H_INCLUDED
