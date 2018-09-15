#include <stdio.h>
#include <my_global.h>
#include <mysql.h>

int main(int argc, char **argv){
printf("Mysql Client Version: %s \n", mysql_get_client_info());
exit(0);
}
