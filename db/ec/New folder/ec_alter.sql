ALTER TABLE ARTIST
ADD constraint art_backup_id_FK foreign key (art_backup) references ARTIST (art_id);