drop table SEMINAR cascade constraint;

create table SEMINAR
(
 SID number(3)primary key,
 S_name varchar2(20) not null,
 S_loc varchar2(20) not null,
 S_date date,
 S_time varchar2(6)
);

drop table CUSTOMER cascade constraint;

create table CUSTOMER
(
 CID number(5) not null,
 fname varchar2(20) not null,
 lname varchar2(20) not null,
 email varchar2(30) not null unique,
 areacode number(3),
 phn_num varchar2(8),
 address varchar2(30),
 city varchar2(20),
 zip number(5),
 state char(2),
 constraint customer_pk primary key(cid)
);

drop table INVOICE cascade constraint;

create table INVOICE
(
 iid number(5) primary key,
 idate date,
 pay_type varchar2(10),
 total number(5,2),
 sub_total number(5,2),
 cid number(5),
 constraint invoice_fk foreign key(cid) references CUSTOMER(CID)
);










drop table PRODUCT cascade constraint;

create table PRODUCT
(
 PID number(3) primary key,
 product_name varchar2(20),
 product_desc varchar2(20),
 unit_price number(4,2),
 quaitiy number(4)
);

drop table CONTACT cascade constraint;

create table CONTACT
(
 CONID number(5) primary key,
 contact_number number(5),
 contact_date date,
 contact_type number(2),
 constraint contact_fk foreign key(contact_number) references CUSTOMER(cid)
);

drop table attendence cascade constraint;

create table attendence
(
 CID number(5),
 SID number(3),
 tic_num number(5),
 seat_num varchar2(3),
 constraint attendence_fk2 foreign key (Cid) references CUSTOMER (Cid),
 constraint attendence_fk1 foreign key (sid) references seminar (sid),
 constraint attedence_pk primary key(cid,sid)
);

drop table lineitem cascade constraint;

create table lineitem
(
 IID number(5),
 PID number(3),
 quan number(3),
 constraint lineitem_fk foreign key (IID) references INVOICE (IID),
 constraint lineitem_fk2 foreign key (PID) references PRODUCT (PID),
 constraint lineitem_pk primary key(iid,pid)
);
