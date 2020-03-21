#ifndef LISTA_H
#define LISTA_H
#include "nodo.hpp"

template <class T>
class lista
{	
		private:
				nodo<T> *list;
				int lon;
				
				
		public:
				//constructores
				lista();
				lista(T e);
				lista(const lista<T> &a) ;
				//consultores 
				bool es_vacia();
				void mostar_primero();
				T consultar(int pos);
				void mostrar();
				int longitud();
				//modificadores
				void vaciar();
				void insertar(int pos,T e);
				void eliminar(int pos);
				void invertir();
				void eliminar_e(T e);
				void mezclarLista(lista a);
				//sobrecarga de operadores
				
				lista& operator = (const lista<T> &a);
				lista<T>& operator +(const lista<T> &a);
				bool operator ==(const lista<T> &a);
				template <class E>	
				friend std::ostream& operator << (std::ostream& salida, const lista<E> &L);
				
				//destructor 
				~lista();
};
//////////////////////////////implementacion 
////constructores
template <class T>
lista<T>::lista()
{
	list=NULL;
	lon=0;
}

template <class T>
lista<T>::lista(T e)
{
		this->list->mod_info(e);
		this->list->mod_prox(NULL);
		this->lon=1;
}

template <class T>
lista<T>::lista(const lista<T> &a)
{
	nodo<T> *aux,*aux2;
	
	if(a.list!=NULL){
		aux=a.list;
		this->list=new nodo<T>(aux->obt_info());
		aux2=this->list;
		aux=aux->obt_prox();
		while(aux!=NULL){
			aux2->mod_prox(new nodo<T>(aux->obt_info()));
		    aux2=aux2->obt_prox();
		    aux=aux->obt_prox();
		}
		this->lon=a.lon;
	
	}else{
			this->list=NULL;
			this->lon=0;
	
	}
}

template <class T>
bool lista<T>::es_vacia()
{
	return(list==NULL);
}

template <class T>
void lista<T>::mostar_primero()
{
	if(list=!NULL){	
		cout<<"Primer elemento: "<<list->obt_info()<<endl;
	}else{
		cout<<"Error, lista vacia"<<endl;
	}
}


template <class T>
T lista<T>::consultar(int pos)
{	
   nodo<T> *aux;
   T e;
   int i;
  
    i=1;
    aux=list;
	while(aux!=NULL && pos!=i){
		i++;
		aux=aux->obt_prox();	
	}
	if(pos==i && aux!=NULL){
		e=aux->obt_info();
	}
	
	return e;
}

template <class T>
void lista<T>::mostrar()
{
	nodo<T> *aux;
	int i=0;
	aux=list;
	if(aux==NULL){
		cout<<"La lista esta vacia"<<endl;
	}else{
		cout<<"Lista";	
		while(aux!=NULL){
			i++;
			cout << "(" << i << ")" <<aux->obt_info() << endl;
			aux=aux->obt_prox();	
		}
	}
}

template <class T>
int lista<T>::longitud()
{
 return this->lon;
}

template<class T>
void lista<T>::eliminar_e(T e)
{
    nodo<T> *temp = list;
    nodo<T> *temp1 = list->obt_prox();
 	nodo<T> *aux_node;
    int cont = 0;
 
    if (list->obt_info() == e) {
        list = temp->obt_prox();
    }else{
        while(temp1){
            if(temp1->obt_info() == e) {
                aux_node = temp1;
                temp->mod_prox(temp1->obt_prox());
                delete aux_node;
                cont++;
                lon--;
            }
            temp = temp->obt_prox();
            temp1 = temp1->obt_prox();
        }
    }
 
    if (cont == 0) {
        cout << "No existe el dato " << endl;
    }
}

template <class T>
void lista<T>::vaciar()
{
	nodo<T> *tmp;
	
	while(list!=NULL){
		tmp = list;
		list = list->obt_prox();
		delete(tmp);
	}
	this->list=NULL;
	this->lon=0;
}

template <class T>
void lista<T>::insertar(int pos,T e){
	nodo<T> *aux,*tmp;
	int i;
	
	if(pos<=lon+1 && pos>0){
		tmp=new nodo<T>(e);
		if(tmp!=NULL){
			if(pos==1){
				tmp->mod_prox(list);
				this->list = tmp;
			}
			else{
				aux=this->list;
				for(i=1;i<pos-1;i++){
					aux = aux->obt_prox();
				}
				
				tmp->mod_prox(aux->obt_prox());
				aux->mod_prox(tmp);
			}
			
			if(pos==lon+1){
				tmp->mod_prox(NULL);
			}
			lon++;
		}
	}
}

