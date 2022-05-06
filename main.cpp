#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <sstream>
#include<iomanip>
using namespace std;

const char* hostname="localhost";
const char* username="root";
const char* password="";
const char* database="tempdb";
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
    string usernamedb,emaildb,passworddb;
    cout<<"Enter username: ";
    cin>>usernamedb;
    cout<<"Enter email id: ";
    cin>>emaildb;
    cout<<"Enter password: ";
    cin>>passworddb;
    stringstream ss;
    ss<<"INSERT INTO users (username, email, password) VALUES ('"+usernamedb+"','"+emaildb+"','"+passworddb+"')";
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
        int qstate = mysql_query(conn,"SELECT * FROM users");
        if(!qstate)
        {
            res=mysql_store_result(conn);
            int count = mysql_num_fields(res);
            column = mysql_fetch_field(res);
            for(int i=1;i<=52;i++)
                cout<<"=";
            cout<<endl;
            for(int i=0; i<count; i++)
            {
                cout<<left<<setw(12)<<setfill(' ')<<column->name<<"|";
                column = mysql_fetch_field(res);
            }
            cout<<endl;
            column = mysql_fetch_field(res);
            for(int i=1; i<=52; i++)
                cout<<"=";
            cout<<endl;
            while(row=mysql_fetch_row(res))
            {
                for(int i=0; i<count; i++)
                    cout<<left<<setw(12)<<setfill(' ')<<row[i]<<"|";
                cout<<endl;
            }
            for(int i=1; i<=52; i++)
                cout<<"=";
            cout<<endl;
        }
    }
}
int main()
{
    MYSQL* conn = connectdatabase();
    //insertion(conn);
    //update(conn);
    display(conn);
    return 0;
}
