import mariadb
from mariadb import Error
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

table_name = "grant_researchers"

cursor.execute("SELECT id FROM researchers;")
researcher_ids = [row[0] for row in cursor.fetchall()]

cursor.execute("SELECT id FROM grants")
grant_ids = [row[0] for row in cursor.fetchall()]

for _ in range(500): 
    researcherid = random.choice(researcher_ids)
    grantid = random.choice(grant_ids)
    cursor.execute(f"INSERT INTO {table_name} (researcherid, grantid) VALUES (?, ?)", (researcherid, grantid))

conn.commit()
conn.close()
