#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <mysql/mysql.h> 

#define DB_SERVER "localhost"
#define DB_USER "test"
#define DB_PSWD "test"
#define DB_NAME "test"

int main(int argc, char **argv) {
    MYSQL *conn_ptr;
    conn_ptr = mysql_init(NULL);
    if (!conn_ptr) {
        std::cout << "mysql init failed\n";
        exit(1);
    }
    conn_ptr = mysql_real_connect (conn_ptr, DB_SERVER, DB_USER, DB_PSWD, DB_NAME, 0, NULL, 0);
    if (conn_ptr) {
        std::cout << "connection success\n";
    } else {
        std::cout << "connection failed\n";
    }
    
    mysql_query(conn_ptr, "SET NAMES utf-8");
    mysql_query(conn_ptr, "SELECT * FROM `income`");
    MYSQL_RES *res_set;
    MYSQL_ROW row;
    unsigned int i = 0;
    res_set = mysql_store_result(conn_ptr);
    unsigned int numrows = mysql_num_rows(res_set);
    while ((row = mysql_fetch_row(res_set)) != NULL){
        printf("id:%s, category_id:%s, amount:%s, %s, %s\n", row[i], row[i+1], row[i+2], row[i+3], row[i+4]);
    }
    
    mysql_close(conn_ptr);
    return 0;
}