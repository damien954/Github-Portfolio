drop table ARTIST cascade constraint;
create table ARTIST
(
 art_id number(4) primary key,
 art_name varchar2(20),
 art_backup number(4),
 art_fee number(7,2));
