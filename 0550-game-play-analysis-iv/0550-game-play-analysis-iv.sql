

select round(count(distinct player_id)/(select count(distinct player_id) from Activity),2)as fraction  
from Activity
where(player_id,date_sub(event_date ,interval 1 day)) in (
select player_id , min(event_date)
from Activity
group by player_id
)




-- SELECT 
-- ROUND(
--     COUNT(DISTINCT a.player_id) / 
--     (SELECT COUNT(DISTINCT player_id) FROM Activity)
-- , 2) AS fraction
-- FROM Activity a
-- JOIN (
--     SELECT player_id, MIN(event_date) AS first_login
--     FROM Activity
--     GROUP BY player_id
-- ) f
-- ON a.player_id = f.player_id
-- AND a.event_date = DATE_ADD(f.first_login, INTERVAL 1 DAY);