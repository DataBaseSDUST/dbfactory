#include <iostream>
#include <string>
#include "db.h"
using namespace std;
/*
void MYSQLDBUtil::conn()
{
	cout<<"MySQL�������ݿ�"<<endl;
}

void MYSQLDBUtil::executeSQL()
{
	cout<<"MySQLִ��SQL���"<<endl;
}

void MYSQLDBUtil::closeConn()
{
	cout<<"MySQL�Ͽ����ݿ�����"<<endl;
}*/

void MsSQLUtil::conn()
{
	cout<<"SQL Server�������ݿ�"<<endl;
}

void MsSQLUtil::executeQuery()
{
	cout<<"SQL Serverִ��SQL���"<<endl;
}

void MsSQLUtil::executeUpdate()
{

}

void MsSQLUtil::closeConn()
{
	cout<<"SQL Server�Ͽ����ݿ�����"<<endl;
}

void OracleUtil::conn()
{
	cout<<"Oracle�������ݿ�"<<endl;
}

void OracleUtil::executeQuery()
{
	cout<<"Oracleִ��SQL���"<<endl;
}

void OracleUtil::executeUpdate()
{

}

void OracleUtil::closeConn()
{
	cout<<"Oracle�Ͽ����ݿ�����"<<endl;
}
