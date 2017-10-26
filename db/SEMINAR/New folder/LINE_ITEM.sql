drop table LINE_ITEM cascade contraint;
create table LINE_ITEM
(
 IID number(5),
 PID number(3),
 QUAN number(3),
 constraint IIDFK foreign key (IID) references INVOICE (IID),
 constraint PIDFK foreign key (PID) references PRODUCT (PID),
 constraint assignment_PK3 primary key (IID,PID)
);