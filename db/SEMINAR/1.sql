drop table Demo cascade constraints;
drop table T cascade constraints;
create table Demo
(
 SID number(3) primary key,
 S_name varchar2(20) not null,
 S_loc varchar2(20) not null
);
create table T
(
S_timestamp timestamp
);
drop table SEMINAR cascade constraints;
create table SEMINAR 
drop table CUSTOMER cascade constraints;
create table CUSTOMER 
(
  CID number(5) primary key,
 Fname varchar2(20) not null,
 Lname varchar2(20) not null,
 Email varchar2(30) not null unique,
 areacode number(3),
 phn_num varchar2(8),
 address varchar2(30),
 city varchar2(20),
 zip number(5),
 State char(2),
 sid number(3) not null
);
drop table t cascade constraints;
create table t
(
 IID number(5) primary key,
 total number(5,2),
 pur_date date,
 constraint CidPK2 foreign key (Cid) references CUSTOMER (Cid)
);
insert into t values(00001,to_date('9-OCT-2014', 'DD-MON-YYYY'),'CREDIT',7.99,8.47);




