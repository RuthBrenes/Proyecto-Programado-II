#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Nodo Nodo;
typedef struct ListaC ListaC;
typedef struct ListaE ListaE;
typedef char string[200];

typedef struct{
    int cedula;
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
}informacionEquipos;

typedef struct{
	int codigo;
	string lugar;
	string codigoPostal;
}lugaresDeDomicilio;

typedef struct{
	string lugarOrigen;
	string lugarDestino;
	int tiempoEnMinutos;
	int distancia;
	string tipoRuta;
}informacionRutas;

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

void lecturaDatosInfoCo(informacionColaborador *infoColaborador);
void creacionEInsercionArchTxtC(const ListaC *C, informacionColaborador *infoColaborador);


void insertarColaborador(ListaC *C, informacionColaborador infoColaborador)
{
	int contador = 0;
	int cantidadColab;

	printf("¿Cuantos colaboradores desea agregar? ");
	scanf("%d", &cantidadColab);
	
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
	scanf("%d",&infoColaborador->cedula);
	getchar();
	
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
	strcpy(ruta, "C:\\Users\\Ruth\\Desktop\\PP2\\InformacionColaboradores\\");
	
	strcat(ruta, infoColaborador->nombres);
	strcpy(infoColaborador->tipoArchivo, ruta);
	strcat(infoColaborador->tipoArchivo, ".txt");
	
	archivo = fopen(infoColaborador->tipoArchivo, "a+");
	fprintf(archivo,"%d; %s; %s; %s; %s; %s;\n", infoColaborador->cedula, infoColaborador->nombres, infoColaborador->apellidos, infoColaborador->correoElectronico, infoColaborador->rol, infoColaborador->fechaCumpleanos);
}

void registroBitacora(ListaC *C, informacionColaborador *infoColaborador)
{
	Nodo *indice;
	int cedula;
	
	printf("Ingrese la cedula del colaborador al que desea agregarle una observacion: ");
	scanf("%d", &cedula);
	getchar();
	printf("\n");
	
	printf("Ingrese la observacion que desea agregar: ");
	gets(infoColaborador->descripcion);
	
	indice = C->inicio;

	while(indice != NULL)
	{
		if(indice->dato.cedula == cedula)
		{
			FILE *archivo; 
			string ruta;
			strcpy(ruta, "C:\\Users\\Ruth\\Desktop\\PP2\\InformacionColaboradores\\");
	
			strcat(ruta, indice->dato.nombres);
			strcpy(infoColaborador->tipoArchivo, ruta);
			strcat(infoColaborador->tipoArchivo, ".txt");
	
			archivo = fopen(infoColaborador->tipoArchivo, "a+");
			fprintf(archivo,"%s\n", infoColaborador->descripcion);
		}
		indice = indice->siguiente;
	}
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
	strcpy(ruta, "C:\\Users\\Ruth\\Desktop\\PP2\\InformacionEquipos\\");
	
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

void insercionAristas(const ListaE *E, informacionEquipos *infoEquipos)
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
	
		strcpy(ruta, "C:\\Users\\Ruth\\Desktop\\PP2\\InformacionEquipos\\");
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
	
	strcpy(ruta, "C:\\Users\\Ruth\\Desktop\\PP2\\InformacionEquipos\\");
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

int main()
{
    ListaC *C;
	C = listaColaborador();
	informacionColaborador infoCo;
	
	ListaE *E;
	E = listaEquipos();
	informacionEquipos infoEq;
	
	
    //insertarColaborador(C, infoCo);
    //mostrarListaColaboradores(C, &infoCo);
	//registroBitacora(C, &infoCo);
    
    //insertarEquipo(E, infoEq);
    //insercionAristas(E, &infoEq);
    //mostrarListaEquipos(E, &infoEq);
    //infoUnEquipo(E, &infoEq);
    //tamano(E);
    
    return 0;
}
