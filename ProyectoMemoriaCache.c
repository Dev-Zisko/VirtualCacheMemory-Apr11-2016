#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <time.h>

// PROTOTIPOS
// PROCESOS Y FUNCIONES
void menu();
int menuCache();
int menuMemoria();
int menuBloqueD();
int menuBloqueA();
int menuDecimal();
int menuBloqueE();
int menuConjunto();
int menuPolitica();
int menuSecuencia();
void m1MapeoDirecto(int mp, int mc, int tb);
void m1MapeoAsociativoConjunto(int mp, int mc, int tb, int tc);
void mostrar(int arreglo[],int byte, int linea, int tag, int tamano,int tipo, int modulo);
void m2MapeoAsociativoConjunto(int mp, int mc, int tb, int tc, int direccion);
void mostrarDatos(int tamano,int bloquesMp,int bloquesMc,int tag,int lineaConjunto,int byte,int tipo);
void m3ArmarMatriz(int bloquesMc, int nc,int reemplazo);


void mostrarDatos(int tamano,int bloquesMp,int bloquesMc,int tag,int lineaConjunto,int byte,int tipo)
{
	printf("Tamano: %db\n",tamano);
	printf("bloquesMp: %d\n",bloquesMp);
	printf("bloquesMc: %d\n",bloquesMc);
	printf("Tag: %db\n",tag);
	if(tipo==1)
	printf("linea: %db\n",lineaConjunto);
	else if (tipo==2)
	printf("conjunto: %db\n",lineaConjunto);
	printf("byte: %db\n",byte);
}

void m1MapeoDirecto(int mp, int mc, int tb)
{
	int bloquesMp;
	int bloquesMc;
	int byte; 
	int linea;
	int tag;
	int tamano;
	int j=0;
	int i;
	tamano = logaritmoBase2(mp);
	int arreglo[tamano];
	bloquesMp = mp / tb;
	bloquesMc = mc / tb;
	byte =  logaritmoBase2(tb);
	linea = logaritmoBase2(bloquesMc);
	tag = tamano-linea-byte; 
	
	mostrarDatos(tamano, bloquesMp, bloquesMc, tag, linea, byte, 1);


	for(i=(tamano-1); i>=0 ; i--)
	{    	
		arreglo[i]=	j;
		j=j+1;
	}
	mostrar(arreglo, byte, linea, tag, tamano, 1,1);
}

void mostrar(int arreglo[],int byte, int linea, int tag, int tamano,int tipo, int modulo)
{
	int i;
	int n[linea];
	int j=0;
	int numeroLinea=0;

	for(i=0; i < tag; i++)
	{
			printf("[%d(t)]",arreglo[i]);
	}
	
	for(i=tag; i < tag + linea; i++)
	{
			if(tipo==1)
			printf("[%d(l)]",arreglo[i]);
			else if(tipo==2)
			printf("[%d(c)]",arreglo[i]);
			n[j]=arreglo[i];
			j=j+1;
	}
	
	for(i= tag + linea  ; i < tamano; i++)
	{
			printf("[%d(b)]",arreglo[i]);
	}
	j=0;
	for(i=linea-1;i>=0;i--)
	{
		numeroLinea=numeroLinea+( n[i] * pow(2,j));
		j=j+1;
	}
	printf("\n");
	if(modulo==2)
	{
		if(tipo==1)
			printf("El bloque se colocara en la linea %d de la memoria cache",numeroLinea);
		if(tipo==2)
			printf("El bloque se colocara en el conjunto %d de la memoria cache",numeroLinea);
	}
	printf("\n\n");
	
}

void m1MapeoAsociativoConjunto(int mp, int mc, int tb, int tc)
{
	int bloquesMp;
	int bloquesMc;
	int byte; 
	int nc;
	int conjunto;
	int tag;
	int tamano;
	int j=0;
	int i;
	bloquesMp = mp / tb;
	bloquesMc = mc / tb;
	nc = bloquesMc / tc;
	if(nc==0){
		printf("El numero de conjuntos es cero. No se pueden calcular los bits de la seccion conjunto\n\n");
		system("PAUSE");
		system("cls");
		menu();
	}
	byte = log2(tb); //logaritmoBase2(tb);
	conjunto = log2(nc);//logaritmoBase2(nc);
	tag = logaritmoBase2(bloquesMp) - conjunto;
	tamano = tag + conjunto + byte;
	int arreglo[tamano];
	
	mostrarDatos(tamano, bloquesMp, bloquesMc, tag, conjunto, byte, 2);

	for(i=(tamano-1); i>=0 ; i--)
	{    	
		arreglo[i]=	j;
		j=j+1;
	}
	
	mostrar(arreglo, byte, conjunto, tag, tamano,2,1);
}


