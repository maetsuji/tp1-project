using namespace std;

class TUCodigoDeTitulo {
private:
    const string VALOR_VALIDO   = "CRA1913576A";   // Definição de constante para evitar número mágico.
    const string VALOR_INVALIDO = "GWM12345678";   // Definição de constante para evitar número mágico.
    codigoDeTitulo *CodigoDeTitulo;                         // Referência para unidade em teste.
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

class TUPercentual {
private:
    const static int VALOR_VALIDO   = 97;   // Definição de constante para evitar número mágico.
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


