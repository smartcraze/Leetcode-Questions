select r.contest_id , 
round(count( r.contest_id)/(SELECT COUNT(*) FROM Users) *100.0,2) as percentage 
from Users u
right join Register r
on u.user_id = r.user_id
group by r.contest_id
order by percentage desc ,contest_id 