int logaritmoBase2(int numero)
{	
	int i = 0;
	while((numero % 2) != 1)
	{
		numero = numero/2;
		i=i+1;
		
	}
	return (i);
}



void m2MapeoDirecto(int mp, int mc, int tb, int direccion) 
{
	int bloquesMp;
	int bloquesMc;
	int byte; 
	int linea;
	int tag;
	int tamano;
	int i =0;
	tamano = logaritmoBase2(mp);
	int arreglo[tamano];
	bloquesMp = mp / tb;
	bloquesMc = mc / tb;
	byte =  logaritmoBase2(tb);
	linea = logaritmoBase2(bloquesMc);
	tag = tamano - linea - byte;
	int tbin = getTamanoBinario(direccion);
	int binario[tbin];
	int numero = direccion;
	
	mostrarDatos(tamano, bloquesMp, bloquesMc, tag, linea, byte, 1);
	
	i=tbin-1;
	while(numero > 0 ) // añade cada elemento binario a un vector
	{ 	
		binario[i]= numero%2;
		numero = numero/2;
		i=i-1;
	     		
	} 
	printf("La direccion es : \n",tbin);
	for(i=0;i< tbin; i++){  //Muestra el vector que contiene al numero binario
		printf("[%d]",binario[i]);
	}
	
     printf("\n\n");
	
	
	for(i=(tamano-1); i>=0 ; i--) //Recorre el arreglo original desde el ultimo elemento al primero al igual que el numero binario
	{    	
	
		//if((binario[tbin-1]==1 ) || (binario[tbin-1]==0)) 
		if(tbin-1>=0){
	
		arreglo[i]=	binario[tbin-1];
		printf("tbin: %d\n",tbin);
			}
		else
		arreglo[i] = 0;
	 	tbin=tbin-1;
	
	}
	mostrar(arreglo, byte, linea, tag, tamano,1,2);
	
}           

void m2MapeoAsociativoConjunto(int mp, int mc, int tb, int tc, int direccion)
{
	int bloquesMp;
	int bloquesMc;
	int byte; 
	int nc;
	int conjunto;
	int tag;
	int tamano;
	int j=0;
	int i;
	bloquesMp = mp / tb;
	bloquesMc = mc / tb;
	nc = bloquesMc / tc;
	byte =  logaritmoBase2(tb);
	conjunto = logaritmoBase2(nc);
	tag = logaritmoBase2(bloquesMp) - conjunto;
	tamano = tag + conjunto + byte;
	int arreglo[tamano];
	
	mostrarDatos(tamano, bloquesMp, bloquesMc, tag, conjunto, byte, 2);
	
	int tbin = getTamanoBinario(direccion);
	int binario[tbin];
	int numero = direccion;
	
	i=tbin-1;
	while(numero > 0 ) // añade cada elemento binario a un vector
	{ 	
		binario[i]= numero%2;
		numero = numero/2;
		i=i-1;
	     		
	} 
	printf("La direccion es : \n",tbin);
	for(i=0;i< tbin; i++){  //Muestra el vector que contiene al numero binario
		printf("[%d]",binario[i]);
	}
	
	printf("\n\n");
	
	for(i=(tamano-1); i>=0 ; i--) //Recorre el arreglo original desde el ultimo elemento al primero al igual que el numero binario
	{    	
	
		//if((binario[tbin-1]==1 ) || (binario[tbin-1]==0)) 
		if(tbin-1>=0)
		arreglo[i]=	binario[tbin-1];
		else
		arreglo[i] = 0;
	 	tbin=tbin-1;
	
	}
	mostrar(arreglo, byte, conjunto, tag, tamano,2,2);
}    

int getTamanoBinario(int numero)
{
	int i = 0;
	while(numero > 0)
	{ 	
		numero = numero/2;
		i=i+1;
	     		
	} 
	
	return i;
	
}

