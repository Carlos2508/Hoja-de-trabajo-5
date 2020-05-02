/*EJERCICIO#2
Realice un programa que, dado el peso, la altura, la edad y el género (M/F) de un grupo de N personas
que pertenecen a un departamento de la república, obtenga un promedio de peso, altura y edad de esta
población. Los datos deben guardarse de forma ordenada por edad en un archivo de datos. Así mismo
el programa debe ser capaz leer los datos del archivo y generar un reporte con la media del peso, altura
y la edad.*/


#include <iostream>
#include <string>
#include <fstream>

using namespace std;
struct promedio{
	float edad;
	float altura;
	float peso;
	string genero;
};
struct emp
{
	int num ; //clave de ordenamiento
	string name ;
	string age ;
	string bs ;
};

void bubbleSort(emp list[], int tam);


int main(){
	float peso, altura;
	float edad;
	float mpeso=0, maltura=0,medad=0, n=0;
	string genero;
	cout<<"Ingrese el peso en lbs: "<<endl;
	cin>>peso;
	cout<<"Ingrese la altura en metros: "<<endl;
	cin>>altura;
	cout<<"Ingrese la edad: "<<endl;
	cin>>edad;
	cout<<"Ingrese el genero de la persona (M-masculino//F-femenino): "<<endl;
	cin>>genero;
	
	
	ofstream archivo; 
	archivo.open("media.txt",ios::app);
	archivo<<edad<<"\t"<<peso<<"\t"<<altura<<"\t"<<genero<<endl;
	archivo.close();

/*	ifstream archivo; //leer archivo 
	archivo.open("media.txt",ios::in);
	cout << "---------------------------------------------" << endl;
	cout << "EDAD"<< "\t" << "PESO" << "\t" << "ALTURA"<< "\t"<< "GENERO"<< endl;
	cout << "---------------------------------------------" << endl; 
	int lineas,i=0;
	string s,linea;	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1); //break;
	}
	while (getline(archivo, s))
        lineas++;
	archivo.close();
	
	promedio recordset[lineas];
	
	archivo.open("media.txt",ios::in);
		if(archivo.fail()){
		cout<<"No se pudo abrir el archivo!!!";
		exit(1);
	}	

	for (int i = 0; i < lineas; i++)
    {
        if (!archivo)
        {                                               
            cerr << "No se puede abrir el archivo " << endl;
            system("PAUSE");
        }
        archivo>>recordset[i].edad>>recordset[i].peso>>recordset[i].altura>>recordset[i].genero;
    }
    archivo.close(); 
	ifstream fp;
    string Tmp;
	fp.open("media.txt");
	emp emp_array[5];

	if (fp)
	{	
   		for (int counter = 0; counter < 3; counter++)
    	{
        	fp >> emp_array[counter].num;
        	fp >> emp_array[counter].name;
        	fp >> emp_array[counter].age;
        	fp >> emp_array[counter].bs;
    	}
	}
	else
    	puts("error"); //

	bubbleSort(emp_array, 5);
                
	for (int counter = 0; counter < 3; counter++)
	{
   	 	cout << emp_array[counter].num << "\t";
   	 	cout << emp_array[counter].name << "\t";
   	 	cout << emp_array[counter].age << "\t";
  	  	cout << emp_array[counter].bs << endl;
	}	
	for(int i = 0; i < lineas; i++){
		mpeso+=recordset[i].peso;
        medad+=recordset[i].edad;
        maltura+=recordset[i].altura;
        n= n+1;
	}
	cout<<"La media de la edad es de: "<<endl;
	cout<<medad/n<<endl;
	cout<<"La media del peso es de: "<<endl;
	cout<<mpeso/n<<endl;	
	cout<<"La media de la altura es de: "<<endl;
	cout<<maltura/n<<endl;	
	system("PAUSE");	
*/
}

void bubbleSort(emp list[], int tam){
    emp temp;
    int i;
    int index;
    for (i = 1; i < tam; i++)
    {
     	//cout<<"i: posicion actual antes"<<list[i].num<<endl;
	    for (index = 0; index < tam - i; index++)
            if (list[index].num > list[index + 1].num)
            {
            	//cout<<"Posicion de intercambio:  "<<endl;
                temp = list[index];
                //cout<<"var temp"<<temp.num<<endl;
                list[index] =  list[index + 1];
                cout<< list[index+1].num<<endl;
                list[index + 1] =  temp;
            }
        //cout<<"i: posicion actual despues"<<list[i].num<<endl;
    }
}


