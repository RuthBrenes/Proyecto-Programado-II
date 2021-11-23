#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Nodo Nodo;
typedef struct ListaC ListaC;
typedef struct ListaE ListaE;
typedef struct ListaL ListaL;
typedef struct arista arista;
typedef struct vertice vertice;
typedef struct grafo grafo;
typedef char string[200];


typedef struct{
    string cedula;
    string nombres;
    string apellidos;
    string correoElectronico;
    string rol;
    string fechaCumpleanos;
    string tipoArchivo;
    string descripcion;
    int cantColaboradores;
}informacionColaborador;

typedef struct{
	string nombre;
	string descripcion;
	string tipoArchivo;
	string origen;
	string destino;
	int tamano;
}informacionEquipos;

typedef struct{
	int codigo;
	string lugar;
	int codigoPostal;
	string tipoArchivo;
	int tamano;
}lugaresDeDomicilio;

typedef struct{
	string origen;
	string destino;
	int tiempoEnMinutos;
	int distancia;
	string tipoRuta;
	string tipoArchivo;
}informacionEtiquetas;

struct Nodo
{
	informacionColaborador dato;
	informacionEquipos dato2;
	Nodo *siguiente;
};

struct ListaC
{
	Nodo *inicio;
};

struct ListaE
{
	Nodo *inicio2;
};

struct ListaL
{
	Nodo *inicioL;
};

struct grafo
{
	vertice *inicioG;
};

struct vertice
{
	vertice *siguiente;
	arista *ady;
	lugaresDeDomicilio datosDomicilio;
	informacionEtiquetas datosEtiquetas;
	string nombre;
};

struct arista
{
	arista *siguiente;
	vertice *ady;	
	informacionEtiquetas datosEtiquetas;
};


ListaC *listaColaborador(void)
{
	ListaC *C;
	C = (ListaC *) malloc(sizeof(ListaC));
	C->inicio = NULL;
	return C;
}

ListaE *listaEquipos(void)
{
	ListaE *E;
	E = (ListaE *) malloc(sizeof(ListaE));
	E->inicio2 = NULL;
	return E;
}

ListaL *listaLugares(void)
{
	ListaL *L;
	L = (ListaL*) malloc(sizeof(ListaL));
	L->inicioL = NULL;
	return L;
}

vertice *inicioG = NULL;

void lecturaDatosInfoCo(informacionColaborador *infoColaborador);
void creacionEInsercionArchTxtC(const ListaC *C, informacionColaborador *infoColaborador);

void insertarColaborador(ListaC *C, informacionColaborador infoColaborador)
{
	int contador = 0;
	int cantidadColab;

	printf("¿Cuantos colaboradores desea agregar? ");
	scanf("%d", &cantidadColab);
	getchar();
	
	infoColaborador.cantColaboradores = 1;
	while(contador < cantidadColab)
	{
		lecturaDatosInfoCo(&infoColaborador);
		Nodo *n, *aux;

		if(C->inicio == NULL) //Valida si la lista esta vacia
		{
			C->inicio = (Nodo *) malloc(sizeof(Nodo));
			C->inicio->dato = infoColaborador;
			C->inicio->siguiente = NULL;
		}
		else
		{
			n = C->inicio;
			while(n != NULL)
			{
				aux = n;
				n = n->siguiente;
			}
			aux->siguiente = (Nodo *) malloc(sizeof(Nodo));
			aux->siguiente->siguiente = NULL;
			aux->siguiente->dato = infoColaborador;
		}
		contador++;
		creacionEInsercionArchTxtC(C, &infoColaborador);
		infoColaborador.cantColaboradores++;
	}		
}

void lecturaDatosInfoCo(informacionColaborador *infoColaborador)
{
	printf("\nInserte la cedula del colaborador %d: ", infoColaborador->cantColaboradores);
	gets(infoColaborador->cedula);
	
	printf("\nIngrese los nombres del colaborador %d: ", infoColaborador->cantColaboradores);
	gets(infoColaborador->nombres);
	
	printf("\nIngrese los apellido del colaborador %d: ", infoColaborador->cantColaboradores);
	gets(infoColaborador->apellidos);
	
	printf("\nIngrese el correo eletronico del colaborador %d: ", infoColaborador->cantColaboradores);
	gets(infoColaborador->correoElectronico);	
    
    printf("\nIngrese el rol en la organizacion del colaborador %d: ", infoColaborador->cantColaboradores);
	gets(infoColaborador->rol);	

    printf("\nIngrese la fecha de cumpleaños del colaborador %d: ", infoColaborador->cantColaboradores);
	gets(infoColaborador->fechaCumpleanos);	
	printf("\n");
}