void m3ArmarMatriz(int bloquesMc, int nc,int reemplazo){
	
	int tc = bloquesMc / nc ; //tamaño del conjunto en bloques
	
	int m[nc][tc+1]; //numero de conjuntos x tamaño de conjunto

	int i; int j; int k; int c; int s; int ff; int fc; int fcap; int sl; int ac; int ts =21; int l; int o; int tb =1; int b;
	
	//Se piden los datos referentes a la secuencia de direcciones.
	while(ts>20){

		printf("Ingrese la cantidad de direcciones de la secuencia (maximo 20)\n");
		scanf("%d",&ts);
		if(ts>20)
		printf("Error. Solo se aceptan un maximo de 20 direcciones.\n");
	}
	system("cls");
	int secuencia[ts];
	for(i=0;i<=ts-1;i++)
	{	
		s=-1;
		while(s<0){
			printf("Indique el numero %d de la secuencia de direcciones: \n",i+1);
			scanf("%d",&s);
			system("cls");
			secuencia[i]=s;
		}


		
	}

	//Se arma la matriz con los datos obtenidos.
	for(i=0; i<=nc-1; i++)
	{
		for(j=0; j<=tc; j++)
		{
			m[i][j]=0;
		}
		
	}
	
	if(reemplazo==1) //LRU
	{
		ff=0; fc=0; fcap=0; ac=0; sl=0; k=0; int mayor=0; int menor =1;
		int n[nc][tc]; 
			//Se arma la matriz secundaria con los contadores.
		for(l=0; l<=nc-1; l++)
		{
			for(o=0; o<=tc-1; o++)
			{
				n[l][o]=0;
				
			}
		
		
		}
		for(i = 0; i<=nc-1;i++) //Inicializa la primera columna en 1 para los contadores de cada bloque
		{
			m[i][0]=1;
		}
	
	
		
		for (s=0;s<=ts-1;s++) //Para cada direccion
		{		
			if(sl==3){
				sl=0;
				printf("\n\n");
			}
			
			c=0;
			j=0;
			
		
			b= secuencia[s] / tb;
			i= b % nc;
			if(i>nc-1)
			{
				printf("%d: Falla por capacidad.   ",secuencia[s]);
				fcap=fcap+1;
				sl=sl+1;
			}
			else
			{
				for(j=1;j<=tc; j++) //Verifica que el conjunto no contenga la direccion
				{
					if(secuencia[s]==m[i][j])
						c=c+1;
				}
				if(c==0)
				{
				
				
					k=m[i][0];
					if(m[i][k]!=0) //Si el bloque del conjunto ya tenia un dato
					{
						for(o=0;o<=tc-1;o++)
						{
							if(n[i][o]<=menor){
							menor = n[i][o];
							k=o+1;	
							}
						}
						printf("%d: Falla por conflicto.   ",secuencia[s]);
						fc=fc+1;
						sl=sl+1;
					}	
					else if(m[i][k]==0) //si el bloque del conjunto estaba vacio
					{	
						printf("%d: Falla forzosa.   ",secuencia[s]);
						ff=ff+1;
						sl=sl+1;
					}
					m[i][k]= secuencia[s];
					
					for(o=0;o<=tc-1;o++)
					{
						if(n[i][o]>mayor){
						mayor = n[i][o];
						menor = mayor;
						}
					}
					n[i][k-1]=mayor+1;
					mayor=0;
				
					m[i][0]=k+1;
					
					if(m[i][0]>tc){				
						m[i][0]=1;
					}
				}
				else //Si se repetia
				{
					sl=sl+1;
					printf("%d: Acierto.   ",secuencia[s]);
					ac=ac+1;
					k=1;
					while(m[i][k]!=secuencia[s]){
						k=k+1;
					}
					for(o=0;o<=tc-1;o++)
					{
						if(n[i][o]>mayor){
						mayor = n[i][o];
						menor = mayor;
						}
						
					}
					n[i][k-1]= mayor+1;
					mayor=0;
				
		    	}
		
			}
		}
	}
	
	
	
	
	if(reemplazo==2) //Fifo
	{
		ff=0; fc=0; fcap=0; ac=0; sl=0;
		for(i = 0; i<=nc-1;i++) //Inicializa la primera columna en 1 para los contadores de cada bloque
		{
			m[i][0]=1;
		}	
	
		for (s=0;s<=ts-1;s++) //Para cada direccion
		{
			if(sl==3){
				sl=0;
				printf("\n\n");
			}
			
			c=0;
			b= secuencia[s] / tb;
			i= b % nc;
			if(i>nc-1)
			{
				printf("%d: Falla por capacidad.   ",secuencia[s]);
				fcap=fcap+1;
				sl=sl+1;
			}
			else
			{
				for(j=1;j<=tc; j++) //Verifica que el conjunto no contenga la direccion
				{
					if(secuencia[s]==m[i][j])
						c=c+1;
				}
			
				if(c==0)
				{
					k=m[i][0];
					
					if(m[i][k]!=0) //Si el bloque del conjunto ya tenia un dato
					{
						printf("%d: Falla por conflicto.   ",secuencia[s]);
						fc=fc+1;
						sl=sl+1;
					}
						
					else if(m[i][k]==0) //si el bloque del conjunto estaba vacio
					{	
						printf("%d: Falla forzosa.   ",secuencia[s]);
						ff=ff+1;
						sl=sl+1;
					}
					m[i][k]= secuencia[s];
					m[i][0]=k+1;
					
					if(m[i][0]>tc){
					
						m[i][0]=1;
					
					}
				}
				else
				{
					sl=sl+1;
					printf("%d: Acierto.   ",secuencia[s]);
					ac=ac+1;
				}	
			}
		}
	}
	
		if(reemplazo==3) //Random
	{
		sl=0; ff=0; fc=0; fcap=0; ac=0;
		for(i = 0; i<=nc-1;i++) //Inicializa la primera columna en 1 para los contadores de cada bloque
		{
			m[i][0]=i;
		
		}	
		
		for (s=0;s<=ts-1;s++) //Para cada direccion
		{
			if(sl==3){
				sl=0;
				printf("\n\n");
			}
			
			c=0;
			b= secuencia[s] / tb;
			i= b % nc;
			if(i>nc-1)
			{
				printf("%d: Falla por capacidad.   ",secuencia[s]);
				fcap=fcap+1;
				sl=sl+1;
			}
			else
			{
				for(j=1;j<=tc; j++) //Verifica que el conjunto no contenga la direccion
				{
				
					if(secuencia[s]==m[i][j])
						c=c+1;
				}
			
				if(c==0)
				{
				
					srand (secuencia[s]);
					k=0;
					while(k==0){
					k=rand() % nc+1;
					}
					printf("%d\n",k);	
								
					if(m[i][k]!=0) //Si el bloque del conjunto ya tenia un dato
					{
						printf("%d: Falla por conflicto.   ",secuencia[s]);
						fc=fc+1;
						sl=sl+1;
					}
						
					else if(m[i][k]==0) //si el bloque del conjunto estaba vacio
					{	
						printf("%d: Falla forzosa.   ",secuencia[s]);
						ff=ff+1;
						sl=sl+1;
					}
					
					m[i][k]= secuencia[s];				
				
				}
				else
				{
					sl=sl+1;
					printf("%d: Acierto.   ",secuencia[s]);
					ac=ac+1;
			    }
			}
		}
	}
	
	
	
	
	
	printf("\n\nTotal de fallas: %d\n",ff+fc+fcap);
	printf("Fallas Forzosas: %d\n",ff);
	printf("Fallas por conflicto: %d\n",fc);
	printf("Fallas por Capacidad: %d\n",fcap);
	printf("Tasa de fallas: %d %\n\n",((ff+fc+fcap)*100)/ts); //CAMBIAR el 20
	printf("Total de aciertos: %d\n", ac);
	printf("Tasa de aciertos: %d %\n\n",(ac*100)/ts);
	printf("Memoria cache:\n\n");
	
	for(i=0; i<=nc-1; i++)
	{
		for(j=0; j<=tc; j++)
		{
			if(j==0)
			{
				printf("conjunto %d:",i);	
			}
			else
			{
				printf("[%d]",m[i][j]);
			}
		
		}
			printf("\n\n");
	}
	
	printf("\n\n");
	
}

