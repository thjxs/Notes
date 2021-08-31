# Retrieving Information from a Table

```sql
SELECT what_to_select
FROM which_table
WHERE conditions_to_satisfy;
```

1. selecting all data

2. selecting particular rows (where)

   ```sql
   SELECT * FROM pet WHERE name = 'Bowser';
   SELECT * FROM pet WHERE birth >= '1998-1-1';
   SELECT * FROM pet WHERE species = 'dog' AND sex = 'f';
   SELECT * FROM pet WHERE species = 'snake' OR species = 'bird';
   SELECT * FROM pet WHERE (species = 'dog' AND sex = 'f') OR (species = 'cat' AND sex = 'm');
   ```

3. selecting particular columns

   ```sql
   SELECT name, birth FROM pet;
   SELECT DISTINCT owner FROM pet;
   SELECT name, species, birth FROM pet WHERE species = 'dog' OR species = 'cat';
   ```

4. sorting rows (order by)

   ```sql
   SELECT name, birth FROM pet ORDER BY birth;
   SELECT name, birth FROM pet ORDER BY birth DESC;
   SELECT name, species, birth FROM pet ORDER BY species, birth DESC;
   ```

5. date calculations (timestampdiff)

   ```SQL
   SELECT name, birth, CURDATE(), TIMESTAMPDIFF(YEAR, birth, CURDATE()) AS age FROM pet;
   SELECT name, birth MONTH(birth) FROM pet;
   ```

6. counting rows (count)

   ```sql
   SELECT count(*) FROM pet;
   SELECT owner, count(*) FROM pet GROUP BY owner;
   SELECT species, sex, count(*) FROM pet GROUP BY species, sex;
   SELECT species, sex, count(*) FROM pet WHERE sex IS NOT NULL GROUP BY species, sex;
   ```

7. Using more than one table

   ```sql
   SELECT pet.name,
   TIMESTAMPDIFF(YEAR, birth, date) AS age,
   remark,
   FROM pet INNER JOIN event
   ON pet.name = event.name
   WHERE event.type = 'litter';
   ```
