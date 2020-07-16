function [J]=cplmnt(I)
[m n]=size(I);
for i=1:m
    for j=1:n
        J(i,j)=~I(i,j);
    end
end
end