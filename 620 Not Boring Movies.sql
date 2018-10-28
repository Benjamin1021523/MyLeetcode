select
    *
from
    cinema
where
    description != "boring" AND id % 2
order by
    rating desc
;