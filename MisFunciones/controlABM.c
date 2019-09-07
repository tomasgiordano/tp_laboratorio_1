#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#define ELEMENTS 1000
#define S 4

                 ////////////////
                //TP FUNCTIONS//
               ////////////////


/** \brief  Inicializa todas las posiciones de la lista de Empleados
*           como vacias. Y ademas, le asigna un id diferente a cada posicion.(autoincremental)
*
* \param    eEmployee list[]
* \param    int len
* \return   (void)
*
*/
void initEmployee(eEmployee list[],int len)
{
    int i;

    for(i=0;i<len;i++)
    {
        list[i].isEmpty=1;
        list[i].id=i+1;
    }

}
/**\brief Agrega un empleado a la lista en el primer espacio vacio que encuentre, retorna 0 si
*           se pudo agregar, o -1 si no hay mas espacio.
*
* \param    eEmployee list[]
* \param    int len
* \param    char name[]
* \param    char lastName[]
* \param    float salary
* \param    int sector
*
* \return   int space(-1 o 0)
*
*/
int addEmployee(eEmployee list[], int len, char name[],char lastName[],float salary,int sector)
{
    int i;
    int space=-1;

    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==1)
        {
            strncpy(list[i].name,name,51);
            strncpy(list[i].lastName,lastName,51);
            list[i].salary=salary;
            list[i].idSector=sector;

            list[i].isEmpty=0;

            toUpperFirstLetter(list,len,i);

            space=0;
            break;
        }
    }

    return space;
}
/**\brief   Busca un id especifico en la lista y devuelve en que posicion de la lista esta y si no es
*           una posicion ocupada por ningun cliente, devuelve -1.
*
* \param    eEmployee list[]
* \param    int len
* \param    int id
*
* \return   int indexPosition
*/
int findEmployeeById(eEmployee list[], int len,int id)
{
    int i;
    int indexPosition=-1;

    for(i=0;i<len;i++)
    {
        if(list[i].id==id && list[i].isEmpty==0)
        {
            indexPosition=i;
            break;
        }
    }

    return indexPosition;
}
/**\brief  Pone un empleado como "posicion vacia", pudiendo ser reescrita.
*          (Elimina un empleado de la lista). Si la posicion no tiene ningun empleado, devuelve 0.
*          De lo contrario, 1.
*
* \param    eEmployee list[]
* \param    int len
* \param    int id
*
* \return   int success
*
*/
int removeEmployee(eEmployee list[], int len, int id)
{
    int find=findEmployeeById(list,len,id);
    int securityOpction;
    int success=0;

    if(find!=-1)
    {
        success=1;
        printf("Esta seguro que quiere eliminar al empleado | %s, %s | ?\n 1)Estoy seguro.\n 2)Volver.\n Ingrese una opcion: ",list[find].lastName,list[find].name);
        scanf("%d",&securityOpction);
        switch(securityOpction)
        {
            case 1:
                list[find].isEmpty=1;
                printf("\nEmpleado eliminado de la lista con exito!\n\n");
            break;
            case 2:
                printf("\nVolviendo...\n\n");
            break;
            default:
                printf("\nERROR. Opcion no valida.\n\n");
            break;
        }
    }

    return success;
}

/** \brief Ordena la lista de los empleados primero por sector, luego alfabeticamente por apellido
*           de manera ascendente utilizando una copia de la estructura eEmpleado para "burbujear".
*
* \param    eEmployee list[]
* \param    int lenE
* \param    eEmployee copy[]
*
* \return   (void)
*
*/

