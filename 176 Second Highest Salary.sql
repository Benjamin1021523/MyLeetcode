SELECT IFNULL(
    (SELECT DISTINCT
    #即使重複也輸出多次
        Salary
        #輸出時換個名字
    FROM
        Employee
    ORDER BY
        Salary DESC
    LIMIT
        1 OFFSET 1
        #n OFFSET m
        #忽略前m筆之後輸出n筆
    ), NULL
) AS SecondHighestSalary;