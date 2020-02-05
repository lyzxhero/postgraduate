CREATE TABLE `B` (
  `bid` int(11) DEFAULT NULL,
  `aid` int(11) DEFAULT NULL,
  `remark` varchar(16) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

INSERT INTO test1.B (bid, aid, remark) VALUES (2, 2, 'two');
INSERT INTO test1.B (bid, aid, remark) VALUES (3, 3, 'three');
INSERT INTO test1.B (bid, aid, remark) VALUES (4, 4, 'four');
INSERT INTO test1.B (bid, aid, remark) VALUES (5, 2, 'two');