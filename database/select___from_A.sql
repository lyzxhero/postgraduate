CREATE TABLE `A` (
  `aid` int(11) DEFAULT NULL,
  `seq` int(11) DEFAULT NULL,
  `remark` varchar(16) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

INSERT INTO test1.A (aid, seq, remark) VALUES (1, 1, 'one');
INSERT INTO test1.A (aid, seq, remark) VALUES (2, 2, 'two');
INSERT INTO test1.A (aid, seq, remark) VALUES (3, 3, 'there');