template <class T>
void lista<T>::invertir(){
	nodo<T> *tmp,*sig,*aux;
	
	tmp=this->list;
	sig=tmp->obt_prox();
	tmp->mod_prox(NULL);
	while(sig!=NULL)
	{
		aux=sig->obt_prox();
		sig->mod_prox(tmp);
		tmp=sig;
		sig=aux;
	}
	this->list=tmp;
	
	
	
}
template <class T>
void lista<T>::eliminar(int pos){
	nodo<T> *tmp,*aux;
	int i;
	
	if(list!=NULL){
		if(pos<=longitud()){
			
			if(pos==1){
				tmp = list;
				list = list->obt_prox();
			}
			else{
				aux = list;
				for(i=1;i<=pos-2;i++){
					aux = aux->obt_prox();
				}
				
				tmp = aux->obt_prox();
				aux->mod_prox(tmp->obt_prox());
			}
			lon = lon-1;
			delete(tmp);
		}
	}
}

//Sobrecarga de operadores
template <class T>
lista<T>& lista<T>::operator =(const lista<T> &a){
	nodo<T> *aux,*aux2;
	
	if(this!=&a){
		if(a.list!=NULL){
			aux=a.list;
			this->list=new nodo<T>(aux->obt_info());
			aux2=this->list;
			aux=aux->obt_prox();
			while(aux!=NULL){
				aux2->mod_prox(new nodo<T>(aux->obt_info()));
				aux2=aux2->obt_prox();
				aux=aux->obt_prox();
				}
			this->lon=a.lon;
			aux=NULL;
			aux2=NULL;
			delete(aux);
			delete(aux2);
		}
		else{
			this->list=NULL;
			this->lon=0;
		}
	}
	return (*this);
}

template <class T>
bool lista<T>::operator ==(const lista<T> &a){
	nodo<T> *aux1,*aux2;
	int i;
	bool flag=true;
	
	if(this != &a){
		if(this->lon == a.lon){
			i=1;
			aux1=this->list;
			aux2=a.list;
			while(i<=lon && flag){
				i++;
				if(aux1->obt_info() == aux2->obt_info()){
					aux1 = aux1->obt_prox();
					aux2 = aux2->obt_prox();
				}
				else{
					flag=false;
				}
			}
		}
		else{
			flag=false;
		}
	}
	return flag;
}

template <class T>
lista<T>& lista<T>::operator +(const lista<T> &a){
	nodo<T> *aux,*nuevo,*aux2,*aux3;
	
	aux=this->list;
	nuevo=NULL;
	aux2=NULL;
	if(aux!=NULL){
		aux2=new nodo<T>(aux->obt_info());
		aux3=aux2;
		aux=aux->obt_prox();
		
		while(aux!=NULL){
			nuevo=new nodo<T>(aux->obt_info());
			aux3->mod_prox(nuevo);
			aux3 = aux3->obt_prox();
			aux=aux->obt_prox();
			nuevo=nuevo->obt_prox();
		}
		aux=a.list;
	}
	else{
		aux=a.list;
		
		aux2=new nodo<T>(aux->obt_info());
		aux3=aux2;
		aux2->mod_prox(nuevo);
		aux=aux->obt_prox();
	}
	while(aux!=NULL){
		nuevo=new nodo<T>(aux->obt_info());
		aux3->mod_prox(nuevo);
		aux3 = aux3->obt_prox();
		aux=aux->obt_prox();
		nuevo=nuevo->obt_prox();
	}
	
	this->lon = this->lon+a.lon;
	
	this->list = aux2;
	return *this;
}
template <class T>
std::ostream& operator << (std::ostream &salida, const lista<T> &L)		
{
	nodo<T> *act = L.list;
	
	while(act != NULL)
	{
		salida<<act->obt_info()<<" ";
		act = act->obt_prox();
	}
	salida<<endl;
	return(salida);
}		

//Destructor de la clase
template <class T>
lista<T>::~lista(){
	vaciar();
}

template <class T>
void lista<T>::mezclarLista(lista a)
{
	nodo<T> *aux,*tmp,*schwarz,*ptr;
	int band=1;
	tmp=a.list;
	aux=this->list;//b
	schwarz=new nodo<T>(aux->obt_info());

	while(tmp != NULL && aux!=NULL&& band)
	{
		//schwarz=new nodo<T>(aux->obt_info());
		
		if(aux->obt_info()<tmp->obt_info())
		{
			if(a.list->obt_info() > schwarz->obt_info()){
			
				schwarz->mod_prox(a.list); 
				a.list=schwarz;	
				ptr=schwarz;
				aux=aux->obt_prox();	
				schwarz=new nodo<T>(aux->obt_info());
			}else{		
					ptr->mod_prox(schwarz);
					ptr=schwarz;
					ptr->mod_prox(tmp);
					aux=aux->obt_prox();
					if(aux!=NULL)
					{
						schwarz=new nodo<T>(aux->obt_info());
					}
				  }
				  
		}else{
				ptr=tmp;
				if(tmp->obt_prox()==NULL)
				{
					band=0;
					
				}else
				{
					tmp=tmp->obt_prox();
				}
				
			}
		
	}
	
	while(aux!=NULL)//si la primera lista ya termino y aun quedan por ordenar los elementos de la segunda lista
	{
		tmp->mod_prox(schwarz);
		tmp=tmp->obt_prox();
		aux=aux->obt_prox();
		if(aux!=NULL)
		{
			schwarz=new nodo<T>(aux->obt_info());
		}
		
	}
	
	
	cout<<a;
}
	
	

#endif
