# Write your MySQL query statement below
delete p1 from person P1 join person p2
on p1.email=p2.email And p1.id>p2.id;