int menuCache(){
	int opcion, memoriac;
	printf("Seleccione el tamano de la memoria cache: \n");
	printf("1. 64B  \n");
	printf("2. 128B \n");
	printf("3. 256B \n");
	printf("4. 512B \n");
	printf("5. 1KB  \n");
	printf("6. Regresar al menu \n \n");
	printf("Opcion: ");
   	scanf("%d",&opcion);
   	    if(opcion==1)
        {
			memoriac = 64;
			           
        }
		else if(opcion==2)
		{
        	memoriac = 128;           
		}
		else if(opcion==3)
		{
			memoriac = 256;           
		}
		else if(opcion==4)
		{
			memoriac = 512;           
		}
		else if(opcion==5)
		{
			memoriac = 1024;           
		}
		else if(opcion==6)
		{
			menu();
		}
		else{
			printf("Opcion invalida, intente nuevamente. \n");
			return menuCache();
		}
		return(memoriac);	
}

int menuMemoria(){
	int memoriap, opcion;
	printf("Seleccione el tamano de la memoria principal: \n");
			printf("1. 256KB  \n");
			printf("2. 512KB  \n");
			printf("3. 1MB  \n");
			printf("4. 2MB  \n");
			printf("5. 4MB  \n");
			printf("6. 8MB  \n");
			printf("7. 16MB \n");
			printf("8. 32MB  \n");
			printf("9. Regresar al menu  \n \n");
			printf("Opcion: ");
   	      	scanf("%d",&opcion);
   	    		if(opcion==1)
          		{
   	    			memoriap = 262144;
   	    			system("cls");        
          		}
		  		else if(opcion==2)
		  		{
          			memoriap = 524288;
          			system("cls");         
		  		}
		  		else if(opcion==3)
		  		{
          			memoriap = 1048576;
          			system("cls");         
		  		}
		  		else if(opcion==4)
		  		{
          			memoriap = 2097152;
          			system("cls");          
		  		}
		  		else if(opcion==5)
		  		{
          			memoriap = 4194304;
          			system("cls");         
		  		}
		  		else if(opcion==6)
		  		{
          			memoriap = 8388608;
          			system("cls");          
		  		}
		  		else if(opcion==7)
		  		{
          			memoriap = 16777216;
          			system("cls");          
		  		}
		  		else if(opcion==8)
		  		{
          			memoriap = 33554432;
          			system("cls");           
		  		}
		  		else if(opcion==9)
		  		{
		  			menu();
		  		}
				else
				{
					printf("Opcion invalida, intente nuevamente. \n");
					return menuMemoria();
				}
		  			return memoriap;
}

