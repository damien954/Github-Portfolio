drop table INVOICE cascade contraint;
create table INVOICE
(
 IID number(5) primary key,
 CID number(5),
 PAY_DATE date,
 PAY_TYPE varchar2(20),
 subtotal number(7,2),
 total number(5,2),
 constraint CidPK2 foreign key (CID) references CUSTOMER (CID)
 );