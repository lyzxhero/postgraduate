CREATE TABLE `compents` (
  `part` varchar(16) DEFAULT NULL,
  `subpart` varchar(16) DEFAULT NULL,
  `num` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci

INSERT INTO test1.compents (part, subpart, num) VALUES ('学校', '教学楼', 10);
INSERT INTO test1.compents (part, subpart, num) VALUES ('学校', '操场', 4);
INSERT INTO test1.compents (part, subpart, num) VALUES ('学校', '食堂', 2);
INSERT INTO test1.compents (part, subpart, num) VALUES ('学校', '宿舍', 3);
INSERT INTO test1.compents (part, subpart, num) VALUES ('教学楼', '教室', 60);
INSERT INTO test1.compents (part, subpart, num) VALUES ('教室', '砖头', 8000);
INSERT INTO test1.compents (part, subpart, num) VALUES ('操场', '砖头', 6000);
INSERT INTO test1.compents (part, subpart, num) VALUES ('食堂', '砖头', 4000);
INSERT INTO test1.compents (part, subpart, num) VALUES ('宿舍', '砖头', 4500);