int menuBloqueD(){
	int opcion, bloque;
	printf("Seleccione el tamano del bloque: \n");
	printf("1. 2B  \n");
	printf("2. 4B  \n");
	printf("3. 8B  \n");
	printf("4. 16B \n");
	printf("5. 32B \n");
	printf("6. Regresar al menu  \n \n");
	printf("Opcion: ");
   	scanf("%d",&opcion);
   	    if(opcion==1)
        {
			bloque = 2;          
        }
		else if(opcion==2)
		{
        	bloque = 4;           
		}
		else if(opcion==3)
		{
        	bloque = 8;           
		}
		else if(opcion==4)
		{
        	bloque = 16;           
		}
		else if(opcion==5)
		{
			bloque = 32;           
		}
		else if(opcion==6)
		{
		  	menu();
		}
		else{
			printf("Opcion invalida, intente nuevamente. \n");
			return menuBloqueD();
		}
		return(bloque);	
}

int menuConjuntoA(){
	int opcion, bloque;
	printf("Seleccione el tamano del conjunto en bloques: \n");
	printf("1. 2  \n");
	printf("2. 4  \n");
	printf("3. 8  \n");
	printf("4. Regresar al menu  \n \n");
	printf("Opcion: ");
   	scanf("%d",&opcion);
   	    if(opcion==1)
        {
			bloque = 2;          
        }
		else if(opcion==2)
		{
        	bloque = 4;           
		}
		else if(opcion==3)
		{
        	bloque = 8;           
		}
		else if(opcion==4)
		{
		  	menu();
		}
		else{
			printf("Opcion invalida, intente nuevamente. \n");
			return menuConjuntoA();
		}
		return(bloque);	
}

