ALTER TABLE PRODUCT
add constraint quanitiyFK foreign key (QUANITITY) references LINE_ITEM (QUAN);