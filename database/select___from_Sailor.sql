CREATE TABLE `Sailor` (
  `sid` varchar(12) DEFAULT NULL,
  `sname` varchar(12) DEFAULT NULL,
  `rating` varchar(12) DEFAULT NULL,
  `age` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

INSERT INTO test1.Sailor (sid, sname, rating, age) VALUES ('22', 'dustin', '7', 45);
INSERT INTO test1.Sailor (sid, sname, rating, age) VALUES ('31', 'lubber', '8', 55);
INSERT INTO test1.Sailor (sid, sname, rating, age) VALUES ('58', 'rusty', '10', 35);
INSERT INTO test1.Sailor (sid, sname, rating, age) VALUES ('200', '耀辉', '99', 25);
INSERT INTO test1.Sailor (sid, sname, rating, age) VALUES ('201', '肖露', '100', 22);