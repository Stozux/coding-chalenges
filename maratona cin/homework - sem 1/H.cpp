// #include <bits/stdc++.h>
// using namespace std;
// #define fIo ios::sync_with_stdio(false); cin.tie(NULL);

// int main()
// {
//     fIo;
//     map<string,string> dict;
//     string k,w;
//     cin >> k >> w;
//     while(k!=" ");
// }
#include <iostream>
#include <string>

int main() {
    std::string linha;

    // Use um loop para ler várias linhas
    while (std::getline(std::cin, linha)) {
        // Verifique se a linha está vazia
        if (linha.empty()) {
            std::cout << "Linha em branco detectada!" << std::endl;
        } else {
            std::cout << "Conteudo da linha: " << linha << std::endl;
        }
    }

    return 0;
}
