drop table PERFROMS cascade constraint;
create table PERFROMS
(
 perf_role varchar2(30),
 perf_date date,
 art_id number(4),
 comp_id number(5),
 constraint art_id_2fk foreign key (art_id) references ARTIST (art_id),
 constraint comp_idfk foreign key (comp_id) references COMPANY (comp_id),
 constraint assignment_PK primary key (art_id,comp_id)
);