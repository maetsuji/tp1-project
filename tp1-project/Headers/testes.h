using namespace std;

//TESTES DE DOMÍNIO

class TUCodigoDeTitulo {
private:
    const string VALOR_VALIDO   = "CRA1913576A";   // Definição de constante para evitar número mágico.
    const string VALOR_INVALIDO = "GWM12345678";   // Definição de constante para evitar número mágico.
    codigoDeTitulo *codigo;                         // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};

class TUCPF {
private:
    const static string VALOR_VALIDO    = "761.776.634-35";  // CPF fictício válido
    const static string VALOR_INVALIDO  = "099.000.999-88";  // CPF fictício inválido
    CPF *cpf;                                   // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};

class TUValor {
private:
    const static float VALOR_VALIDO    = 7343.57;  // Valor válido
    const static float VALOR_INVALIDO  = 4000999.69;  // Valor inválido
    Valor *valor;                                   // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.
public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar os testes.
};

class TUData {
private:
    const static int DIA_VALIDO  = 10;   // Definição de constante para evitar valores mágicos.
    const static int MES_VALIDO  = 5;   // Definição de constante para evitar valores mágicos.
    const static int ANO_VALIDO  = 2023;   // Definição de constante para evitar valores mágicos.
    const static int DIA_INVALIDO  = 32;   // Definição de constante para evitar valores mágicos.
    const static int MES_INVALIDO  = 13;   // Definição de constante para evitar valores mágicos.
    const static int ANO_INVALIDO  = 1999;   // Definição de constante para evitar valores mágicos.
    Data *data;                             // Referência para a unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unadade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar os testes.

};

class TUEstado {
private:
    const static string VALOR_VALIDO    = "Previsto";  //Estado fictício válido
    const static string VALOR_INVALIDO  = "Imprevisto";  //Estado fictício inválido
    Estado *estado;                         // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};

class TUNome {
private:
    const static string NOME_VALIDO  = "João Silva";   // Definição de constante para evitar valores mágicos.
    const static string NOME_INVALIDO = "123456"; // Definição de constante para evitar valores mágicos.
    Nome *nome;                             // Referência para a unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unadade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar os testes.

};

class TUPercentual {
private:
    const static int VALOR_VALIDO   = 97;    // Definição de constante para evitar número mágico.
    const static int VALOR_INVALIDO = 107;   // Definição de constante para evitar número mágico.
    Percentual *percentual;                         // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};

class TUSetor {
private:
    const static string VALOR_VALIDO    = "Agricultura";  //Setor fictício válido
    const static string VALOR_INVALIDO  = "Agronomia";  //Setor fictício inválido
    Setor *setor;                           // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();            // Cenário de teste.
    void testarCenarioFalha();              // Cenário de teste.

public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};


//TESTES DE ENTIDADE

class TUConta{
private:
    const int CPF_VALIDO="063.179.831-51";  // Definição de constante para evitar número mágico.
    const string NOME_VALIDO="Caio Rafik";  // Definição de constante para evitar número mágico.
    const int SENHA_VALIDA="063179";        // Definição de constante para evitar número mágico.
    Conta *conta                            // Referência para unidade em teste.
    int estado;                             // Estado do teste.
    void setUp();                           // Método para criar unidade em teste.
    void tearDown();                        // Método para destruir unidade em teste.
    void testarCenarioSucesso();
public:
    const static int SUCESSO =  0;          // Definição de constante para reportar resultado de teste.
    const static int FALHA   = -1;          // Definição de constante para reportar resultado de teste.
    int run();                              // Método para executar teste.
};

