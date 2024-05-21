# Assignment 1 

[- I'm using MariaDB and not PostgreSQL.]

## Creating all tables: 

```
MariaDB [(none)]> CREATE DATABASE assignment_1;
Query OK, 1 row affected (0.001 sec)

MariaDB [(none)]> SHOW DATABASES;
+--------------------+
| Database           |
+--------------------+
| _bb9e8352d4f1dda5  |
| assignment_1       |
| information_schema |
| mysql              |
| performance_schema |
| sys                |
| test               |
| tweaker_test       |
+--------------------+
8 rows in set (0.003 sec)

MariaDB [(none)]> USE assignment_1;
Database changed
MariaDB [assignment_1]> CREATE TABLE orgs(id INT PRIMARY KEY, name VARCHAR(100), streetaddr VARCHAR(200), city VARCHAR(100), state CHAR(2), zip CHAR(5), phone CHAR(10));
Query OK, 0 rows affected (0.246 sec)

MariaDB [assignment_1]> CREATE TABLE researchers (id INT PRIMARY KEY, name VARCHAR(100), org INT, FOREIGN KEY (org) REFERENCES orgs(id));
Query OK, 0 rows affected (0.219 sec)

MariaDB [assignment_1]> CREATE TABLE programs (id INT PRIMARY KEY, name VARCHAR(200), dictorate CHAR(3));
Query OK, 0 rows affected (0.122 sec)

MariaDB [assignment_1]> CREATE TABLE grants(id INT PRIMARY KEY, title VARCHAR(300), amount FLOAT, org INT, pi INT, manager INT, started DATE,  ended DATE, abstract TEXT, FOREIGN KEY (org) REFERENCES orgs(id), FOREIGN KEY (pi) REFERENCES managers(id));
Query OK, 0 rows affected (0.075 sec)

MariaDB [assignment_1]> CREATE TABLE grant_researchers (researcherid INT, grantid INT, FOREIGN KEY (researcherid) REFERENCES researchers(id), FOREIGN KEY (grantid) REFERENCES grants(id));
Query OK, 0 rows affected (0.080 sec)

MariaDB [assignment_1]> CREATE TABLE fields (id INT PRIMARY KEY, name VARCHAR(100));
Query OK, 0 rows affected (0.114 sec)

MariaDB [assignment_1]> CREATE TABLE grant_fields (grantid INT, fieldid INT, FOREIGN KEY (grantid) REFERENCES grants(id), FOREIGN KEY (fieldid) REFERENCES fields(id));
Query OK, 0 rows affected (0.113 sec)

MariaDB [assignment_1]> CREATE TABLE grant_programs (grantid INT, programid INT, FOREIGN KEY (grantid) REFERENCES grants(id), FOREIGN KEY (programid) REFERENCES programs(id));
Query OK, 0 rows affected (0.153 sec)

```

- Wrote a python script to add dummy/fake data into those tables. 
Refer to `fake_data.py` file for code. 


