%%
%warshall's algo
clear;
b=[1 1 0 0 0
    0 0 0 1 0
    0 0 0 0 1
    0 1 0 0 0
    0 0 0 0 0];

[m n]=size(b);
b1=b;
j=1;
for j=1:n
for i=1:n
    if b1(i,j)>=1
        for k=1:n
            b1(i,k)=b1(i,k)+b1(j,k);                
        end
    end
end
end
for i=1:n
    for j=1:n
       if b1(i,j)>1
            b1(i,j)=1;
       end
    end
end

b1
b