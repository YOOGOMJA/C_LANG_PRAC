-- CREATE DEPARTMENT TABLE

CREATE TABLE DEPARTMENT (
    DEPTNO      INT     NOT NULL,
    DEPTNAME    VARCHAR(10),
    FLOOR       NUMBER,
    PRIMARY KEY(DEPTNO)
);

-- CREATE EMPLOYEE TABLE

CREATE TABLE EMPLOYEE (
    EMPNO       INT     NOT NULL,
    EMPNAME     VARCHAR(20) UNIQUE,
    TITLE       VARCHAR(20),
    MANAGER     INT,
    SALARY      INT,
    HIREDATE    DATE,
    DNO         INT,
    PRIMARY KEY(EMPNO),
    FOREIGN KEY(MANAGER) REFERENCES EMPLOYEE(EMPNO),
    FOREIGN KEY(DNO) REFERENCES DEPARTMENT(DEPTNO)
);

-- INSERT DEPARTMENT TABLE VALUES

INSERT INTO DEPARTMENT VALUES (1 , '영업', 8);
INSERT INTO DEPARTMENT VALUES (2 , '기획', 10);
INSERT INTO DEPARTMENT VALUES (3 , '개발', 9);
INSERT INTO DEPARTMENT VALUES (4 , '총무', 7);

-- INSERT EMPLOYEE TABLE VALUES

INSERT INTO EMPLOYEE VALUES(4377 , '이성래' , '사장' , NULL , 5000000 , '1996-01-05' , 2);
INSERT INTO EMPLOYEE VALUES(1234 , '장건호' , '부장' , 4377 , 4200000 , '1996-11-23' , 1);
INSERT INTO EMPLOYEE VALUES(3426 , '박영권' , '과장' , 1234 , 3000000 , '1998-07-20' , 1);
INSERT INTO EMPLOYEE VALUES(1365 , '김상원' , '사원' , 3426 , 1500000 , '2004-02-26' , 1);
INSERT INTO EMPLOYEE VALUES(1099 , '이재원' , '사원' , 3426 , 1800000 , '2003-12-21' , 1);
INSERT INTO EMPLOYEE VALUES(3011 , '이수민' , '부장' , 4377 , 4300000 , '1996-04-30' , 3);
INSERT INTO EMPLOYEE VALUES(2468 , '조범수' , '과장' , 3011 , 3500000 , '1998-12-17' , 3);
INSERT INTO EMPLOYEE VALUES(2544 , '오준석' , '대리' , 2468 , 2700000 , '2002-08-25' , 3);
INSERT INTO EMPLOYEE VALUES(1003 , '조민희' , '대리' , 2468 , 2600000 , '2001-02-19' , 2);
INSERT INTO EMPLOYEE VALUES(3427 , '최종철' , '사원' , 1003 , 1500000 , '2005-10-28' , 3);
INSERT INTO EMPLOYEE VALUES(3228 , '김주훈' , '부장' , 4377 , 4000000 , '1997-03-06' , 2);
INSERT INTO EMPLOYEE VALUES(2106 , '김창섭' , '대리' , 3228 , 2500000 , '2003-03-05' , 2);

