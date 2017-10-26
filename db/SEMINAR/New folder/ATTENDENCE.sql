drop table ATTENDENCE cascade contraint;
create table ATTENDENCE
(
 CID number(5),
 SID number(3),
 tic_num number(3),
 seat_num varchar2(5),
 constraint CidPK3 foreign key (CID) references CUSTOMER (CID),
 constraint sidPK2 foreign key (SID) references seminar (SID),
 constraint assignment_PK2 primary key (CID,SID)
);