void sortEmployees(eEmployee list[], int lenE,eEmployee copy[])
{
    int i;
    int j;
    int comp;
    //comp=stricmp(list[i].lastName,list[j].lastName);

    for(i=0;i<lenE;i++)
    {
        for(j=i+1;j<lenE;j++)
        {
            comp=stricmp(list[i].lastName,list[j].lastName);

            if(list[i].idSector>list[j].idSector)
            {
                copy[0].id=list[i].id;
                copy[0].idSector=list[i].idSector;
                strcpy(copy[0].lastName,list[i].lastName);
                strcpy(copy[0].name,list[i].name);
                copy[0].salary=list[i].salary;
                copy[0].isEmpty=list[i].isEmpty;

                list[i].id=list[j].id;
                list[i].idSector=list[j].idSector;
                strcpy(list[i].lastName,list[j].lastName);
                strcpy(list[i].name,list[j].name);
                list[i].salary=list[j].salary;
                list[i].isEmpty=list[j].isEmpty;

                list[j].id=copy[0].id;
                list[j].idSector=copy[0].idSector;
                strcpy(list[j].lastName,copy[0].lastName);
                strcpy(list[j].name,copy[0].name);
                list[j].salary=copy[0].salary;
                list[j].isEmpty=copy[0].isEmpty;
            }
            else if(comp>0&&list[i].idSector==list[j].idSector)
            {
                copy[0].id=list[i].id;
                copy[0].idSector=list[i].idSector;
                strcpy(copy[0].lastName,list[i].lastName);
                strcpy(copy[0].name,list[i].name);
                copy[0].salary=list[i].salary;
                copy[0].isEmpty=list[i].isEmpty;

                list[i].id=list[j].id;
                list[i].idSector=list[j].idSector;
                strcpy(list[i].lastName,list[j].lastName);
                strcpy(list[i].name,list[j].name);
                list[i].salary=list[j].salary;
                list[i].isEmpty=list[j].isEmpty;

                list[j].id=copy[0].id;
                list[j].idSector=copy[0].idSector;
                strcpy(list[j].lastName,copy[0].lastName);
                strcpy(list[j].name,copy[0].name);
                list[j].salary=copy[0].salary;
                list[j].isEmpty=copy[0].isEmpty;
            }
        }
    }
}


/**\brief Imprime toda la lista de los empleados
*
* \param
* \param
*
* \return
*
*/

void printEmployees(eEmployee list[],int lenE,eSector sectors[],int lenS)
{
    int i;
    for(i=0;i<lenE;i++)
    {
        if(list[i].isEmpty==0)
        {
            printOneEmployee(list,lenE,sectors,lenS,i);
        }
    }
}




                 /////////////////////
                //ANOTHER FUNCTIONS//
               /////////////////////




/** \brief  Modifica el nombre de un empleado en la lista
 *
 * \param   eEmpleado list[]
 * \param   int len
 * \param   int position
 *
 * \return  (void)
 *
 */

void modifyNameEmployee(eEmployee list[],int len, int position)
{
    char newName[51];
    fflush(stdin);

    printf("Ingrese el nuevo NOMBRE del empleado |%s,%s|: ",list[position].lastName,list[position].name);
    fgets(newName,51,stdin);
    newName[strlen(newName)-1]='\0';

    strcpy(list[position].name,"");
    strcat(list[position].name,newName);

    printf("\nNombre modificado exitosamente!\n");
}

/** \brief Modifica el apellido de un empleado
 *
 * \param   eEmployee list[]
 * \param   int len
 * \param   int position
 *
 * \return  (void)
 *
 */

void modifyLastNameEmployee(eEmployee list[],int len, int position)
{
    char newLastName[51];
    fflush(stdin);

    printf("Ingrese el nuevo APELLIDO del empleado |%s,%s|: ",list[position].lastName,list[position].name);
    fgets(newLastName,51,stdin);
    newLastName[strlen(newLastName)-1]='\0';

    strcpy(list[position].lastName,"");
    strcat(list[position].lastName,newLastName);

    printf("\nApellido modificado exitosamente!\n\n");
}

/** \brief  Modifica el salario de un empleado
 *
 * \param   eEmployee list[]
 * \param   int len
 * \param   int position
 *
 * \return  (void)
 *
 */

