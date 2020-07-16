function [b]=rflctn(a)
[m n]=size(a);
for i=1:m
    for j=1:n
        b(m+1-i,n+1-j)=a(i,j);
    end
end
end