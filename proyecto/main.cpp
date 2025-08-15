#include<iostream>
#include "arbolBinario.hpp"


int main(){
    ArbolBin<int> nuevo(3,ArbolBin<int>(2,ArbolBin<int>(),ArbolBin<int>()),ArbolBin<int>());

    // std::list<int> misNodos = nuevo.nodosArbol();

    // while(!misNodos.empty()){
    //     std::cout<<misNodos.front();
    //     misNodos.pop_front();
    // }
    return 0;
}