int menuDecimal(){
	int numero;
	printf("Indique el numero decimal a buscar: \n");
	scanf("%d", &numero);
	return(numero);
}

int menuBloqueE(){
	int opcion, bloque;
	printf("Seleccione el tamano en bloques de la memoria cache: \n");
	printf("1. 2   \n");
	printf("2. 4   \n");
	printf("3. 8   \n");
	printf("4. 16  \n");
	printf("5. 32  \n");
	printf("6. 64  \n");
	printf("7. 128 \n");
	printf("8. Regresar al menu  \n \n");
	printf("Opcion: ");
   	scanf("%d",&opcion);
   	    if(opcion==1)
        {
			bloque = 2;          
        }
		else if(opcion==2)
		{
        	bloque = 4;           
		}
		else if(opcion==3)
		{
        	bloque = 8;           
		}
		else if(opcion==4)
		{
        	bloque = 16;           
		}
		else if(opcion==5)
		{
        	bloque = 32;           
		}
		else if(opcion==6)
		{
        	bloque = 64;           
		}
		else if(opcion==7)
		{
        	bloque = 128;           
		}
		else if(opcion==8)
		{
		  	menu();
		}
		else{
			printf("Opcion invalida, intente nuevamente. \n");
			return menuBloqueE();
		}
		return(bloque);	
}

int menuConjunto(){
	int opcion, conjunto;
	printf("Seleccione la cantidad del conjunto: \n");
	printf("1. 2  \n");
	printf("2. 4  \n");
	printf("3. 8  \n");
	printf("4. 16 \n");
	printf("5. Regresar al menu  \n \n");
	printf("Opcion: ");
   	scanf("%d",&opcion);
   	    if(opcion==1)
        {
			conjunto = 2;          
        }
		else if(opcion==2)
		{
        	conjunto = 4;           
		}
		else if(opcion==3)
		{
        	conjunto = 8;           
		}
		else if(opcion==4)
		{
        	conjunto = 16;           
		}
		else if(opcion==5)
		{
			menu();
		}
		else{
			printf("Opcion invalida, intente nuevamente. \n");
			return menuConjunto();
		}
		
		return(conjunto);	
}

int menuPolitica(){
	int opcion;
	int politica;
	printf("Seleccione la cantidad del conjunto: \n");
	printf("1. LRU  \n");
	printf("2. FIFO  \n");
	printf("3. RAND  \n");
	printf("4. Regresar al menu \n \n");
	printf("Opcion: ");
   	scanf("%d",&opcion);
   	    if(opcion==1)
        {
			politica = 1;          
        }
		else if(opcion==2)
		{
        	politica = 2;           
		}
		else if(opcion==3)
		{
        	politica = 3;           
		}
		else if(opcion==4)
		{
			menu();
		}
		else
		{
			printf("Opcion invalida, intente nuevamente. \n");
			return menuPolitica();
		}
	
		
		return(politica);	
}

/*int menuSecuencia(){
	int secuencia;
	int opcion;
	opcion = 1;
	while(opcion == 1){
		printf("Indique un numero de la secuencia de direcciones: \n");
		scanf("%d", &secuencia);
		
		printf("Desea colocar otro numero en la secuencia? (1= Si. 0= No.) \n");
		scanf("%d", &opcion);
	}
	return(secuencia);
} */

