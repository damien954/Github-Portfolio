drop table SEMINAR cascade contraint;
create table SEMINAR
(
 SID number(3) primary key,
 S_name varchar2(20) not null,
 S_loc varchar2(20) not null,
 S_timestamp timestamp
);