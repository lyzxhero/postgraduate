CREATE TABLE `Reserver` (
  `sid` varchar(12) DEFAULT NULL,
  `bid` varchar(12) DEFAULT NULL,
  `day` varchar(12) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

INSERT INTO test1.Reserver (sid, bid, day) VALUES ('22	', '101', '10/10/96');
INSERT INTO test1.Reserver (sid, bid, day) VALUES ('58	', '103', '11/12/96');
INSERT INTO test1.Reserver (sid, bid, day) VALUES ('200	', '888', '11/15/96');
INSERT INTO test1.Reserver (sid, bid, day) VALUES ('200	', '888', '11/16/96');
INSERT INTO test1.Reserver (sid, bid, day) VALUES ('200	', '101', '11/17/96');
INSERT INTO test1.Reserver (sid, bid, day) VALUES ('200	', '103', '11/18/96');
INSERT INTO test1.Reserver (sid, bid, day) VALUES ('201	', '101', '11/19/96');
INSERT INTO test1.Reserver (sid, bid, day) VALUES ('201	', '103', '11/20/96');
INSERT INTO test1.Reserver (sid, bid, day) VALUES ('200	', '105', '11/21/96');