void modifySalaryEmployee(eEmployee list[],int len, int position)
{
    int newSalary;

    printf("Ingrese el nuevo SALARIO del empleado |%s,%s|: $",list[position].lastName,list[position].name);
    scanf("%d",&newSalary);

    list[position].salary=newSalary;

    printf("\nSalario modificado exitosamente!\n\n");
}

/** \brief  Modifica el sector de un empleado
 *
 *  \param   eEmployee list[]
 *  \param   int len
 *  \param   int position
 *  \param   eSector sectors[]
 *  \param   int lenS
 *
 * \return   (void)
 *
 */

void modifySectorEmployee(eEmployee list[],int lenE, int position,eSector sectors[],int lenS)
{
    int newSector;

    printf("Ingrese el nuevo SECTOR del empleado |%s,%s|:\n",list[position].lastName,list[position].name);
    newSector=validateSector(sectors,lenS);
    list[position].idSector=newSector;

    printf("\nSector modificado exitosamente!\n\n");
}

/** \brief  Valida si el sector ingresado esta en la lista de sectores validos. Y cuando
 *              se ingresa uno valido, lo devuelve(id del sector).
 *
 * \param   eSector sectors[]
 * \param   int lenS
 *
 * \return  int sector
 *
 */

int validateSector(eSector sectors[],int lenS)
{
    int sector;
    int i;

    for(i=0;i<lenS;i++)
    {
        printf("%d)%s\n",sectors[i].idSector,sectors[i].descripcion);
    }
    printf("Sector: ");
    scanf("%d",&sector);

    while(sector>lenS || sector<=0)
    {
        printf("ERROR. Sector no valido, ingrese nuevamente el sector: ");
        scanf("%d",&sector);
    }
    return sector;
}

/** \brief  Imprime un solo empleado de una posicion en especifica.
 *
 * \param   eEmployee list[]
 * \param   int lenE
 * \param   eSector sectors[]
 * \param   int lenS
 * \param   int position
 *
 * \return  (void)
 *
 */

void printOneEmployee(eEmployee list[],int lenE,eSector sectors[],int lenS,int position)
{
    int sectorDescription;
    sectorDescription=searchSectorDescription(list,sectors,lenS,position);

    printf("\t%d\t%s, %s\t\t $%.2f\t%s\n",list[position].id,list[position].lastName,list[position].name,list[position].salary,sectors[sectorDescription].descripcion);
}

/** \brief  Busca la descripcion del sector segun el id sector del empleado. Devuelve la posicion de "sectors" en la que
 *           esta la descripcion del sector que le pertenece al idsector del empleado.
 *
 * \param   eEmployee list[]
 * \param   eSector sectors[]
 * \param   int lenS
 * \param   int position
 *
 * \return  int i
 *
 */

 int searchSectorDescription(eEmployee list[],eSector sectors[],int lenS,int position)
 {
    int i;

    for(i=0;i<lenS;i++)
    {
        if(list[position].idSector==sectors[i].idSector)
        {
            break;
        }
    }
    return i;
 }

/** \brief Hace mayuscula la primer letra de una palabra y vuelve minusculas todas las demas
 *
 * \param   eEmployee list[]
 * \param   int len
 * \param   int position
 *
 * \return  (void)
 *
 */

 void toUpperFirstLetter(eEmployee list[],int len,int position)
 {
    int i;

    list[position].name[0]=toupper(list[position].name[0]);
    for(i=1;i<51;i++)
    {
        list[position].name[i]=tolower(list[position].name[i]);
    }

    list[position].lastName[0]=toupper(list[position].lastName[0]);
    for(i=1;i<51;i++)
    {
        list[position].lastName[i]=tolower(list[position].lastName[i]);
    }

 }

 /** \brief Hardcodea una lista de 20 empleados
  *
  * \param  eEmployee list[]
  * \param  int tam
  *
  * \return (void)
  *
  */