void creacionEInsercionArchTxtC(const ListaC *C, informacionColaborador *infoColaborador)
{
	Nodo *indice;
	FILE *archivo; 
	string ruta;
	strcpy(ruta, ".\\InformacionColaboradores\\");
	
	strcat(ruta, infoColaborador->cedula);
	strcpy(infoColaborador->tipoArchivo, ruta);
	strcat(infoColaborador->tipoArchivo, ".txt");
	
	archivo = fopen(infoColaborador->tipoArchivo, "a+");
	fprintf(archivo,"%s; %s; %s; %s; %s; %s;\n", infoColaborador->cedula, infoColaborador->nombres, infoColaborador->apellidos, infoColaborador->correoElectronico, infoColaborador->rol, infoColaborador->fechaCumpleanos);
}

void registroBitacora(ListaC *C, informacionColaborador *infoColaborador)
{
	Nodo *indice;
	string cedula;
	string descripcion;
	
	printf("Ingrese la cedula del colaborador al que desea agregarle una observacion: ");
	gets(cedula);
	printf("\n");
	
	printf("Ingrese la observacion que desea agregar: ");
	gets(descripcion);
	printf("\n");
	printf(".\n");
	printf(".\n");
	printf(".\n");
	
	indice = C->inicio;

	FILE *archivo; 
	string ruta;
	strcpy(ruta, ".\\InformacionColaboradores\\");
	
	strcat(ruta, cedula);
	strcpy(infoColaborador->tipoArchivo, ruta);
	strcat(infoColaborador->tipoArchivo, ".txt");
	
	archivo = fopen(infoColaborador->tipoArchivo, "a+");
	fprintf(archivo,"%s\n", descripcion);
	
	printf("Se agrego la descripcion exitosamente");
}

void mostrarListaColaboradores(const ListaC *C, informacionColaborador *infoColaborador)
{
	Nodo *i;
	printf("\nLa informacion es: \n");
	for(i = C->inicio; i!= NULL; i = i->siguiente)
	{
		informacionColaborador datoMostrar = i->dato;
		printf("%d\n%s\n%s\n%s\n%s\n%s\n", datoMostrar.cedula, datoMostrar.nombres, datoMostrar.apellidos, datoMostrar.correoElectronico, datoMostrar.rol, datoMostrar.fechaCumpleanos);
	}	
}

void lecturaDatosEquipos(informacionEquipos *infoEquipos)
{
	printf("\nIngrese el nombre del equipo: ");
	gets(infoEquipos->nombre);
	
	printf("\nIngrese la descripcion del equipo: ");
	gets(infoEquipos->descripcion);
	printf("\n");
}

void creacionEInsercionArchTxtE(const ListaE *E, informacionEquipos *infoEquipos)
{
	Nodo *indice;
	FILE *archivo; 
	string ruta;
	strcpy(ruta, ".\\InformacionEquipos\\");
	
	strcat(ruta, infoEquipos->nombre);
	strcpy(infoEquipos->tipoArchivo, ruta);
	strcat(infoEquipos->tipoArchivo, ".txt");
	
	archivo = fopen(infoEquipos->tipoArchivo, "a+");
	fprintf(archivo,"%s\nDescripcion: %s\n", infoEquipos->nombre, infoEquipos->descripcion);
}

void insertarEquipo(ListaE *E, informacionEquipos infoEquipos)
{
	int contador = 0;
	int cantidadEquipos;
	
	printf("¿Cuantos equipos desea agregar? ");
	scanf("%d", &cantidadEquipos);
	getchar();
	
	while(contador < cantidadEquipos)
	{
		lecturaDatosEquipos(&infoEquipos);
		Nodo *n, *aux;
		
		if(E->inicio2 == NULL) //Valida si la lista esta vacia
		{
			E->inicio2 = (Nodo *) malloc(sizeof(Nodo));
			E->inicio2->dato2 = infoEquipos;
			E->inicio2->siguiente = NULL;
		}
		else
		{
			n = E->inicio2;
			while(n != NULL)
			{
				aux = n;
				n = n->siguiente;
			}
			aux->siguiente = (Nodo *) malloc(sizeof(Nodo));
			aux->siguiente->siguiente = NULL;
			aux->siguiente->dato2 = infoEquipos;
		}
		contador++;
		creacionEInsercionArchTxtE(E, &infoEquipos);
	}		
}

