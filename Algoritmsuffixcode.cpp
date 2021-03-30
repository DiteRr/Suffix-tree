#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
#include <string>
#include <stack>
#include <cmath>
 




struct nodo{
     int pos;
	 string s;
     struct nodo *izq, *der;
};



nodo* crearNodoHijo(string simbolo, nodo* &q, int pos){
     nodo* nuevoNodo = new(struct nodo);
     q->izq = nuevoNodo; 
	 nuevoNodo->s= simbolo;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;
     nuevoNodo->pos = pos;

     return nuevoNodo;
}
int k = 0;
//stack <int> occST_stack;
//stack <int> occSA_stack;

void Recorrer (nodo* p, nodo* q,int i,int po,string str,int n){
   bool L = true;
   while(L  && p!=NULL ){
		    
			
			if(p!=NULL && p->s == str.substr(po,1)){
			 //letras iguales
			  if(p->izq == NULL){
			  	 bool B = true;
				 int pos1 = p->pos;
			  	 int pos2 = i;
			  	 int j = 1;
			  	 p->pos = -1;
				   while(B){
			  	  	
					if(str.substr(pos1+j+n,1) < str.substr(i+j+n,1)){
						  
						  nodo* nuevoNodo1 = NULL;
						  nuevoNodo1 = new(struct nodo);
						  p->izq = nuevoNodo1;
						  nuevoNodo1->s= str.substr(pos1+j+n,1);
						  nuevoNodo1->der = NULL;
						  nuevoNodo1->izq = NULL;
						  nuevoNodo1->pos = pos1;
						  p=nuevoNodo1;
						  
						  nodo * nuevoNodo2 = NULL;
						  nuevoNodo2 = new(struct nodo);
						  p->der = nuevoNodo2;
						  nuevoNodo2->s= str.substr(i+j+n,1);
						  nuevoNodo2->der = NULL;
						  nuevoNodo2->izq = NULL;
						  nuevoNodo2->pos = pos2;
						  B = false;
						 }
					else if(str.substr(pos1+j+n,1) > str.substr(i+j+n,1)){
						
						  
						  nodo* nuevoNodo1 = NULL;
						  nuevoNodo1 = new(struct nodo);
						  p->izq = nuevoNodo1;
						  nuevoNodo1->s= str.substr(i+j+n,1);
						  nuevoNodo1->der = NULL;
						  nuevoNodo1->izq = NULL;
						  nuevoNodo1->pos = pos2;
						  p=nuevoNodo1;
					     
					      nodo* nuevoNodo2 = NULL;
					      nuevoNodo2 = new(struct nodo);
						  p->der = nuevoNodo2;
						  nuevoNodo2->s= str.substr(pos1+j+n,1);
						  nuevoNodo2->der = NULL;
						  nuevoNodo2->izq = NULL;
						  nuevoNodo2->pos = pos1;
					      B = false;
					
					}
					else{
						nodo* nuevoNodo3 = new(struct nodo);
						p->izq = nuevoNodo3;
						nuevoNodo3->s= str.substr(pos1+j+n,1);
						nuevoNodo3->der = NULL;
						nuevoNodo3->izq = NULL;
						nuevoNodo3->pos = -1;
						q=p;
						p=nuevoNodo3;
						j=j+1;
					
						
					}
				 
				}
			 	
			  	 
			  	 
			  }
			  else{
			  	    
					 q=p;
					 p=p->izq;
					 Recorrer(p,q,i,po+1,str,n+1);
			  
			  
			  
			  }
			  L = false;  
			 }
			else if(p!=NULL && p->s > str.substr(po,1)){
			   //change 
			   if(q->izq == p){
			   nodo* nuevoNodo = new(struct nodo);
			   q->izq = nuevoNodo; 
			   nuevoNodo->s= str.substr(po,1);
			   nuevoNodo->der = p;
			   nuevoNodo->izq = NULL;
			   nuevoNodo->pos = i;
			   	
			   	
			   }
			   else{
			   nodo* nuevoNodo = new(struct nodo);
			   q->der = nuevoNodo; 
			   nuevoNodo->s= str.substr(po,1);
			   nuevoNodo->der = p;
			   nuevoNodo->izq = NULL;
			   nuevoNodo->pos = i;
			   	}
			 
			   L = false;
		    }
		    else{
			 q=p;
			 p=p->der;
		    }
			
		
		}
		if(L && p==NULL){
			// agrega al ultimo hermano
			   nodo* nuevoNodo = new(struct nodo);
			   q->der = nuevoNodo; 
			   nuevoNodo->s= str.substr(po,1);
			   nuevoNodo->der = p;
			   nuevoNodo->izq = NULL;
			   nuevoNodo->pos = i;
			   L = false;
		}
		  
	  
	  
	
	
	}
void RecorrerNodoInterno(nodo* p){
nodo* q = p;		

	while(p!=NULL){
	    if(p->izq!=NULL){ // nodo interno
		    if(p->izq->der==NULL){ // nodo interno con un solo hijo
				q=p->izq;
				while(q!=NULL && q->der == NULL){
				p->s = p->s+q->s;
				p->izq = q->izq;
				q=p->izq;
				}
				//cout << p->s << endl;
			}
			else{
				//cout << p->s << endl;
			}
			
			if(q!=NULL){
				RecorrerNodoInterno(p->izq);
			}
	 	}
	 	else{
	 		//cout << p->s << endl;
	 	}
		p=p->der;
	 		
	 		
	}
}
	
	
void  subArray(nodo* p,int  sArray []){
	 	
	 	while(p!=NULL){
	 		if(p->izq!=NULL){
				 cout << p->s;
				 subArray(p->izq,sArray);
	 			
			 }
	 		else{
	 		 	cout << p->s;
				sArray[k]=p->pos;
	 		 	k++;
	 		}
	 		p=p->der;
	 		
	 		
		 }
	 	
	 	
	 }

