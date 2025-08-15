#ifndef NODONHPP
#define NODONHPP


// Una clase para nodos de arboles N-ario

template<class Element>
class NodoN{
    private:
        Element e;
        NodoN<Element> *hijoIzq, *hermanoDer;

    public:

        NodoN(Element e, NodoN<Element> *izq, NodoN<Element> *der);
        NodoN(Element e);
        Element& getInfo();
        NodoN<Element> *getHijoIzq();
        NodoN<Element> *getHermanoDer();
        void setHijoIzq(NodoN<Element> *izq);
        void setHermanoDer(NodoN<Element> *der);
};
template<class Element>
NodoN<Element>::NodoN(Element e, NodoN<Element> *izq, NodoN<Element> *der){
    this->e = e;
    hijoIzq = izq;
    hermanoDer = der;
}

template <class Element>
inline NodoN<Element>::NodoN(Element e) : NodoN<Element>(e,NULL,NULL)
{
}

template<class Element>
Element& NodoN<Element>::getInfo(){
    return e;
}

template <class Element>
NodoN<Element> *NodoN<Element>::getHermanoDer(){
    return hermanoDer;
}

template<class Element>
void NodoN<Element>::setHijoIzq(NodoN<Element> *izq){
    hijoIzq = izq;

}


template<class Element>
void NodoN<Element>::setHermanoDer(NodoN<Element> *der){
    hermanoDer = der;
}

#endif