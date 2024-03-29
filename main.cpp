#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <sstream>
#include <iomanip>
#include <string.h>
#include <unistd.h>
using namespace std;

const char* hostname="localhost";
const char* username="root";
const char* password="";
const char* database="passwords";
unsigned int port=3306;
const char* unixsocket=NULL;
unsigned long clientflag=0;

void encryption(MYSQL*);
void loading();
MYSQL* connectdatabase()
{
    MYSQL* conn;
    conn=mysql_init(0);
    conn=mysql_real_connect(conn,hostname,username,password,database,port,unixsocket,clientflag);
    if(conn)
    {
        loading();
        char a[]="                    Connection established with table saved_passwords of MYSQL database passwords..";
        for(int i=0; i<99; i++)
        {
            cout<<a[i];
            usleep(200);
        }
        cout<<"\n\n";
        return conn;
    }
    else
    {
        cout<<"Database not connected...";
        return conn;
    }
}
int size;
static int counter=0;
void insertion(MYSQL* conn)
{
    counter++;
    int qstate = 0;
    string SITE,USERNAME,PASSWORD;
    cout<<"Enter site name: ";
    cin>>SITE;
    cout<<"Enter username: ";
    cin>>USERNAME;
    cout<<"Enter password: ";
    cin>>PASSWORD;
    cout<<endl;
    size=PASSWORD.length();
    stringstream ss;
    ss<<"INSERT INTO saved_passwords (SITE, USERNAME, PASSWORD) VALUES ('"+SITE+"','"+USERNAME+"','"+PASSWORD+"')";
    string query = ss.str();
    const char* q = query.c_str();
    qstate = mysql_query(conn,q);
    encryption(conn);
    if(qstate==0)
        cout<<"Record inserted"<<endl;
    else
        cout<<"Record insertion failed"<<endl;
}

