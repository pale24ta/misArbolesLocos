#ifndef NODOARBOLHPP
#define NODOARBOLHPP

#include<iostream>
#include<list>
//
template<class Element>
class NodoBinario{

    // Atributos

    private:
        Element e;
        NodoBinario<Element> *hijoIzq, *hijoDer;

    public:
    
    // Metodos

        NodoBinario(Element e); // Constructor
        Element& getInfo();
        void setInfo(Element e);
        NodoBinario<Element> *getHijoIzq();
        NodoBinario<Element> *getHijoDer();
        void setHijoIzq(NodoBinario<Element> *izq);
        void setHijoDer(NodoBinario<Element> *der);


};

template<class Element>
NodoBinario<Element>::NodoBinario(Element e): info(e), hijoIzq(NULL), hijoDer(NULL){} // Constructor

template<class Element>
Element& NodoBinario<Element>::getInfo()
{
    return info;
}

template<class Element>
void NodoBinario<Element>::setInfo(Element e)
{
    info = e;
}

template<class Element>
NodoBinario<Element> *NodoBinario<Element>::getHijoIzq()
{
    return hijoIzq;
}

template<class Element>
NodoBinario<Element> *NodoBinario<Element>::getHijoDer()
{
    return hijoDer;
}
template<class Element>
void NodoBinario<Element>::setHijoIzq(NodoBinario<Element> *izq)
{
    hijoIzq = izq;
}
template<class Element>
void NodoBinario<Element>::setHijoDer(NodoBinario<Element> *der)
{
    hijoDer = der;
}


#endif