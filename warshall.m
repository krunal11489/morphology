close all;
clear;
a=[1 1 0 0 0;
   0 0 0 1 0;
   0 0 0 0 1;
   0 1 0 0 0;
   0 0 1 0 0];
[m n]=size(a);
a1(m,n)=0;
for j=1:n
    for i=1:n
        if(a(i,j)==1)
            for k=1:n
                a1(i,k)=a(i,k)+a(j,k);
                if(a1(i,k)>1)
                    a1(i,k)=1;
                end
            end
        end
    end
end