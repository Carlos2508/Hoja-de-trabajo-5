/*HOJA DE TRABAJO #5
EJERCICIO # 1
En una librería se venden 4 modelos diferentes de cuadernos, con los siguientes precios:
? Modelo#1 – Q10.00
? Modelo#2 – Q15.00
? Modelo#3 – Q18.50
? Modelo#4 – Q25.00
Por otra parte, se tiene información sobre las ventas realizadas durante los últimos 30 días, estos
movimientos se deben de guardar en un archivo de la siguiente forma:
DIA1,MOD,CANT
DIA2,MOD,CANT
.
.
.
DIA30,MODELO,CANTIDAD
DIAi = Variable que representa el día que se efectuó la venta i (1 - 30)
MOD= Variable que representa código de Modelo que se vendió. (1 – 4)
CANT= Variable que representa la cantidad de unidades vendidas.
El programa debe ser capaz de:
? Modificar el número de unidades vendidas, solicitando al usuario el día y código de articulo
(modificación del archivo)
? Eliminación de un día especifico de venta (modificación del archivo)
? Calcular el total recaudado por modelo en los 30 días.
? Calcular cuál fue el modelo que se vendió mas en los 30 días 
*/


#include <fstream>
#include <iostream>
#include <string>
#include <sstream> 
#include <regex>
#include <iomanip> 

using namespace std;
void insert_data_db();
void mp();
void leer_data_db();
void eliminar();
void modificar();
/*struct estudiante {
	int id;
	string nombre;
	float nota;	
};*/

int main(){	
	mp();
	//return 0;	
}
void mp(){
	int resp;
	//string nombrearchivo;
	//cout<<"Indique nombre de archivo: ";
	//getline(cin,nombrearchivo);
	
	do {
		system("CLS");
		cout<<"--------------------------"<<"\n";
		cout<<" Menu Principal"<<"\n";
		cout<<"-------------------"<<"\n";
		cout<<" 1 - Ingresar Venta "<<"\n";
		cout<<" 2 - Reporte "<<"\n";
		cout<<" 3 - Eliminar Venta"<<"\n";
		cout<<" 4 - Modificar Venta"<<"\n";
		cout<<" 5 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			insert_data_db();			
		}
		else if (resp==2){		
			system("CLS");
			leer_data_db();
		}
		else if (resp==3){		
			system("CLS");
			eliminar();	
		}			
		else if (resp==4){
			system("CLS");
			modificar();
		}
		else if (resp==5)
			break;
		else 
			break;
		
	} while(resp!=5);	
}