void menu()
{
	int opcion, memoriap, memoriac, bloque, numero, conjunto;
	int politica;
	system("cls");
	system("color F0");
	printf("                                          #                                                 ### \n ");
 	printf("#     #                                                  #####                                  \n ");
 	printf("##   ##  ######  #    #   ####   #####   #    ##        #     #    ##     ####   #    #  ###### \n ");
 	printf("# # # #  #       ##  ##  #    #  #    #  #   #  #       #         #  #   #    #  #    #  #      \n ");
 	printf("#  #  #  #####   # ## #  #    #  #    #  #  #    #      #        #    #  #       ######  #####  \n ");
 	printf("#     #  #       #    #  #    #  #####   #  ######      #        ######  #       #    #  #      \n ");
 	printf("#     #  #       #    #  #    #  #   #   #  #    #      #     #  #    #  #    #  #    #  #      \n ");
 	printf("#     #  ######  #    #   ####   #    #  #  #    #       #####   #    #   ####   #    #  ###### \n ");                                                                                                       
	printf("\n");
	printf("\n");
	printf("+-++-++-++-++-++-++-++-++-++-++          |    +-++-++-++-++-++-++-++-++-++-++\n");
	printf("|      Funcion de Mapeo:      |          |    |     Ubicacion de bloques:   |\n");
	printf("+-++-++-++-++-++-++-++-++-++-++          |    +-++-++-++-++-++-++-++-++-++-++\n");                  
	printf("                                         |\n"); 
	printf("1. Mapeo directo.                        |    3. Mapeo directo.\n");
	printf("                                         |\n"); 
	printf("2. Mapeo asociativo por conjunto.        |    4. Mapeo asociativo por conjunto.\n");
	printf("                                         |\n"); 
	printf("                                         |\n"); 
	printf("+-++-++-++-++-++-++-++-++-++-++-++-++    |\n");
	printf("| Simulador de reemplazo de bloques |    |\n");
	printf("+-++-++-++-++-++-++-++-++-++-++-++-++    |\n");
	printf("                                         |\n");
	printf("5. Empezar a emular el comportamiento    |\n");
	printf("   de la memoria cache.                  |\n");
	printf("                                         |\n");
	printf("                                                                             +-++-++-++-++-++-++-++");
	printf("\n"); 
	printf("                                                                             | Marque su opcion: ");                                                                                                                                                                  	
	scanf("%d",&opcion);
	system("cls");
	switch(opcion){
		case 1:
			memoriap = menuMemoria();
			system("cls");
			memoriac = menuCache();
			system("cls");
			bloque = menuBloqueD();
			system("cls");	
          	m1MapeoDirecto(memoriap,memoriac,bloque);
   		  	system("PAUSE");
		  	system("cls");
   	      	menu();
   		  	break;
   		case 2:
			memoriap = menuMemoria();
			system("cls");
			memoriac = menuCache();
			system("cls");
			bloque = menuBloqueD();
			system("cls");	
			conjunto = menuConjuntoA();
			system("cls");
   			m1MapeoAsociativoConjunto(memoriap,memoriac,bloque,conjunto);
   			system("PAUSE");
		  	system("cls");
   	      	menu();
   		  	break;
		case 3:
			memoriap = menuMemoria();
			system("cls");
			memoriac = menuCache();
			system("cls");
			bloque = menuBloqueD();
			system("cls");
			numero = menuDecimal();
			system("cls");
         	m2MapeoDirecto(memoriap,memoriac,bloque,numero);
   		  	system("PAUSE");
		  	system("cls");
   	      	menu();
   		  	break;
   		case 4:
			memoriap = menuMemoria();
			system("cls");
			memoriac = menuCache();
			system("cls");
			bloque = menuBloqueD();
			system("cls");
			conjunto = menuConjuntoA();
			system("cls");
			numero = menuDecimal();
			system("cls");
   			m2MapeoAsociativoConjunto(memoriap,memoriac,bloque,conjunto,numero);
   			system("PAUSE");
		  	system("cls");
   	      	menu();
   		  	break;
   		case 5:
			bloque = menuBloqueE();
			system("cls");
			conjunto = menuConjunto();
			system("cls");
			politica = menuPolitica();
			system("cls");
   			m3ArmarMatriz(bloque, conjunto, politica);
   			system("PAUSE");
		  	system("cls");
   	      	menu();
   		  	break;
   		default:
   	       	printf("Ha marcado una opcion incorrecta por favor intente nuevamente.  \n");
   	       	system("PAUSE");
   	       	system("cls");
   	       	system("cls");
   		   	menu();
           	break;
	}                                                                   
}

int main()
{
	
	menu();
	/*m1MapeoDirecto(262144,1024,8);
	system("PAUSE");
	system("cls");
	m1MapeoAsociativoConjunto(262144,1024,8,2);
	system("PAUSE");
	system("cls");
	m2MapeoDirecto(262144,128,8,219);
	system("PAUSE");
	system("cls");
	m2MapeoAsociativoConjunto(262144,128,8,2, 220);
	system("PAUSE");*/
	/*	m3ArmarMatriz(16,4,1, 0);
	system("PAUSE");
	system("cls");
	m3ArmarMatriz(16,4,2,0);
	system("PAUSE");
	system("cls");
	*/
	return 0;
}
