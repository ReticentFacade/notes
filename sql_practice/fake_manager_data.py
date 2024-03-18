import mariadb
from mariadb import Error
from faker import Faker
import random

try: 
    conn = mariadb.connect(
        user = "root",
        password = "password",
        host = "localhost", 
        port = 3306,
        database = "assignment_1"
    )
    cursor = conn.cursor()
except Error as e: 
    print(f"Error connecting to MariaDB: {e}")
    exit()

table_name = "managers"
fake = Faker()

for _ in range(500):
    name = fake.name()
    cursor.execute(f"INSERT INTO {table_name} (name) VALUES (?)", (name,))

conn.commit()
conn.close()
