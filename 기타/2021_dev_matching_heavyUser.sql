-- 코드를 입력하세요
select * 
from places
where 
host_id in (
    select host_id 
    from (
            SELECT host_id, count(host_id) as cnt
            from places
            group by host_id
        ) a 
    where a.cnt > 1
)
order by id
