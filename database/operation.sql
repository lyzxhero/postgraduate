



show databases




select * from Reserver




create table Sailor (sid varchar(12),sname varchar(12),rating varchar(12),age int)
  insert into Sailor values
                             ('22','dustin','7',45),
                             ('31','lubber','8',55),
                             ('58','rusty','10',35),
                             ('200','耀辉','99',25),
                             ('201','肖露','100',22);
select *
from Sailor;


select * from Sailor1 s1 where s1.sid in (select sid from Reserver where bid='103')


select a.sid,b.sid,b.sname
from
     (
     select sid from Reserver where bid='103'
    ) a
left join
         Sailor1 b
         on a.sid=b.sid;


select
  r.sid,s.sname,s.age,
       s.age*2 as age2
from
     (select distinct sid from Reserver) r
     left join Sailor1 s on r.sid=s.sid;


select s1.sid,sname from Sailor1 s1 where
    exists (select 1 from Reserver r where r.bid ='103' and s1.sid =r.sid);



select * from Reserver;



insert  into Reserver values ('201','101','11/19/96'),('200','103','11/20/96');



-- find ids of boat which are reservered by only one sailor
select  bid from Reserver group by bid having count(sid) = 3;



-- find name of sails who reserve red boat and green boat
-- 外层表示预定过红船的人  内层表示预定过绿船的人是不是也预定了红船
select s.sname from Reserver r left join Boat b on r.bid=b.bid
 left join Sailor1 s on r.sid=s.sid
  where b.color = 'red'
  and r.sid in
  (
      select ri.sid from Reserver ri left join Boat bi on ri.bid=bi.bid
      where bi.color = 'green'
      and ri.sid = r.sid
  );




-- 查找预定了所有传的水手 divsion
-- 通过否定的否定

-- such Sailor that there is no boat without a Reserver tuple showing Reserve
select
      *
from
      Sailor1 s
where
    not exists(
                select
                      *
                from
                     Boat b
                where
                    not exists (
                                  select
                                        *
                                  from
                                       Reserver r
                                  where
                                      r.bid = b.bid
                                      and r.sid = s.sid
                              )
                );




select
       case when age >= 22 and age <25 then '1'
            when age >= 25 and age <50 then '2'
           else 'other' end as k1,
       age,sname
from Sailor1;







create table teacher  (name varchar(16),rank1 varchar(16));
create table course (subject varchar(16),enrollment varchar(16),quater varchar(8),teacher varchar(16));







select * from Reserver;



create table A (aid int,seq int,remark varchar(16));
insert into A values (1,1,'one'),(2,2,'two'),(3,3,'there');


create table B (bid int,aid int,remark varchar(16));
insert into B values (2,2,'two'),(3,3,'three'),(4,4,'four');
insert into B values (5,2,'two');






select * from B b where exists (select 1 from A a where a.aid=b.aid);





create table compents(part varchar(16),subpart varchar(16),num int);


insert into compents values ('学校','教学楼',10),
                            ('学校','操场',4),
                            ('学校','食堂',2),
                            ('学校','宿舍',3),
                            ('教学楼','教室',60),
                            ('教室','砖头',8000),
                            ('操场','砖头',6000),
                            ('食堂','砖头',4000),
                            ('食堂','砖头',4500)
                            ;



#
# with
#     tempPart (part,qty) as
#     (
#       (select  part,num from compents where part='学校')
#         union  all
#       (select  c.subpart,c.num * tp.num as num from compents c,tempPart tp where tp.part = tempPart.subpart)
#     )





select
    c1.part,
    c1.subpart,
    c1.num * c2.num * case when c3.num is null then 1 else c3.num end as num1

from
     (
         select * from compents where part='学校' -- and subpart !='教学楼'
     ) c1
left join
    compents c2 on c1.subpart=c2.part
left join compents c3 on c2.subpart = c3.part




show tables

select * from B

show create table  B;


CREATE TABLE `B` (
  `bid` int(11) DEFAULT NULL,
  `aid` int(11) DEFAULT NULL,
  `remark` varchar(16) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci























