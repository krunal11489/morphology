function [J]=gry_to_bin(I,t)
[m n]=size(I);
for i=1:m
    for j=1:n
        if(I(i,j)>t)
            J(i,j)=true;
        else
            J(i,j)=false;
        end
    end
end
end