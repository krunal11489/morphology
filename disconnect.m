function[I]=disconnect(I)
[m,n]=size(I);
for i=1:m
    for j=1:n
        J(i+1,j+1)=I(i,j);
    end
end
for i=2:m+1
    for j=2:n+1
        if(J(i,j)==true)
            q=0;
            for i1=-1:1
                for j1=-1:1
                    if(i1~=0 && j1~=0)
                        if(J(i+i1,j+j1)==true)
                            q=1;break;
                        end
                    end
                end
                if(q==1)
                    break;
                end
            end
            if(q==0)
                I(i-1,j-1)=false;
            end
        end
    end
end
end
