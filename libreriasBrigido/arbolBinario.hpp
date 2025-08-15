#ifndef ARBOLBINHPP
#define ARBOLBINHPP

#include "nodoBinario.hpp"
#include<iostream>
#include <list>

template <class Element>
class ArbolBin{


    private:

        NodoBinario<Element> *raiz;
        int peso;

    private: 

        NodoBinario<Element> *copiarNodos(NodoBinario<Element> *ptr);
        void preOrden(NodoBinario<Element> *ptr, std::list<Element>& nodos);
        void eliminarNodoBinario(NodoBinario<Element> *ptr);
    
    public:
        ArbolBin(); // Arbol Vacio
        ArbolBin(Element e, ArbolBin<Element> a1, ArbolBin<Element> a2);
        ArbolBin(const ArbolBin<Element> &binary_tree);
        ~ArbolBin();
        int getPeso();
        bool esVacio();
        Element& getRaiz();
        std::list<Element> nodosArbol();
        ArbolBin<Element> getHijoIzquierdo();
        ArbolBin<Element> getHijoDerecho();
        void vaciarArbol();
};




#endif

template <class Element>
inline NodoBinario<Element> *ArbolBin<Element>::copiarNodos(NodoBinario<Element> *ptr)
{
    if(ptr != NULL){
        
        NodoBinario<Element> *nodoNuevo = new NodoBinario<Element>(ptr->getInfo(),copiarNodos(ptr->getHijoIzq()),copiarNodos(ptr->getHijoDer));
        return nodoNuevo;
    }else{
        return NULL;
    }
}


template <class Element>
inline void ArbolBin<Element>::preOrden(NodoBinario<Element> *ptr, std::list<Element> &nodos)
{
    if(ptr != NULL){
        nodos.push_back(ptr->getInfo());
        preOrden(ptr->getHijoIzq(),nodos);
        preOrden(ptr->getHijoDer(),nodos);
    }
}

template <class Element>
inline void ArbolBin<Element>::eliminarNodoBinario(NodoBinario<Element> *ptr)
{
    NodoBinario<Element> *borrador;
    if(ptr->getHijoIzq() != NULL){
        eliminarNodoBinario(ptr->getHijoIzq());
        borrador = ptr->getHijoIzq();
        ptr->setHijoIzq(NULL);
        delete borrador;
    }
    if(ptr->getHijoDer() != NULL){
        eliminarNodoBinario(ptr->getHijoDer());
        borrador = ptr->getHijoDer();
        ptr->getHijoDer(NULL);
        delete borrador;
    }
}

template <class Element>
inline ArbolBin<Element>::ArbolBin(): raiz(NULL) , peso(0)
{
}

template <class Element>
inline ArbolBin<Element>::ArbolBin(Element e, ArbolBin<Element> a1, ArbolBin<Element> a2)
{
    raiz = new NodoBinario<Element>(e,a1.raiz,a2.raiz);
    peso += a1.peso + a2.peso;
}

template <class Element>
inline ArbolBin<Element>::ArbolBin(const ArbolBin &binary_tree)
{
    raiz = copiarNodos(binary_tree.raiz);
    peso = binary_tree;
}

template <class Element>
inline ArbolBin<Element>::~ArbolBin()
{
    vaciarArbol();
}

template <class Element>
inline int ArbolBin<Element>::getPeso()
{
    return peso;
}

template <class Element>
inline bool ArbolBin<Element>::esVacio()
{
    return peso == 0;
}

template <class Element>
inline Element& ArbolBin<Element>::getRaiz()
{
    return raiz->getInfo();
}

template <class Element>
inline std::list<Element> ArbolBin<Element>::nodosArbol()
{
    std::list<Element> nodoArboles;

    preOrden(raiz,nodoArboles);

    return nodoArboles;
}

template <class Element>
inline ArbolBin<Element> ArbolBin<Element>::getHijoIzquierdo()
{   
    ArbolBin<Element> sub;
    sub.raiz = copiarNodos(raiz->getHijoIzq());
}

template <class Element>
inline ArbolBin<Element> ArbolBin<Element>::getHijoDerecho()
{
    ArbolBin<Element> sub;
    std::list<Element> nodosHijo;
    
    sub.raiz = copiarNodos(raiz->getHijoIzq());
    preOrden(sub.raiz,nodosHijo);

    sub.peso = nodosHijo.size();

    return sub;
}

template <class Element>
inline void ArbolBin<Element>::vaciarArbol()
{
    if(raiz != NULL){
        NodoBinario<Element> *b = raiz;
        eliminarNodoBinario(raiz);
        raiz = NULL;
        delete b;
        peso = 0;
    }
}