void mostrarListaEquipos(const ListaE *E, informacionEquipos *infoEquipos)
{
	Nodo *i;
	printf("\nLa informacion es: \n");
	for(i = E->inicio2; i!= NULL; i = i->siguiente)
	{
		informacionEquipos datoMostrar = i->dato2;
		printf("%s\n%s\n%s\n%s\n", datoMostrar.nombre, datoMostrar.descripcion, datoMostrar.origen, datoMostrar.destino);
	}	
	printf("\n");
}

int tamano(ListaE *E)
{
	Nodo *aux;
	int contador = 0;
	aux = E->inicio2;
	
	while(aux != NULL)
	{
		aux = aux->siguiente;
		contador++;
	}
	printf("Cantidad de equipos: %d", contador);
	return contador;
}

void insercionColabEquipos(const ListaE *E, informacionEquipos *infoEquipos)
{
	FILE *archivo; 
	int cantidadAristas;
	int contador;
	string ruta;
	
	printf("Ingrese la cantidad de conexiones que desea realizar: ");
	scanf("%d", &cantidadAristas);
	getchar();
	printf("\n");
	
	while(contador < cantidadAristas)
	{
		printf("Ingrese el nombre del equipo: ");
		gets(infoEquipos->origen);
		printf("\n");
		
		printf("Ingrese el colaborador o el equipo al cual desea relacionar: ");
		gets(infoEquipos->destino);
		printf("\n");
	
		strcpy(ruta, ".\\InformacionEquipos\\");
		strcat(ruta, infoEquipos->origen);
		strcpy(infoEquipos->tipoArchivo, ruta);
		strcat(infoEquipos->tipoArchivo, ".txt");
		
		archivo = fopen(infoEquipos->tipoArchivo, "a+");
		fprintf(archivo,"%s\n", infoEquipos->destino);
		
		contador++;
	}
}

void infoUnEquipo(ListaE *E, informacionEquipos *infoEquipos)
{	
	FILE *archivo;
	string aux; 
	string ruta;
	string informacionEquipo;
	
	printf("Ingrese el nombre del equipo al cual desea ver la informacion: ");
	gets(informacionEquipo);
	
	strcpy(ruta, ".\\InformacionEquipos\\");
	strcat(ruta, informacionEquipo);
	strcpy(infoEquipos->tipoArchivo, ruta);
	strcat(infoEquipos->tipoArchivo, ".txt");
	
	archivo = fopen(infoEquipos->tipoArchivo, "a+");
	
	while(fgets(aux, 100, archivo))
	{
		printf("%s", aux);
	}
	
	fclose(archivo);
}

void extraerListaEquipos(informacionEquipos *infoEquipos, string lista[])
{	
	int indice = 0;
	while(indice < infoEquipos->tamano)
	{
		printf("%s ", lista[indice]);
		if(strcmp(lista[indice], "Rachel") == 0)
		{
			printf("Si\n");
		}
		else
		{
			printf("No\n");
		}
		indice ++;
	}
}

void extraerInfoTxt(informacionEquipos *infoEquipos)
{
	FILE *archivo = NULL; 
	
	string listaEquipos[100];
	infoEquipos->tamano = 0;
	int indice = 0;
	char linea[300];
	char *delimitador = "\n";
	char *token = NULL;
	
	string ruta;
	strcpy(ruta, ".\\InformacionEquipos\\Biblioteca");
	
	strcpy(infoEquipos->tipoArchivo, ruta);
	strcat(infoEquipos->tipoArchivo, ".txt");
	
	archivo = fopen(infoEquipos->tipoArchivo, "a+");
	
	if(archivo)
	{
		while(fgets(linea, 300, archivo))
		{
   			token = strtok(linea, delimitador);
   			while( token != NULL ) 
			{
      			printf("%s\n", token);
      			strcpy(listaEquipos[indice], token);
      			infoEquipos->tamano++;
      			indice++;
    
      			token = strtok(NULL, delimitador);
   			}
		}
		fclose(archivo);
	}
	extraerListaEquipos(infoEquipos, listaEquipos);
}