void hardcodeEmployeeList(eEmployee list[],int tam)
{
    int i;

    char names[][51]= {"Carlos","Maria","Valent","Pedro","Tomas","Mateo","Martin","Tony","Steve","Bruce","Ricardo","Silvina","Martin","Berto","Steve","Shir","Lionel","Zoe","Samuel","Milena"};
    char lastNames[][51]= {"Adalf","Giordano","Brunet","Arnaldo","Castel","Bondar","Aster","Stark","Rogers","Banner","Fort","Luna","Perez","Einstein","Jobs","Khan","Messi","Ronaldo","Isma","Kocmur"};
    float salary[]= {22000,22000,15000,4000,21000,6000,9000,6000,8000,11000,8000,21000,4000,9000,6000,4000,12000,8000,31000,24000,35000};
    int sector[]={1,2,3,4,1,2,3,4,2,1,3,4,2,1,2,4,1,3,4,1};

    for(i=0; i<tam; i++)
    {
        strcpy(list[i].name, names[i]);
        strcpy(list[i].lastName, lastNames[i]);
        list[i].salary = salary[i];
        list[i].isEmpty = 0;
        list[i].idSector = sector[i];
    }
}

/** \brief  Hace la suma de todos los salarios de todos los empleados y devuelve el total
 *
 * \param   eEmployee list[]
 * \param   int len
 *
 * \return  float total
 *
 */

 float salaryTotal(eEmployee list[],int len)
 {
     int i;
     float total=0;

     for(i=0;i<len;i++)
     {
        if(list[i].isEmpty==0)
        {
            total=list[i].salary+total;
        }
     }
     return total;
 }

 /** \brief Hace la cuenta del promedio de todos los salarios de la lista. Devuelve el promedio.
  *
  * \param  eEmployee list[]
  * \param  int len
  *
  * \return float average
  *
  */

  float salaryAverage(eEmployee list[],int len)
  {
      int i;
      int counter=0;
      float average=0;
      float total;

      total=salaryTotal(list,len);

      for(i=0;i<len;i++)
      {
          if(list[i].isEmpty==0)
          {
              counter=counter+1;
          }
      }

      average=(float)total/counter;

      return average;
  }

/** \brief  Devuelve la cantidad de empleados que su sueldo supera el promedio de sueldos
*
* \param    eEmployee list[]
* \param    int len
*
* \return   int counterEmployee
*
*/

int salaryAverageOvercome(eEmployee list[],int len)
{
    int i;
    int counterEmployee=0;
    float average;

    average=salaryAverage(list,len);

    for(i=0;i<len;i++)
    {
        if(list[i].salary>average&&list[i].isEmpty==0)
        {
            counterEmployee=counterEmployee+1;
        }
    }

       return counterEmployee;
}

/** \brief  Si no hay ningun empleado en la lista, devuelve 0, si hay por lo menos uno, devuelve 1.
*
* \param    eEmployee list[]
* \param    int len
*
* \return   int oneE
*
*/


int oneEmployee(eEmployee list[],int len)
{
    int i;
    int oneE=0;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty==0)
        {
            oneE=1;
            break;
        }
    }
    return oneE;
}







                 //////////////////
                //MENU FUNCTIONS//
               //////////////////





/** \brief  Menu alta de empleados
 *
 * \param   eEmployee list[]
 * \param   int lenE
 * \param   eSector sectors[]
 * \param   int lenS
 *
 * \return void
 *
 */

