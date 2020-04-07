#include <iostream>

using namespace std;
#include "rlutil.h"
using namespace rlutil;

#include<clocale>
#include "stdlib.h"
#include "string.h"
struct Productos
{
    int id=0;
    char nombre[30];
    char precio;
    int stock;
    int minn;
};
#include "producto.h"

int main()
{
    setlocale(LC_ALL, "Spanish");
    menuproducto();
    return 0;
}