bool vacio()
{
	if(inicioG == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void insertarLugaresAdy(informacionEtiquetas infoEtiquetas);
void insercionRutas(informacionEtiquetas *infoEtiquetas);

void creacionEInsercionArchTxtD(const grafo *G, lugaresDeDomicilio *infoDomicilios)
{
	Nodo *indice;
	FILE *archivo; 
	string ruta;
	strcpy(ruta, ".\\InformacionDomicilios\\");
	
	strcat(ruta, infoDomicilios->lugar);
	strcpy(infoDomicilios->tipoArchivo, ruta);
	strcat(infoDomicilios->tipoArchivo, ".txt");
	
	archivo = fopen(infoDomicilios->tipoArchivo, "a+");
	fprintf(archivo,"%d; %s; %d\n", infoDomicilios->codigo, infoDomicilios->lugar, infoDomicilios->codigoPostal);
}

void insercionVerticesTxt(lugaresDeDomicilio *infoDomicilios)
{
	FILE *archivo; 
	string ruta;
	strcpy(ruta, ".\\InformacionDomicilios\\Lugares");
	
	strcpy(infoDomicilios->tipoArchivo, ruta);
	strcat(infoDomicilios->tipoArchivo, ".txt");
	
	archivo = fopen(infoDomicilios->tipoArchivo, "a+");
	fprintf(archivo,"%s\n", infoDomicilios->lugar);
}

void lecturaDatosDomicilio(lugaresDeDomicilio *infoDomicilios)
{
		printf("\nIngrese el codigo: ");
		scanf("%d", &infoDomicilios->codigo);
		getchar();
	
		printf("\nIngrese el nombre del lugar: ");
		gets(infoDomicilios->lugar);
	
		printf("\nIngrese el codigo postal: ");
		scanf("%d", &infoDomicilios->codigoPostal);
		getchar();
		printf("\n");
}	

void insertarDomicilios(grafo *G, lugaresDeDomicilio infoDomicilios)
{
	int contador = 0;
	int cantidadDomicilios;
	
	printf("¿Cuantos lugares de domicilio desea agregar? ");
	scanf("%d", &cantidadDomicilios);
	getchar();
	
	while(contador < cantidadDomicilios)
	{
		lecturaDatosDomicilio(&infoDomicilios);
		vertice *nuevo = (vertice *)malloc(sizeof(vertice));
		nuevo->datosDomicilio = infoDomicilios;
		nuevo->siguiente = NULL;
		nuevo->ady = NULL;

		if(vacio())
		{
			inicioG = nuevo;
		}
		else
		{
			vertice *aux;
			aux = inicioG;
			while(aux->siguiente != NULL)
			{
				aux = aux->siguiente;
			}
			aux->siguiente = nuevo;
		}
		contador++;
		creacionEInsercionArchTxtD(G, &infoDomicilios);
		insercionVerticesTxt(&infoDomicilios);
	}
}

void cargarListaDom(grafo *G, lugaresDeDomicilio *infoDomicilios, string nombre)
{
	vertice *nuevo = (vertice *)malloc(sizeof(vertice));
	strcpy(nuevo->datosDomicilio.lugar, nombre);
	nuevo->siguiente = NULL;
	nuevo->ady = NULL;
	
	if(vacio())
	{
		inicioG = nuevo;
	}
	else
	{
		vertice *aux;
		aux = inicioG;
		while(aux->siguiente != NULL)
		{
			aux = aux->siguiente;
		}
		aux->siguiente = nuevo;
	}
}

void extraerInfoTxtL(grafo *G, lugaresDeDomicilio *infoDomicilios)
{
	FILE *archivo = NULL; 
	Nodo *n, *aux;
	infoDomicilios->tamano = 0;
	int indice = 0;
	char linea[300];
	char *delimitador = "\n";
	char *token = NULL;
	
	string ruta;
	strcpy(ruta, ".\\InformacionDomicilios\\Lugares");
	
	strcpy(infoDomicilios->tipoArchivo, ruta);
	strcat(infoDomicilios->tipoArchivo, ".txt");
	
	archivo = fopen(infoDomicilios->tipoArchivo, "a+");
	
	if(archivo)
	{
		while(fgets(linea, 300, archivo))
		{
   			token = strtok(linea, delimitador);
   			while( token != NULL ) 
			{
      			//printf("%s\n", token);
      			cargarListaDom(G, infoDomicilios, token);
      			infoDomicilios->tamano++;
      			indice++;
    
      			token = strtok(NULL, delimitador);
   			}
		}
		fclose(archivo);
	}
}

vertice *getVertice(string nombre)
{	
	vertice *aux;
	aux = inicioG;

	while(aux != NULL)
	{
		if(strcmp(aux->datosDomicilio.lugar, nombre) == 0)
		{
			return aux;
		}
		aux = aux->siguiente;
	}
	return NULL;
}

void insercionRutas(informacionEtiquetas *infoEtiquetas)
{	
	printf("Ingrese el lugar de origen: ");
	gets(infoEtiquetas->origen);
	
	printf("Ingrese el lugar de destino: ");
	gets(infoEtiquetas->destino);
	
	printf("Ingrese el tiempo estimado en minutos: ");
	scanf("%d", &infoEtiquetas->tiempoEnMinutos);
	
	printf("Ingrese la distancia en kilometros: ");
	scanf("%d", &infoEtiquetas->distancia);
	getchar();
	
	printf("Ingrese el tipo de ruta (terrestre, aerea o maritima): ");
	gets(infoEtiquetas->tipoRuta);
	printf("\n");
}

void insertarLugaresAdy(informacionEtiquetas infoEtiquetas)
{
	int cantRutas;
	int contador = 0;
	
	printf("¿Cuantas rutas desea agregar? ");
	scanf("%d", &cantRutas);
	getchar();
	printf("\n");
	
	while(contador < cantRutas)
	{
		insercionRutas(&infoEtiquetas);
		
		vertice *origen = getVertice(infoEtiquetas.origen);
		vertice *destino = getVertice(infoEtiquetas.destino);
		
		arista *nueva = (arista *)malloc(sizeof(arista));
		nueva->datosEtiquetas = infoEtiquetas;
		nueva->siguiente = NULL;
		nueva->ady = NULL;
		
		arista *aux;
		aux = origen->ady;
	
		if(aux == NULL)
		{
			origen->ady = nueva;
			nueva->ady = destino;
		}
		else
		{
			while(aux->siguiente != NULL)
			{
				aux = aux->siguiente;
			}
			aux->siguiente = nueva;
			nueva->ady = destino;
		}
		contador++;
	}
}

void listaAdyacencia(informacionEtiquetas *infoEtiquetas)
{
	printf("Lista de adyacencia");
	FILE *archivo; 
	vertice *vertAux;
	arista *arisAux;
	string ruta;
	
	vertAux = inicioG;
	
	while(vertAux != NULL)
	{
		printf("\n%s -> ", vertAux->nombre);
		arisAux = vertAux->ady;
		while(arisAux != NULL)
		{
			printf("%s -> ", arisAux->ady->datosDomicilio.lugar);
			printf("%d ", arisAux->datosEtiquetas.tiempoEnMinutos);
			printf("%d ", arisAux->datosEtiquetas.distancia);
			printf("%s ", arisAux->datosEtiquetas.tipoRuta);
			
			strcpy(ruta, ".\\InformacionDomicilios\\");
			strcat(ruta, vertAux->datosDomicilio.lugar);
			strcpy(infoEtiquetas->tipoArchivo, ruta);
			strcat(infoEtiquetas->tipoArchivo, ".txt");
		
			archivo = fopen(infoEtiquetas->tipoArchivo, "a+");
			fprintf(archivo,"%s; %d; %d; %s\n", arisAux->ady->datosDomicilio.lugar, arisAux->datosEtiquetas.tiempoEnMinutos, arisAux->datosEtiquetas.distancia, arisAux->datosEtiquetas.tipoRuta);
			
			arisAux = arisAux->siguiente;
		}
		vertAux = vertAux->siguiente;
		printf("\n");
	}
}

int main()
{
    ListaC *C;
	C = listaColaborador();
	informacionColaborador infoCo;
	
	ListaE *E;
	E = listaEquipos();
	informacionEquipos infoEq;
	
	grafo *G;
	
	lugaresDeDomicilio infoDom;
	informacionEtiquetas infoE;
	
    //insertarColaborador(C, infoCo);
    //mostrarListaColaboradores(C, &infoCo);
	//registroBitacora(C, &infoCo);
    
    //insertarEquipo(E, infoEq);
    //insercionColabEquipos(E, &infoEq);
    //mostrarListaEquipos(E, &infoEq);
    //infoUnEquipo(E, &infoEq);
    //tamano(E);
    
    //insertarDomicilios(G, infoDom);
    //extraerInfoTxtL(G, &infoDom);
    //insertarLugaresAdy(infoE);
    //listaAdyacencia(&infoE);
    
    //extraerInfoTxt(&infoEq);
    
    return 0;
}
