#include <iostream>
#include<mysql.h>

using namespace std;

int q_estado;

int main()
{
    int opc;
    MYSQL* conectar;//variable tipo mysql
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "jyzene", "Ocarinaoft!me123", "db_producto", 3306, NULL, 0);
    if (conectar) {
        cout << "Selecciona la opcion que desees realizar" << endl;
        cout << "1) Insertar datos" << endl;
        cout << "2) Leer datos " << endl;
        cout << "0) salir" << endl;
        cin >> opc;

        switch (opc) {
            case 1:
                string producto;
                cout << "Ingrese el producto: ";
                cin >> producto;
                string insert = "Insert into producto(producto) values('" + producto + "')";
                const char* i = insert.c_str();
                q_estado = mysql_query(conectar, i);
                if (!q_estado) {
                    cout << "si conecto!" << endl;
                }
                else {
                    cout << "hubo un error :(" << endl;
                }
                break;
            case 2:
                string consulta = "select * from producto";
                const char* c = consulta.c_str();
                q_estado = mysql_query(conectar, c);
                if (!q_estado) {
                    resultado = mysql_store_result(conectar);
                    while (fila = mysql_fetch_row(resultado)) {
                        cout << fila[0] << "," << fila[1] << endl;
                    }
                }
                break;
            case 0:
                break;
        
        }
    }
    else {
        cout << "rayos, algo fallo :(" << endl;
    }

    system("pause");
    return 0;
}