void encryption(MYSQL* conn)
{
    MYSQL_ROW row;
    MYSQL_RES* res;
    char A[size];
    char B[size*3];
    int qstate = mysql_query(conn,"SELECT * FROM saved_passwords");
    res=mysql_store_result(conn);
    int count = mysql_num_fields(res);
    if(conn)
    {
        if(!qstate)
        {
            while((row=mysql_fetch_row(res)))
            {
                strcpy(A,row[count-1]);
                int i=0;
                for (int k = 0; k < size*3; k += 3)
                {
                    if(A[i]==32 || A[i]=='\0')
                    {
                        B[k]=32;
                        B[k+1]=32;
                        B[k+2]=32;
                    }
                    if (A[i] == 'a')
                    {
                        B[k] = '-';
                        B[k + 1] = '.';
                        B[k + 2] = '-';
                    }
                    else if (A[i] == 'b')
                    {
                        B[k] = '-';
                        B[k + 1] = '-';
                        B[k + 2] = '.';
                    }
                    else if (A[i] == 'c')
                    {
                        B[k] = ',';
                        B[k + 1] = '"';
                        B[k + 2] = ',';
                    }
                    else if (A[i] == 'd')
                    {
                        B[k] = '-';
                        B[k + 1] = ',';
                        B[k + 2] = '-';
                    }
                    else if (A[i] == 'e')
                    {
                        B[k] = '.';
                        B[k + 1] = '-';
                        B[k + 2] = '-';
                    }
                    else if (A[i] == 'f')
                    {
                        B[k] = '_';
                        B[k + 1] = '"';
                        B[k + 2] = '_';
                    }
                    else if (A[i] == 'g')
                    {
                        B[k] = '-';
                        B[k + 1] = '"';
                        B[k + 2] = ',';
                    }
                    else if (A[i] == 'h')
                    {
                        B[k] = '_';
                        B[k + 1] = '_';
                        B[k + 2] = '_';
                    }
                    else if (A[i] == 'i')
                    {
                        B[k] = '-';
                        B[k + 1] = '/';
                        B[k + 2] = '-';
                    }
                    else if (A[i] == 'j')
                    {
                        B[k] = '-';
                        B[k + 1] = '#';
                        B[k + 2] = '-';
                    }
                    else if (A[i] == 'k')
                    {
                        B[k] = '/';
                        B[k + 1] = '-';
                        B[k + 2] = '-';
                    }
                    else if (A[i] == 'l')
                    {
                        B[k] = '#';
                        B[k + 1] = '-';
                        B[k + 2] = '-';
                    }
                    else if (A[i] == 'm')
                    {
                        B[k] = ',';
                        B[k + 1] = '_';
                        B[k + 2] = ',';
                    }
                    else if (A[i] == 'n')
                    {
                        B[k] = '/';
                        B[k + 1] = ',';
                        B[k + 2] = '/';
                    }
                    else if (A[i] == 'o')
                    {
                        B[k] = '#';
                        B[k + 1] = ',';
                        B[k + 2] = '#';
                    }
                    else if (A[i] == 'p')
                    {
                        B[k] = '/';
                        B[k + 1] = '/';
                        B[k + 2] = '/';
                    }
                    else if (A[i] == 'q')
                    {
                        B[k] = '#';
                        B[k + 1] = '#';
                        B[k + 2] = '#';
                    }
                    else if (A[i] == 'r')
                    {
                        B[k] = '*';
                        B[k + 1] = '/';
                        B[k + 2] = '-';
                    }
                    else if (A[i] == 's')
                    {
                        B[k] = '*';
                        B[k + 1] = '*';
                        B[k + 2] = '*';
                    }
                    else if (A[i] == 't')
                    {
                        B[k] = '*';
                        B[k + 1] = ',';
                        B[k + 2] = '*';
                    }
                    else if (A[i] == 'u')
                    {
                        B[k] = '*';
                        B[k + 1] = ',';
                        B[k + 2] = ',';
                    }
                    else if (A[i] == 'v')
                    {
                        B[k] = '/';
                        B[k + 1] = '*';
                        B[k + 2] = '*';
                    }
                    else if (A[i] == 'w')
                    {
                        B[k] = '#';
                        B[k + 1] = '*';
                        B[k + 2] = '*';
                    }
                    else if (A[i] == 'x')
                    {
                        B[k] = ',';
                        B[k + 1] = '*';
                        B[k + 2] = '/';
                    }
                    else if (A[i] == 'y')
                    {
                        B[k] = '/';
                        B[k + 1] = '*';
                        B[k + 2] = '/';
                    }
                    else if (A[i] == 'z')
                    {
                        B[k] = '#';
                        B[k + 1] = '*';
                        B[k + 2] = '#';
                    }
                    else if (A[i] == 'A')
                    {
                        B[k] = '3';
                        B[k + 1] = '3';
                        B[k + 2] = '5';
                    }
                    else if (A[i] == 'B')
                    {
                        B[k] = '3';
                        B[k + 1] = '4';
                        B[k + 2] = '5';
                    }
                    else if (A[i] == 'C')
                    {
                        B[k] = '4';
                        B[k + 1] = '0';
                        B[k + 2] = '9';
                    }
                    else if (A[i] == 'D')
                    {
                        B[k] = '3';
                        B[k + 1] = '2';
                        B[k + 2] = '1';
                    }
                    else if (A[i] == 'E')
                    {
                        B[k] = '6';
                        B[k + 1] = '0';
                        B[k + 2] = '3';
                    }
                    else if (A[i] == 'F')
                    {
                        B[k] = '4';
                        B[k + 1] = '0';
                        B[k + 2] = '1';
                    }
                    else if (A[i] == 'G')
                    {
                        B[k] = '3';
                        B[k + 1] = '3';
                        B[k + 2] = '7';
                    }
                    else if (A[i] == 'H')
                    {
                        B[k] = '6';
                        B[k + 1] = '6';
                        B[k + 2] = '2';
                    }
                    else if (A[i] == 'I')
                    {
                        B[k] = '3';
                        B[k + 1] = '0';
                        B[k + 2] = '3';
                    }
                    else if (A[i] == 'J')
                    {
                        B[k] = '6';
                        B[k + 1] = '6';
                        B[k + 2] = '9';
                    }
                    else if (A[i] == 'K')
                    {
                        B[k] = '4';
                        B[k + 1] = '1';
                        B[k + 2] = '1';
                    }
                    else if (A[i] == 'L')
                    {
                        B[k] = '6';
                        B[k + 1] = '9';
                        B[k + 2] = '6';
                    }
                    else if (A[i] == 'M')
                    {
                        B[k] = '3';
                        B[k + 1] = '4';
                        B[k + 2] = '2';
                    }
                    else if (A[i] == 'N')
                    {
                        B[k] = '7';
                        B[k + 1] = '6';
                        B[k + 2] = '9';
                    }
                    else if (A[i] == 'O')
                    {
                        B[k] = '4';
                        B[k + 1] = '4';
                        B[k + 2] = '5';
                    }
                    else if (A[i] == 'P')
                    {
                        B[k] = '3';
                        B[k + 1] = '0';
                        B[k + 2] = '7';
                    }
                    else if (A[i] == 'Q')
                    {
                        B[k] = '7';
                        B[k + 1] = '2';
                        B[k + 2] = '9';
                    }
                    else if (A[i] == 'R')
                    {
                        B[k] = '5';
                        B[k + 1] = '4';
                        B[k + 2] = '5';
                    }
                    else if (A[i] == 'S')
                    {
                        B[k] = '3';
                        B[k + 1] = '4';
                        B[k + 2] = '0';
                    }
                    else if (A[i] == 'T')
                    {
                        B[k] = '7';
                        B[k + 1] = '3';
                        B[k + 2] = '8';
                    }
                    else if (A[i] == 'U')
                    {
                        B[k] = '4';
                        B[k + 1] = '5';
                        B[k + 2] = '2';
                    }
                    else if (A[i] == 'V')
                    {
                        B[k] = '7';
                        B[k + 1] = '5';
                        B[k + 2] = '2';
                    }
                    else if (A[i] == 'W')
                    {
                        B[k] = '3';
                        B[k + 1] = '2';
                        B[k + 2] = '5';
                    }
                    else if (A[i] == 'X')
                    {
                        B[k] = '5';
                        B[k + 1] = '6';
                        B[k + 2] = '9';
                    }
                    else if (A[i] == 'Y')
                    {
                        B[k] = '5';
                        B[k + 1] = '3';
                        B[k + 2] = '2';
                    }
                    else if (A[i] == 'Z')
                    {
                        B[k] = '3';
                        B[k + 1] = '1';
                        B[k + 2] = '5';
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
                    else if (A[i]=='~')
                    {
                        B[k] = 'm';
                        B[k + 1] = 'c';
                        B[k + 2] = 'l';
                    }
                    else if (A[i]=='`')
                    {
                        B[k] = 'm';
                        B[k + 1] = 'l';
                        B[k + 2] = 'c';
                    }
                    else if (A[i]=='!')
                    {
                        B[k] = 'c';
                        B[k + 1] = 'l';
                        B[k + 2] = 'm';
                    }
                    else if (A[i]=='@')
                    {
                        B[k] = 'c';
                        B[k + 1] = 'm';
                        B[k + 2] = 'l';
                    }
                    else if (A[i]=='#')
                    {
                        B[k] = 'l';
                        B[k + 1] = 'm';
                        B[k + 2] = 'c';
                    }
                    else if (A[i]=='$')
                    {
                        B[k] = 'l';
                        B[k + 1] = 'c';
                        B[k + 2] = 'm';
                    }
                    else if (A[i]=='%')
                    {
                        B[k] = 'a';
                        B[k + 1] = 'e';
                        B[k + 2] = 'o';
                    }
                    else if (A[i]=='^')
                    {
                        B[k] = 'a';
                        B[k + 1] = 'o';
                        B[k + 2] = 'e';
                    }
                    else if (A[i]=='&')
                    {
                        B[k] = 'e';
                        B[k + 1] = 'o';
                        B[k + 2] = 'a';
                    }
                    else if (A[i]=='*')
                    {
                        B[k] = 'e';
                        B[k + 1] = 'a';
                        B[k + 2] = 'o';
                    }
                    else if (A[i]=='(')
                    {
                        B[k] = 'o';
                        B[k + 1] = 'a';
                        B[k + 2] = 'e';
                    }
                    else if (A[i]==')')
                    {
                        B[k] = 'i';
                        B[k + 1] = 's';
                        B[k + 2] = 'j';
                    }
                    else if (A[i]=='_')
                    {
                        B[k] = 'i';
                        B[k + 1] = 'j';
                        B[k + 2] = 's';
                    }
                    else if (A[i]=='-')
                    {
                        B[k] = 's';
                        B[k + 1] = 'j';
                        B[k + 2] = 'i';
                    }
                    else if (A[i]=='+')
                    {
                        B[k] = 's';
                        B[k + 1] = 'i';
                        B[k + 2] = 'j';
                    }
                    else if (A[i]=='=')
                    {
                        B[k] = 'j';
                        B[k + 1] = 'i';
                        B[k + 2] = 's';
                    }
                    else if (A[i]=='{')
                    {
                        B[k] = 'j';
                        B[k + 1] = 's';
                        B[k + 2] = 'i';
                    }
                    else if (A[i]=='[')
                    {
                        B[k] = 'z';
                        B[k + 1] = 'u';
                        B[k + 2] = 'n';
                    }
                    else if (A[i]=='}')
                    {
                        B[k] = 'z';
                        B[k + 1] = 'n';
                        B[k + 2] = 'u';
                    }
                    else if (A[i]==']')
                    {
                        B[k] = 'u';
                        B[k + 1] = 'n';
                        B[k + 2] = 'z';
                    }
                    else if (A[i]=='|')
                    {
                        B[k] = 'u';
                        B[k + 1] = 'z';
                        B[k + 2] = 'n';
                    }
                    else if (A[i]==':')
                    {
                        B[k] = 'n';
                        B[k + 1] = 'u';
                        B[k + 2] = 'z';
                    }
                    else if (A[i]==';')
                    {
                        B[k] = 'r';
                        B[k + 1] = 'f';
                        B[k + 2] = 't';
                    }
                    else if (A[i]==34)
                    {
                        B[k] = 'r';
                        B[k + 1] = 't';
                        B[k + 2] = 'f';
                    }
                    else if (A[i]=='<')
                    {
                        B[k] = 'f';
                        B[k + 1] = 'r';
                        B[k + 2] = 't';
                    }
                    else if (A[i]==',')
                    {
                        B[k] = 't';
                        B[k + 1] = 'r';
                        B[k + 2] = 'f';
                    }
                    else if (A[i]=='>')
                    {
                        B[k] = 't';
                        B[k + 1] = 'f';
                        B[k + 2] = 'r';
                    }
                    else if (A[i]=='.')
                    {
                        B[k] = 'w';
                        B[k + 1] = 'p';
                        B[k + 2] = 'k';
                    }
                    else if (A[i]=='?')
                    {
                        B[k] = 'w';
                        B[k + 1] = 'k';
                        B[k + 2] = 'p';
                    }
                    else if (A[i]=='/')
                    {
                        B[k] = 'p';
                        B[k + 1] = 'k';
                        B[k + 2] = 'w';
                    }
                    i++;
                }
            }
        }
    }
    string enc_pass(B,size*3);
    MYSQL_ROW row2;
    MYSQL_RES* res2;
    mysql_query(conn,"SELECT * FROM saved_passwords");
    res2=mysql_store_result(conn);
    int count1 = mysql_num_fields(res2);
    for(int x=0; x<counter; x++)
    {
        row2=mysql_fetch_row(res2);
    }
    string SITE=row2[count1-3];
    stringstream ss;
    ss<<"UPDATE saved_passwords SET PASSWORD='"+enc_pass+"' WHERE SITE='"+SITE+"'";
    string query=ss.str();
    const char* q=query.c_str();
    qstate=mysql_query(conn,q);
    if(qstate==0)
    {
        loading();
        cout<<"Encryption successful"<<endl;
    }
    else
        cout<<"Encryption failed"<<endl;
}
class pass
{
    string p;
public:
    pass()
    {
        cout<<"Enter a master password to decrypt your passwords later: ";
        getline(cin>>ws,p);
        system("cls");
    }
    bool pass_check(string q)
    {
        if(p==q)
            return 1;
        else
            return 0;
    }
} obj;

static int counter1=0,counter2=0;
void decryption(MYSQL* conn)
{
    MYSQL_ROW row_;
    MYSQL_RES* res_;
    string q;
    cout<<"Enter the master password: ";
    getline(cin>>ws,q);
    cout<<endl;
    bool b=obj.pass_check(q);
    int c=0;
    int qstate1=mysql_query(conn,"SELECT * FROM saved_passwords");
    if(!qstate1)
    {
        res_=mysql_store_result(conn);
        while((row_=mysql_fetch_row(res_)))
        {
            c++;
        }
    }
    if(b==true && c!=0)
    {
        loading();
        MYSQL_ROW row;
        MYSQL_RES* res;
        int qstate = mysql_query(conn,"SELECT * FROM saved_passwords");
        res=mysql_store_result(conn);
        int count = mysql_num_fields(res);
        if(conn)
        {
            if(!qstate)
            {
                while((row=mysql_fetch_row(res)))
                {
                    counter1++;
                    int size=strlen(row[count-1]);
                    char A[size];
                    char B[size/3];
                    strcpy(A,row[count-1]);
                    int i=0;
                    for (int k = 0; k < size; k += 3)
                    {
                        if (A[k] == 32 && A[k + 1] == 32 && A[k + 2] == 32)
                        {
                            B[i] = 32;
                        }
                        else if (A[k] == '-' && A[k + 1] == '.' && A[k + 2] == '-')
                        {
                            B[i] = 'a';
                        }
                        else if (A[k] == '-' && A[k + 1] == '-' && A[k + 2] == '.')
                        {
                            B[i] = 'b';
                        }
                        else if (A[k] == ',' && A[k + 1] == '"' && A[k + 2] == ',')
                        {
                            B[i] = 'c';
                        }
                        else if (A[k] == '-' && A[k + 1] == ',' && A[k + 2] == '-')
                        {
                            B[i] = 'd';
                        }
                        else if (A[k] == '.' && A[k + 1] == '-' && A[k + 2] == '-')
                        {
                            B[i] = 'e';
                        }
                        else if (A[k] == '_' && A[k + 1] == '"' && A[k + 2] == '_')
                        {
                            B[i] = 'f';
                        }
                        else if (A[k] == '-' && A[k + 1] == '"' && A[k + 2] == ',')
                        {
                            B[i] = 'g';
                        }
                        else if (A[k] == '_' && A[k + 1] == '_' && A[k + 2] == '_')
                        {
                            B[i] = 'h';
                        }
                        else if (A[k] == '-' && A[k + 1] == '/' && A[k + 2] == '-')
                        {
                            B[i] = 'i';
                        }
                        else if (A[k] == '-' && A[k + 1] == '#' && A[k + 2] == '-')
                        {
                            B[i] = 'j';
                        }
                        else if (A[k] == '/' && A[k + 1] == '-' && A[k + 2] == '-')
                        {
                            B[i] = 'k';
                        }
                        else if (A[k] == '#' && A[k + 1] == '-' && A[k + 2] == '-')
                        {
                            B[i] = 'l';
                        }
                        else if (A[k] == ',' && A[k + 1] == '_' && A[k + 2] == ',')
                        {
                            B[i] = 'm';
                        }
                        else if (A[k] == '/' && A[k + 1] == ',' && A[k + 2] == '/')
                        {
                            B[i] = 'n';
                        }
                        else if (A[k] == '#' && A[k + 1] == ',' && A[k + 2] == '#')
                        {
                            B[i] = 'o';
                        }
                        else if (A[k] == '/' && A[k + 1] == '/' && A[k + 2] == '/')
                        {
                            B[i] = 'p';
                        }
                        else if (A[k] == '#' && A[k + 1] == '#' && A[k + 2] == '#')
                        {
                            B[i] = 'q';
                        }
                        else if (A[k] == '*' && A[k + 1] == '/' && A[k + 2] == '-')
                        {
                            B[i] = 'r';
                        }
                        else if (A[k] == '*' && A[k + 1] == '*' && A[k + 2] == '*')
                        {
                            B[i] = 's';
                        }
                        else if (A[k] == '*' && A[k + 1] == ',' && A[k + 2] == '*')
                        {
                            B[i] = 't';
                        }
                        else if (A[k] == '*' && A[k + 1] == ',' && A[k + 2] == ',')
                        {
                            B[i] = 'u';
                        }
                        else if (A[k] == '/' && A[k + 1] == '*' && A[k + 2] == '*')
                        {
                            B[i] = 'v';
                        }
                        else if (A[k] == '#' && A[k + 1] == '*' && A[k + 2] == '*')
                        {
                            B[i] = 'w';
                        }
                        else if (A[k] == ',' && A[k + 1] == '*' && A[k + 2] == '/')
                        {
                            B[i] = 'x';
                        }
                        else if (A[k] == '/' && A[k + 1] == '*' && A[k + 2] == '/')
                        {
                            B[i] = 'y';
                        }
                        else if (A[k] == '#' && A[k + 1] == '*' && A[k + 2] == '#')
                        {
                            B[i] = 'z';
                        }
                        else if (A[k] == '3' && A[k + 1] == '3' && A[k + 2] == '5')
                        {
                            B[i] = 'A';
                        }
                        else if (A[k] == '3' && A[k + 1] == '4' && A[k + 2] == '5')
                        {
                            B[i] = 'B';
                        }
                        else if (A[k] == '4' && A[k + 1] == '0' && A[k + 2] == '9')
                        {
                            B[i] = 'C';
                        }
                        else if (A[k] == '3' && A[k + 1] == '2' && A[k + 2] == '1')
                        {
                            B[i] = 'D';
                        }
                        else if (A[k] == '6' && A[k + 1] == '0' && A[k + 2] == '3')
                        {
                            B[i] = 'E';
                        }
                        else if (A[k] == '4' && A[k + 1] == '0' && A[k + 2] == '1')
                        {
                            B[i] = 'F';
                        }
                        else if (A[k] == '3' && A[k + 1] == '3' && A[k + 2] == '7')
                        {
                            B[i] = 'G';
                        }
                        else if (A[k] == '6' && A[k + 1] == '6' && A[k + 2] == '2')
                        {
                            B[i] = 'H';
                        }
                        else if (A[k] == '3' && A[k + 1] == '0' && A[k + 2] == '3')
                        {
                            B[i] = 'I';
                        }
                        else if (A[k] == '6' && A[k + 1] == '6' && A[k + 2] == '9')
                        {
                            B[i] = 'J';
                        }
                        else if (A[k] == '4' && A[k + 1] == '1' && A[k + 2] == '1')
                        {
                            B[i] = 'K';
                        }
                        else if (A[k] == '6' && A[k + 1] == '9' && A[k + 2] == '6')
                        {
                            B[i] = 'L';
                        }
                        else if (A[k] == '3' && A[k + 1] == '4' && A[k + 2] == '2')
                        {
                            B[i] = 'M';
                        }
                        else if (A[k] == '7' && A[k + 1] == '6' && A[k + 2] == '9')
                        {
                            B[i] = 'N';
                        }
                        else if (A[k] == '4' && A[k + 1] == '4' && A[k + 2] == '5')
                        {
                            B[i] = 'O';
                        }
                        else if (A[k] == '3' && A[k + 1] == '0' && A[k + 2] == '7')
                        {
                            B[i] = 'P';
                        }
                        else if (A[k] == '7' && A[k + 1] == '2' && A[k + 2] == '9')
                        {
                            B[i] = 'Q';
                        }
                        else if (A[k] == '5' && A[k + 1] == '4' && A[k + 2] == '5')
                        {
                            B[i] = 'R';
                        }
                        else if (A[k] == '3' && A[k + 1] == '4' && A[k + 2] == '0')
                        {
                            B[i] = 'S';
                        }
                        else if (A[k] == '7' && A[k + 1] == '3' && A[k + 2] == '8')
                        {
                            B[i] = 'T';
                        }
                        else if (A[k] == '4' && A[k + 1] == '5' && A[k + 2] == '2')
                        {
                            B[i] = 'U';
                        }
                        else if (A[k] == '7' && A[k + 1] == '5' && A[k + 2] == '2')
                        {
                            B[i] = 'V';
                        }
                        else if (A[k] == '3' && A[k + 1] == '2' && A[k + 2] == '5')
                        {
                            B[i] = 'W';
                        }
                        else if (A[k] == '5' && A[k + 1] == '6' && A[k + 2] == '9')
                        {
                            B[i] = 'X';
                        }
                        else if (A[k] == '5' && A[k + 1] == '3' && A[k + 2] == '2')
                        {
                            B[i] = 'Y';
                        }
                        else if (A[k] == '3' && A[k + 1] == '1' && A[k + 2] == '5')
                        {
                            B[i] = 'Z';
                        }
                        else if (A[k] == '-' && A[k + 1] == '*' && A[k + 2] == '-')
                        {
                            B[i] = '0';
                        }
                        else if (A[k] == '+' && A[k + 1] == '*' && A[k + 2] == '*')
                        {
                            B[i] = '1';
                        }
                        else if (A[k] == '+' && A[k + 1] == '*' && A[k + 2] == '-')
                        {
                            B[i] = '2';
                        }
                        else if (A[k] == '*' && A[k + 1] == '+' && A[k + 2] == '-')
                        {
                            B[i] = '3';
                        }
                        else if (A[k] == '-' && A[k + 1] == '+' && A[k + 2] == '-')
                        {
                            B[i] = '4';
                        }
                        else if (A[k] == '+' && A[k + 1] == '-' && A[k + 2] == '*')
                        {
                            B[i] = '5';
                        }
                        else if (A[k] == '+' && A[k + 1] == '+' && A[k + 2] == '+')
                        {
                            B[i] = '6';
                        }
                        else if (A[k] == '<' && A[k + 1] == '<' && A[k + 2] == '<')
                        {
                            B[i] = '7';
                        }
                        else if (A[k] == '>' && A[k + 1] == '>' && A[k + 2] == '>')
                        {
                            B[i] = '8';
                        }
                        else if (A[k] == '<' && A[k + 1] == '*' && A[k + 2] == '>')
                        {
                            B[i] = '9';
                        }
                        else if (A[k] == '\0' && A[k + 1] == '\0' && A[k + 2] == '\n')
                        {
                            B[i] = '\n';
                        }
                        else if (A[k] == 'm' && A[k + 1] == 'c' && A[k + 2] == 'l')
                        {
                            B[i] = '~';
                        }
                        else if (A[k] == 'm' && A[k + 1] == 'l' && A[k + 2] == 'c')
                        {
                            B[i] = '`';
                        }
                        else if (A[k] == 'c' && A[k + 1] == 'l' && A[k + 2] == 'm')
                        {
                            B[i] = '!';
                        }
                        else if (A[k] == 'c' && A[k + 1] == 'm' && A[k + 2] == 'l')
                        {
                            B[i] = '@';
                        }
                        else if (A[k] == 'l' && A[k + 1] == 'm' && A[k + 2] == 'c')
                        {
                            B[i] = '#';
                        }
                        else if (A[k] == 'l' && A[k + 1] == 'c' && A[k + 2] == 'm')
                        {
                            B[i] = '$';
                        }
                        else if (A[k] == 'a' && A[k + 1] == 'e' && A[k + 2] == 'o')
                        {
                            B[i] = '%';
                        }
                        else if (A[k] == 'a' && A[k + 1] == 'o' && A[k + 2] == 'e')
                        {
                            B[i] = '^';
                        }
                        else if (A[k] == 'e' && A[k + 1] == 'o' && A[k + 2] == 'a')
                        {
                            B[i] = '&';
                        }
                        else if (A[k] == 'e' && A[k + 1] == 'a' && A[k + 2] == 'o')
                        {
                            B[i] = '*';
                        }
                        else if (A[k] == 'o' && A[k + 1] == 'a' && A[k + 2] == 'e')
                        {
                            B[i] = '(';
                        }
                        else if (A[k] == 'i' && A[k + 1] == 's' && A[k + 2] == 'j')
                        {
                            B[i] = ')';
                        }
                        else if (A[k] == 'i' && A[k + 1] == 'j' && A[k + 2] == 's')
                        {
                            B[i] = '_';
                        }
                        else if (A[k] == 's' && A[k + 1] == 'j' && A[k + 2] == 'i')
                        {
                            B[i] = '-';
                        }
                        else if (A[k] == 's' && A[k + 1] == 'i' && A[k + 2] == 'j')
                        {
                            B[i] = '+';
                        }
                        else if (A[k] == 'j' && A[k + 1] == 'i' && A[k + 2] == 's')
                        {
                            B[i] = '=';
                        }
                        else if (A[k] == 'j' && A[k + 1] == 's' && A[k + 2] == 'i')
                        {
                            B[i] = '{';
                        }
                        else if (A[k] == 'z' && A[k + 1] == 'u' && A[k + 2] == 'n')
                        {
                            B[i] = '[';
                        }
                        else if (A[k] == 'z' && A[k + 1] == 'n' && A[k + 2] == 'u')
                        {
                            B[i] = '}';
                        }
                        else if (A[k] == 'u' && A[k + 1] == 'n' && A[k + 2] == 'z')
                        {
                            B[i] = ']';
                        }
                        else if (A[k] == 'u' && A[k + 1] == 'z' && A[k + 2] == 'n')
                        {
                            B[i] = '|';
                        }
                        else if (A[k] == 'n' && A[k + 1] == 'u' && A[k + 2] == 'z')
                        {
                            B[i] = ':';
                        }
                        else if (A[k] == 'r' && A[k + 1] == 'f' && A[k + 2] == 't')
                        {
                            B[i] = ';';
                        }
                        else if (A[k] == 'r' && A[k + 1] == 't' && A[k + 2] == 'f')
                        {
                            B[i] = 34;
                        }
                        else if (A[k] == 'f' && A[k + 1] == 'r' && A[k + 2] == 't')
                        {
                            B[i] = '<';
                        }
                        else if (A[k] == 't' && A[k + 1] == 'r' && A[k + 2] == 'f')
                        {
                            B[i] = ',';
                        }
                        else if (A[k] == 't' && A[k + 1] == 'f' && A[k + 2] == 'r')
                        {
                            B[i] = '>';
                        }
                        else if (A[k] == 'w' && A[k + 1] == 'p' && A[k + 2] == 'k')
                        {
                            B[i] = '.';
                        }
                        else if (A[k] == 'w' && A[k + 1] == 'k' && A[k + 2] == 'p')
                        {
                            B[i] = '?';
                        }
                        else if (A[k] == 'p' && A[k + 1] == 'k' && A[k + 2] == 'w')
                        {
                            B[i] = '/';
                        }
                        i++;
                    }
                    string dec_pass(B,size/3);
                    mysql_query(conn,"SELECT * FROM saved_passwords");
                    mysql_store_result(conn);
                    string SITE=row[count-3];
                    stringstream ss;
                    ss<<"UPDATE saved_passwords SET PASSWORD='"+dec_pass+"' WHERE SITE='"+SITE+"'";
                    string query=ss.str();
                    const char* q=query.c_str();
                    int qstate1=mysql_query(conn,q);
                    if(qstate1==0)
                        counter2++;
                }
                if(counter1==counter2)
                    cout<<"Decryption successful"<<endl;
                else
                    cout<<"Decryption failed"<<endl;
            }
        }
    }
    else
    {
        if(b==false)
            cout<<"Wrong password"<<endl;
        else if(c==0)
            cout<<"No records inserted"<<endl;
    }
}

void display(MYSQL* conn)
{
    loading();
    MYSQL_ROW row;
    MYSQL_RES* res;
    MYSQL_FIELD* column;
    if(conn)
    {
        int qstate=mysql_query(conn,"SELECT * FROM saved_passwords");
        if(!qstate)
        {
            res=mysql_store_result(conn);
            int count=mysql_num_fields(res);
            column=mysql_fetch_field(res);
            for(int i=1; i<=152; i++)
            {
                cout<<"=";
            }
            cout<<endl;
            for(int i=0; i<count; i++)
            {
                if(i<2)
                    cout<<left<<setw(24)<<setfill(' ')<<column->name<<"|";
                else
                    cout<<left<<setw(50)<<setfill(' ')<<column->name<<"|";
                column = mysql_fetch_field(res);
            }
            cout<<endl;
            column=mysql_fetch_field(res);
            for(int i=1; i<=152; i++)
            {
                cout<<"=";
            }
            cout<<endl;
            while((row=mysql_fetch_row(res)))
            {

                for(int i=0; i<count; i++)
                {
                    if(i<2)
                        cout<<left<<setw(24)<<setfill(' ')<<row[i]<<"|";
                    else
                        cout<<left<<setw(50)<<setfill(' ')<<row[i]<<"|";
                }
                cout<<endl;
            }
            for(int i=1; i<=152; i++)
            {
                cout<<"=";
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"Fetching failed"<<endl;
    }
}

void del(MYSQL* conn)
{
    MYSQL_ROW row;
    MYSQL_RES* res;
    string PASSWORD;
    cout<<"Enter master password:";
    getline(cin>>ws,PASSWORD);
    cout<<endl;
    bool b=obj.pass_check(PASSWORD);
    int c=0;
    int qstate1=mysql_query(conn,"SELECT * FROM saved_passwords");
    if(!qstate1)
    {
        res=mysql_store_result(conn);
        while((row=mysql_fetch_row(res)))
        {
            c++;
        }
    }
    if(b==true && c!=0)
    {
        int qstate=0;
        string SITE;
        cout<<"Enter site to be deleted:";
        cin>>SITE;
        stringstream ss;
        ss<<"DELETE FROM saved_passwords WHERE SITE='"+SITE+"'";
        string query=ss.str();
        const char* q=query.c_str();
        qstate=mysql_query(conn,q);
        if(qstate==0)
            cout<<"Record deleted"<<endl;
        else
            cout<<"Record deletion failed"<<endl;
    }
    else
    {
        if(b==false)
            cout<<"Wrong password"<<endl;
        else if(c==0)
            cout<<"No records inserted"<<endl;
    }
}

void update(MYSQL* conn)
{
    MYSQL_ROW row;
    MYSQL_RES* res;
    string PASSWORD;
    cout<<"Enter master password:";
    getline(cin>>ws,PASSWORD);
    bool b=obj.pass_check(PASSWORD);
    int c=0;
    int qstate1=mysql_query(conn,"SELECT * FROM saved_passwords");
    if(!qstate1)
    {
        res=mysql_store_result(conn);
        while((row=mysql_fetch_row(res)))
        {
            c++;
        }
    }
    if(b==true && c!=0)
    {
        int qstate=0;
        string new_pass,SITE;
        cout<<"Enter site name:";
        cin>>SITE;
        cout<<"Enter new password:";
        cin>>new_pass;
        stringstream ss;
        ss<<"UPDATE saved_passwords SET PASSWORD='"+new_pass+"' WHERE SITE='"+SITE+"'";
        string query=ss.str();
        const char* q=query.c_str();
        qstate=mysql_query(conn,q);
        encryption(conn);
        if(qstate==0)
            cout<<"Record updated"<<endl;
        else
            cout<<"Record updation failed"<<endl;
    }
    else
    {
        if(b==false)
            cout<<"Wrong password"<<endl;
        else if(c==0)
            cout<<"No records inserted"<<endl;
    }
}

void loading()
{
    for (int x = 0; x < 152; x++)
    {
        printf("%c", 219);
        usleep(2000);
    }
    cout<<endl;
}
void reset(MYSQL* conn)
{
    stringstream ss;
    ss<<"DELETE FROM saved_passwords";
    string query=ss.str();
    const char* q=query.c_str();
    mysql_query(conn,q);
    stringstream ss1;
    ss1<<"ALTER TABLE saved_passwords AUTO_INCREMENT=11001";
    query=ss1.str();
    q=query.c_str();
    mysql_query(conn,q);
}

int main()
{
    MYSQL* conn = connectdatabase();
    reset(conn);
    int ch;
    while(true)
    {
limit:
        cout<<"\n\nEnter a choice from given table: "<<endl;
        cout<<"1. Insertion of record"<<endl;
        cout<<"2. Display record(s)"<<endl;
        cout<<"3. Decryption of record"<<endl;
        cout<<"4. Updation of record"<<endl;
        cout<<"5. Deletion of record"<<endl;
        cout<<"6. Exit program"<<endl<<endl;
        cout<<"Your choice: ";
        cin>>ch;
        cout<<endl;
        switch(ch)
        {
        case 1:
        {
            insertion(conn);
            break;
        }
        case 2:
        {
            display(conn);
            break;
        }
        case 3:
        {
            decryption(conn);
            break;
        }
        case 4:
        {
            update(conn);
            break;
        }
        case 5:
        {
            del(conn);
            break;
        }
        case 6:
        {
            exit(0);
        }
        default:
        {
            cout<<"Enter a valid choice!!!!!"<<endl;
            goto limit;
        }
        }
    }
    return 0;
}
