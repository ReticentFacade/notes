import mariadb
from mariadb import Error
from faker import Faker
import random

try:
    conn = mariadb.connect(
        user="root",
        password="password",
        host="localhost",
        port=3306,
        database="assignment_1"
    )
    cursor = conn.cursor()
except Error as e:
    print(f"Error connecting to MariaDB: {e}")
    exit()

# Specifying table name:
table_name = "researchers"

fake = Faker()

# Select all ids from `orgs` table: 
cursor.execute("SELECT id FROM orgs")
org_ids = [row[0] for row in cursor.fetchall()]

for _ in range(500):
    name = "Professor " + fake.name()
    org = random.choice(org_ids)
    cursor.execute(f"INSERT INTO {table_name} (name, org) VALUES (?, ?)", (name, org))

# Commit:
conn.commit()
conn.close()

