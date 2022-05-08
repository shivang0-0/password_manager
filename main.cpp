#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <sstream>
#include<iomanip>
using namespace std;

const char* hostname="localhost";
const char* username="root";
const char* password="";
const char* database="passwords";
unsigned int port=3306;
const char* unixsocket=NULL;
unsigned long clientflag=0;

MYSQL* connectdatabase()
{
    MYSQL* conn;
    conn=mysql_init(0);
    conn=mysql_real_connect(conn,hostname,username,password,database,port,unixsocket,clientflag);
    if(conn)
    {
        cout<<"connected"<<endl;
        return conn;
    }
    else
    {
        cout<<"not connected";
        return conn;
    }
}
void insertion (MYSQL* conn)
{
    int qstate = 0;
    string SITE,USERNAME,PASSWORD;
    cout<<"Enter site name: ";
    cin>>SITE;
    cout<<"Enter username: ";
    cin>>USERNAME;
    cout<<"Enter password: ";
    cin>>PASSWORD;
    stringstream ss;
    ss<<"INSERT INTO saved_passwords (SITE, USERNAME, PASSWORD) VALUES ('"+SITE+"','"+USERNAME+"','"+PASSWORD+"')";
    string query = ss.str();
    const char* q = query.c_str();
    qstate = mysql_query(conn,q);
    if(qstate == 0)
    {
        cout<<"Record inserted...~~~ \n";
    }
    else
    {
        cout<<"Failed to insert...~~~ \n";
    }
}
void update (MYSQL* conn)
{
    int qstate;
    string usernamedb,emaildb,passworddb;
    int ID;
    cout<<"Enter id to be updated:";
    cin>>ID;
    cout<<"Enter new username: ";
    cin>>usernamedb;
    cout<<"Enter new email id: ";
    cin>>emaildb;
    cout<<"Enter new password: ";
    cin>>passworddb;
    stringstream ss;
    ss<<"UPDATE users SET username='"+usernamedb+"',email='"+emaildb+"',password='"+passworddb+"' WHERE id="<<ID;
    string query = ss.str();
    const char* q = query.c_str();
    qstate = mysql_query(conn,q);
    if(qstate == 0)
    {
        cout<<"Record updated...~~~ \n";
    }
    else
    {
        cout<<"Failed to update...~~~ \n";
    }
}
void del(MYSQL* conn)
{
    int qstate;
    string usernamedb,emaildb,passworddb;
    int ID;
    cout<<"Enter id to be deleted:";
    cin>>ID;
    stringstream ss;
    ss<<"DELETE FROM users WHERE id="<<ID;
    string query = ss.str();
    const char* q = query.c_str();
    qstate = mysql_query(conn,q);
    if(qstate == 0)
    {
        cout<<"Record deleted...~~~ \n";
    }
    else
    {
        cout<<"Failed to delete...~~~ \n";
    }
}
void display(MYSQL* conn)
{
    MYSQL_ROW row;
    MYSQL_RES* res;
    MYSQL_FIELD* column;
    if(conn)
    {
        int qstate = mysql_query(conn,"SELECT * FROM saved_passwords");
        if(!qstate)
        {
            res=mysql_store_result(conn);
            int count = mysql_num_fields(res);
            column = mysql_fetch_field(res);
            for(int i=1; i<=100; i++)
                cout<<"=";
            cout<<endl;
            for(int i=0; i<count; i++)
            {
                cout<<left<<setw(24)<<setfill(' ')<<column->name<<"|";
                column = mysql_fetch_field(res);
            }
            cout<<endl;
            column = mysql_fetch_field(res);
            for(int i=1; i<=100; i++)
                cout<<"=";
            cout<<endl;
            while((row=mysql_fetch_row(res)))
            {
                for(int i=0; i<count; i++)
                    cout<<left<<setw(24)<<row[i]<<setfill(' ')<<"|";
                cout<<endl;
            }
            for(int i=1; i<=100; i++)
                cout<<"=";
            cout<<endl;
        }
    }
}
void encryption(MYSQL* conn)
{
    MYSQL_ROW row;
    MYSQL_RES* res;
    char A[13];
    char B[39];
    if(conn)
    {
        int qstate = mysql_query(conn,"SELECT * FROM saved_passwords");
        if(!qstate)
        {
            res=mysql_store_result(conn);
            int count = mysql_num_fields(res);
            while((row=mysql_fetch_row(res)))
            {
                strcpy(A,row[count-1]);
                for(int i=0; i<13; i++)
                    cout<<A[i];
                int i=0;
                for (int k = 0; k < 39; k += 3)
                {
                    if(A[i]==32 || A[i]==32)
                    {
                        B[k]=32;
                        B[k+1]=32;
                        B[k+2]=32;
                    }
                    if (A[i] == 'a' || A[i] == 'A')
                    {
                        B[k] = '-';
                        B[k + 1] = '.';
                        B[k + 2] = '-';
                    }
                    else if (A[i] == 'b' || A[i] == 'B')
                    {
                        B[k] = '-';
                        B[k + 1] = '-';
                        B[k + 2] = '.';
                    }
                    else if (A[i] == 'c' || A[i] == 'C')
                    {
                        B[k] = ',';
                        B[k + 1] = '"';
                        B[k + 2] = ',';
                    }
                    else if (A[i] == 'd' || A[i] == 'D')
                    {
                        B[k] = '-';
                        B[k + 1] = ',';
                        B[k + 2] = '-';
                    }
                    else if (A[i] == 'e' || A[i] == 'E')
                    {
                        B[k] = '.';
                        B[k + 1] = '-';
                        B[k + 2] = '-';
                    }
                    else if (A[i] == 'f' || A[i] == 'F')
                    {
                        B[k] = '_';
                        B[k + 1] = '"';
                        B[k + 2] = '_';
                    }
                    else if (A[i] == 'g' || A[i] == 'G')
                    {
                        B[k] = '-';
                        B[k + 1] = '"';
                        B[k + 2] = ',';
                    }
                    else if (A[i] == 'h' || A[i] == 'H')
                    {
                        B[k] = '_';
                        B[k + 1] = '_';
                        B[k + 2] = '_';
                    }
                    else if (A[i] == 'i' || A[i] == 'I')
                    {
                        B[k] = '-';
                        B[k + 1] = '/';
                        B[k + 2] = '-';
                    }
                    else if (A[i] == 'j' || A[i] == 'J')
                    {
                        B[k] = '-';
                        B[k + 1] = '#';
                        B[k + 2] = '-';
                    }
                    else if (A[i] == 'k' || A[i] == 'K')
                    {
                        B[k] = '/';
                        B[k + 1] = '-';
                        B[k + 2] = '-';
                    }
                    else if (A[i] == 'l' || A[i] == 'L')
                    {
                        B[k] = '#';
                        B[k + 1] = '-';
                        B[k + 2] = '-';
                    }
                    else if (A[i] == 'm' || A[i] == 'M')
                    {
                        B[k] = ',';
                        B[k + 1] = '_';
                        B[k + 2] = ',';
                    }
                    else if (A[i] == 'n' || A[i] == 'N')
                    {
                        B[k] = '/';
                        B[k + 1] = ',';
                        B[k + 2] = '/';
                    }
                    else if (A[i] == 'o' || A[i] == 'O')
                    {
                        B[k] = '#';
                        B[k + 1] = ',';
                        B[k + 2] = '#';
                    }
                    else if (A[i] == 'p' || A[i] == 'P')
                    {
                        B[k] = '/';
                        B[k + 1] = '/';
                        B[k + 2] = '/';
                    }
                    else if (A[i] == 'q' || A[i] == 'Q')
                    {
                        B[k] = '#';
                        B[k + 1] = '#';
                        B[k + 2] = '#';
                    }
                    else if (A[i] == 'r' || A[i] == 'R')
                    {
                        B[k] = '*';
                        B[k + 1] = '/';
                        B[k + 2] = '-';
                    }
                    else if (A[i] == 's' || A[i] == 'S')
                    {
                        B[k] = '*';
                        B[k + 1] = '*';
                        B[k + 2] = '*';
                    }
                    else if (A[i] == 't' || A[i] == 'T')
                    {
                        B[k] = '*';
                        B[k + 1] = ',';
                        B[k + 2] = '*';
                    }
                    else if (A[i] == 'u' || A[i] == 'U')
                    {
                        B[k] = '*';
                        B[k + 1] = ',';
                        B[k + 2] = ',';
                    }
                    else if (A[i] == 'v' || A[i] == 'V')
                    {
                        B[k] = '/';
                        B[k + 1] = '*';
                        B[k + 2] = '*';
                    }
                    else if (A[i] == 'w' || A[i] == 'W')
                    {
                        B[k] = '#';
                        B[k + 1] = '*';
                        B[k + 2] = '*';
                    }
                    else if (A[i] == 'x' || A[i] == 'X')
                    {
                        B[k] = ',';
                        B[k + 1] = '*';
                        B[k + 2] = '/';
                    }
                    else if (A[i] == 'y' || A[i] == 'Y')
                    {
                        B[k] = '/';
                        B[k + 1] = '*';
                        B[k + 2] = '/';
                    }
                    else if (A[i] == 'z' || A[i] == 'Z')
                    {
                        B[k] = '#';
                        B[k + 1] = '*';
                        B[k + 2] = '#';
                    }
                    else if (A[i] == '0')
                    {
                        B[k] = '-';
                        B[k + 1] = '*';
                        B[k + 2] = '-';
                    }
                    else if (A[i] == '1')
                    {
                        B[k] = '+';
                        B[k + 1] = '*';
                        B[k + 2] = '*';
                    }
                    else if (A[i] == '2')
                    {
                        B[k] = '+';
                        B[k + 1] = '*';
                        B[k + 2] = '-';
                    }
                    else if (A[i] == '3')
                    {
                        B[k] = '*';
                        B[k + 1] = '+';
                        B[k + 2] = '-';
                    }
                    else if (A[i] == '4')
                    {
                        B[k] = '-';
                        B[k + 1] = '+';
                        B[k + 2] = '-';
                    }
                    else if (A[i] == '5')
                    {
                        B[k] = '+';
                        B[k + 1] = '-';
                        B[k + 2] = '*';
                    }
                    else if (A[i] == '6')
                    {
                        B[k] = '+';
                        B[k + 1] = '+';
                        B[k + 2] = '+';
                    }
                    else if (A[i] == '7')
                    {
                        B[k] = '<';
                        B[k + 1] = '<';
                        B[k + 2] = '<';
                    }
                    else if (A[i] == '8')
                    {
                        B[k] = '>';
                        B[k + 1] = '>';
                        B[k + 2] = '>';
                    }
                    else if (A[i] == '9')
                    {
                        B[k] = '<';
                        B[k + 1] = '*';
                        B[k + 2] = '>';
                    }
                    else if (A[i] == '\n')
                    {
                        B[k] = '\0';
                        B[k + 1] = '\0';
                        B[k + 2] = '\n';
                    }
                    i++;
                }
            }
        }
    }
    for (int i = 0; i < 39; i++)
    {
        cout<<B[i];
    }
}
int main()
{
    MYSQL* conn = connectdatabase();
    //insertion(conn);
    //update(conn);
    display(conn);
    encryption(conn);
    return 0;
}
