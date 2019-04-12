create table 학생
(이름 varchar(15) NOT NULL,
학번 char(8),
전공 char(5),
성별 sex,
생년월일 date,
primary key(학번),
foreign key(전공) references 학과(학과코드),
on delete set null,
on update cacade,
constraint 생년월일제약 check(생년월일 >= '1980-01-01'));

SELECT ID, NAME FROM CUSTOMER;

SELECT DISTINCT GRADE FROM CUSTOMER;

SELECT * FROM CUSTOMER ORDER BY ID DESC;

SELECT NAME FROM CUSTOMER WHERE AGE IS NULL;

SELECT NAME FROM CUSTOMER WHERE AGE IS NOT NULL;

UPDATE 속성 SET 속성 = 속성 + 값 WHERE 속성 = 값;

DELETE FROM 테이블 WHERE 검색조건;

GRANT UPDATE ON 수강 TO 이재우 (WITH GRANT OPTION);

REVOKE UPDATE ON 수강 FROM 이재우 CASCADE;

ALTER TABLE academy ADD 주소 CHAR(15);

ALTER TABLE academy 주소 MODIFY juso CHAR(15);

ALTER TABLE academy DROP 주소 CASCADE;

CREATE TABLE 상점
(상점코드 CHAR(), 상점명 CHAR(), 매출 INT(), 마감일 DATE,
PRIMARY KEY (상점코드),
FOREIGN KEY (상점명) REFERENCES 협력업체(상점코드),
ON DELETE CASCADE, ON UPDATE CASCADE,
CONSTRAINT CHECK (마감일 >= '2015-12-25')
);

CREATE SCHEMA BOOOLEAN AUTHORIZATION 블린;

CREATE DOMAIN gender CHAR(5);

CREATE INDEX stc_idx
	ON 학생(학번 DESC)
	CLUSTER;

CREATE VIEW 컴과뷰(학번, 이름, 학년)
	AS SELECT 학번, 이름, 학년
		FROM 학생
		WHERE 학과 = '컴퓨터과학과'
		WITH CHECK OPTION;

SELECT A.강의이름, A.강의실, A.강의시간, A.이수구분, B.교수이름, B.소속학과, B.전화번호
FROM 강의 A INNER JOIN 교수 B
ON A.교수번호 = B.교수번호;

SELECT A.학생이름, A.소속학과, A.전화번호, B.신청시각
FROM 학생 A INNER JOIN 수강신청 B
ON A.학생번호 = B.학생번호
WHERE B.강의번호 = 'LA01';

SELECT A.강의번호, A.강의이름, A.이수구분, B.교수이름, B.직위
FROM 강의 A INNER JOIN 교수 B
ON A.교수번호 = B.교수번호;

SELECT A.번호, A.이름, A.취득점수, B.등급
FROM 학사 A CROSS JOIN 등급기준표 B
WHERE A.취득점수 BETWEEN B.하한 AND B.상한;

SELECT A.*, B.* 
FROM 학생 A LEFT OUTER JOIN 수강신청 B
ON A.학생번호 = B.학생번호;

SELECT A.*, B.*
FROM 학생 A RIGHT OUTER JOIN 수강신청 B
ON A.학생정보 = B.학생정보;

SELECT A.강의시간, A.강의이름, A.인원제한, A.이수구분, 
B.강의이름 AS 선수강의이름, B.이수구분 AS 선수이수구분
FROM 강의 A INNER JOIN 강의 B
ON A.선수과목 = B.강의번호;

SELECT 상품명 FROM 상품 WHERE 가격 IS NULL ORDER BY 상품명 DESC;

SELECT 교수번호, 교수이름, 연구실위치, 전화번호
FROM 교수 
WHERE 교수번호 = (SELECT 교수번호 FROM 강의 WHERE 강의번호 = 'KO31');

SELECT 교수번호, 교수이름, 연구실위치, 전화번호
FROM 교수
WHERE 교수번호 IN (SELECT 교수번호 FROM 강의 WHERE 이수구분 LIKE '전공%');

SELECT 학생번호, 학생이름, 나이, 전화번호, 주소
FROM 학생
WHERE 나이 >= (SELECT AVG(나이) FROM 학생);

SELECT * FROM 강의 WHERE EXISTS (SELECT * FROM 수강신청 WHERE 강의.강의번호 = 수강신청.강의번호);
SELECT A.* FROM 강의 A INNER JOIN 수강신청 ON A.강의번호 = B. 강의번호; //위와 같은 결과

SELECT SUM(판매량) FROM 판매 WHERE ID IN (SELECT ID FORM 상품 WHERE 상품명 LIKE ('가공%')); 
