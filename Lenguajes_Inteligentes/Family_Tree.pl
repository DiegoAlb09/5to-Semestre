female(pammi).
female(lizza).
female(patty).
female(anny).
female(jean).
female(anny).

male(jimmy).
male(bobby).
male(tomy).
male(pitter).
male(john).
male(johnson).

parent(johnson,pammi).
parent(anny,pammi).
parent(pammi,bobby).
parent(tomy,bobby).
parent(tomy,lizza).
parent(bobby,anny).
parent(bobby,patty).
parent(patty,jimmy).
parent(bobby,pitter).
parent(pitter,jean).
parent(pitter,john).


mother(X,Y):- parent(X,Y),female(X).
father(X,Y):- parent(X,Y),male(X).
haschild(X):- parent(X,_).
sister(X,Y):- parent(Z,X),parent(Z,Y),female(X),X\==Y.
brother(X,Y):- parent(Z,X),parent(Z,Y),male(X),X\==Y.