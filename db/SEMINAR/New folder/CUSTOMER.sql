drop table CUSTOMER cascade contraint;
create table CUSTOMER
(
 CID number(5) primary key,
 Fname varchar2(20) not null,
 Lname varchar2(20) not null,
 Email varchar2(30) unique,
 areacode number(3),
 phn_num varchar2(8),
 address varchar2(30),
 city varchar2(20),
 zip number(5),
 State char(2)
);