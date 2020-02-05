CREATE TABLE `Boat` (
  `bid` varchar(12) DEFAULT NULL,
  `bname` varchar(12) DEFAULT NULL,
  `color` varchar(12) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

INSERT INTO test1.Boat (bid, bname, color) VALUES ('101', 'tiger', 'red');
INSERT INTO test1.Boat (bid, bname, color) VALUES ('103', 'lion', 'green');
INSERT INTO test1.Boat (bid, bname, color) VALUES ('105', 'hero', 'blue');
INSERT INTO test1.Boat (bid, bname, color) VALUES ('888', 'lyzx', 'black');