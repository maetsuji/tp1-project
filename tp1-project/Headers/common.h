// Definindo a macro CLR_SCR para limpar a tela
#ifdef _WIN32
    #include <cstdlib> // Para a função system()

    #define CLR_SCR() system("cls")
#else
    #include <cstdlib> // Para a função system()

    #define CLR_SCR() system("clear")
#endif
