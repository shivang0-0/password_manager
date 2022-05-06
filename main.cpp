#include <iostream>
#include <windows.h>
#include <C:\Program Files (x86)\Dev-Cpp\MinGW64\include\mysql.h>
using namespace std;
const char* hostname="localhost";
const char* username="root";
const char* password="";
const char* database="tempdb";
unsigned int port=3306;
const char* unixsocket=NULL;
unsigned long clientflag=0;
void connectdatabase()
{
    MYSQL* conn;
    conn=mysql_init(0);
    conn=mysql_real_connect(conn,hostname,username,password,database,port,unixsocket,clientflag);
    if(conn)
        cout<<"connected"<<endl;
    else
        cout<<"not connected";
}

int main()
{
    connectdatabase();
    return 0;
}
