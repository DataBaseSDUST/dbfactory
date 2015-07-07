#ifndef DB_INCLUDE_H
#define DB_INCLUDE_H
#include <iostream>
#include <string>
#include <mysql.h>
#include "sqlite3.h"
#include "smartptr.h"
using namespace std;
using namespace commutil;

class DBUtil
{
public:
	//��ʼ�����ݿ�����
	virtual void conn()=0;
	//�����ݿ�����
	virtual void open(string userName,string pass,string database)=0;
	//ִ��SQL��ѯ���
	virtual void executeQuery()=0;
	//ִ��insert,update,delete�������ݿ�����
	virtual void executeUpdate() = 0;
	//�ر����ݿ����ӣ��Ƿ��б�Ҫ
	virtual void closeConn()=0;
	virtual ~DBUtil(){}
};

/****
*
* ����mysql���ݿ����
*
****/
class MySQLUtil:public DBUtil
{
public:
	virtual void conn();
	virtual void open(string userName,string pass,string database);
	virtual void executeQuery();
	virtual void executeUpdate();
	virtual void closeConn();
	~MySQLUtil();
private:
	MYSQL	*m_conn;
};

//����mssql
class MsSQLUtil:public DBUtil
{
public:
	virtual void conn();
	virtual void open(string userName,string pass,string database);
	virtual void executeQuery();
	virtual void executeUpdate();
	virtual void closeConn();
};

//����oracle
class OracleUtil:public DBUtil
{
public:
	virtual void conn();
	virtual void open(string userName,string pass,string database);
	virtual void executeQuery();
	virtual void executeUpdate();
	virtual void closeConn();
};

//����sqlite
class SQLiteUtil:public DBUtil
{
public:
	~SQLiteUtil();
	virtual void conn();
	virtual void open(string userName,string pass,string database);
	virtual void executeQuery();
	virtual void executeUpdate();
	virtual void closeConn();
	static int	callback(void *notUsed, int argc, char **argv, char **szColName);
private:
	sqlite3 *m_pDB;
};

/***

	��ȡ���ݿ�ʵ���Ĺ���
	ʹ��traits������Ҫ�ڹ�����getDBInstance�н��д�����if�ж�(����java�ķ���)

***/
template<class T>
class DBFactory
{
public:
	static SmartPtr<DBUtil> *getDBInstance();
};

template<class T>
SmartPtr<DBUtil> DBFactory<T>::getDBInstance()
{
	SmartPtr<DBUtil> db(new T());
	return db;
	//return new T();
}
#endif