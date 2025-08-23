
#define MYSQL_HOSTNAME            "localhost"
#define MYSQL_USERNAME            "root"
#define MYSQL_PASSWORD            ""
#define MYSQL_DATABASE            "northwest"

new MySQL:sql_Handle;

stock mysql_get_error()
{
    new reason[128];
    mysql_error(reason);

    return reason;
}

stock mysql_init()
{
    print("[N:MYSQL]: Connecting to MySQL server");
    sql_Handle = mysql_connect(MYSQL_HOSTNAME, MYSQL_USERNAME, MYSQL_PASSWORD, MYSQL_DATABASE);

    if(mysql_errno(sql_Handle) != 0)
    {
        printf("[N:MYSQL]: Connection refused\n[N:MYSQL]: Reason: %s", mysql_get_error());
        print("[N:MYSQL]: Server automatically shutting down");

        SendRconCommand("exit");
        return false;
    }

    print("[N:MYSQL]: Successfully connected to MySQL server!");
    print("[N:MYSQL]: Fetching server data from database... ");
    return true;
}
