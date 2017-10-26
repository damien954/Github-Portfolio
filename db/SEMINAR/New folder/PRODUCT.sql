drop table PRODUCT cascade contraint;
create table PRODUCT
(
 PID number(3) primary key,
 product_name varchar2(20),
 product_desc varchar2(20),
 unit_price number(4,2),
 QUANITITY number(4)
 );