stack <int> locateSA(int A [], string str, string ocurr, stack <int> occSA_stack){
	int b=0;
	int s = 0;
	int m=ocurr.length();
	int t= str.length()-2;
	while(b < t){
		s=(b+t)/2;
	 	if(ocurr > str.substr(A[s],m)){
			b=s+1;

		}else{
			t=s;
		}
		
	}
	int e=b-1;
	t=str.length()-1;
	while(e<t){
		float result = (e+t)/float(2);
		s=round(result);
		if(ocurr==str.substr(A[s],m)){
			e=s;
		}else{
			t=s-1;
		}
	}
    while (b<=e){
		occSA_stack.push(A[b]);
    	b++;
	}
	return occSA_stack;
		
}
stack <int> ArbolOcurrencia(nodo* p, stack <int> occST_stack){	 	
	 	while(p!=NULL){
	 		if(p->izq!=NULL){
				occST_stack = ArbolOcurrencia(p->izq,occST_stack);
	 			
			 }
	 		else{
	 		 	occST_stack.push(p->pos);
	 		}
	 		p=p->der;
	 	 }
	 	 
	 	 return occST_stack;
}



stack <int> locateST(string str, string ocurr, nodo* p,stack <int> occST_stack){
	
	bool L = true;
	int i=0;
	nodo* q = p;
	nodo* c = p;
	int len = 0;
    while(L && q!=NULL && i!=ocurr.length()){
		 len = q->s.length();	
			if(q->s == ocurr.substr(i,len)){
				c=q;
				q=q->izq;
				i = i + len;
			}
			else{
				q=q->der;			
			    if(q==NULL){
			    	L=false;
			    }
			
			}
			
	}
	
	if(q!=NULL && i==ocurr.length()){
		// termina en un nodo interno
	occST_stack =ArbolOcurrencia(c->izq,occST_stack);
	}
	else if (q==NULL && i==ocurr.length()){
		// termina en la ultima hoja
		
	   occST_stack.push(c->pos);
	}
	else if(L  && q==NULL && i<ocurr.length()){
		// la ocurrencia sigue despues de la ultima hoja
		
		if(ocurr.substr(i,ocurr.length()-i) == str.substr(c->pos+i,ocurr.length()-i)){
		occST_stack.push(c->pos);
		}
	}
	return occST_stack;
}

	






int  main(){
	
    nodo* R;   // creado Arbol
    nodo* p;
    nodo* q;
    R = new(struct nodo);
    R->der = NULL;
    R->izq = NULL;
    R->s = ' ';
    R->pos = -1;
    
	
	string str = "mississippi";  //AQUI ESCRIBE LA PALABRA QUE QUIERAS PROBAR.
        //str = str + "\n";
	
  	str =   str + "\30"; // reemplaza el simbolo $=34 tabla ASCCI porque el el simbolo espacio es " "=31.
	
	p=crearNodoHijo(str.substr(0,1),R,0); 
	  
    int po = 0;
    int n = 0;
  	q=R;
  	for(int i=1; i<str.length(); i++){
	   n=0;
	   q=R;
	   p=R->izq;
	   po=i;
           Recorrer(p,q,i,po,str,n);
       
	}
	p=R->izq;
        int sArray [str.length()];
	
	cout << "Aristas del arbol en preorden:"<<endl;
	
	subArray(p,sArray);
	 
	cout << "\n" << "Arreglo de sufijos" << "\n";
	
	for(int i=0; i<str.length()-1; i++){
        cout << sArray[i] << "-";	
     }
	 cout << sArray[str.length()-1];
	 cout << endl; 
	 
	 RecorrerNodoInterno(p); 
	 p=R->izq;
	 
	 cout << "palabra ingresada: ";
	 cout << str << endl;
	 
	 
	 
	 
	 string ocurr = "ss";  // AQUI ESCRIBE LA OCURRENCIA
	 
	 cout << "buscar ocurrencia: ";
	 cout << ocurr << endl;
	 
	 
	
	 //Locate para el arreglo
	 stack <int> occSA_stack;
	 occSA_stack = locateSA(sArray,str,ocurr,occSA_stack);
	 
	 if(occSA_stack.empty()){

                // print user message
                printf("There aren't ocurrences!\n");

            }
	 
	 while (!occSA_stack.empty()) {
       printf("ocurrence in: %i\n", occSA_stack.top());
       occSA_stack.pop();
	   }

 
     //Locate para el arbol
     stack <int> occST_stack;
	 occST_stack = locateST(str,ocurr,p,occST_stack); // ESTE ES EL LOCATE PARA EL ARBOL
	 
	 
	 if(occST_stack.empty()){

                // print user message
                printf("There aren't ocurrences!\n");

            }
	 
	 while (!occST_stack.empty()) {
       printf("ocurrence in: %i\n", occST_stack.top());
       occST_stack.pop();
	   }
	
 return 0;
 
 }
  
 
