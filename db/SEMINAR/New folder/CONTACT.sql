drop table CONTACT cascade contraint;
create table CONTACT
(
 CONID number(5) primary key,
 contact_number number(5),
 contact_date date,
 contact_type varchar2(10),
 constraint CidPK foreign key (contact_number) references CUSTOMER (Cid)
);