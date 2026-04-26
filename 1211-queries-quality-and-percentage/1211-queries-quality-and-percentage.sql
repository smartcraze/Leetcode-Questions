select query_name ,
round(avg(q.rating/q.position),2) as quality ,
round(sum(if(q.rating < 3 ,1,0))/count(*) * 100 ,2) as poor_query_percentage 
from Queries q
group by query_name 

