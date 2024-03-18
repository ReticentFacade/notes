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
    print("Error connecting to MariaDB: {e}")
    exit()

table_name = "grants"

fake = Faker()

cursor.execute("SELECT * FROM orgs")
org_ids = [row[0] for row in cursor.fetchall()]

cursor.execute("SELECT id FROM researchers")
researcher_ids = [row[0] for row in cursor.fetchall()]

cursor.execute("SELECT id FROM managers")
manager_ids = [row[0] for row in cursor.fetchall()]

for _ in range(500):
    title = fake.sentence()
    amount = round(random.uniform(10000, 1000000), 2) # Random amount between 10,000 and 1,000,000
    org_id = random.choice(org_ids)
    pi_id = random.choice(researcher_ids)
    manager_id = random.choice(manager_ids)
    started_date = fake.date_this_decade()
    ended_date = fake.date_between_dates(date_start = started_date, date_end = "+1y")
    abstract = fake.paragraph()

    cursor.execute(f"INSERT INTO {table_name} (title, amount, org, pi, manager, started, ended, abstract) VALUES (?, ?, ?, ?, ?, ?, ?, ?)", (title, amount, org_id, pi_id, manager_id, started_date, ended_date, abstract))

conn.commit()
conn.close()
