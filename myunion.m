%union of same size binary images
function[K]=union(I,J)
[m n]=size(I);
for i=1:m
    for j=1:n
        K(i,j)=I(i,j)|J(i,j);
    end
end
end