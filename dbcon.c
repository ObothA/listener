#include<stdio.h>
#include </usr/include/mysql/mysql.h>
#include </usr/include/stdio.h>
//#include </usr/include/mysql/my_global.h>
#include </usr/include/mysql/my_global.h>

int main() {
   MYSQL *conn;
   MYSQL_RES *res;
   MYSQL_ROW row;

   char *server = "localhost";
   char *user = "root";
   char *password = "R00t."; 
   char *database = "mobilewimeadb";

   conn = mysql_init(NULL);

   /* Connect to database */
   if (!mysql_real_connect(conn, server,
         user, password, database, 0, NULL, 0)) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }

   /* send SQL query */
   if (mysql_query(conn, "select * from aws")) {
      fprintf(stderr, "%s\n", mysql_error(conn));
      exit(1);
   }

   res = mysql_use_result(conn);

   /* output table name */
   printf("MySQL Tables in mysql database:\n");
   while ((row = mysql_fetch_row(res)) != NULL)
      printf("%s %s %s %s %s %s \n", row[0],row[1],row[2],row[3],row[4],row[5]);

   /* close connection */
   mysql_free_result(res);
   mysql_close(conn);
}
