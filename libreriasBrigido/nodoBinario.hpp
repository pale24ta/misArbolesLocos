#ifndef NODOARBOLHPP
#define NODOARBOLHPP

template<class Element>
class NodoBinario{

    // Atributos

    private:
        Element e;
        NodoBinario<Element> *hijoIzq, *hijoDer;

    public:
    
    // Metodos

        NodoBinario(Element e); // Constructor
        NodoBinario(Element e, NodoBinario<Element> *izq, NodoBinario<Element> *der); // Constructor
        Element& getInfo();
        void setInfo(Element e);
        NodoBinario<Element> *getHijoIzq();
        NodoBinario<Element> *getHijoDer();
        void setHijoIzq(NodoBinario<Element> *izq);
        void setHijoDer(NodoBinario<Element> *der);


};

template<class Element>
NodoBinario<Element>::NodoBinario(Element e): e(e), hijoIzq(NULL), hijoDer(NULL){} // Constructor

template <class Element>
inline NodoBinario<Element>::NodoBinario(Element e, NodoBinario<Element> *izq, NodoBinario<Element> *der): e(e), hijoIzq(izq), hijoDer(der){}

template<class Element>
Element& NodoBinario<Element>::getInfo()
{
    return e;
}

template<class Element>
void NodoBinario<Element>::setInfo(Element e)
{
    this->e = e;
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