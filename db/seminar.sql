drop table customer cascade contraint;
create customer
(

cid number(5) primary key,
fname varchar2(20) not null,
lname varchar2(20) not null,
email varchar2 (30) not null,
areacode number (3),
phn_num number(7),
address varchar2(30),
city varchar2(2),
zip number(5),
state char(2) ,
sid number(3),
constraint cfk foreign key (sid) references seminar (sid)
);


drop table seminar cascade contraint;
create seminar
(
sid number(3) primary key,
s_name varchar2(20),
s_loc varchar2(20),
s_date date,
s_time timestamp,
);