void addEmployeeMenu(eEmployee list[],int lenE,eSector sectors[],int lenS)
{
    int space;

    char name[51];
    char lastName[51];
    float salary;
    int sector;

    printf("\n--MENU DE CREACION DE EMPLEADO--\n\n");
    fflush(stdin);
    printf("Ingrese el nombre: ");
    fgets(name,51,stdin);
    name[strlen(name)-1]='\0';

    printf("Ingrese el apellido: ");
    fgets(lastName,51,stdin);
    lastName[strlen(lastName)-1]='\0';

    printf("Ingrese el salario del empleado: $");
    scanf("%f",&salary);

    printf("Ingrese el sector del empleado:\n");
    sector=validateSector(sectors,lenS);

    space=addEmployee(list,ELEMENTS,name,lastName,salary,sector);

    if(space==0)
    {
        printf("\nEmpleado dado de ALTA con exito!\n\n");
    }
    else
    {
        printf("\nERROR. No hay mas lugar en la lista.\n\n");
    }
    system("pause");
}

/** \brief Menu de baja de empleado
 *
 * \param eEmployee list[]
 * \param int len
 *
 * \return void
 *
 */

void removeEmployeeMenu(eEmployee list[],int len)
{
    int id;
    int success;

    printf("\n--MENU DE BAJA DE EMPLEADO--\n\n");
    printf("Ingrese el id del empleado que desea eliminar: ");
    scanf("%d",&id);

    success=removeEmployee(list,len,id);

    if(success!=1)
    {
        printf("\nERROR. El id que ha ingresado no le pertenece a ningun empleado en la lista.\n\n");
    }

    system("pause");
}

/** \brief Menu de modificacion de empleado
 *
 * \param eEmployee list[]
 * \param int len
 * \param eSector sectors[]
 * \param int lenS
 *
 * \return void
 *
 */

void modifyEmployeeMenu(eEmployee list[], int lenE,eSector sectors[],int lenS)
{
    int id;
    int position;
    int option;

    printf("\n--MENU DE MODIFICACION DE EMPLEADO--\n\n");
    printf("Ingrese el id del empleado que desea modificar: ");
    scanf("%d",&id);

    position=findEmployeeById(list,lenE,id);

    if(position!=-1)
    {
        printf("Que desea modificar del empleado |%s,%s|?\n\n1)Nombre\n2)Apellido\n3)Salario\n4)Sector\n\n",list[position].lastName,list[position].name);
        printf("Ingrese opcion: ");
        scanf("%d",&option);

        switch(option)
        {
            case 1:
                modifyNameEmployee(list,lenE,position);
            break;
            case 2:
                modifyLastNameEmployee(list,lenE,position);
            break;
            case 3:
                modifySalaryEmployee(list,lenE,position);
            break;
            case 4:
                modifySectorEmployee(list,lenE,position,sectors,lenS);
            break;
            default:
                printf("\nERROR. Opcion no valida.\n\n");
            break;
        }
    }
    else
    {
        printf("\nERROR. El id que ha ingresado no le pertenece a ningun empleado en la lista.\n\n");
    }
    system("pause");
}

/** \brief  Mostrar lista de empleados e informacion que pedia el tp
 *
 * \param   eEmployee list[]
 * \param   int lenE
 * \param   eSector sectors[]
 * \param   int lenS
 * \param   eEmployee copy[]
 *
 * \return  void
 *
 */

void showEmployeesMenu(eEmployee list[],int lenE,eSector sectors[],int lenS,eEmployee copy[])
{
    float total;
    float average;
    int employeeSalaryAverage;

    total=salaryTotal(list,lenE);
    average=salaryAverage(list,lenE);
    employeeSalaryAverage=salaryAverageOvercome(list,lenE);

    printf("\n--LISTA DE EMPLEADOS--\n\n");
    printf("\tID\tAPELLIDO, NOMBRE\t  SALARIO\t  SECTOR\n\n");

    sortEmployees(list,lenE,copy);
    printEmployees(list,lenE,sectors,lenS);

    printf("\nEl total de todos los sueldos es: $%.2f",total);
    printf("\nEl promedio de los sueldos es de: $%.2f",average);
    printf("\nLa cantidad de empleados que superan el sueldo promedio son: %d.\n\n",employeeSalaryAverage);
    system("pause");
}
