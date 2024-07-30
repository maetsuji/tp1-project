#include <iostream>
#include <string>
#include "dominios.h"
#include "entidades.h"


using namespace std;

int main(){
    //INCLUIR EM ENTIDADES AS CHAVES ESTRANGEIRAS (CPF->PAGAMENTO e CODIGODEPAGAMENTO->TITULO)
        página 1 (TELA DE LOGIN): "---- 80%"
                "0.Criar conta -------- 80% ----- Serviço"
                "1.Autenticar  -------- 80% ----- Serviço"
                "2.Sair."
        pagina 2 (MEU PAINEL):
                "1.Dados de Conta-Conta::EXECUTAR() ------ 60% ----- Serviço "
                "2.Investimentos"
                "3.Voltar"
        pagina 3 (Dados de Conta-Conta::EXECUTAR())
                "1.Alterar ------- 70% ------- Serviço"
                "2.Ler ----------- 80% ------- Serviço"
                "3.Excluir ------- 00% ------- Serviço"
                "4.Voltar"
        pagina 4 (Investimetnos) "Não Iniciado" ---- Devemos usar algum padrão?
                "1.Pagamentos"
                "2.Titulos"
                "3.Voltar"
        pagina 4.1 (Pagamentos)  "Não Iniciado" ---- Devemos usar algum padrão?
                "0.Criar"
                "1.Alterar"
                "2.Ler"
                "3.Excluir"
                "4.Voltar"
        pagina 4.2 (Titulos)     "Não Iniciado" ---- Devemos usar algum padrão?
                "0.Criar"
                "1.Alterar"
                "2.Ler"
                "3.Excluir"
                "4.Voltar"
}
