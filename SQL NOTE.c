create table �л�
(�̸� varchar(15) NOT NULL,
�й� char(8),
���� char(5),
���� sex,
������� date,
primary key(�й�),
foreign key(����) references �а�(�а��ڵ�),
on delete set null,
on update cacade,
constraint ����������� check(������� >= '1980-01-01'));

SELECT ID, NAME FROM CUSTOMER;

SELECT DISTINCT GRADE FROM CUSTOMER;

SELECT * FROM CUSTOMER ORDER BY ID DESC;

SELECT NAME FROM CUSTOMER WHERE AGE IS NULL;

SELECT NAME FROM CUSTOMER WHERE AGE IS NOT NULL;

UPDATE �Ӽ� SET �Ӽ� = �Ӽ� + �� WHERE �Ӽ� = ��;

DELETE FROM ���̺� WHERE �˻�����;

GRANT UPDATE ON ���� TO ����� (WITH GRANT OPTION);

REVOKE UPDATE ON ���� FROM ����� CASCADE;

ALTER TABLE academy ADD �ּ� CHAR(15);

ALTER TABLE academy �ּ� MODIFY juso CHAR(15);

ALTER TABLE academy DROP �ּ� CASCADE;

CREATE TABLE ����
(�����ڵ� CHAR(), ������ CHAR(), ���� INT(), ������ DATE,
PRIMARY KEY (�����ڵ�),
FOREIGN KEY (������) REFERENCES ���¾�ü(�����ڵ�),
ON DELETE CASCADE, ON UPDATE CASCADE,
CONSTRAINT CHECK (������ >= '2015-12-25')
);

CREATE SCHEMA BOOOLEAN AUTHORIZATION ��;

CREATE DOMAIN gender CHAR(5);

CREATE INDEX stc_idx
	ON �л�(�й� DESC)
	CLUSTER;

CREATE VIEW �İ���(�й�, �̸�, �г�)
	AS SELECT �й�, �̸�, �г�
		FROM �л�
		WHERE �а� = '��ǻ�Ͱ��а�'
		WITH CHECK OPTION;

SELECT A.�����̸�, A.���ǽ�, A.���ǽð�, A.�̼�����, B.�����̸�, B.�Ҽ��а�, B.��ȭ��ȣ
FROM ���� A INNER JOIN ���� B
ON A.������ȣ = B.������ȣ;

SELECT A.�л��̸�, A.�Ҽ��а�, A.��ȭ��ȣ, B.��û�ð�
FROM �л� A INNER JOIN ������û B
ON A.�л���ȣ = B.�л���ȣ
WHERE B.���ǹ�ȣ = 'LA01';

SELECT A.���ǹ�ȣ, A.�����̸�, A.�̼�����, B.�����̸�, B.����
FROM ���� A INNER JOIN ���� B
ON A.������ȣ = B.������ȣ;

SELECT A.��ȣ, A.�̸�, A.�������, B.���
FROM �л� A CROSS JOIN ��ޱ���ǥ B
WHERE A.������� BETWEEN B.���� AND B.����;

SELECT A.*, B.* 
FROM �л� A LEFT OUTER JOIN ������û B
ON A.�л���ȣ = B.�л���ȣ;

SELECT A.*, B.*
FROM �л� A RIGHT OUTER JOIN ������û B
ON A.�л����� = B.�л�����;

SELECT A.���ǽð�, A.�����̸�, A.�ο�����, A.�̼�����, 
B.�����̸� AS ���������̸�, B.�̼����� AS �����̼�����
FROM ���� A INNER JOIN ���� B
ON A.�������� = B.���ǹ�ȣ;

SELECT ��ǰ�� FROM ��ǰ WHERE ���� IS NULL ORDER BY ��ǰ�� DESC;

SELECT ������ȣ, �����̸�, ��������ġ, ��ȭ��ȣ
FROM ���� 
WHERE ������ȣ = (SELECT ������ȣ FROM ���� WHERE ���ǹ�ȣ = 'KO31');

SELECT ������ȣ, �����̸�, ��������ġ, ��ȭ��ȣ
FROM ����
WHERE ������ȣ IN (SELECT ������ȣ FROM ���� WHERE �̼����� LIKE '����%');

SELECT �л���ȣ, �л��̸�, ����, ��ȭ��ȣ, �ּ�
FROM �л�
WHERE ���� >= (SELECT AVG(����) FROM �л�);

SELECT * FROM ���� WHERE EXISTS (SELECT * FROM ������û WHERE ����.���ǹ�ȣ = ������û.���ǹ�ȣ);
SELECT A.* FROM ���� A INNER JOIN ������û ON A.���ǹ�ȣ = B. ���ǹ�ȣ; //���� ���� ���

SELECT SUM(�Ǹŷ�) FROM �Ǹ� WHERE ID IN (SELECT ID FORM ��ǰ WHERE ��ǰ�� LIKE ('����%')); 
