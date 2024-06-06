#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Respostas {
    string ondeNosConhecemos;
    string animeFavorito;
    string tempoJuntos;
    string apelidoCarinhoso;
    string comoGostoDeFicar;
};

void printBorderedText(const string& text) {
    int length = text.length();
    string border(length + 4, '*');

    cout << border << endl;
    cout << "* " << text << " *" << endl;
    cout << border << endl;
}

void exibirMensagemDeAmor(const Respostas& respostas) {
    system("cls"); // Limpa a tela (funciona no Windows)
    printBorderedText("Mensagem de Amor");
    cout << "\nObrigado por responder ao quiz! Aqui estão suas respostas:\n" << endl;
    cout << "1. Onde nos conhecemos? " << respostas.ondeNosConhecemos << endl;
    cout << "2. Qual meu anime favorito? " << respostas.animeFavorito << endl;
    cout << "3. Quanto tempo estamos juntos? " << respostas.tempoJuntos << endl;
    cout << "4. Qual é o seu apelido carinhoso para mim? " << respostas.apelidoCarinhoso << endl;
    cout << "5. Como eu gosto de ficar com você? " << respostas.comoGostoDeFicar << endl;
    cout << "\nEu te amo muito amor da minha vida💜!\n" << endl;
    cout << "\nMuito, muito, muito mesmo!\n" << endl;
    cout << "Pressione qualquer tecla para sair..." << endl;
    cin.ignore();
    cin.get();
}

void salvarRespostasEmArquivo(const Respostas& respostas) {
    ofstream arquivo("respostas.txt");
    if (arquivo.is_open()) {
        arquivo << "1. Onde nos conhecemos? " << respostas.ondeNosConhecemos << endl;
        arquivo << "2. Qual meu anime favorito? " << respostas.animeFavorito << endl;
        arquivo << "3. Quanto tempo estamos juntos? " << respostas.tempoJuntos << endl;
        arquivo << "4. Qual é o seu apelido carinhoso para mim? " << respostas.apelidoCarinhoso << endl;
        arquivo << "5. Como eu gosto de ficar com você? " << respostas.comoGostoDeFicar << endl;
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo para salvar as respostas." << endl;
    }
}

int main() {
    Respostas respostas;
    
    cout << "Bem-vindo ao Quiz de Relacionamento!" << endl;
    cout << "Por favor, responda às seguintes perguntas:" << endl;

    cout << "1. Onde nos conhecemos? ";
    getline(cin, respostas.ondeNosConhecemos);

    cout << "2. Qual meu anime favorito? ";
    getline(cin, respostas.animeFavorito);

    cout << "3. Quanto tempo estamos juntos? ";
    getline(cin, respostas.tempoJuntos);

    cout << "4. Qual apelido carinhoso eu mais gosto? ";
    getline(cin, respostas.apelidoCarinhoso);

    cout << "5. Como eu gosto de ficar com você? ";
    getline(cin, respostas.comoGostoDeFicar);

    salvarRespostasEmArquivo(respostas);
    exibirMensagemDeAmor(respostas);

    return 0;
}