void insert_data_db(){
	//declaracion de variables
	int diai;
	int mod;
	int cant;
	ofstream db;

	system("CLS");
	//Ingreso de datos
	cout<<"*** Ingreso de Dias de cada venta ***\n\n";
	cout<<"Indique el día de la venta (1-30): "<<endl;
	cin>>diai;
	//cin.ignore();
	fflush(stdin);
	cout<<"Indique el modelo de la venta: "<<endl;
	cout<<"1*Modelo – Q10.0"<<endl;
	cout<<"2*Modelo – Q15.00"<<endl; 
	cout<<"3*Modelo – Q18.50"<<endl;
	cout<<"4*Modelo – Q25.00 "<<endl;
	cin>>mod;
	fflush(stdin);	
	cout<<"Indique la cantidad de la venta:         "<<endl;
	cin>>cant;

	//Insercion de datos a un archivo
	try {
		db.open("ventasdias.txt",ios::app);
		db<<"\t"<<diai<<"\t"<<mod<<"\t"<<cant<<endl;   //"|"
		db.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
		system("Pause");
	}	
}
void leer_data_db(){
	//declaracion de variables
	int oid,i,mayorid,maximo;
	string onombre;
	float onota, cant1=0,cant2=0,cant3=0,cant4=0;	
	string linea;
	float suma= 0;
	float modelo1=0,modelo2=0, modelo3=0, modelo4=0;
	
	
	ifstream db;	
	try{
		db.open("ventasdias.txt",ios::in);	

		cout<<"Datos del archivo:"<<endl;
		cout<<" Día|"<<"      Mod      |"<<"Cant|"<<endl;		
		while (db>>oid>>onombre>>onota){
			cout<<oid<<"\t"<<"\t"<<onombre<<"\t"<<onota<<endl;
			i++;					
			suma+=onota;
//			system("Pause");
			if (onombre=="1"){
				modelo1+=1;
				cant1+=onota;
			}

			if (onombre=="2"){
				modelo2+=1;
				cant2+=onota;
			}

			if (onombre=="3"){
				modelo3+=1;	
				cant3+=onota;
			}
			if (onombre=="4"){
				modelo4+=1;
				cant4+=onota;
			}
			
	
		}
				
		db.close();	
		
		cout<<"\nTotal vendido: "<<suma<<endl;
			 
		int n1,n2,n3,n4,maximo;
		n1=modelo1;
		n2=modelo2;
		n3=modelo3;
		n4=modelo4;
		 
		maximo=n1;
		  
		if(maximo<n2){
		maximo=n2;
		}
		if(maximo<n3){
		maximo=n3;
		}
		if(maximo<n4){
		maximo=n4;
		}
		cout<<"El modelo mas vendido en los 30 dias es el: Modelo#"<<maximo<<endl;
		cout<<"El modelo#1 con una cantidad vendida de: "<<cant1<<" Por un costo total de: Q"<<cant1*10<<endl;		 
		cout<<"El modelo#2 con una cantidad vendida de: "<<cant2<<" Por un costo total de: Q"<<cant2*15<<endl;
		cout<<"El modelo#3 con una cantidad vendida de: "<<cant3<<" Por un costo total de: Q"<<cant3*18.50<<endl;
		cout<<"El modelo#4 con una cantidad vendida de: "<<cant4<<" Por un costo total de: Q"<<cant4*25<<endl;
					 
		system("Pause");
	}
	catch(exception& X){
		cout<<"Error en la manipulacion del archivo"<<endl;
		cout<<"Error: "<<X.what()<<endl;
		system("Pause");
	}
	
}

void eliminar(){
	ifstream db_a; //archivo anterior
	ofstream db_n; //archivo nuevo
	int aux,oid,onota,flag;
	string onombre;
	remove("Temporal.txt");
	
	db_a.open("ventasdias.txt",ios::in);
	db_n.open("Temporal.txt",ios::app);
	
	cout<<"Ingrese ID que desea borrar: "<<endl;
	cin>>aux;
	
	while (db_a>>oid>>onombre>>onota){
		if(aux==oid){
			cout<<"Registro Eliminado...."<<endl;
			flag =1;
		}			
		else if(aux!=oid)
			db_n<<onombre<<"\t"<<oid<<"\t"<<onota<<endl;
		//aux=0;
		//oid=0;					
	}
	db_a.close();
	db_n.close();
	
	if (flag==1){
		remove("ventasdias.txt");
		rename("Temporal.txt","ventasdias.txt");
	}	
	system("Pause");
}

void modificar(){
	ifstream db_a; //archivo anterior
	ofstream db_n; //archivo nuevo
	int aux,oid,onota,flag,inota;
	string onombre;
	char respuesta;
	remove("Temporal.txt");
	
	db_a.open("ventasdias.txt",ios::in);
	db_n.open("Temporal.txt",ios::app);
	
	cout<<"Ingrese el dia de la venta del que modificara informacion: "<<endl;
	cin>>aux;
	do {
		cout<<"Ingrese Cantidad a modificar: "<<endl;
		cin>>inota;
		cout<<"\n\nEsta Seguro? Si/No:  ";
		cin>>respuesta;
		cout<<"\n"<<endl;
		respuesta = toupper(respuesta);		
	} while (respuesta!='SI');	
	
	//leer archivo anterior
	while (db_a>>oid>>onombre>>onota){
		if(aux==oid){
			db_n<<oid<<"\t"<<onombre<<"\t"<<inota<<endl;
			cout<<"Archivo Actualizado...."<<endl;
			flag =1;
		}			
		else if(aux!=oid)
			db_n<<oid<<"\t"<<onombre<<"\t"<<onota<<endl;
		//aux=0;
		//oid=0;					
	}
	db_a.close();
	db_n.close();
	
	if (flag==1){
		remove("ventasdias.txt");
		rename("Temporal.txt","ventasdias.txt");
	}	
	system("Pause");
}
