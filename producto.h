#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED


void cargar(struct Productos *p,int a)
{
    int cont=0,id;
    cout<<"Cargar ID del producto"<<endl;
    cin>>id;
    for(int i=0; i<10; i++)
    {
        if(p[i].id==id)
        {
            cont++;
        }
    }
    if(cont==0)
    {
        p[a].id=id;


        cout<<"Cargar nombre"<<endl;
        cin>> p[a].nombre;
        cout<<"cargar precio"<<endl;
        cin>> p[a].precio;
        cout<<"Cargar stock"<<endl;
        cin>>p[a].stock;
        cout<<"cargar stock minimo"<<endl;
        cin>>p[a].minn;



    }
    else
    {
        cout<<"id de producto ya utilizado" <<endl;
    }
    system("pause");
}

void editarproducto(struct Productos *p, int a)
{
    int id,cont=0,guardari;
    cout<<"Ingrese el producto a editar"<<endl;
    cin>>id;
    for(int i=0; i<a; i++)
    {
        if(id==p[i].id)
        {
            guardari=i;
            cont++;
        }

    }
    if(cont==1)
    {
        cout<<"El producto "<<id<< "Contiene el siguiente registro: "<<endl;
        cout<<"Su nombre es " <<p[guardari].nombre<<endl;
        cout<<"Su precio es "<<p[guardari].precio<<endl;
        cout<<"Su stock es "<<p[guardari].stock<<endl;
        cout<<"Su Stock minimo es " <<p[guardari].minn<<endl;
        cout <<endl;
        cout<<"Cargar nuevo nombre"<<endl;
        cin>> p[guardari].nombre;
        cout<<"cargar nuevo precio"<<endl;
        cin>> p[guardari].precio;
        cout<<"Cargar nuevo stock"<<endl;
        cin>> p[guardari].stock;
        cout<<"Cargar nuevo Stock minimo "<<endl;
        cin>> p[guardari].minn;
        system("pause");
    }
    else
    {
        cout<<"El Id del producto no exite"<<endl;
        system("pause");
    }
}
void listarproducto(struct Productos *p, int a)
{
    int id, cont=0, guardari;
    cout<<"Ingrese el producto a listar"<<endl;
    cin>>id;
    for(int i=0; i<a; i++)
    {
        if(id==p[i].id)
        {
            cont++;
            guardari=i;
        }
    }
    if(cont==1)
    {
        cout<<"El producto "<<id<< " Contiene el siguiente registro: "<<endl;
        cout<<"Su nombre es " <<p[guardari].nombre<<endl;
        cout<<"Su precio es "<<p[guardari].precio<<endl;
        cout<<"Su stock es "<<p[guardari].stock<<endl;
        cout<<"Su Stock minimo es " <<p[guardari].minn<<endl;
        cout <<endl;
    }
    else
    {
        cout<<"El Id del producto no exite"<<endl;
    }
    system("pause");
}
void listarxprecio(struct Productos *p, int a)
{
    struct Productos l[a];
    struct Productos aux;
    for(int i=0; i<a; i++)
    {
        l[i].id=p[i].id;
        strcpy(l[i].nombre,p[i].nombre);
        l[i].precio=p[i].precio;
        l[i].stock=p[i].stock;
        l[i].minn=p[i].minn;
        /*cout<<"El producto "<<l[i].id<< "Contiene el siguiente registro: "<<endl;
        cout<<"Su nombre es " <<l[i].nombre<<endl;
        cout<<"Su precio es "<<l[i].precio<<endl;
        cout<<"Su stock es "<<l[i].stock<<endl;
        cout<<"Su Stock minimo es " <<l[i].minn<<endl;*/
    }

   for(int i=0; i<a; i++)
    {
        aux.id=l[i].id;
        strcpy(aux.nombre,p[i].nombre);
        aux.precio=l[i].precio;
        aux.stock=l[i].stock;
        aux.minn=l[i].minn;

        for(int x=1; x<a; x++)
        {
            if(l[i].precio<l[x].precio)
            {

                l[i].id=l[x].id;
                strcpy(l[i].nombre,p[x].nombre);
                l[i].precio=l[x].precio;
                l[i].stock=l[x].stock;
                l[i].minn=l[x].minn;


                l[x].id=aux.id;
                strcpy(l[x].nombre,aux.nombre);
                l[x].precio=aux.precio;
                l[x].stock=aux.stock;
                l[x].minn=aux.minn;
            }

        }
    }
    cout<<"Los productos ordenados de mayor a menor segun su precio son: "<<endl;

    for(int i=0; i<a; i++)
    {
        cout<< l[i].id<<" ";
    }
}
void menuproducto()
{
    int opcion, cant=10,a=0;
    Productos p[10];
    do
    {
        cout<<"MENÚ PRODUCTOS"<<endl;
        cout<<"--------------------------------------------------"<<endl;
        cout<<"1 - Cargar producto"<<endl;
        cout<<"2 - Editar producto x ID"<<endl;
        cout<<"3 - Listar producto x ID"<<endl;
        cout<<"4 - Listar productos (ordenados por precio)"<<endl;
        cout<<"--------------------------------------------------"<<endl;
        cout<<"0 - Salir del programa"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        switch (opcion)
        {
        case 1 :
            if(a!=10)
            {
                cargar(p,a);
                a++;
                system("cls");
            }
            else
            {
                cout<<"Ya se ingresaron 10 productos"<<endl;
            }
            break;
        case 2:
            editarproducto(p,a);
            system("cls");
            break;
        case 3:
            listarproducto(p,a);
            system("cls");
            break;
        case 4 :
            listarxprecio(p,a);
            system("pause");
            system("cls");
            break;
        case 0 :
            break;
        default:
            cout<<"opcion incorrecta"<<endl;
            break;
        }
    }
    while(opcion!=0);

}

#endif // PRODUCTO_H_INCLUDED
