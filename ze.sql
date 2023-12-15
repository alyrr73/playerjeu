CREATE DATABASE basedd;
CREATE TABLE jeu(
    id INT AUTO_INCREMENT PRIMARY KEY,
    nom VARCHAR(255),
    club VARCHAR(255),
    );
INSERT INTO jeu ( nom, club) VALUES (1,'Ronaldo', 'Madrid');
INSERT INTO jeu (nom, club) VALUES (2,'Grizou','barca');


COMMIT;