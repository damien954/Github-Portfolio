drop table COMMERCIAL cascade constraint;
create table COMMERCIAL
(
 comm_code number(5) primary key,
 comm_prod varchar2(20),
 comp_id number(2),
 constraint com_idPK foreign key (comp_id) references COMPANY (comp_id));

