select ename, job
from emp
where deptno in (
select deptno
from dept
where loc = 'NEW YORK'
and loc != 'CHICAGO');

select distinct e.job
from emp e, dept d
where e.deptno = d.deptno 
and d.dname = 'RESEARCH';

select ename, sal, job
from emp
where job in (
select job 
from emp
where ename = 'SCOTT')
and sal <(
select sal
from emp
where ename ='KING');

select e.ename, e.sal, e.job
from emp e, emp s, emp k
where e.job = s.job
and s.ename = 'SCOTT'
and e.sal < k.sal
and k.ename ='KING';

select m.ename, m.sal, e.ename, e.sal
from emp m, emp e
where e.mgr = m.empno
and e.sal > m.sal;

select e.ename, e.sal
from emp e, emp m
where e.job = 'CLERK'
and e.sal> m.sal
and m.ename = 'MARTIN' ;


select ename, sal
from emp
where sal in (
select min(sal)
from emp
where job != 'CLERK'
or  job != 'MANAGER');
